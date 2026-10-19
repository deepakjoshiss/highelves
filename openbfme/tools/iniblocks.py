import re, struct, json, sys, os
# block-level diff of the mod's modified/new INI-type files against the base versions (read-only)
SCR = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
def entries(path):
    with open(path, 'rb') as f:
        f.read(8); count, _ = struct.unpack('>II', f.read(8))
        for _ in range(count):
            off, size = struct.unpack('>II', f.read(8))
            name = b''
            while (c := f.read(1)) != b'\0': name += c
            yield name.decode('latin-1').replace('\\', '/').lower(), off, size
def base_reader(rotwk, bfme2, rpol, bpol):
    index = {}
    for inst, pol in ((rotwk, rpol), (bfme2, bpol)):
        ondisk = {}
        for root, _, files in os.walk(inst):
            for n in files:
                if n.lower().endswith('.big'): ondisk[os.path.relpath(os.path.join(root, n), inst).replace('\\', '/').lower()] = os.path.join(root, n)
        for p in sorted([a['path'].replace('\\', '/') for a in json.load(open(pol))['archives']], reverse=True):
            big = ondisk.get(p.lower())
            if big:
                for name, off, size in entries(big): index.setdefault(name, (big, off, size))
    def read(name):
        if name not in index: return None
        big, off, size = index[name]
        with open(big, 'rb') as f: f.seek(off); return f.read(size)
    return read
def strip(line):
    line = re.sub(r'(;|//).*', '', line)
    return ' '.join(line.split())
def blocks(text):
    out, cur, key = {}, [], None
    for raw in text.decode('latin-1').splitlines():
        s = strip(raw)
        if not s: continue
        if key is None:
            if s.lower().startswith('#define'):
                parts = s.split(None, 2); out['#define ' + (parts[1] if len(parts) > 1 else '')] = s.lower(); continue
            if s.lower().startswith('#include'):
                out['#include ' + s.split(None, 1)[1].strip('"').lower()] = s.lower(); continue
            if raw[:1].isspace() or s.lower() == 'end': continue
            key = s if len(s.split()) <= 3 else ' '.join(s.split()[:2]); cur = [s.lower()]
            continue
        cur.append(s.lower())
        if s.lower() == 'end' and not raw[:1].isspace():
            k = key; n = 2
            while k in out: k = f"{key} #{n}"; n += 1
            out[k] = '\n'.join(cur); key = None
    if key: out[key] = '\n'.join(cur)
    return out
if __name__ == '__main__':
    comp = json.load(open(os.path.join(SCR, 'modcompare.json')))
    read = base_reader(*sys.argv[1:5]); mod = sys.argv[5]
    report = {}
    exts = ('.ini', '.inc')
    for kind in ('modified', 'new'):
        for x in comp[kind]:
            rel = x[0] if isinstance(x, list) else x
            if not rel.endswith(exts): continue
            mine = blocks(open(os.path.join(mod, rel), 'rb').read()) if os.path.exists(os.path.join(mod, rel)) else None
            if mine is None:
                for root, _, files in os.walk(mod):
                    for n in files:
                        if os.path.relpath(os.path.join(root, n), mod).replace('\\', '/').lower() == rel: mine = blocks(open(os.path.join(root, n), 'rb').read())
            base = blocks(read(rel)) if kind == 'modified' else {}
            lk = {k.lower(): k for k in base}
            added = [k for k in mine if k.lower() not in lk]
            removed = [k for k in base if k.lower() not in {m.lower() for m in mine}]
            changed = []
            for k in mine:
                b = lk.get(k.lower())
                if b and mine[k] != base[b]:
                    ml, bl = mine[k].split('\n'), base[b].split('\n')
                    changed.append([k, len(set(ml) ^ set(bl))])
            report[rel] = {'kind': kind, 'added': added, 'removed': removed, 'changed': changed}
    json.dump(report, open(os.path.join(SCR, 'iniblocks.json'), 'w'), indent=0)
    tot = {'added': 0, 'removed': 0, 'changed': 0}
    for r in report.values():
        for k in tot: tot[k] += len(r[k])
    print(len(report), 'files;', tot)
