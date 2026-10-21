import sys, os, re, subprocess, collections
# usage: drawcheck.py <mod repo> <merged ini dir> : fails when an object whose draw names (Model / AnimationName / Animation / IdleAnimation) the mod
# changed against its first commit loses one of the mod's Model names, or loses a quarter or more of the mod's draw name references: the line merge
# can keep a module's Model line and take another skeleton's animations (Elrond, 2026-10-21). Gains (2.02's additions) only print.
H, M = sys.argv[1:3]; REV = os.environ['REBASE_OURS']
git = lambda *a: subprocess.run(['git', '-C', H, *a], capture_output=True, check=True).stdout.decode('latin-1')
first = git('rev-list', '--max-parents=0', 'HEAD').split()[0]
def tree(rev):
    names = [n for n in git('ls-tree', '-r', '--name-only', rev, 'data/ini').split() if n.lower().endswith(('.ini', '.inc'))]
    return '\n'.join(git('show', f'{rev}:{n}') for n in names)
def draws(t):
    out = {}
    t = '\n'.join(re.sub(r'(;|//).*', '', l) for l in t.splitlines())
    for m in re.finditer(r'(?ims)^(?:Object|ChildObject)\s+(\w+)\b(.*?)^End\b', t):
        models = collections.Counter(n.lower() for n in re.findall(r'(?im)^\s*Model\s*=\s*(\S+)', m.group(2)))
        names = collections.Counter(n.lower() for n in re.findall(r'(?im)^\s*(?:Model|AnimationName|Animation|IdleAnimation)\s*=\s*(\S+)', m.group(2)))
        out.setdefault(m.group(1).lower(), (models, names))
    return out
base, ours = draws(tree(first)), draws(tree(REV))
merged = draws('\n'.join(open(os.path.join(r, f), encoding='latin-1').read() for r, _, fs in os.walk(M) for f in fs if f.lower().endswith(('.ini', '.inc'))))
bad = 0
for o, (models, names) in sorted(ours.items()):
    if o not in base or names == base[o][1] or o not in merged or merged[o][1] == names: continue
    lost, gained = names - merged[o][1], merged[o][1] - names
    fail = bool(set(models) - set(merged[o][0])) or sum(lost.values()) * 4 >= sum(names.values())
    bad += fail
    print(f"  {'FAIL' if fail else 'ok  '} {o}: lost {sum(lost.values())} of the mod's {sum(names.values())} (e.g. {sorted(lost)[:3]}), gained {sum(gained.values())} (e.g. {sorted(gained)[:3]})")
print(f'draws: {bad} objects lost the mod\'s model or a quarter of its draw names'); sys.exit(1 if bad else 0)
