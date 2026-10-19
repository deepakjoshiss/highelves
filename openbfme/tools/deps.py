import sys, os, re, json
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from iniblocks import base_reader, entries
# usage: deps.py rotwk bfme2 rpol bpol modroot "Kind Name" ...   (read-only)
rotwk, bfme2, rpol, bpol, mod = sys.argv[1:6]; wanted = sys.argv[6:]
read = base_reader(rotwk, bfme2, rpol, bpol)
# every INI-ish file of the base, in load precedence (base_reader already resolves precedence per name)
names = set()
for inst, pol in ((rotwk, rpol), (bfme2, bpol)):
    for root, _, files in os.walk(inst):
        for n in files:
            if n.lower().endswith('.big'):
                for name, _, _ in entries(os.path.join(root, n)):
                    if name.endswith(('.ini', '.inc')): names.add(name)
TOP = re.compile(r'^(\w+)[ \t]+([\w\-\.]+)', re.M)
DEF = re.compile(r'^\s*#define\s+(\w+)\s*(.*)$', re.M | re.I)
def scan(text):
    defs, blocks = {}, set()
    for m in DEF.finditer(text): defs[m.group(1).upper()] = m.group(2)
    for m in TOP.finditer(text):
        if m.group(1).lower() not in ('end', 'endif'): blocks.add(m.group(2).lower())
    return defs, blocks
base_defs, base_blocks = {}, set()
for n in names:
    d, b = scan((read(n) or b'').decode('latin-1')); base_blocks |= b
    for k, v in d.items(): base_defs.setdefault(k, v)
mod_defs, mod_blocks, mod_text = {}, {}, {}
for root, _, files in os.walk(mod):
    if '.git' in root: continue
    for n in files:
        if n.lower().endswith(('.ini', '.inc')):
            t = open(os.path.join(root, n), 'rb').read().decode('latin-1'); rel = os.path.relpath(os.path.join(root, n), mod)
            d, _ = scan(t)
            for k, v in d.items(): mod_defs.setdefault(k, (v, rel))
            for m in re.finditer(r'^(\w+)[ \t]+([\w\-\.]+)[^\n]*\n(.*?)^End\b', t, re.M | re.S):
                mod_blocks.setdefault((m.group(1).lower(), m.group(2).lower()), (m.group(0), rel))
def body(kind, name): return mod_blocks.get((kind.lower(), name.lower()))
todo = [tuple(w.split(None, 1)) for w in wanted]; seen = set(); macros = {}; refs = {}
while todo:
    kind, name = todo.pop()
    if (kind.lower(), name.lower()) in seen: continue
    seen.add((kind.lower(), name.lower()))
    b = body(kind, name)
    if not b: refs[name] = 'NOT IN MOD'; continue
    text = re.sub(r'(;|//)[^\n]*', '', b[0])
    for tok in set(re.findall(r'\b[A-Z][A-Z0-9_]{3,}\b', text)):
        if tok in mod_defs or tok in base_defs:
            st = 'base' if tok in base_defs and (tok not in mod_defs or mod_defs[tok][0].split(';')[0].strip() == base_defs[tok].split(';')[0].strip()) else ('changed in mod' if tok in base_defs else 'mod only')
            macros[tok] = (st, mod_defs.get(tok, ('', ''))[1], (mod_defs.get(tok) or (base_defs.get(tok),))[0].split(';')[0].strip()[:40])
            for tok2 in re.findall(r'\b[A-Z][A-Z0-9_]{3,}\b', mod_defs.get(tok, ('',))[0]):
                if tok2 in mod_defs and tok2 not in macros: macros[tok2] = ('base' if tok2 in base_defs else 'mod only', mod_defs[tok2][1], mod_defs[tok2][0].split(';')[0].strip()[:40])
    for m in re.finditer(r'(?im)^\s*(\w*TemplateName|WarheadTemplateName|FireFX|ProjectileDetonationFX|FireOCL|ProjectileDetonationOCL)\s*=\s*(\w+)', text):
        n2 = m.group(2)
        if m.group(1).lower() == 'warheadtemplatename': todo.append(('Weapon', n2))
        refs[n2] = 'base' if n2.lower() in base_blocks else ('mod only' if any(k[1] == n2.lower() for k in mod_blocks) else 'MISSING')
    for n2 in set(re.findall(r'\bUpgrade_\w+', text)):
        refs[n2] = 'base' if n2.lower() in base_blocks else ('mod only' if ('upgrade', n2.lower()) in mod_blocks else 'MISSING')
print("== blocks pulled in:", sorted(f"{k} {n}" for k, n in seen))
print("== macros:")
for k, v in sorted(macros.items()): print(f"   {v[0]:15} {k:40} = {v[2]:40} ({v[1]})")
print("== names referenced:")
for k, v in sorted(refs.items(), key=lambda kv: kv[1]): print(f"   {v:10} {k}")
