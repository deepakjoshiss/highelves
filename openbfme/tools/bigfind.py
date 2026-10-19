import struct, sys, os, re
# usage: bigfind.py <big> <name-regex> [content-regex]   (read-only)
def entries(path):
    with open(path, 'rb') as f:
        magic = f.read(4)
        if magic not in (b'BIGF', b'BIG4'): return
        f.read(4); count, _ = struct.unpack('>II', f.read(8))
        for _ in range(count):
            off, size = struct.unpack('>II', f.read(8))
            name = b''
            while (c := f.read(1)) != b'\0': name += c
            yield name.decode('latin-1'), off, size
big, namerx = sys.argv[1], re.compile(sys.argv[2], re.I)
contentrx = re.compile(sys.argv[3].encode(), re.I) if len(sys.argv) > 3 else None
with open(big, 'rb') as f:
    for name, off, size in entries(big):
        if not namerx.search(name): continue
        if contentrx is None:
            print(name, size); continue
        f.seek(off); data = f.read(size)
        if contentrx.search(data): print(name, size)
