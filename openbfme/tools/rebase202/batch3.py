import sys, json, os
# usage: batch3.py <review.json> <resolutions dir> : batch 3a, approved 2026-10-21: the 117 held #define macros take v9.8.0's value.
# None is a mod edit: for 116 the mod's value is in v9.8.0's own change history for that line (";,; old value"), or carries 2.02's ;,; marker;
# ELVEN_MIST_OBJECT_FILTER is the same list, v9.8.0 adding its new Ent Ash melee units. The mod's own balance lives in its H_* macros.
R = json.load(open(sys.argv[1])); D = sys.argv[2]
held = [r for r in R if r['kind'] == 'held' and r['name'].startswith('#define')]
assert len(held) == 117, len(held)
with open(os.path.join(D, 'macros.ini'), 'w', encoding='latin-1') as f:
    for r in sorted(held, key=lambda r: r['name']):
        f.write(f"; rebase202-file: {r['file']}\n" + r['theirs'].replace('\r\n', '\n').rstrip('\n') + '\n')
print('macros: 117 from v9.8.0')
