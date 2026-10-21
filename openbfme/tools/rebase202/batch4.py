import sys, json, os
# usage: batch4.py <review.json> <resolutions dir> : batch 3b, approved 2026-10-21: the held buttons, command sets and sounds take v9.8.0's
# version (2.02's audio pass, new voice lines, expansions built as upgrades, USER_67 power locks, purchased tooltips, upgrade tiers ...),
# except two command sets that stay the mod's: the porter's (v9.8.0's set plus the mod's Gondolin tower at 11) and Thranduil's (the elf cloak
# and Rampage, matching the mod's super bow; 2.02's Hidden Hunter / Dead Eye need its hidden-bow weapon sets).
KINDS = ('commandbutton', 'commandset', 'audioevent', 'multisound', 'musictrack')
KEEP = {'commandset elvenportercommandset', 'commandset elventhranduilcommandset'}
R = json.load(open(sys.argv[1])); D = sys.argv[2]
held = [r for r in R if r['kind'] == 'held' and r['name'].split()[0] in KINDS]
assert len(held) == 120 and KEEP <= {r['name'] for r in held}, len(held)
with open(os.path.join(D, 'buttons_sounds.ini'), 'w', encoding='latin-1') as f:
    for r in sorted(held, key=lambda r: r['name']):
        if r['name'] not in KEEP: f.write(f"; rebase202-file: {r['file']}\n" + r['theirs'].replace('\r\n', '\n').rstrip('\n') + '\n\n')
print('buttons, command sets, sounds: 118 from v9.8.0, 2 kept')
