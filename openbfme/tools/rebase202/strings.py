import sys, struct
# usage: strings.py <lang patch big> <mod strings> <out lotr.str> : the mod's data/lotr.str, generated (2026-10-23): 2.02 v9.8.0's data\lotr.str
# (englishpatch202.big) whole, with the mod's own labels (modstrings.str, the only place to edit them) in place of 2.02's text, and the labels 2.02
# lacks after it. Labels and END are case-blind, as the game reads them (ZH GameText: stricmp; 2.02 ends entries with END, End and ENd).
def big_file(path, name):
    f = open(path, 'rb'); f.read(8); count = struct.unpack('>I', f.read(4))[0]; f.read(4)
    for _ in range(count):
        off, size = struct.unpack('>II', f.read(8)); n = b''
        while (c := f.read(1)) != b'\0': n += c
        if n.decode('latin-1').lower() == name: f.seek(off); return f.read(size)
    raise SystemExit(f'{name} is not in {path}')
def entries(lines):
    # (label, label line, END line); blank and // lines between entries are kept as they are
    out, i = [], 0
    while i < len(lines):
        s = lines[i].strip()
        if not s or s.startswith('//'): i += 1; continue
        j = i + 1
        while j < len(lines) and lines[j].strip().upper() != 'END': j += 1
        if j == len(lines): raise SystemExit(f'line {i + 1} {s!r}: no END')
        out.append((s.split()[0].lower(), i, j)); i = j + 1
    return out
if __name__ == '__main__':
    base = big_file(sys.argv[1], 'data\\lotr.str').decode('utf-8').split('\n')  # 2.02's file: UTF-8, LF
    mod = open(sys.argv[2], encoding='utf-8').read().replace('\r\n', '\n').split('\n')
    mine = {k: mod[i:j + 1] for k, i, j in entries(mod)}
    out, at, replaced = [], 0, set()
    for k, i, j in entries(base):
        if k in mine:
            assert k not in replaced, f'{k}: twice in 2.02'
            out += base[at:i] + mine[k]; at = j + 1; replaced.add(k)
    out += base[at:]
    added = [k for k in mine if k not in replaced]
    if added: out += ['', '// The High Elves mod: its labels 2.02 lacks (openbfme/tools/rebase202/modstrings.str)'] + sum((mine[k] for k in added), [])
    text = '\n'.join(out)
    if not text.endswith('\n'): text += '\n'
    got = {k for k, _, _ in entries(text.split('\n'))}
    lost = {k for k, _, _ in entries(base)} - got
    assert not lost and set(mine) <= got, (sorted(lost)[:5], sorted(set(mine) - got)[:5])
    open(sys.argv[3], 'w', encoding='utf-8', newline='').write(text)
    print(f'strings: 2.02 {len(entries(base))} labels, the mod {len(mine)} ({len(replaced)} in place of 2.02\'s text, {len(added)} added)')
