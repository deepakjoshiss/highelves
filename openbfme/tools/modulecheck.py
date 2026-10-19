import sys, re, collections
cov = {}
for line in open(sys.argv[1]):
    m = re.match(r'\|\s*\d+\s*\|\s*(\w+)\s*\|\s*(\w+)\s*\|\s*\d+\s*\|\s*\d+\s*\|\s*([\w ]+?)\s*\|', line)
    if m: cov[m.group(1)] = m.group(3)
cov['DoCommandUpgrade'] = 'ported'
used = collections.defaultdict(set)
for f in sys.stdin.read().split():
    try: text = open(f, encoding='latin-1').read()
    except FileNotFoundError: continue
    for m in re.finditer(r'(?im)^\s*(Behavior|Draw|Body|ClientUpdate|ClientBehavior)\s*=\s*(\w+)', text):
        used[m.group(2)].add(f.split('/')[-1])
by = collections.defaultdict(list)
for cls, fs in used.items(): by[cov.get(cls, 'not in table')].append((cls, len(fs)))
for st in sorted(by, key=lambda s: (s != 'ported', s)):
    items = sorted(by[st], key=lambda x: -x[1])
    print(f"== {st}: {len(items)} classes")
    print("   " + ", ".join(f"{c} ({n})" for c, n in items))
