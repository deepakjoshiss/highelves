import struct, sys, os, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from iniblocks import entries
# usage: w3dchannels.py <anim.w3d> <mod art dir> <rotwk> <bfme2>   (read-only)
KIND = {0: 'X position', 1: 'Y position', 2: 'Z position', 3: 'X rotation', 4: 'Y rotation', 5: 'Z rotation', 6: 'rotation (quaternion)'}
def chunks(data, off, end):
    while off + 8 <= end:
        t, s = struct.unpack_from('<II', data, off); size = s & 0x7FFFFFFF
        yield t, off + 8, size, bool(s & 0x80000000); off += 8 + size
def find_skeleton(name, modart, rotwk, bfme2):
    fn = name.lower() + '.w3d'
    for root, _, files in os.walk(modart):
        for f in files:
            if f.lower() == fn: return open(os.path.join(root, f), 'rb').read(), 'mod art'
    for inst in (rotwk, bfme2):
        for root, _, files in os.walk(inst):
            for n in files:
                if n.lower().endswith('.big'):
                    p = os.path.join(root, n)
                    for e, o, s in entries(p):
                        if e.endswith('/' + fn):
                            with open(p, 'rb') as f: f.seek(o); return f.read(s), os.path.basename(p)
    return None, None
def bones(data):
    out = {}
    for t, o, s, _ in chunks(data, 0, len(data)):
        if t == 0x100:
            for t2, o2, s2, _ in chunks(data, o, o + s):
                if t2 == 0x102:
                    n = s2 // 60
                    for i in range(n): out[i] = data[o2 + 60*i:o2 + 60*i + 16].split(b'\0')[0].decode('latin-1')
    return out
path, modart, rotwk, bfme2 = sys.argv[1:5]
data = open(path, 'rb').read()
for t, o, s, _ in chunks(data, 0, len(data)):
    if t not in (0x200, 0x280): continue
    hdr = None; seen = collections.defaultdict(list)
    for t2, o2, s2, _ in chunks(data, o, o + s):
        if t2 in (0x201, 0x281): hdr = data[o2:o2+s2]
        if t2 in (0x282, 0x284):
            pivot, vlen, flags = struct.unpack_from('<HBB', data, o2 + 4); seen[(pivot, flags)].append(data[o2+8:o2+s2])
        if t2 == 0x202:
            vlen, flags, pivot = struct.unpack_from('<HHH', data, o2 + 4); seen[(pivot, flags)].append(data[o2+12:o2+s2])
    name = hdr[4:20].split(b'\0')[0].decode() if hdr else '?'; hier = hdr[20:36].split(b'\0')[0].decode() if hdr else '?'
    skel, where = find_skeleton(hier, modart, rotwk, bfme2); names = bones(skel) if skel else {}
    print(f"{os.path.basename(path)}: animation {name} of skeleton {hier} ({'skeleton from ' + where if where else 'skeleton not found'}), {sum(len(v) for v in seen.values())} channels")
    for (pivot, flags), copies in sorted(seen.items()):
        if len(copies) > 1:
            same = all(c == copies[0] for c in copies[1:])
            print(f"   bone {pivot} '{names.get(pivot, '?')}', {KIND.get(flags, flags)}: {len(copies)} copies, {'byte-identical' if same else 'DIFFERENT data'} ({', '.join(str(len(c)) + ' bytes' for c in copies)})")
