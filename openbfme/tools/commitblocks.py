import subprocess, sys, os, json
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from iniblocks import blocks
repo = sys.argv[1]
def git(*a): return subprocess.run(['git', '-C', repo, *a], capture_output=True).stdout
commits = git('log', '--reverse', '--format=%H %ad %s', '--date=short').decode().splitlines()[1:]
out = []
for line in commits:
    h, date, subj = line.split(' ', 2)
    files = [f for f in git('diff', '--name-only', h + '^', h).decode().splitlines()]
    ini = [f for f in files if f.lower().endswith(('.ini', '.inc', '.str'))]
    art = [f for f in files if not f.lower().endswith(('.ini', '.inc', '.str'))]
    feat = {'commit': h[:8], 'date': date, 'subject': subj, 'art': len(art), 'art_sample': [os.path.basename(a) for a in art][:6], 'ini': {}}
    for f in ini:
        if f.lower().endswith('.str'): feat['ini'][f] = 'string table'; continue
        old = git('show', f'{h}^:{f}'); new = git('show', f'{h}:{f}')
        ob, nb = blocks(old), blocks(new)
        ol = {k.lower(): k for k in ob}; nl = {k.lower() for k in nb}
        added = [k for k in nb if k.lower() not in ol]
        removed = [k for k in ob if k.lower() not in nl]
        changed = [k for k in nb if k.lower() in ol and nb[k] != ob[ol[k.lower()]]]
        feat['ini'][f] = {'added': added, 'removed': removed, 'changed': changed}
    out.append(feat)
json.dump(out, open(sys.argv[2], 'w'), indent=1)
for f in out:
    a = sum(len(v['added']) for v in f['ini'].values() if isinstance(v, dict))
    c = sum(len(v['changed']) for v in f['ini'].values() if isinstance(v, dict))
    r = sum(len(v['removed']) for v in f['ini'].values() if isinstance(v, dict))
    print(f"{f['date']} {f['subject'][:48]:48} ini files {len(f['ini']):3}  +{a:<4} ~{c:<4} -{r:<4} art {f['art']}")
