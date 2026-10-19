import struct, sys, os, json, hashlib
# usage: modcompare.py <rotwk dir> <bfme2 dir> <mod dir> <out json> <rotwk table> <bfme2 table>   (read-only; the tables: engine/data/retail-archives/*.json)
def entries(path):
    with open(path, 'rb') as f:
        if f.read(4) not in (b'BIGF', b'BIG4'): return
        f.read(4); count, _ = struct.unpack('>II', f.read(8))
        for _ in range(count):
            off, size = struct.unpack('>II', f.read(8))
            name = b''
            while (c := f.read(1)) != b'\0': name += c
            yield name.decode('latin-1').replace('\\', '/').lower(), off, size
def install_bigs(d, policy):
    # the engine's pinned table gives each archive's retail-case path; retail order: strcmp ascending on that path, then reversed
    ondisk = {}
    for root, _, files in os.walk(d):
        for n in files:
            if n.lower().endswith('.big'): ondisk[os.path.relpath(os.path.join(root, n), d).replace('\\', '/').lower()] = os.path.join(root, n)
    paths = [a['path'].replace('\\', '/') for a in json.load(open(policy))['archives']]
    return [ondisk[p.lower()] for p in sorted(paths, reverse=True) if p.lower() in ondisk]
rotwk, bfme2, mod, outp, rpol, bpol = sys.argv[1:7]
index = {}
for inst, pol in ((rotwk, rpol), (bfme2, bpol)):
    for big in install_bigs(inst, pol):
        for name, off, size in entries(big):
            index.setdefault(name, (big, off, size))
def base_bytes(name):
    big, off, size = index[name]
    with open(big, 'rb') as f:
        f.seek(off); return f.read(size)
result = {'identical': [], 'modified': [], 'new': []}
for root, _, files in os.walk(mod):
    if '/.git' in root: continue
    for n in files:
        p = os.path.join(root, n); rel = os.path.relpath(p, mod).replace('\\', '/').lower()
        if not (rel.startswith('data/') or rel.startswith('art/') or rel.startswith('maps/')): continue
        if rel not in index: result['new'].append(rel); continue
        mine = open(p, 'rb').read()
        base = base_bytes(rel)
        same = mine == base or mine.replace(b'\r\n', b'\n').strip() == base.replace(b'\r\n', b'\n').strip()
        result['identical' if same else 'modified'].append((rel, os.path.basename(index[rel][0])))
json.dump(result, open(outp, 'w'), indent=0)
for k in result: print(k, len(result[k]))
