import sys, os, re, struct, subprocess, collections
# usage: batch7.py <review.json> <resolutions dir> : the edits made to data/ini after the rebase, as approved, so an --apply keeps them. Each block is
# the version the merge takes (the mod's before the rebase, REBASE_OURS, or v9.8.0's for a block only 2.02 has: merge-report.json "v9.8.0 added"),
# cut by the merge's own reader and named by its block key, with its edits applied; every edit must match once.
T = os.path.dirname(os.path.abspath(__file__)); H = os.path.abspath(os.path.join(T, '..', '..', '..'))
sys.path.insert(0, os.path.dirname(T)); from iniblocks import strip
src = open(os.path.join(T, 'merge.py')).read(); M = {'re': re, 'collections': collections, 'strip': strip}
exec(src[src.index('ELVEN ='):src.index('def rev_tree')], M)  # merge.py's blockkey / parse (merge.py runs the merge on import)
BIG = os.environ.get('BIG', os.path.expanduser('~/Games/BFME/Patch202/__patch202.big'))  # rebase.sh's default
EDITS = {  # (file under data/ini, block key, source): [(pattern, replacement)]
    # 2026-10-22: the two upgrades had each other's cost constant (both 400 then); highelves 5bb8b6d
    ('mod/upgrade.inc', 'upgrade upgrade_mallorntreebloom', 'ours'): [(r'(BuildCost\s*=\s*)H_ELVEN_NIMRODEL_WATERS_COST', r'\g<1>H_ELVEN_MALLORN_TREE_BLOOM_COST')],
    ('mod/upgrade.inc', 'upgrade upgrade_nimrodelwaters', 'ours'): [(r'(BuildCost\s*=\s*)H_ELVEN_MALLORN_TREE_BLOOM_COST', r'\g<1>H_ELVEN_NIMRODEL_WATERS_COST')],
    # 2026-10-22: 2.02's palantir vision tracker: its own KindOf dropped PalantirVisionBase's UNATTACKABLE and units attacked the invisible tracker;
    # highelves 358794e (OpenBFME's scan also skips NOT_AUTOACQUIRABLE now, as retail's)
    ('object/system/system.ini', 'object palantirvisiontracker', 'theirs'): [
        (r'(KindOf = PRELOAD NOT_AUTOACQUIRABLE) (IGNORE_FOR_VICTORY[^\r\n]*)',
         r"\1 UNATTACKABLE \2 ;;,;; UNATTACKABLE added: units attacked this invisible tracker (its own KindOf drops PalantirVisionBase's)")],
    # 2026-10-22: the Create-a-Hero bow held between shots: BETWEEN_FIRING_SHOTS_A WEAPONSET_TOGGLE_1 played the idle for the one tick between the
    # reload's end and the next shot, so the hero lowered the bow and drew it again; highelves 80f0287
    ('object/createahero/createaheroanims.inc', 'animationstate = special_weapon_two', 'theirs'): [
        (r'(AnimationState\s*=\s*BETWEEN_FIRING_SHOTS_A WEAPONSET_TOGGLE_1\r?\n\s*StateName\s*=\s*STATE_ready\r?\n\t\t\tAnimation)(\r?\n)'
         r'(\t\t\t\tAnimationName\t\t= )#\(MODEL\)_B_IDLA(\r?\n\t\t\t\tAnimationMode\t\t= )ONCE',
         r"\1\t\t\t\t\t// hold the drawn bow between shots (as CONTINUOUS_FIRE_MEAN): the one tick between the reload's end and the next shot "
         r"dropped to #(MODEL)_B_IDLA and back\2\3#(MODEL)_B_ATKA2\4MANUAL")],  # the file's own line breaks (LF)
    # 2026-10-23, the mod's changes to other factions and to every faction go back to 2.02 v9.8.0 (the High Elves split: vanilla stays 2.02's), except
    # the fixes kept (the palantir tracker above, the statue's DAMAGE_MULT 125% in batch2.py, the burning deaths' speed 0, the garrison range below).
    # Game rules: 2.02's command points for 5-8 players and its WeaponBonus GARRISONED lines (100%: they add nothing, RW 0x6CA4B5), the mod's range.
    ('gamedata.ini', 'gamedata', 'theirs'): [
        (r'(GarrisonedRangeMultiplier = )1\.10( ;,; 1\.25)', r'\g<1>1.4 ; mod (2.02 v9.8.0: 1.10)\2')],
    ('experiencelevels.ini', 'experiencescalartable defaultexperiencescalartable', 'theirs'): [],
    ('attributemodifier.ini', 'modifierlist genericheroleadership', 'theirs'): [],  # the linger time: 3000, not the mod's 2200
    ('default/object.ini', 'object defaultthingtemplate', 'theirs'): [],  # no game-speed hook (Upgrade_New0, TestingFastGamePlay: x1 anyway)
    # the AI: 2.02's targeting, build discount and armies (the High Elves faction gets no AI)
    ('default/skirmishaidata.ini', 'skirmishaidata theskirmishaidata', 'theirs'): [],
    ('default/skirmishaidata.ini', 'armydefinition elvenarmy', 'theirs'): [],
    ('default/skirmishaidata.ini', 'armydefinition mordorarmy', 'theirs'): [],
    ('default/skirmishaidata.ini', 'armydefinition isengardarmy', 'theirs'): [],
    # the evil factions' production buildings: 2.02's exit delay, no UseReturnToFormation
    ('object/evilfaction/structures/evilmen/haradrimpalace.ini', 'object mordorharadrimpalace', 'theirs'): [],
    ('object/evilfaction/structures/wild/cave.ini', 'object goblincave', 'theirs'): [],
    ('object/evilfaction/structures/isengard/urukpit.ini', 'object isengardurukpit', 'theirs'): [],
    ('object/evilfaction/structures/isengard/isengardtavern.ini', 'object isengardtavern', 'theirs'): [],
    ('object/evilfaction/structures/mordor/orcpit.ini', 'object mordororcpit', 'theirs'): [],
    ('object/evilfaction/structures/mordor/mordortavern.ini', 'object mordortavern', 'theirs'): [],
}
rev = os.environ['REBASE_OURS']
def theirs(rel):
    f = open(BIG, 'rb'); f.read(8); count = struct.unpack('>I', f.read(4))[0]; f.read(4)
    for _ in range(count):
        off, size = struct.unpack('>II', f.read(8)); name = b''
        while (c := f.read(1)) != b'\0': name += c
        if name.decode('latin-1').replace('\\', '/').lower() == 'data/ini/' + rel: f.seek(off); return f.read(size)
    raise SystemExit(f'{rel} is not in {BIG}')
for n, ((rel, key, source), edits) in enumerate(EDITS.items()):
    data = theirs(rel) if source == 'theirs' else subprocess.run(['git', '-C', H, 'show', f'{rev}:data/ini/{rel}'], capture_output=True, check=True).stdout
    found = [s[3] for s in M['parse'](data) if s[0] == 'block' and s[1] == key]
    assert len(found) == 1, (rel, key, len(found))  # a resolution names every block of its key in the file
    block = found[0]
    for rx, new in edits:  # none: the block as its source has it (a revert to 2.02's)
        block, k = re.subn(rx, new, block); assert k == 1, (rel, key, rx, k)
    # one file per block: a module fragment (the Create-a-Hero AnimationState) ends only at a column-0 End, so a block after it in the same file
    # would be read into it
    with open(os.path.join(sys.argv[2], f'handedit{n:02d}.ini'), 'w', encoding='latin-1', newline='') as f:
        f.write(f'; rebase202-file: {rel}\r\n' + block + ('' if block.endswith('\n') else '\r\n'))  # no blank line after: the reader would keep it in the block
print('hand edits:', len(EDITS))
