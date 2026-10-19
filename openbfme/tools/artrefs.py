import sys, os, re, subprocess, collections
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from iniblocks import entries
# usage: artrefs.py rotwk bfme2 modroot   (read-only): models/textures the author's INI changes name -> in base / in mod art / nowhere
rotwk, bfme2, mod = sys.argv[1:4]
base = set()
for inst in (rotwk, bfme2):
    for root, _, files in os.walk(inst):
        for n in files:
            if n.lower().endswith('.big'):
                for name, _, _ in entries(os.path.join(root, n)):
                    if name.startswith('art/'): base.add(os.path.splitext(os.path.basename(name))[0].lower())
modart = {os.path.splitext(f)[0].lower(): f for f in subprocess.run(['git', '-C', mod, 'ls-files', 'art'], capture_output=True, text=True).stdout.split() for f in [os.path.basename(f)]}
first = subprocess.run(['git', '-C', mod, 'rev-list', '--max-parents=0', 'HEAD'], capture_output=True, text=True).stdout.strip()
files = [f for f in subprocess.run(['git', '-C', mod, 'diff', '--name-only', first, 'HEAD', '--', 'data/ini'], capture_output=True, text=True).stdout.split() if f.endswith(('.ini', '.inc'))]
REF = re.compile(r'(?im)^\s*(Model|Texture|Texture1|ButtonImage|SelectPortrait|Animation|IdleAnimation|AnimationName)\s*=\s*([\w\.]+)')
refs = collections.defaultdict(set)
for f in files:
    p = os.path.join(mod, f)
    if not os.path.exists(p): continue
    for m in REF.finditer(open(p, encoding='latin-1').read()):
        kind, name = m.group(1).lower(), m.group(2)
        if kind in ('buttonimage', 'selectportrait'): continue  # mapped images, not files
        key = os.path.splitext(name.split('.')[0] if kind != 'texture' else name)[0].lower()
        if key in ('none', 'nil') or ('_' not in key and kind != 'texture'): continue  # FLYA, ATKA1: the INI's own animation aliases, not files
        refs[key].add(os.path.basename(f))
st = collections.Counter(); out = collections.defaultdict(list)
for k, fs in refs.items():
    s = 'both (mod replaces)' if k in base and k in modart else 'base only' if k in base else 'mod art only' if k in modart else 'NOWHERE'
    st[s] += 1; out[s].append((k, sorted(fs)))
print(dict(st))
for s in ('mod art only', 'both (mod replaces)', 'NOWHERE'):
    print(f"== {s}: {len(out[s])}")
    for k, fs in sorted(out[s])[:60]: print(f"   {k:28} <- {', '.join(fs)[:90]}")
