import os, struct, subprocess, sys, tempfile
# usage: vanilla202.py <patch big> <lang big> <label>   (from the mod repo's root)
# Commits 2.02's data/ini/** (__patch202.big) and data/lotr.str (englishpatch202.big) to the branch `vanilla` and tags it vanilla-<label>;
# master and the work tree stay untouched (a temporary index and work tree). CRLF becomes LF, nothing else changes. A path keeps the spelling
# master already tracks (case-blind), else lower case, so the two branches name the same files. A 2.02 update: this, then `git merge vanilla`.
def entries(path):
    try:
        f = open(path, 'rb')
    except OSError as e:
        raise SystemExit(f'{path}: {e.strerror}')
    with f:
        if f.read(4) != b'BIGF':
            raise SystemExit(f'{path}: not a BIG archive')
        f.read(4); count, _ = struct.unpack('>II', f.read(8)); index = []
        for _ in range(count):
            off, size = struct.unpack('>II', f.read(8)); name = b''
            while (c := f.read(1)) != b'\0': name += c
            index.append((off, size, name.decode('latin-1')))
        out = {}
        for off, size, name in index:
            f.seek(off); out[name] = f.read(size)
    return out
def git(*a, **kw):
    return subprocess.run(['git', *a], capture_output=True, check=True, **kw).stdout.decode().strip()

patch, lang, label = sys.argv[1:4]
tag = f'vanilla-{label}'
if subprocess.run(['git', 'rev-parse', '-q', '--verify', f'refs/tags/{tag}'], capture_output=True).returncode == 0:
    raise SystemExit(f'tag {tag} exists')
files = {n.replace('\\', '/'): b for n, b in entries(patch).items() if n.lower().startswith('data\\ini\\')}
lotr = [b for n, b in entries(lang).items() if n.lower() == 'data\\lotr.str']
if not files or len(lotr) != 1:
    raise SystemExit(f'{patch}: {len(files)} data\\ini files, {lang}: {len(lotr)} data\\lotr.str')
files['data/lotr.str'] = lotr[0]
tracked = {p.lower(): p for p in git('ls-files', 'data').split('\n') if p}
repo = os.path.abspath(git('rev-parse', '--git-dir'))
with tempfile.TemporaryDirectory() as tmp:
    for name, data in files.items():
        p = os.path.join(tmp, tracked.get(name.lower(), name.lower()))
        os.makedirs(os.path.dirname(p), exist_ok=True)
        open(p, 'wb').write(data.replace(b'\r\n', b'\n'))
    env = dict(os.environ, GIT_INDEX_FILE=os.path.join(tmp, '.index'))
    git('-C', tmp, f'--git-dir={repo}', f'--work-tree={tmp}', 'add', '-A', '--', 'data', env=env)
    tree = git('-C', tmp, f'--git-dir={repo}', 'write-tree', env=env)
parent = subprocess.run(['git', 'rev-parse', '-q', '--verify', 'refs/heads/vanilla'], capture_output=True, text=True).stdout.strip()
commit = git('commit-tree', tree, *(['-p', parent] if parent else []), '-m', f'2.02 {label}: data/ini and data/lotr.str as extracted (CRLF to LF)')
git('update-ref', 'refs/heads/vanilla', commit, *([parent] if parent else ['']))
git('tag', tag, commit)
print(f'vanilla {commit[:7]} ({tag}): {len(files)} files')
