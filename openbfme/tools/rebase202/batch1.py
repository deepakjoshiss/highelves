import sys, json, re, os
# usage: batch1.py <review.json> <resolutions dir> : batch 1 hand merges approved 2026-10-21 (items 4-9, 10 = B, 11); review.json from a merge
# run without resolutions. Each draft starts as the block's line merge (its REVIEW spots the mod's), then the approved spots are set.
R = json.load(open(sys.argv[1])); D = sys.argv[2]
def block(name): return [r for r in R if r['name'] == name and 'spots' in r][0]
def spots(name): return [x for x in block(name)['spots'] if x['how'].startswith('REVIEW')]
def spot(name, rx):
    # the one REVIEW spot of the block whose mod side matches rx (spots are picked by content: their order moves when the merge changes)
    m = [x for x in spots(name) if re.search(rx, x['mod'])]; assert len(m) == 1, (name, rx, len(m)); return m[0]
DRAFTS = {'watchtower.ini': 'commandset elvenwatchtowercommandset', 'statue.ini': 'modifierlist heroicstatuepassiveleadership',
          'summoned.ini': 'experiencelevel summoneddefensivestructureslevel1', 'legolas.ini': 'object rohanlegolas', 'elrond.ini': 'object elvenelrond',
          'thranduil.ini': 'object elventhranduil', 'elvenarmy.ini': 'armydefinition elvenarmy', 'citadel.ini': 'object elvencitadel'}
for f, n in DRAFTS.items(): open(os.path.join(D, f), 'w', encoding='latin-1').write(block(n)['merged'])
def put(draft, name, rx, new):
    p = os.path.join(D, draft); d = open(p, encoding='latin-1').read(); old = spot(name, rx)['mod']
    assert d.count(old) == 1, (name, rx, d.count(old)); open(p, 'w', encoding='latin-1').write(d.replace(old, new))

def respawn_b(name, rx='RespawnRules'):
    # 2.02's per-level table (cost 60% -> 100%, time x 1.000 -> 1.675 by level), its base time swapped for the mod's faster one:
    # HERO_RESPAWNTIME_TIER_k (70, in seconds) -> #DIVIDE( H_HERO_RESPAWNTIME_TIER_m 1000 ), m = the tier the mod's line used
    s = spot(name, rx); m = re.search(r'H_HERO_RESPAWNTIME_TIER_(\d)', s['mod']).group(1)
    out = []
    for l in s['theirs'].split('\n'):
        if not l.lstrip().startswith(';'): l = re.sub(r'\bHERO_RESPAWNTIME_TIER_\d\b', f'#DIVIDE( H_HERO_RESPAWNTIME_TIER_{m} 1000 )', l)
        out.append(l)
    return '\n'.join(out)

def cp_with_include(name, rx='CommandPoints'):
    # the mod's command points line, then 2.02's corrode-allegiance include
    s = spot(name, rx); inc = [l for l in s['theirs'].split('\n') if '#include' in l]
    assert len(inc) == 1; return s['mod'] + inc[0] + '\n'

# 4. watchtower: 2.02's slots are the combination (both put ExitGarrison at 2, Silverthorn at 3; 2.02 adds stealth detection at 1)
put('watchtower.ini', 'commandset elvenwatchtowercommandset', 'Command_ExitGarrison', spot('commandset elvenwatchtowercommandset', 'Command_ExitGarrison')['theirs'])
# 6. heroic statue leadership: 2.02's modifiers, the mod's duration (2.02's DAMAGE_MULT 25% kept as 2.02 wrote it: listed for Deepak)
st = spot('modifierlist heroicstatuepassiveleadership', 'DAMAGE_MULT')['theirs']; assert st.count('= 3000') == 1
put('statue.ini', 'modifierlist heroicstatuepassiveleadership', 'DAMAGE_MULT', st.replace('= 3000', '= 2100 ; mod (2.02 v9.8.0: 3000)'))
# 5. summoned defensive structures level 1: 2.02's version, the mod's TreeFlet added to its targets
s = spot('experiencelevel summoneddefensivestructureslevel1', 'TargetNames')['theirs']
assert s.count('GondorSentryTower_Independant ;,; MordorBarricade') == 1
put('summoned.ini', 'experiencelevel summoneddefensivestructureslevel1', 'TargetNames', s.replace('GondorSentryTower_Independant ;,; MordorBarricade', 'GondorSentryTower_Independant TreeFlet ;,; MordorBarricade'))
# 7. Legolas: respawn B; the mod's ability range 500 with 2.02's ApproachRequiresLOS = No
put('legolas.ini', 'object rohanlegolas', 'StartAbilityRange', spot('object rohanlegolas', 'StartAbilityRange')['mod'].replace(';ApproachRequiresLOS', 'ApproachRequiresLOS').replace('= Yes', '= No ;,; Yes (2.02 v9.8.0)'))
put('legolas.ini', 'object rohanlegolas', 'RespawnRules', respawn_b('object rohanlegolas'))
# 8 + 10. Elrond, Thranduil: the mod's command points + 2.02's include; respawn B (spot 0 stays the mod's: Elrond's model, Thranduil's weapon sets)
for name, f in (('object elvenelrond', 'elrond.ini'), ('object elventhranduil', 'thranduil.ini')):
    new1, new2 = cp_with_include(name), respawn_b(name)
    put(f, name, 'RespawnRules', new2); put(f, name, 'CommandPoints', new1)
print('batch 1 scripted merges applied')

