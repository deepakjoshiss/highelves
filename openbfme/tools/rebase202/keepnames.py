import re, sys, os, subprocess, collections
# usage: keepnames.py <mod repo> <merged ini dir> [names file] : fails when a name of the mod's own is used less than in the committed mod:
# H_* / Upgrade_New*, and the names merge.py found only the mod defines (modonly.txt: its added blocks, its first-commit blocks 2.02 lacks)
H, M = sys.argv[1:3]
extra = [l.strip() for l in open(sys.argv[3])] if len(sys.argv) > 3 else []
tok = re.compile(r'\b(h_[a-z0-9_]+|upgrade_new[a-z0-9_]*' + ''.join('|' + re.escape(x) for x in extra if x) + r')\b')
strip = lambda t: '\n'.join(re.sub(r'(;|//).*', '', l) for l in t.splitlines()).lower()
def count(texts):
    c = collections.Counter()
    for t in texts: c.update(tok.findall(strip(t)))
    return c
names = subprocess.run(['git', '-C', H, 'ls-tree', '-r', '--name-only', os.environ['REBASE_OURS'], 'data/ini'], capture_output=True, text=True, check=True).stdout.split()
head = count(subprocess.run(['git', '-C', H, 'show', f"{os.environ['REBASE_OURS']}:{n}"], capture_output=True).stdout.decode('latin-1') for n in names if n.lower().endswith(('.ini', '.inc')))
merged = count(open(os.path.join(r, f), encoding='latin-1').read() for r, _, fs in os.walk(M) for f in fs if f.lower().endswith(('.ini', '.inc')))
drop = {k: (head[k], merged[k]) for k in head if merged[k] < head[k]}
for k, v in sorted(drop.items()): print(f'  lost: {k} {v[0]} -> {v[1]}')
print(f'mod names: {len(head)} checked, {len(drop)} used less'); sys.exit(1 if drop else 0)
