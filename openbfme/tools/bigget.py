import struct, sys
# usage: bigget.py <big> <exact name> <out file>   (read-only extract)
big, want, out = sys.argv[1], sys.argv[2].lower(), sys.argv[3]
with open(big, 'rb') as f:
    f.read(8); count, _ = struct.unpack('>II', f.read(8))
    for _ in range(count):
        off, size = struct.unpack('>II', f.read(8))
        name = b''
        while (c := f.read(1)) != b'\0': name += c
        if name.decode('latin-1').lower() == want:
            pos = f.tell(); f.seek(off); data = f.read(size); f.seek(pos)
            open(out, 'wb').write(data); print('wrote', out, size); break
