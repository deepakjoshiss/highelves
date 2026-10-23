import sys, os, re, subprocess, collections
# usage: relay.py <mod repo>                      : rewrites data/ini so every line the mod does not really change is 2.02's (branch vanilla)
#        relay.py <mod repo> --check <old ini dir> : exits 1 when data/ini means anything else than <old ini dir> (blocks, top-level #includes, files)
# One-time (2026-10-23), before master records vanilla as merged: the mod's files kept an older 2.02's comments and layout, which a git merge of
# the next 2.02 would meet as edits. Per file both have: vanilla's segments in vanilla's order; a block the mod did not change keeps vanilla's
# text, a changed one takes the mod's; a block or top-level #include only the mod has follows the nearest earlier block both have; the mod's
# comment lines go; a vanilla block the mod moved to another file stays there and leaves the vanilla file (moving it back broke the load order:
# sciences named before their definition, a ChildObject before its parent); a module fragment file keeps the mod's text whole.
T = os.path.dirname(os.path.abspath(__file__)); sys.path.insert(0, os.path.dirname(T)); from iniblocks import strip
src = open(os.path.join(T, 'merge.py')).read(); M = {'re': re, 'collections': collections, 'strip': strip}
exec(src[src.index('ELVEN ='):src.index('def rev_tree')], M)  # merge.py's parse / Tree (merge.py runs the merge on import)
Tree = M['Tree']
INI = ('.ini', '.inc')

def tree_of(root):
    out = {}
    for d, _, fs in os.walk(root):
        for x in fs:
            if x.lower().endswith(INI): p = os.path.join(d, x); out[os.path.relpath(p, root)] = open(p, 'rb').read()
    return out
def meaning(files):
    # every block's normalized text by its key (a nameless repeat's key without the first-field suffix the Tree adds), the top-level #includes per file
    t = Tree(files); blocks = collections.Counter(); incs = {}
    for rel, segs in t.segs.items():
        # every top-level line that is not a comment: the #includes, and the lines the block reader could not place (a fragment file's module body)
        incs[rel] = collections.Counter(strip(s[1]).lower() for s in segs if s[0] == 'raw' and strip(s[1]))
        for s in segs:
            if s[0] == 'block': blocks[(s[1].split(' | ')[0], s[2])] += 1
    return blocks, incs

repo = sys.argv[1]; ini = os.path.join(repo, 'data', 'ini')
if len(sys.argv) > 2:
    assert sys.argv[2] == '--check', sys.argv[2]
    old, new = tree_of(sys.argv[3]), tree_of(ini)
    if {k.lower() for k in old} != {k.lower() for k in new}: raise SystemExit(f'files differ: {sorted({k.lower() for k in old} ^ {k.lower() for k in new})[:10]}')
    (ob, oi), (nb, ni) = meaning(old), meaning(new)
    # a #define repeated with the same value means nothing more (2.02 itself defines INFINITE_CLIP_SIZE 0 in weapon.ini and mod/weapon.inc)
    once = lambda c: collections.Counter({k: 1 if k[0].startswith('#define') else n for k, n in c.items()})
    ob, nb = once(ob), once(nb)
    keys = {k for k, _ in (ob - nb) + (nb - ob)}
    inc = [r for r in set(oi) | set(ni) if oi.get(r) != ni.get(r)]
    print(f'{len(keys)} keys differ, {len(inc)} include lists differ', sorted(keys)[:10], sorted(inc)[:10])
    sys.exit(1 if keys or inc else 0)

git = lambda *a: subprocess.run(['git', '-C', repo, *a], capture_output=True, check=True).stdout
mine = tree_of(ini)
van = {p[len('data/ini/'):]: git('show', f'vanilla:{p}') for p in git('ls-tree', '-r', '--name-only', 'vanilla', 'data/ini').decode().split('\n') if p.lower().endswith(INI)}
both = sorted(r for r in mine if r in van)
V = {r: Tree({r: van[r]}).segs[r.lower()] for r in both}
O = Tree(mine); Oseg = O.segs  # whole tree: a moved block is found by name
# pass 1: the master block each vanilla block takes (its own file's block of the same key and occurrence, else the one block of that key that
# no vanilla file takes in place)
local = {}  # (rel, key, n) of a vanilla block -> master bid
for r in both:
    for s in V[r]:
        if s[0] == 'block':
            bid = (r.lower(), s[1], s[4][2])
            if bid in O.blocks: local[(r, s[1], s[4][2])] = bid
taken_in_place = set(local.values())
claim, moved, stats = dict(local), set(), collections.Counter()
for r in both:
    for s in V[r]:
        if s[0] != 'block' or (r, s[1], s[4][2]) in claim: continue
        c = [b for b in O.byname.get(s[1], []) if b not in taken_in_place]
        # moved by the mod (into its mod/*.inc): it stays where the mod put it, so the load order the mod runs with is kept; the 2.02 file loses it
        if c: moved.add((r, s[1], s[4][2])); stats['moved by the mod: left out here'] += 1
        else: stats['vanilla block the mod lacks: kept 2.02'] += 1
claimed = set(claim.values())
# a file the block reader cannot place line by line (a module fragment file: loose lines between its blocks) keeps the mod's text whole
loose = lambda segs: any(s[0] == 'raw' and strip(s[1]) and not strip(s[1]).lower().startswith('#include') for s in segs)
whole = {r for r in both if loose(V[r]) or loose(Oseg[r.lower()])}
stats['fragment files kept as the mod has them'] = len(whole)
# pass 2: write
out_files = {}
for r in both:
    if r in whole: continue
    out, anchor_at, extra = [], {}, collections.defaultdict(list)
    vincs = {strip(s[1]).lower() for s in V[r] if s[0] == 'raw' and strip(s[1])}
    anchor = None
    for s in Oseg[r.lower()]:  # the mod's own blocks and lines, anchored to the nearest earlier block both have
        if s[0] == 'block':
            if s[4] in claimed: anchor = s[4]
            else: extra[anchor].append(s[3]); stats['mod block kept after its neighbour'] += 1
        elif strip(s[1]) and strip(s[1]).lower() not in vincs:
            extra[anchor].append(s[1]); stats['mod line kept (#include or other)'] += 1
    def flush(key):
        for t in extra.pop(key, []):
            if out and not out[-1].endswith('\n'): out.append('\n')
            out.append(t if t.endswith('\n') else t + '\n')
    started = False
    for s in V[r]:
        if s[0] == 'raw': out.append(s[1]); continue
        if not started: flush(None); started = True
        if (r, s[1], s[4][2]) in moved: continue
        b = claim.get((r, s[1], s[4][2]))
        if b is None: out.append(s[3])
        else:
            ob = O.blocks[b]
            out.append(s[3] if ob[2] == s[2] else ob[3]); stats['vanilla text' if ob[2] == s[2] else 'mod text'] += 1
            flush(b)
    if not started: flush(None)
    for k in list(extra): flush(k)  # anchors that moved away with their block
    out_files[r] = ''.join(out)
for r, text in out_files.items():
    open(os.path.join(ini, r), 'w', encoding='latin-1', newline='').write(text)
print(f'{len(out_files)} files written;', dict(stats))
