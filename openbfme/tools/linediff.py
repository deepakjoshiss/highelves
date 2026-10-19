import sys, os, difflib, re
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from iniblocks import base_reader
read = base_reader(*sys.argv[1:5]); mod = sys.argv[5]
def norm(b):
    out = []
    for l in b.decode('latin-1').splitlines():
        l = ' '.join(re.sub(r'(;|//).*', '', l).split())
        if l: out.append(l)
    return out
for rel in sys.argv[6:]:
    a, b = norm(read(rel) or b''), norm(open(os.path.join(mod, rel), 'rb').read())
    d = [l for l in difflib.unified_diff(a, b, lineterm='', n=0) if not l.startswith(('---', '+++'))]
    print(f"######## {rel}: {sum(1 for l in d if l.startswith('-'))} lines removed, {sum(1 for l in d if l.startswith('+'))} added")
    for l in d[:int(os.environ.get('MAXL', '60'))]: print('   ', l[:130])
