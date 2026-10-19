import sys, os, re, subprocess, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from iniblocks import entries
rotwk, bfme2, mod = sys.argv[1:4]
base = set()
for inst in (rotwk, bfme2):
    for root, _, files in os.walk(inst):
        for n in files:
            if n.lower().endswith('.big'):
                for name, _, _ in entries(os.path.join(root, n)):
                    if name.startswith('art/'): base.add(os.path.splitext(os.path.basename(name))[0].lower())
modart = {os.path.splitext(os.path.basename(f))[0].lower() for f in subprocess.run(['git', '-C', mod, 'ls-files', 'art'], capture_output=True, text=True).stdout.split()}
ASSET = re.compile(r'^[a-z]{2}[a-z0-9]{2,}_[a-z0-9]+$')
REF = re.compile(r'(?im)^\s*(Model|Animation)\s*=\s*([\w\.]+)')
for f in sys.argv[4:]:
    p = os.path.join(mod, f); c = collections.Counter(); missing = set()
    for m in REF.finditer(open(p, encoding='latin-1').read()):
        k = m.group(2).split('.')[0].lower()
        if not ASSET.match(k) or k.endswith(('_reallydamaged', '_rubble', '_damaged')): continue
        s = 'mod' if k in modart and k not in base else 'mod+base' if k in modart else 'base' if k in base else 'none'
        c[s] += 1
        if s == 'none': missing.add(k)
    print(f"{os.path.basename(f):32} mod-only {c['mod']:3}  mod-replaces {c['mod+base']:3}  base {c['base']:3}  in neither {c['none']:3}  {' '.join(sorted(missing)[:6])}")
