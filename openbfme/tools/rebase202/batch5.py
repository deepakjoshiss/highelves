import sys, json, os, re
# usage: batch5.py <review.json> <resolutions dir> : batch 3c, the heroes, approved 2026-10-21.
#   The 40 held hero blocks take v9.8.0's version (2.02's work: auto-resolve and power bonuses, Arwen's flood, Galadriel, Celeborn, the Mirror,
#   Elrond's powers, the hero melee weapons and warheads, and the hero experience levels).
#   2.02's upgrade scheme: a hero's experience level grants Upgrade_ObjectLevelN and its powers wait for those; the per-hero unlock upgrades
#   2.02 removed (Upgrade_LegolasHawkStrike ...) are no longer granted, and the merge's prune drops their definitions once nothing names them.
#   The mod's own Upgrade_New1 / Upgrade_New2 (levels 7 and 10, its weapon upgrades) stay: each elven hero level grants v9.8.0's upgrades
#   plus the mod's Upgrade_New* ones, also the levels both sides changed (their line merge had kept the mod's per-hero Upgrades line).
R = json.load(open(sys.argv[1])); D = sys.argv[2]
HERO = re.compile(r'arwen|elrond|glorfindel|haldir|legolas|thranduil|galadriel|celeborn|cirdan|tauriel|gildor|hero', re.I)
SKIP = ('#define', 'commandbutton', 'commandset', 'audioevent', 'multisound', 'musictrack')
held = [r for r in R if r['kind'] == 'held' and not r['name'].startswith(SKIP) and HERO.search(r['name'])]
assert len(held) == 40, len(held)

def upgrades(t): return [x for l in re.findall(r'(?im)^\s*Upgrades\s*=\s*([^;\n]*)', t) for x in l.split()]
def set_upgrades(text, names):
    # one "Upgrades = ..." line with `names`, where the first one was (else before the block's last End)
    lines = text.replace('\r\n', '\n').rstrip('\n').split('\n'); out, done = [], False
    for l in lines:
        if re.match(r'\s*Upgrades\s*=', l):
            if not done: out.append('\tUpgrades\t\t\t\t= ' + ' '.join(names) + ' ; 2.02 v9.8.0 scheme (+ the mod\'s Upgrade_New*)'); done = True
            continue
        out.append(l)
    if not done:
        i = max(k for k, l in enumerate(out) if re.match(r'\s*End\b', l, re.I))
        out.insert(i, '\tUpgrades\t\t\t\t= ' + ' '.join(names) + ' ; the mod\'s Upgrade_New*')
    return '\n'.join(out) + '\n'

def level_target(r): m = re.search(r'(?im)^\s*TargetNames\s*=\s*([^;\n]*)', r['ours'] or ''); return m.group(1) if m else ''
levels = {}
for r in R:  # every elven hero level, held or changed on both sides
    if not r['name'].startswith('experiencelevel ') or r['theirs'] is None or not HERO.search(level_target(r) + r['name']): continue
    if r['kind'] not in ('held', 'both changed'): continue
    start = r['theirs'] if r['kind'] == 'held' else r['merged']
    names = upgrades(r['theirs']) + [u for u in upgrades(r['ours']) if u.lower().startswith('upgrade_new') and u not in upgrades(r['theirs'])]
    levels[(r['file'], r['name'])] = set_upgrades(start, names) if names else start

with open(os.path.join(D, 'heroes.ini'), 'w', encoding='latin-1') as f:
    for r in sorted(held, key=lambda r: r['name']):
        if (r['file'], r['name']) in levels: continue
        f.write(f"; rebase202-file: {r['file']}\n" + r['theirs'].replace('\r\n', '\n').rstrip('\n') + '\n\n')
    for (file, name), text in sorted(levels.items()):
        f.write(f"; rebase202-file: {file}\n" + text.rstrip('\n') + '\n\n')
print(f'heroes: {len(held)} held blocks from v9.8.0; {len(levels)} hero levels on 2.02\'s scheme (+ Upgrade_New*)')

