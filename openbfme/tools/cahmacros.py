import sys, os, re, json
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from iniblocks import base_reader, entries
# usage: cahmacros.py rotwk bfme2 rpol bpol mod  -> changed CAH macros and the base blocks that use them (json to stdout summary)
rotwk, bfme2, rpol, bpol, mod = sys.argv[1:6]
read = base_reader(rotwk, bfme2, rpol, bpol)
DEF = re.compile(r'^\s*#define\s+(\w+)\s+([^\r\n;]*)', re.M | re.I)
def defs(t): return {m.group(1).upper(): m.group(2).strip() for m in DEF.finditer(t)}
base_g = defs((read('data/ini/createaherogamedata.inc') or b'').decode('latin-1'))
mod_g = defs(open(os.path.join(mod, 'data/ini/createaherogamedata.inc'), 'rb').read().decode('latin-1'))
changed = {k: v for k, v in mod_g.items() if base_g.get(k, None) != v}
print("changed or new macros:", len(changed))
for k, v in sorted(changed.items()): print(f"   {k:45} {base_g.get(k, '(new)')[:30]:>30} -> {v[:40]}")
names = set()
for inst in (rotwk, bfme2):
    for root, _, files in os.walk(inst):
        for n in files:
            if n.lower().endswith('.big'):
                for name, _, _ in entries(os.path.join(root, n)):
                    if name.endswith(('.ini', '.inc')) and name.startswith('data/ini/'): names.add(name)
pat = re.compile(r'\b(' + '|'.join(sorted(changed, key=len, reverse=True)) + r')\b')
users = {}
for n in sorted(names):
    if n.endswith('createaherogamedata.inc'): continue
    t = (read(n) or b'').decode('latin-1')
    t2 = re.sub(r'(;|//)[^\n]*', '', t)
    for m in re.finditer(r'^(\w+)[ \t]+([\w\-\.]+)[^\n]*\n(.*?)^End\b', t2, re.M | re.S):
        used = set(pat.findall(m.group(0)))
        if used: users[f"{m.group(1)} {m.group(2)}"] = (n, sorted(used))
    if pat.search(t2) and n.endswith('.inc'):
        if not any(v[0] == n for v in users.values()): users[f"(fragment) {n}"] = (n, sorted(set(pat.findall(t2))))
print("base blocks using them:", len(users))
for k, (f, u) in sorted(users.items(), key=lambda kv: kv[1][0]): print(f"   {k:60} {f.split('/')[-1]:32} {', '.join(u)[:80]}")
json.dump({'changed': changed, 'users': users}, open(os.path.join(os.path.dirname(os.path.dirname(os.path.abspath(__file__))), 'cahmacros.json'), 'w'))
