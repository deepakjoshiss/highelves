import sys, os
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from iniblocks import blocks, base_reader
# usage: blockdiff.py rotwk bfme2 rpol bpol modroot rel... : changed blocks with their removed/added lines
read = base_reader(*sys.argv[1:5]); mod = sys.argv[5]
for rel in sys.argv[6:]:
    base = blocks(read(rel) or b''); mine = blocks(open(os.path.join(mod, rel), 'rb').read())
    lb = {k.lower(): k for k in base}
    print(f"######## {rel}")
    for k in mine:
        b = lb.get(k.lower())
        if b is None: print(f"  NEW {k}"); continue
        if mine[k] == base[b]: continue
        ml, bl = mine[k].split('\n'), base[b].split('\n')
        print(f"  CHANGED {k}")
        for l in bl:
            if l not in ml: print(f"      - {l[:110]}")
        for l in ml:
            if l not in bl: print(f"      + {l[:110]}")
    for k in base:
        if k.lower() not in {m.lower() for m in mine}: print(f"  REMOVED {k}")