# 9. elven AI army: 2.02's unit swaps, the mod's percentages, Tauriel. Spots 0 and 2: the mod's tweak was to members 2.02 replaced (peasants,
# Ent_Member4), so 2.02's; spot 1: 2.02's, with the mod's phase 3 share (20) for the member both changed; spot 3: Tauriel, then 2.02's Legolas
A = 'armydefinition elvenarmy'
sp = {i: spot(A, rx) for i, rx in enumerate(('RohanPeasantHordeInn_Member', r'PercentageOfArmyPhase2\s*=\s*30', 'ElvenEnt_Member4', 'MirkwoodTauriel'))}
mod3 = [l for l in sp[1]['mod'].split('\n') if 'PercentageOfArmyPhase3' in l][0]
t1 = sp[1]['theirs'].split('\n'); i = next(k for k, l in enumerate(t1) if 'PercentageOfArmyPhase3' in l); t1[i] = mod3 + ' ; mod (2.02 v9.8.0: 35.0)'
new3, k = re.subn(r'(ArmyMemberDefinition\s+|Unit\s*=\s*)ElvenThranduil\b', r'\1ElvenLegolas', sp[3]['mod']); assert k == 2, k
put('elvenarmy.ini', A, 'MirkwoodTauriel', new3); put('elvenarmy.ini', A, 'ElvenEnt_Member4', sp[2]['theirs'])
put('elvenarmy.ini', A, r'PercentageOfArmyPhase2\s*=\s*30', '\n'.join(t1)); put('elvenarmy.ini', A, 'RohanPeasantHordeInn_Member', sp[0]['theirs'])
print('elven army merged')

# 11. elven citadel: spot 0 the mod's (ivory tower, vines); spot 1 2.02's resurrection aura (the line merge already took 2.02's module header)
put('citadel.ini', 'object elvencitadel', 'IdleSpawnRate', spot('object elvencitadel', 'IdleSpawnRate')['theirs'])
print('citadel merged')

# 13. Haldir: the mod moved his body into Object ElvenHaldirInterface (ElvenHaldir is its child), so 2.02's Haldir changes are ported there.
# Approved: the corrode-allegiance CP include, the tooltip, the dual-weapon aura. Not SpecialEnemySenseUpdate (OpenBFME lacks it); 2.02's other
# Haldir changes go to batch 2.
import subprocess
src = subprocess.run(['git', '-C', os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', '..')), 'show', os.environ['REBASE_OURS'] + ':data/ini/object/goodfaction/units/elven/haldir.ini'],
                     capture_output=True, check=True).stdout.decode('latin-1')
iface = src[src.index('Object ElvenHaldirInterface'):]; iface = iface[:re.search(r'(?m)^End\s*$', iface).end()] + '\n'
lines = iface.split('\n'); out = []
for l in lines:
    out.append(l)
    if re.match(r'\s*CommandPoints\s*=\s*H_HERO_COMMAND_POINTS_TIER_2', l): out.append('\t#include "..\\..\\..\\CORRODE_ALLEGIANCE_CP_HACK_TIER_2.inc" ; 2.02 v9.8.0')
    if re.match(r'\s*DisplayRangedDamage\s*=', l): out.append('\tDescription\t\t= TOOLTIP:Haldir ; 2.02 v9.8.0')
    if re.match(r'\s*HeroSortOrder\s*=', l):
        out += ['', '\tBehavior = AttributeModifierAuraUpdate ModuleTag_VisionModifier ; 2.02 v9.8.0', '\t\tTriggeredBy = Upgrade_WeaponToggle',
                '\t\tBonusName = DualWeaponHeroInMeleeModifier', '\t\tRefreshDelay = 100', '\t\tAllowSelf = Yes', '\tEnd']
assert len(out) == len(lines) + 9, len(out) - len(lines)
open(os.path.join(D, 'haldir.ini'), 'w', encoding='latin-1').write('\n'.join(out))
print('haldir interface ported')

# the Elven fortress limit stays the mod's 8 (batch 3e: every other faction 5, the first commit 8 for the Elves only); the citadel had it too
p = os.path.join(D, 'citadel.ini'); c = open(p, encoding='latin-1').read()
c, k = re.subn(r'(MaxSimultaneousOfType\s*=\s*)5\b', r'\g<1>8 ; mod (2.02 v9.8.0: 5)', c); assert k == 1, k
open(p, 'w', encoding='latin-1').write(c); print('citadel: fortress limit 8')

# Elrond's draw module is the mod's whole (approved 2026-10-21): the line merge kept the mod's Model line (auelrond_tha, the elf warrior skeleton)
# but took 2.02's animations, which are for 2.02's RUElrond skeleton. Only the draw module: the edits above (command points, respawn) stay.
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__))); from resolve import draw_modules
src = subprocess.run(['git', '-C', os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', '..')), 'show',
                      os.environ['REBASE_OURS'] + ':data/ini/object/goodfaction/units/elven/elrond.ini'], capture_output=True, check=True).stdout.decode('latin-1')
ours = re.search(r'(?ims)^Object\s+ElvenElrond\b.*?^End\b', src.replace('\r\n', '\n')).group(0)
p = os.path.join(D, 'elrond.ini'); d = open(p, encoding='latin-1').read()
mine = [m for m in draw_modules(ours) if m[2] == 'ModuleTag_DRAW']; theirs_ = [m for m in draw_modules(d) if m[2] == 'ModuleTag_DRAW']
assert len(mine) == 1 and len(theirs_) == 1 and d.count(theirs_[0][3]) == 1, (len(mine), len(theirs_))
open(p, 'w', encoding='latin-1').write(d.replace(theirs_[0][3], mine[0][3])); print('elrond: the mod\'s draw module')
