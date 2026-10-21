import os, re, subprocess, tempfile
# Line-level three-way merge of one block (git merge-file --diff3), each conflict spot then resolved:
#   both sides only added -> both (the mod's first); a side that changed only comments -> the other's; the same fields in the same order ->
#   per line, the side that changed it (the mod's where both did); else the mod's spot, marked REVIEW.
sig = lambda l: ' '.join(re.sub(r'(;|//).*', '', l).split())
key = lambda l: sig(l).split('=')[0].strip().lower()
norm = lambda t: '\n'.join(l.rstrip() for l in t.replace('\r\n', '\n').split('\n')).rstrip('\n') + '\n'
HUNK = re.compile(r'(?m)^<<<<<<< mod\n(.*?)^\|\|\|\|\|\|\| v8\.4\n(.*?)^=======\n(.*?)^>>>>>>> v9\.8\.0\n', re.S)  # whole marker lines

def resolve(m, b, t):
    M, B, T = (x.split('\n')[:-1] if x else [] for x in (m, b, t))
    sM, sB, sT = ([sig(l) for l in X if sig(l)] for X in (M, B, T))
    if not sB: return M + T, 'both added'
    if sM == sB: return T, "2.02's (yours changed only comments)"
    if sT == sB or sM == sT: return M, 'yours (2.02 changed only comments, or the same)'
    if len(sM) == len(sB) == len(sT) and [key(l) for l in sM] == [key(l) for l in sB] == [key(l) for l in sT]:
        out, i, mixed = [], 0, False
        T_ = [l for l in T if sig(l)]
        for l in M:
            if not sig(l): out.append(l); continue
            if sig(l) == sB[i] and sT[i] != sB[i]: out.append(T_[i]); mixed = True
            else: out.append(l)
            i += 1
        return out, 'per field' if mixed else 'yours (same fields)'
    return M, 'REVIEW: kept yours'

def merge3(base, ours, theirs, protect=None):
    # -> (text, spots); spots: [{how, mod, base, theirs}]. A base line naming one of `protect` (the mod's own names) is a first-commit edit, not
    # v8.4: it becomes a placeholder with the same field, so 2.02's version of that line meets the mod's as a conflict and the mod's wins
    d = tempfile.mkdtemp()
    if protect:
        base = '\n'.join(f"{key(l) or l} = __first_commit_edit__" if sig(l) and protect.search(sig(l)) else l for l in norm(base).split('\n'))
    for k, v in (('base', base), ('ours', ours), ('theirs', theirs)): open(os.path.join(d, k), 'w', encoding='latin-1').write(norm(v))
    p = subprocess.run(['git', 'merge-file', '-p', '--diff3', '-L', 'mod', '-L', 'v8.4', '-L', 'v9.8.0', *(os.path.join(d, k) for k in ('ours', 'base', 'theirs'))],
                       capture_output=True)
    spots = []
    def sub(mo):
        lines, how = resolve(*mo.groups())
        spots.append(dict(how=how, mod=mo.group(1), base=mo.group(2), theirs=mo.group(3)))
        return ''.join(l + '\n' for l in lines)
    text = HUNK.sub(sub, p.stdout.decode('latin-1'))
    assert not re.search(r'(?m)^(<<<<<<< mod|\|\|\|\|\|\|\| v8\.4|>>>>>>> v9\.8\.0)$', text), 'unresolved marker'  # the INI has <<<<<<<< comment rules
    return text, spots

# A Draw module's whole text, depth-aware: a line whose first word is a draw sub-block type opens a block, "End" closes one, and BeginScript ..
# EndScript is skipped (its Lua has its own "end"). -> [(first line, line after the module, module tag, text)]
DRAW_OPENERS = {'defaultconditionstate', 'conditionstate', 'modelconditionstate', 'defaultmodelconditionstate', 'animationstate', 'idleanimationstate',
                'transitionstate', 'animation'}
def draw_modules(text):
    code = lambda l: re.sub(r'(;|//).*', '', l).strip()
    word = lambda l: (re.split(r'[\s=]+', code(l)) or [''])[0].lower()
    lines = text.split('\n'); out = []; i = 0
    while i < len(lines):
        if not re.match(r'(?i)^Draw\s*=\s*\w+\s+\w+', code(lines[i])):
            i += 1; continue
        d, j = 1, i + 1
        while j < len(lines) and d:
            w = word(lines[j])
            if w == 'beginscript':
                while j + 1 < len(lines) and word(lines[j]) != 'endscript': j += 1
            elif w == 'end': d -= 1
            elif w in DRAW_OPENERS: d += 1
            j += 1
        out.append((i, j, code(lines[i]).split()[-1], '\n'.join(lines[i:j]))); i = j
    return out
