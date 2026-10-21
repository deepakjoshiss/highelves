import re, sys, os, subprocess, collections
# usage: checkheroes.py <mod repo> <merged ini dir> <v9.8.0 big> : fails when a hero waits for a level unlock its own experience levels
# never grant, unless plain v9.8.0 or the committed mod already had that gap (2.02's own, the mod's own: listed, not failed).
# A level unlock: Upgrade_ObjectLevelN, or any upgrade some ExperienceLevel grants (in the merged tree or the committed mod: the v8.4 per-hero
# ones). A hero is an Object / ChildObject with KindOf HERO; a ChildObject inherits its parent's modules, and its levels count for the parent.
H, M, BIG = sys.argv[1:4]
strip = lambda t: '\n'.join(re.sub(r'(;|//).*', '', l) for l in t.splitlines())
def texts_dir(root):
    return [strip(open(os.path.join(r, f), encoding='latin-1').read()) for r, _, fs in os.walk(root) for f in fs if f.lower().endswith(('.ini', '.inc'))]
def texts_head():
    names = subprocess.run(['git', '-C', H, 'ls-tree', '-r', '--name-only', 'HEAD', 'data/ini'], capture_output=True, text=True, check=True).stdout.split()
    return [strip(subprocess.run(['git', '-C', H, 'show', f'HEAD:{n}'], capture_output=True).stdout.decode('latin-1')) for n in names if n.lower().endswith(('.ini', '.inc'))]
def texts_big():
    import struct
    f = open(BIG, 'rb'); f.read(8); n = struct.unpack('>I', f.read(4))[0]; f.read(4); ents = []
    for _ in range(n):
        off, size = struct.unpack('>II', f.read(8)); name = b''
        while (c := f.read(1)) != b'\0': name += c
        ents.append((off, size, name.decode('latin-1').lower().replace('\\', '/')))
    out = []
    for off, size, nm in ents:
        if nm.startswith('data/ini/') and nm.endswith(('.ini', '.inc')): f.seek(off); out.append(strip(f.read(size).decode('latin-1')))
    return out
def grants(texts):
    g = collections.defaultdict(set)
    for t in texts:
        for m in re.finditer(r'(?ims)^ExperienceLevel\s+\w+(.*?)^End\b', t):
            tn = re.search(r'(?im)^\s*TargetNames\s*=\s*([^\n]*)', m.group(1))
            ups = {x.lower() for l in re.findall(r'(?im)^\s*Upgrades\s*=\s*([^\n]*)', m.group(1)) for x in l.split()}
            for h in (tn.group(1).split() if tn else []): g[h.lower()] |= ups
    return g
head = texts_head(); level_ups = {u for t in (texts_dir(M), head) for v in grants(t).values() for u in v}
def gaps(merged):
    g = grants(merged)
    objs, parent = {}, {}
    for t in merged:
        for m in re.finditer(r'(?ims)^(Object|ChildObject)\s+(\w+)(?:[ \t]+(\w+))?(.*?)^End\b', t):
            objs[m.group(2).lower()] = m.group(4)
            if m.group(1).lower() == 'childobject' and m.group(3): parent[m.group(2).lower()] = m.group(3).lower()
    children = collections.defaultdict(set)
    for c, p in parent.items(): children[p].add(c)
    def chain(o):
        while o: yield o; o = parent.get(o)
    def is_hero(o): return any(re.search(r'(?im)^\s*KindOf\s*=[^\n]*\bHERO\b', objs.get(x, '')) for x in chain(o))
    out = {}
    for o in sorted(objs):
        if not is_hero(o) or o in children: continue  # a parent is checked through its children (they are what gets built)
        waits = {x.lower() for b in chain(o) for l in re.findall(r'(?im)^\s*TriggeredBy\s*=\s*([^\n]*)', objs.get(b, '')) for x in l.split()}
        waits = {u for u in waits if u in level_ups or re.match(r'upgrade_objectlevel\d+$', u)}
        missing = {u for u in waits if u not in g.get(o, set())}
        if missing and g.get(o): out[o] = missing
    return out, sum(1 for o in objs if is_hero(o) and o not in children)
now, n = gaps(texts_dir(M)); before = gaps(head)[0]; v980 = gaps(texts_big())[0]
bad = 0
for o, miss in sorted(now.items()):
    new = miss - before.get(o, set()) - v980.get(o, set())
    if new: bad += 1
    print(f"  {'NEW ' if new else 'old '}{o}: waits for {sorted(miss)}, never granted by its levels" + ('' if new else ' (also in ' + ('v9.8.0' if o in v980 else 'the committed mod') + ')'))
print(f'heroes: {n} checked, {bad} with a new level unlock their levels never grant'); sys.exit(1 if bad else 0)