# The mod's own uses of a removed per-hero unlock bind to the level-N upgrade 2.02 grants at the same level (Upgrade_HaldirGoldenArrow: 8):
# Haldir's "Lorien Captain" aura (the interface draft batch1/2 wrote) and his super bow warhead (the mod's block, weapon.ini).
import subprocess
p = os.path.join(D, 'haldir.ini'); h = open(p, encoding='latin-1').read()
h, k = re.subn(r'(BonusName\s*=\s*StandardDebuff\s*\n\s*TriggeredBy\s*=\s*)Upgrade_HaldirGoldenArrow', r'\1Upgrade_ObjectLevel8 ; 2.02 scheme: Upgrade_HaldirGoldenArrow', h)
assert k == 1, k; open(p, 'w', encoding='latin-1').write(h)
src = subprocess.run(['git', '-C', os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', '..')), 'show', 'HEAD:data/ini/weapon.ini'],
                     capture_output=True, check=True).stdout.decode('latin-1')
w = re.search(r'(?ims)^Weapon\s+HaldirSuperBowWarhead\b.*?^End\b[^\n]*\n', src).group(0)
w, k = re.subn(r'(RequiredUpgradeNames\s*=\s*)Upgrade_HaldirGoldenArrow\b', r'\1Upgrade_ObjectLevel8 ; 2.02 scheme: Upgrade_HaldirGoldenArrow', w)
assert k == 2, k
with open(os.path.join(D, 'heroes.ini'), 'a', encoding='latin-1') as f: f.write('; rebase202-file: weapon.ini\n' + w + '\n')
print('haldir: Lorien Captain aura and super bow warhead on Upgrade_ObjectLevel8')

# Levels the mod changed and 2.02 did not (no review entry): the removed per-hero unlocks come out of their grants too, the rest stays
# (ElvenGlorfindelLevel7: Upgrade_GlorindelStarlight; ElvenLegolasLevel10: Upgrade_LegolasArrowWind, keeping the mod's Upgrade_New2).
# The 21 per-hero unlock upgrades the v8.4 hero levels granted and v9.8.0 no longer defines:
REMOVED = {u.lower() for u in '''Upgrade_ArwenElvenGraceTrigger Upgrade_ArwenFloodTrigger Upgrade_ElrondElvenGrace Upgrade_ElrondFarsight
    Upgrade_ElrondLeadership Upgrade_ElrondRestoration Upgrade_ElrondTornado Upgrade_GlorfindelBladeOfPurity Upgrade_GlorfindelWindRider
    Upgrade_GlorindelStarlight Upgrade_HaldirGoldenArrow Upgrade_HaldirLeadership Upgrade_LegolasArrowWind Upgrade_LegolasHawkStrike
    Upgrade_LegolasKnifeFighter Upgrade_LegolasTrainArchers Upgrade_ThranduilDeadeye Upgrade_ThranduilElfCloak Upgrade_ThranduilMoveUnseen
    Upgrade_ThranduilThornofVengeance Upgrade_ThranduilWildWalk'''.split()}
done = {name for (_, name) in levels} | {r['name'] for r in R}  # the merge decides every block it reviewed (both changed: its line merge)
# only levels the plain merge kept as the mod's ("ours changed"); the rest it already takes from v9.8.0 or merges
ours_changed = set(json.load(open(os.path.join(os.path.dirname(sys.argv[1]), 'merge-report.json'))).get('ours changed', []))
src = subprocess.run(['git', '-C', os.path.abspath(os.path.join(os.path.dirname(os.path.abspath(__file__)), '..', '..', '..')), 'show', 'HEAD:data/ini/experiencelevels.ini'],
                     capture_output=True, check=True).stdout.decode('latin-1')
extra = []
for m in re.finditer(r'(?ims)^ExperienceLevel\s+(\w+)\b.*?^End\b[^\n]*\n', src):
    name = 'experiencelevel ' + m.group(1).lower(); ups = upgrades(m.group(0))
    if name in done or name not in ours_changed or not any(u.lower() in REMOVED for u in ups): continue
    keep = [u for u in ups if u.lower() not in REMOVED]
    text = set_upgrades(m.group(0), keep) if keep else re.sub(r'(?im)^\s*Upgrades\s*=[^\n]*\n', '', m.group(0).replace('\r\n', '\n'))
    extra.append(f'; rebase202-file: experiencelevels.ini\n{text.rstrip()}\n\n'); print(f'  {m.group(1)}: dropped {[u for u in ups if u.lower() in REMOVED]}, kept {keep}')
with open(os.path.join(D, 'heroes.ini'), 'a', encoding='latin-1') as f: f.write(''.join(extra))
