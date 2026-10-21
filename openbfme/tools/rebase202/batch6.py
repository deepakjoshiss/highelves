import sys, json, os, re
# usage: batch6.py <review.json> <resolutions dir> : the held blocks left after batches 1-5, group by group as approved, through the protected
# merge: v9.8.0's version, except a line that names one of the mod's own things (modonly.txt: its H_* macros, Upgrade_New*, its blocks 2.02
# lacks such as NoldorArcherHorde) stays the mod's. Groups (first match on the block name, as reviewed):
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__))); from resolve import merge3
GROUPS = [('Heroes', r'arwen|elrond|glorfindel|haldir|legolas|thranduil|galadriel|celeborn|cirdan|tauriel|gildor|hero'),
          ('Lothlorien', r'lorien|galadhrim'), ('Mirkwood', r'mirkwood'), ('Rivendell / Noldor', r'rivendell|noldor|lancer|imladris'),
          ('Ents & eagles', r'\bent|ent_|ents|eagle|tree|mallorn'),
          ('Buildings & fortress', r'fortress|citadel|barracks|pasture|forge|tower|wall|statue|mirror|well|moot|porter|structure|expansion|gate'),
          ('Elven misc', r'elv|elf'), ('Other', r'.')]
APPROVED = {  # group: date approved
    'Rivendell / Noldor': '2026-10-21',  # 17 as v9.8.0; the 10 Noldor warrior levels keep the mod's TargetNames (its Noldor archers)
    'Lothlorien': '2026-10-21',          # as v9.8.0
    'Mirkwood': '2026-10-21',            # as v9.8.0; the range-finder keeps the mod's H_ELVEN_MIRKWOOD_ARCHER_RANGE lines
    'Ents & eagles': '2026-10-21',       # as v9.8.0
    'Buildings & fortress': '2026-10-21',  # as v9.8.0, but the fortress limit stays the mod's 8 (FIX)
    'Elven misc': '2026-10-21',          # as v9.8.0
}
# first-commit edits the protection cannot see (a plain value), found in review: block -> [(pattern, replacement)], each must apply
FIX = {'object elvenfortress': [(r'(MaxSimultaneousOfType\s*=\s*)5\b', r'\g<1>8 ; mod (2.02 v9.8.0: 5; every other faction 5, the first commit 8 for the Elves only)')]}
DONE_KINDS = ('#define', 'commandbutton', 'commandset', 'audioevent', 'multisound', 'musictrack')  # batches 3 and 4
R = json.load(open(sys.argv[1])); D = sys.argv[2]
names = [l.strip() for l in open(os.path.join(os.path.dirname(sys.argv[1]), 'modonly.txt')) if l.strip()]
modrx = re.compile(r'\b(' + '|'.join(map(re.escape, sorted(names, key=len, reverse=True))) + r')\b', re.I)
group = lambda n: next(g for g, rx in GROUPS if re.search(rx, n, re.I))
count = {}
with open(os.path.join(D, 'groups.ini'), 'w', encoding='latin-1') as f:
    for r in sorted(R, key=lambda r: r['name']):
        if r['kind'] != 'held' or r['name'].startswith(DONE_KINDS) or group(r['name']) not in APPROVED: continue
        text, spots = merge3(r['base'], r['ours'], r['theirs'], modrx)
        assert not any(s['how'].startswith('REVIEW') for s in spots), r['name']  # a spot the rules cannot settle needs a decision
        for rx, new in FIX.get(r['name'], []):
            text, k = re.subn(rx, new, text); assert k, (r['name'], rx)
        f.write(f"; rebase202-file: {r['file']}\n" + text.rstrip('\n') + '\n\n'); count[group(r['name'])] = count.get(group(r['name']), 0) + 1
print('groups:', count)
