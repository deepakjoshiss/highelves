import sys, os, re, struct
# usage: hebases.py <BFME2 Bases.big> <mod repo>   (reads the archive, writes <mod repo>/bases/)
# The High Elves castle layouts: 2.02's layout (BFME2's Bases.big; RotWK and 2.02 ship none of their own) named HE<layout>, every template it builds
# that has a High Elves copy named HE<template>. HEElvenFortress unpacks HEFortress_Elves (split.py's LAYOUTS), so a High Elves player's fortress
# builds HEElvenCitadel. Written uncompressed: the reader decompresses only a RefPack stream (openbfme-godot MapUtil.cpp); the objects list (the
# map editor's view) stays 2.02's, the castle builds from CastleTemplates (CastleBehavior RW 0x7987EE).
LAYOUTS = ['Fortress_Elves']
big, mod = sys.argv[1], os.path.abspath(sys.argv[2])

def refpack(d):
    # EA RefPack (QFS): header 0x10FB (flags in the first byte), 3- or 4-byte size
    flags = d[0]; assert d[1] == 0xFB, 'not refpack'
    i = 2; size_len = 4 if flags & 0x80 else 3
    if flags & 0x01: i += size_len
    i += size_len
    out = bytearray()
    while i < len(d):
        b0 = d[i]
        if b0 < 0x80:
            b1 = d[i + 1]; i += 2; n = b0 & 3; out += d[i:i + n]; i += n
            ln = ((b0 & 0x1C) >> 2) + 3; off = ((b0 & 0x60) << 3) + b1 + 1
        elif b0 < 0xC0:
            b1, b2 = d[i + 1], d[i + 2]; i += 3; n = b1 >> 6; out += d[i:i + n]; i += n
            ln = (b0 & 0x3F) + 4; off = ((b1 & 0x3F) << 8) + b2 + 1
        elif b0 < 0xE0:
            b1, b2, b3 = d[i + 1], d[i + 2], d[i + 3]; i += 4; n = b0 & 3; out += d[i:i + n]; i += n
            ln = ((b0 & 0x0C) << 6) + b3 + 5; off = ((b0 & 0x10) << 12) + (b1 << 8) + b2 + 1
        elif b0 < 0xFC:
            n = ((b0 & 0x1F) << 2) + 4; i += 1; out += d[i:i + n]; i += n; continue
        else:
            n = b0 & 3; i += 1; out += d[i:i + n]; i += n; break
        for _ in range(ln): out.append(out[-off])
    return bytes(out)

def big_file(path, want):
    with open(path, 'rb') as f:
        if f.read(4) not in (b'BIGF', b'BIG4'): raise SystemExit(f'{path}: not a BIG archive')
        f.read(4); n = struct.unpack('>I', f.read(4))[0]; f.read(4)
        for _ in range(n):
            o, s = struct.unpack('>II', f.read(8)); nm = b''
            while (c := f.read(1)) != b'\0': nm += c
            if nm.decode('latin-1').lower() == want.lower():
                f.seek(o); d = f.read(s)
                return refpack(d[8:]) if d[:4] == b'EAR\0' else d
    raise SystemExit(f'{path}: no {want}')

def chunks(d):
    # the name table {id: name} and its end, then the top-level chunks [(name, version, start of data, size)] to the end of the file
    if d[:4] != b'CkMp': raise SystemExit('not a chunk file')
    i = 8; table = {}
    for _ in range(struct.unpack('<i', d[4:8])[0]):
        l = d[i]; name = d[i + 1:i + 1 + l].decode('latin-1'); i += 1 + l; table[struct.unpack('<I', d[i:i + 4])[0]] = name; i += 4
    end, top = i, []
    while i < len(d):
        cid, ver, size = struct.unpack('<IHi', d[i:i + 10]); top.append((table[cid], ver, i + 10, size)); i += 10 + size
    if i != len(d): raise SystemExit('the chunks do not end with the file')
    return table, end, top

def castle_entries(body, ver):
    # CastleTemplates (openbfme-godot MapChunks.cpp parseCastleTemplates, RW 0x731010): name key, count, entries; returns (entries, end of the entries)
    i = 8; out = []
    for _ in range(struct.unpack('<i', body[4:8])[0]):
        names = []
        for _ in range(2):
            l = struct.unpack('<H', body[i:i + 2])[0]; names.append(body[i + 2:i + 2 + l].decode('latin-1')); i += 2 + l
        fixed = 16 + (8 if ver >= 4 else 0)
        out.append((names[0], names[1], body[i:i + fixed])); i += fixed
    return out, i

ascii_ = lambda s: struct.pack('<H', len(s)) + s.encode('latin-1')
copies = {m.group(1)[2:].lower(): m.group(1) for m in re.finditer(r'(?m)^(?:Object|ChildObject|ObjectReskin)\s+(HE\w+)',
          open(os.path.join(mod, 'data', 'ini', 'object', 'zz_highelves', 'highelves.ini'), encoding='latin-1').read())}
for layout in LAYOUTS:
    d = big_file(big, f'bases\\{layout}\\{layout}.bse')
    table, end, top = chunks(d)
    if list(table.values()).count(layout) != 1: raise SystemExit(f'{layout}: not once in the name table')
    head = b'CkMp' + d[4:8] + b''.join(struct.pack('B', len(n)) + n.encode('latin-1') + struct.pack('<I', k)
                                       for k, n in ((k, 'HE' + n if n == layout else n) for k, n in table.items()))
    if len(head) != end + 2: raise SystemExit('the name table does not rebuild')
    body, renamed = [], []
    ids = {n: k for k, n in table.items()}
    for name, ver, start, size in top:
        data = d[start:start + size]
        if name == 'CastleTemplates':
            entries, stop = castle_entries(data, ver)
            new = [(first, copies.get(tpl.lower(), tpl), rest) for first, tpl, rest in entries]
            renamed += [f'{a[1]} -> {b[1]}' for a, b in zip(entries, new) if a[1] != b[1]]
            data = data[:8] + b''.join(ascii_(f) + ascii_(t) + r for f, t, r in new) + data[stop:]
        body.append(struct.pack('<IHi', ids[name], ver, len(data)) + data)
    out = head + b''.join(body)
    # read back: the chunks end with the file, the layout is named HE<layout>, its entries are the renamed ones
    table2, _, top2 = chunks(out)
    ct = [c for c in top2 if c[0] == 'CastleTemplates']
    assert 'HE' + layout in table2.values() and len(ct) == 1
    got, _ = castle_entries(out[ct[0][2]:ct[0][2] + ct[0][3]], ct[0][1])
    assert [t for _, t, _ in got] == [copies.get(t.lower(), t) for _, t, _ in castle_entries(d[[c for c in top if c[0] == 'CastleTemplates'][0][2]:], ct[0][1])[0]]
    p = os.path.join(mod, 'bases', 'he' + layout.lower(), 'he' + layout.lower() + '.bse')
    os.makedirs(os.path.dirname(p), exist_ok=True)
    open(p, 'wb').write(out)
    print(f'{os.path.relpath(p, mod)}: {len(out)} bytes, {len(got)} entries, renamed: {renamed or "-"}')
