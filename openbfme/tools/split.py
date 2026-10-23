import sys, os, re, subprocess, collections, difflib
# usage: split.py <mod repo>                         : moves every elven change of the mod into the faction FactionHighElves (one-time, 2026-10-23)
#        split.py <mod repo> --check <pre-split ini>  : the plan's four checks (openbfme-godot docs/superpowers/plans/2026-10-23-highelves-faction.md)
# The vanilla side becomes vanilla's text plus the fixes kept on master, one hook (ElvenBuildingFoundation), the High Elves names added to the
# levels they share, the faction block and the #include lines of the High Elves files. High Elves objects are ChildObjects of the vanilla ones
# carrying the mod's differences (or whole copies where a child cannot say them), other blocks copies named HE<name>.
H = os.path.abspath(sys.argv[1]); INI = os.path.join(H, 'data', 'ini')
sys.path.insert(0, os.path.join(H, 'openbfme', 'tools')); from iniblocks import strip
git = lambda *a: subprocess.run(['git', '-C', H, *a], capture_output=True, check=True).stdout
_src = git('show', '85baa95:openbfme/tools/rebase202/merge.py').decode()
MG = {'re': re, 'collections': collections, 'strip': strip}
exec(_src[_src.index('ELVEN ='):_src.index('def rev_tree')], MG)  # merge.py's block reader (parse / Tree), from the history
parse, Tree = MG['parse'], MG['Tree']
MG['TOP'].add('newevaevent')  # an indented NewEvaEvent (the mod's MirkwoodTaurielDie) starts a block, not the end of the one above
EXT = ('.ini', '.inc')
OBJDIR = 'object/zz_highelves'  # after every vanilla object folder in the load's sorted order: a child after its parent
HEDIR = 'highelves'

def disk_tree(root):
    out = {}
    for d, _, fs in os.walk(root):
        for x in fs:
            if x.lower().endswith(EXT): p = os.path.join(d, x); out[os.path.relpath(p, root)] = open(p, 'rb').read()
    return out
def vanilla_tree():
    names = [p for p in git('ls-tree', '-r', '--name-only', 'vanilla', 'data/ini').decode().split('\n') if p.lower().endswith(EXT)]
    return {p[len('data/ini/'):]: git('show', f'vanilla:{p}') for p in names}

# ---- what the mod changed, and who uses it ---------------------------------------------------------------------------------------------
SHARED = {'normaldamagefx', 'weatherkiller', 'createahero'}                       # kept for every faction
REVERT_ONLY = {'goodspellbookcommandset', 'goodspellstorecommandset', 'menspellbookcommandset', 'menspellstorecommandset', 'dwarvesspellbookcommandset',
               'dwarvesspellstorecommandset', 'arnorspellbookcommandset', 'arnorspellstorecommandset',
               'lwb_elvenfortress'}  # back to 2.02, not copied (the War of the Ring Tauriel army: High Elves are not in War of the Ring yet)
EXTRA_SEED = {'rohanlegolas', 'legolasbow', 'legolashawkstrikewarhead', 'rohanelvenwarriorsword', 'specialabilityhawkstrike', 'legolaslevel7', 'legolaslevel10',
              'legolaslevel11', 'rohanlegolascommandset', 'noldorsilverarrowtrail', 'elventhranduilbowwarhead', 'elvesspellbookcommandset',
              'elvesspellstorecommandset', 'goodspellbook', 'spellbookcloudbreak', 'dwarvensummonedcitadelkeep', 'dwarvensummonedcitadelcommandset',
              'enshroudingmist'}
ALSO_COPY = {'elvesspellbook',                                                   # unchanged, but its parent and command set become the High Elves ones
             'elvenfortress'}                                                    # unchanged, but it unpacks the High Elves layout (LAYOUTS)
LAYOUTS = {'Fortress_Elves'}  # castle layouts renamed with the copies: openbfme/tools/hebases.py writes bases\\hefortress_elves, 2.02's fortress_elves building HEElvenCitadel
STRAY = {'object/gamedata.ini'}  # a 2021 GameData block in the object folder: global values (supply box 8, camera, particles, the 5-8 player command points), back to 2.02's
HOOKS = {'elvenbuildingfoundation'}                                               # placed by maps and castles: a CommandSetUpgrade, not a copy
VANILLA_VALUES = {'elvenbarracks': 'buildtime', 'elvengreenpasture': 'buildtime', 'elvenfortress': 'maxsimultaneousoftype', 'elvencitadel': 'maxsimultaneousoftype'}
# the mod's changes kept on the vanilla side, for every faction (Deepak's list, 2026-10-23); every other changed block not copied is 2.02's again
KEEP = {'gamedata',                                                               # garrisoned range 1.4x
        'ingameui',                                                               # the mod's radius cursors
        'object isengardbeserker', 'object isengardwormtongue', 'object mordordrummertroll',  # burning units stand still (2.02's won't-die bug)
        'modifierlist heroicstatuepassiveleadership',                             # the statue's 125% (2.02's typo)
        'object palantirvisiontracker',                                           # unattackable (2.02 loses the parent's flag)
        'object createahero', 'animationstate = special_weapon_two',              # the Create-a-Hero archer: one object for every faction
        'weaponset | conditions = weaponset_create_a_hero_ws_38 weaponset_toggle_1',
        'weapon weatherkiller',                                                   # also clears Light of Trees
        'damagefx normaldamagefx'}                                                # bow-hit sparks

def nm(key): w = key.split(); return w[1] if len(w) > 1 and '=' not in key else None
TOK = re.compile(r'[a-z0-9_]+')
def macros(M):
    # #define name -> its value's tokens (lower case), the mod's and 2.02's
    out = {}
    for bid, b in M.blocks.items():
        if bid[1].startswith('#define'):
            p = strip(b[2]).split(None, 2)
            if len(p) > 1: out[p[1].lower()] = TOK.findall(p[2].lower()) if len(p) > 2 else []
    return out
def targets(line, D, depth=0):
    # the object names of a TargetNames line, macros expanded
    out = []
    for t in TOK.findall(strip(line).split('=', 1)[1].lower() if '=' in line else ''):
        out += targets('x = ' + ' '.join(D[t]), D, depth + 1) if t in D and depth < 8 else [t]
    return out
def fixes_of(status):
    fixes = {b for b, s in status.items() if s == 'changed' and b[1] in KEEP}
    missing = KEEP - {b[1] for b in fixes}
    if missing or len(fixes) != len(KEEP): raise SystemExit(f'KEEP names blocks the mod did not change, or twice: {sorted(missing)}')
    return fixes
def analyse(M, V, texts):
    status = {}
    for bid, b in M.blocks.items():
        t = V.match(bid); status[bid] = 'new' if t is None else ('same' if t[2] == b[2] else 'changed')
    byname = collections.defaultdict(list)
    for bid in M.blocks:
        n = nm(bid[1]) if not bid[1].startswith('#define') else (bid[1].split()[1] if len(bid[1].split()) > 1 else None)
        if n: byname[n].append(bid)
    byfile = collections.defaultdict(list)
    for bid in M.blocks: byfile[bid[0]].append(bid)
    E = collections.defaultdict(set); D = macros(M)
    for bid, b in M.blocks.items():
        lines = b[2].split('\n'); me = nm(bid[1])
        body = '\n'.join(lines[1:]) if not bid[1].startswith('#define') else ' '.join(b[2].split()[2:])
        for t in set(TOK.findall(body)):
            if t != me and t in byname: E[bid].update(byname[t])
        for inc in re.findall(r'#include\s+"?([^"\s]+)"?', b[2]):
            p = os.path.normpath(os.path.join(os.path.dirname(bid[0]), inc.replace('\\', '/'))).lower(); E[bid].update(byfile.get(p, []))
        if bid[1].startswith('experiencelevel'):
            for l in lines:
                if l.startswith('targetnames'):
                    for t in targets(l, D):
                        for o in byname.get(t, []): E[o].add(bid)
    rev = collections.defaultdict(set)
    for a, ns in E.items():
        for n in ns: rev[n].add(a)
    isobj = lambda b: b[1].startswith('object ')
    ispt = lambda b: b[1].startswith('playertemplate ')
    side, par = {}, {}
    for b, s in M.blocks.items():
        if isobj(b) or ispt(b):
            m = re.search(r'^\s*side\s*=\s*(\w+)', s[2], re.M); side[b] = m.group(1) if m else None
            h = s[2].split('\n')[0].split()
            if h[0] in ('childobject', 'objectreskin') and len(h) > 2: par[b] = h[2]
    def sideof(b, d=0):
        if side.get(b) or d > 10 or b not in par: return side.get(b)
        for p in byname.get(par[b], []):
            if isobj(p): return sideof(p, d + 1)
    for b in list(side): side[b] = sideof(b)
    owner = collections.defaultdict(set)
    for o in side:
        todo, seen = [o], {o}
        while todo:
            for n in E.get(todo.pop(), ()):
                if n in seen: continue
                seen.add(n)
                if isobj(n) or ispt(n): continue
                owner[n].add(side[o] or '?'); todo.append(n)
    for o in side: owner[o] = {side[o] or '?'}
    root = byname['factionelves'][0]
    elv, todo = {root}, [root]
    while todo:
        for n in E.get(todo.pop(), ()):
            if n not in elv: elv.add(n); todo.append(n)
    return status, byname, E, rev, owner, elv, root

def inventory(M, status, byname, E, rev, owner, elv, root):
    K = lambda b: b[1]
    seed = {b for b, s in status.items() if s == 'changed' and 'elves' in owner.get(b, ()) and nm(K(b)) not in SHARED}
    seed |= {b for b, s in status.items() if s == 'changed' and (nm(K(b)) in EXTRA_SEED or 'mirkwoodarcherlevel' in K(b))}
    seed -= {b for b in seed if nm(K(b)) in VANILLA_VALUES and status[b] == 'same'}
    isobj = lambda b: K(b).startswith('object ')
    def elvenish(b):
        if b == root: return True
        if b not in elv or K(b).startswith('experiencelevel'): return False
        return 'elves' in owner.get(b, ()) or b in seed
    def covered(n, r):
        if not isobj(n): return False
        name = nm(K(n)); ls = [l for l in M.blocks[r][2].split('\n') if re.search(r'\b' + re.escape(name) + r'\b', l)]
        return bool(ls) and all('filter' in l or '+' + name in l or (isobj(r) and l.startswith('object')) for l in ls)
    clone = {b for b in seed if not K(b).startswith('playertemplate ')}; hooks, todo = set(), list(clone)
    while todo:
        n = todo.pop()
        for r in rev.get(n, ()):
            if r in clone or not elvenish(r) or covered(n, r) or K(r).startswith('playertemplate '): continue  # the faction is written from FactionElves
            if isobj(r) and nm(K(r)) in HOOKS: hooks.add(r); continue
            clone.add(r); todo.append(r)
    # a block between two copies is a copy: the High Elves spell book's buttons lead to powers that need the copied sciences, Legolas' bow to the
    # copied warhead (a path through an object, a level or a block of the mod's own does not count; it ends at a copy that is not an object)
    blocked = lambda b: K(b).startswith(('object ', 'playertemplate ', 'experiencelevel')) or status[b] == 'new' or nm(K(b)) in REVERT_ONLY
    while True:
        new = set()
        for c in clone:
            if nm(K(c)) in REVERT_ONLY or K(c).startswith('playertemplate '): continue
            par, todo = {}, [c]
            while todo:
                x = todo.pop()
                for d in E.get(x, ()):
                    if d in par or d == c: continue
                    par[d] = x
                    if d in clone and not isobj(d):
                        y = x
                        while y != c: new.add(y); y = par[y]
                    elif d not in clone and not blocked(d): todo.append(d)
        new -= clone
        if not new: break
        clone |= new
    clone |= {b for n in ALSO_COPY for b in byname.get(n, [])}
    reverted = set(clone) | {b for b, s in status.items() if s == 'changed' and nm(K(b)) in REVERT_ONLY}
    clone = {b for b in clone if status[b] != 'new' and nm(K(b)) not in REVERT_ONLY}
    return seed, clone, hooks, reverted

# ---- names ------------------------------------------------------------------------------------------------------------------------------
def renamer(names):
    rx = re.compile(r'(?<![:\w.])(' + '|'.join(sorted(map(re.escape, names), key=len, reverse=True)) + r')(?![\w.])', re.I)
    return lambda text: rx.sub(lambda m: 'HE' + m.group(1), text)
def realname(block_text):
    return block_text.split('\n')[0].split()[1]

# ---- objects ----------------------------------------------------------------------------------------------------------------------------
MODULE = re.compile(r'^(behavior|draw|body|clientupdate|clientbehavior)\s*=\s*(\S+)\s+(\S+)', re.I)
# which lines open a nested block: RotWK's own field grammar (the engine's engine/data/rotwk-201/field-tables.json, read from the game binary)
import json
_G = json.load(open(os.path.join(os.path.dirname(H), 'openbfme-godot', 'engine', 'data', 'rotwk-201', 'field-tables.json')))
_F = _G['functions']
BLOCKS, FLOATLINE, DISPATCH, FIRSTTOKEN, LINES = set(), set(), {}, {}, set()
for _t in _G['tables'].values():
    for _r in _t['rows']:
        _n, _f = _r['name'].lower(), _F.get(_r['fn'], {})
        if _f.get('kind') != 'block': LINES.add(_n); continue
        _c, _d = _f.get('conditional') or {}, _f.get('dispatch') or {}  # a block opened only for some lines (the grammar's reviewed cases)
        if _c.get('opens') == 'unlessFloat': FLOATLINE.add(_n)
        elif _c.get('opens') == 'firstTokenIs': FIRSTTOKEN[_n] = _c['value'].lower()
        elif 'names' in _d: DISPATCH[_n] = {x.lower() for x, tb in zip(_d['names'], _d['tables']) if tb}
        else: BLOCKS.add(_n)
SETS = {_r['name'].lower() for _r in _G['tables'][_G['objectTable']['table']]['rows'] if _F.get(_r['fn'], {}).get('kind') == 'block'}
def opens(s):
    w = [x for x in re.split(r'[\s=]+', s.strip().lower()) if x]
    if not w: return False
    name, vals = w[0], w[1:]
    if name in DISPATCH: return bool(vals) and vals[0] in DISPATCH[name]
    if name in FIRSTTOKEN: return bool(vals) and vals[0] == FIRSTTOKEN[name]
    if name in FLOATLINE: return not vals  # a number opens nothing, a macro is a number too (Radius = GENERIC_KEEP_MONEY_RANGE): the block form has no value
    if name in BLOCKS and name in LINES: return not vals  # a block in one table, a line in another (Turret): the block has no value
    return name in BLOCKS
class Unplaceable(Exception): pass
WHY = {}  # object -> why it is a whole copy
def expand(text, rel, tree, depth=0):
    out = []
    for l in text.split('\n'):
        m = re.match(r'\s*#include\s+"?([^"\s;]+)"?', l, re.I)
        if m and depth < 8:
            p = os.path.normpath(os.path.join(os.path.dirname(rel), m.group(1).replace('\\', '/')))
            hit = next((k for k in tree if k.lower() == p.lower()), None)
            if hit is None: raise Unplaceable(f'{rel}: #include {m.group(1)} not found')
            out += expand(tree[hit].decode('latin-1'), hit, tree, depth + 1).split('\n')
        else: out.append(l)
    return '\n'.join(out)
def object_parts(text):
    # (header, fields {key: [lines]}, modules {tag: (class, lines)}, sets {kind: [[lines]...]}); Unplaceable when the nesting does not close
    lines = text.split('\n'); header = lines[0]
    last = max(i for i, l in enumerate(lines) if strip(l).lower() == 'end')
    fields, modules, sets = collections.OrderedDict(), collections.OrderedDict(), collections.defaultdict(list)
    depth, cur, info, script = 0, None, None, False
    for l in lines[1:last]:
        s = strip(l); sl = s.lower(); first = sl.split()[0] if sl else ''
        if script:
            cur.append(l)
            if first.startswith('endscript'): script = False
            continue
        if depth and first.startswith('beginscript'): script = True; cur.append(l); continue
        if depth == 0:
            if not s: continue
            m = MODULE.match(s)
            if m: cur, info, depth = [l], ('module', m.group(2).lower(), m.group(3)), 1; continue
            if first in SETS: cur, info, depth = [l], ('set', first), 1; continue
            if sl == 'end': raise Unplaceable('End at object level')
            fields.setdefault(re.split(r'[\s=]', sl, maxsplit=1)[0], []).append(l); continue
        cur.append(l)
        if sl == 'end':
            depth -= 1
            if depth == 0:
                if info[0] == 'module':
                    if info[2].lower() in {t.lower() for t in modules}: raise Unplaceable(f'tag {info[2]} twice')
                    modules[info[2]] = (info[1], cur)
                else: sets[info[1]].append(cur)
        elif opens(s) or MODULE.match(s): depth += 1
    if depth: raise Unplaceable('nesting does not close')
    return header, fields, modules, sets
norm = lambda ls: [strip(l) for l in ls if strip(l)]
def equivalents(fields):
    return [t for l in fields.get('equivalentto', []) for t in strip(l).split('=', 1)[1].split()]
def child_of_object(name, vtext, mtext, mraw):
    # ChildObject HE<name> <name> with the mod's differences; None when a child cannot say them (an unset field, a changed LocomotorSet / Prerequisites)
    try: vh, vf, vm, vs = object_parts(vtext); mh, mf, mm, ms = object_parts(mtext); _, rawf, _, _ = object_parts(mraw)
    except Unplaceable as e: WHY[name] = f'unplaceable: {e}'; return None
    out = [f'ChildObject HE{name} {name}', '\tEquivalentTo = ' + ' '.join(dict.fromkeys([name] + equivalents(vf) + equivalents(rawf)))]
    for k in vf:
        if k not in mf and k != 'equivalentto': WHY[name] = f'field {k} only in 2.02'; return None
    for k, ls in mf.items():
        if k != 'equivalentto' and norm(ls) != norm(vf.get(k, [])): out += ls
    for kind in SETS - {'weaponset', 'armorset', 'unitspecificsounds', 'unitspecificfx'}:
        if [norm(b) for b in vs.get(kind, [])] != [norm(b) for b in ms.get(kind, [])]: WHY[name] = f'{kind} changed'; return None
    for kind in ('weaponset', 'armorset', 'unitspecificsounds', 'unitspecificfx'):
        if [norm(b) for b in vs.get(kind, [])] != [norm(b) for b in ms.get(kind, [])]:
            for b in ms.get(kind, []): out += b
    vt = {t.lower(): (t, c, ls) for t, (c, ls) in vm.items()}; mt = {t.lower(): (t, c, ls) for t, (c, ls) in mm.items()}
    for k, (t, c, ls) in vt.items():
        if k not in mt: out.append(f'\tRemoveModule {t}')
    for k, (t, c, ls) in mt.items():
        if k not in vt: out += ls; continue
        vtag, vc, vls = vt[k]
        if norm(vls) == norm(ls): continue
        renamed = [ls[0].replace(t, t + '_HE', 1)] + ls[1:]
        if vc == c: out += [f'\tReplaceModule {vtag}'] + renamed + ['\tEnd']
        else: out += [f'\tRemoveModule {vtag}'] + renamed
    return '\n'.join(out + ['End', ''])

# ---- the split --------------------------------------------------------------------------------------------------------------------------
def rel_include(from_rel, to_rel):
    return os.path.relpath(to_rel, os.path.dirname(from_rel) or '.').replace('/', '\\')
def he_inc(rel): return f'{HEDIR}/' + rel.replace('/', '_').rsplit('.', 1)[0] + '.inc'

def vanilla_values(mine, van):
    # 2.02's values where the decision keeps them (build time, fortress limit), before anything is compared
    V0 = Tree(van)
    for rel, data in list(mine.items()):
        text = data.decode('latin-1'); changed = False
        for obj, field in VANILLA_VALUES.items():
            m = re.search(r'(?ims)^(Object|ChildObject)\s+' + obj + r'\b.*?^End\b', text)
            vb = [b for b in V0.blocks.values() if b[1] == 'object ' + obj]
            if not m or not vb: continue
            vl = [l for l in vb[0][3].split('\n') if strip(l).lower().startswith(field)]
            block = m.group(0); nb = '\n'.join((vl.pop(0) if strip(l).lower().startswith(field) and vl else l) for l in block.split('\n'))
            if nb != block: text = text.replace(block, nb, 1); changed = True
        if changed: mine[rel] = text.encode('latin-1')

def split():
    mine, van = disk_tree(INI), vanilla_tree()
    vanilla_values(mine, van)
    M, V = Tree(mine), Tree(van)
    status, byname, E, rev, owner, elv, root = analyse(M, V, None)
    seed, clone, hooks, reverted = inventory(M, status, byname, E, rev, owner, elv, root)
    names = {realname(M.blocks[b][3]) for b in clone} | LAYOUTS
    ren = renamer(names)
    cloned_lower = {n.lower() for n in names}
    K = lambda b: b[1]
    D = macros(M)
    objname = {realname(s[3]).lower(): realname(s[3]) for s in M.blocks.values() if K(s).startswith('object ')}
    own_lower = {nm(K(b)) for b, s in status.items() if s == 'new' and K(b).startswith('object ')}
    print('inventory:', dict(collections.Counter(K(b).split()[0] for b in clone)), 'hooks:', sorted(nm(K(b)) for b in hooks), 'reverted:', len(reverted))
    # High Elves blocks, by destination
    he_objects, he_files = [], collections.defaultdict(list)          # (sort key, text); he_files: destination .inc -> [(sort key, text)]
    order = {bid: (bid[0], i) for rel, segs in M.segs.items() for i, s in enumerate(segs) if s[0] == 'block' for bid in [s[4]]}
    defines = []
    def vanilla_file(b):
        t = V.match(b); return t[4][0] if t else b[0]
    def home(b):
        # the 2.02 file whose High Elves .inc holds this block (a block in a mod-only file: the 2.02 file that includes it)
        rel = vanilla_file(b)
        if rel in V.segs: return rel
        for r2, segs in M.segs.items():
            if r2 in V.segs and any(re.search(r'#include\s+"?[^"]*' + re.escape(os.path.basename(rel)), s[1] if s[0] == 'raw' else s[3], re.I) for s in segs): return r2
        return rel
    whole = 0
    for b in sorted(clone, key=lambda b: order[b]):
        mb = M.blocks[b]; name = realname(mb[3]); t = V.match(b)
        if K(b).startswith('object '):
            vh = t[3].split('\n')[0].split(); mh = mb[3].split('\n')[0].split()
            text = None
            if vh[0].lower() == mh[0].lower() == 'object':
                mexp = expand(mb[3], b[0], mine); text = child_of_object(name, expand(t[3], t[4][0], van), ren(mexp), mexp)
                if text: text = text.replace(f'ChildObject HE{name} HE{name}', f'ChildObject HE{name} {name}')
            if text is None:
                whole += 1; WHY.setdefault(name, 'header: ' + ' '.join(vh[:1] + vh[2:3]) + ' -> ' + ' '.join(mh[:1] + mh[2:3]))
                body = ren(mb[3]).split('\n')
                eq = '\tEquivalentTo = ' + ' '.join(dict.fromkeys([name] + [x for l in mb[3].split('\n') if strip(l).lower().startswith('equivalentto') for x in strip(l).split('=', 1)[1].split()]))
                body = [body[0]] + [eq] + [l for l in body[1:] if not strip(l).lower().startswith('equivalentto')]
                text = '\n'.join(body)
                text = re.sub(r'#include\s+"?([^"\s;]+)"?', lambda m: '#include "' + rel_include(OBJDIR + '/highelves.ini', os.path.normpath(os.path.join(os.path.dirname(b[0]), m.group(1).replace('\\', '/')))) + '"', text)
            he_objects.append((order[b], name, text))
        elif K(b).startswith('experiencelevel'):
            lines, raw = ren(mb[3]).split('\n'), mb[3].split('\n')
            out = []
            for i, l in enumerate(lines):
                if strip(l).lower().startswith('targetnames'):
                    # the High Elves copies and the mod's own objects it targets, macros expanded (H_ELVEN_ARCHER_DAMAGE_FILTER)
                    keep = list(dict.fromkeys('HE' + objname[x] if x in cloned_lower else objname[x] for x in targets(raw[i], D) if x in cloned_lower or x in own_lower))
                    if not keep: out = None; break
                    l = '\tTargetNames = ' + ' '.join(keep)
                out.append(l)
            if out: he_files[he_inc(home(b))].append((order[b], '\n'.join(out)))
        else:
            he_files[he_inc(home(b))].append((order[b], ren(mb[3])))
    for b, s in status.items():
        if s != 'new' or b[0] in STRAY: continue
        text = ren(M.blocks[b][3])
        if K(b).startswith('#define'): defines.append((order[b], text, home(b)))
        elif K(b).startswith('object '):
            # a vanilla name it is EquivalentTo stays, the High Elves copy's name joins it (ElvenMirkwoodArcherB: both archers' filters)
            raw = M.blocks[b][3].split('\n')
            text = '\n'.join(re.sub(r'(?i)^(\s*EquivalentTo\s*=\s*)(.*)$', lambda m: m.group(1) + ' '.join(x for w in strip(raw[i]).split('=', 1)[1].split() for x in ([w, 'HE' + w] if w.lower() in cloned_lower else [w])), l) for i, l in enumerate(text.split('\n')))
            he_objects.append((order[b], realname(M.blocks[b][3]), re.sub(r'#include\s+"?([^"\s;]+)"?', lambda m: '#include "' + rel_include(OBJDIR + '/highelves.ini', os.path.normpath(os.path.join(os.path.dirname(b[0]), m.group(1).replace('\\', '/')))) + '"', text)))
        elif '=' in K(b): continue  # a module fragment stays in its fragment file
        elif b[0].startswith('mappedimages/') and b[0] not in V.segs: continue  # the folder loads the mod's own image files as they are
        else: he_files[he_inc(home(b))].append((order[b], text))
    he_files[f'{HEDIR}/upgrade_highelves.inc'].append((('', 0), 'Upgrade Upgrade_HighElvesFaction ; the High Elves player (FactionHighElves InitialUpgrades)\n\tType = PLAYER\nEnd'))
    # parents before children in the one objects file
    he_objects.sort(key=lambda x: x[0]); names_in = {n.lower(): i for i, (_, n, _) in enumerate(he_objects)}; ordered, done = [], set()
    def place(i):
        if i in done: return
        done.add(i); h = he_objects[i][2].split('\n')[0].split()
        if len(h) > 2 and h[2].lower() in names_in: place(names_in[h[2].lower()])
        ordered.append(he_objects[i][2])
    for i in range(len(he_objects)): place(i)
    # the vanilla side
    out = {}
    fixes = fixes_of(status)
    loose = lambda segs: any(s[0] == 'raw' and strip(s[1]) and not strip(s[1]).lower().startswith('#include') for s in segs)
    lv_extra = collections.defaultdict(list)
    for b in sorted(clone, key=lambda b: order[b]):
        if K(b).startswith('object '):
            for l in sorted(E.get(b, ()), key=lambda l: order[l]):
                if K(l).startswith('experiencelevel') and l not in clone and status[l] == 'same': lv_extra[V.match(l)[4]].append('HE' + realname(M.blocks[b][3]))
    for rel in V.segs:
        vrel = next(k for k in van if k.lower() == rel)
        msegs = M.segs.get(rel)
        if msegs is not None and (loose(V.segs[rel]) or loose(msegs)):
            keep = any(s[0] == 'block' and s[4] in fixes for s in msegs)
            out[vrel] = (mine[next(k for k in mine if k.lower() == rel)] if keep else van[vrel]).decode('latin-1'); continue
        parts = []
        for s in V.segs[rel]:
            if s[0] == 'raw': parts.append(s[1]); continue
            mb = M.match(s[4]); text = s[3]
            if mb is not None and mb[4] in fixes: text = mb[3]
            if s[4] in lv_extra:
                text = re.sub(r'(?im)^(\s*TargetNames\s*=[^;\r\n]*?)(\s*(;.*)?)$', lambda m: m.group(1).rstrip() + ' ' + ' '.join(lv_extra[s[4]]) + (' ' + m.group(3) if m.group(3) else ''), text, count=1)
            if mb is not None and mb[4] in hooks:
                i = text.rstrip().rfind('\n'); text = text[:i] + '\n\tBehavior = CommandSetUpgrade ModuleTag_HighElvesCommandSet ; the High Elves player\'s buildings\n\t\tTriggeredBy = Upgrade_HighElvesFaction\n\t\tCommandSet = HEElvenFoundationCommandSet\n\tEnd' + text[i:]
            parts.append(text)
        out[vrel] = ''.join(parts)
    for dest, items in he_files.items():
        host = next((k for k in out if he_inc(k.lower()) == dest), None) or ('upgrade.ini' if dest == f'{HEDIR}/upgrade_highelves.inc' else None)
        if host is None: raise SystemExit(f'{dest}: no 2.02 file to include it')
        out[host] = out[host].rstrip('\n') + f'\n#include "{rel_include(host, dest)}" ; the High Elves faction\n'
    # the mod's macros: water.ini's in macros.inc, before any use; the others at the top of their own file's High Elves .inc, which an audio file
    # needs (the audio INI loads in an environment of its own, without water.ini: M_TAURIEL_RESPONSE_VOLUME, mod 8b006c4)
    water = [d for d in defines if d[2] == 'default/water.ini']
    if water:
        host = 'default/water.ini'
        out[host] = f'#include "{rel_include(host, HEDIR + "/macros.inc")}" ; the High Elves faction\'s macros, before any use\n' + out[host]
    own_defs = collections.defaultdict(list)
    for d in defines:
        if d[2] != 'default/water.ini': own_defs[he_inc(d[2])].append(d)
    for dest in own_defs:
        if dest not in he_files: raise SystemExit(f'{dest}: macros without blocks (no include for them)')
    pt = M.blocks[byname['factionelves'][0]][3]
    pt, k = re.subn(r'(?i)\APlayerTemplate\s+FactionElves\b', 'PlayerTemplate FactionHighElves', ren(pt)); assert k == 1, 'faction header'
    for field, value in (('PlayableSide', 'Yes'), ('DisplayName', 'INI:FactionHighElves'), ('InitialUpgrades', 'Upgrade_ElfFaction Upgrade_HighElvesFaction'), ('DefaultPlayerAIType', 'ElvesSkirmishAI')):
        pt, k = re.subn(r'(?im)^(\s*' + field + r'\s*=\s*)[^\r\n]*$', lambda m: m.group(1) + value, pt, count=1); assert k == 1, field
    out['playertemplate.ini'] = out['playertemplate.ini'].rstrip('\n') + '\n\n; The High Elves mod: its own faction (openbfme-godot docs/HIGHELVES.md)\n' + pt + ('\n' if not pt.endswith('\n') else '')
    out[OBJDIR + '/highelves.ini'] = '; The High Elves faction: ChildObjects of the vanilla elves with the mod\'s differences, whole copies where a child cannot say them, the mod\'s own objects\n\n' + '\n\n'.join(ordered) + '\n'
    lines = lambda ds: ''.join(t if t.endswith('\n') else t + '\n' for _, t, _ in sorted(ds, key=lambda x: x[0]))
    if water: out[HEDIR + '/macros.inc'] = '; The High Elves faction\'s macros\n' + lines(water)
    for dest, items in he_files.items():
        top = ('; the macros of this file\'s own blocks (an audio file loads without the main load\'s macros)\n' + lines(own_defs[dest]) + '\n') if own_defs.get(dest) else ''
        out[dest] = '; The High Elves faction (openbfme-godot docs/HIGHELVES.md)\n\n' + top + '\n\n'.join(t.rstrip('\n') for _, t in sorted(items, key=lambda x: x[0])) + '\n'
    # the mod's own files: fragment files stay (renamed names inside); the others dissolve into the High Elves files above
    for rel in mine:
        if rel.lower() in V.segs or rel.lower().startswith((OBJDIR, HEDIR + '/')): continue
        if rel.lower() in STRAY: out[rel] = None; continue
        segs = M.segs[rel.lower()]
        if rel.lower().startswith('mappedimages/') or any(s[0] == 'block' and '=' in s[1] for s in segs): out[rel] = ren(mine[rel].decode('latin-1'))
        else: out[rel] = None
    # a mod-only file something still includes stays (renamed names inside): a fragment of modules, a file of #defines
    def included(texts):
        refs = set()
        for rel, text in texts:
            for inc in re.findall(r'(?im)^\s*#include\s+"?([^"\s;]+)"?', text or ''):
                refs.add(os.path.normpath(os.path.join(os.path.dirname(rel), inc.replace('\\', '/'))).lower())
        return refs
    while True:
        refs = included(list(out.items()) + [(r, mine[r].decode('latin-1')) for r in mine if r not in out])
        back = [r for r, t in out.items() if t is None and r.lower() in refs]
        if not back: break
        for r in back: out[r] = ren(mine[r].decode('latin-1'))
    # a macro of the mod that only 2.02's own text uses goes: SAURON would give 2.02's Sauron1 level (TargetNames = SAURON, a macro 2.02
    # commented out) to vanilla Mordor
    mod_defs = {strip(t).split()[1].lower() for _, t, _ in defines}
    tokens = lambda texts: collections.Counter(x for t in texts if t for l in t.split('\n') for x in TOK.findall(strip(l).lower()))
    in_van = tokens(v.decode('latin-1') for v in van.values())
    while True:
        use = tokens(out.values())
        dead = {n for n in mod_defs if in_van[n] and use[n] - in_van[n] <= 1}
        if not dead: break
        print('  unused macro dropped:', sorted(dead)); mod_defs -= dead
        for r, t in out.items():
            if t and r.lower().startswith(HEDIR + '/'): out[r] = ''.join(l for l in t.splitlines(True) if not (strip(l).lower().startswith('#define') and strip(l).split()[1].lower() in dead))
    for rel, text in out.items():
        p = os.path.join(INI, rel)
        if text is None:
            if os.path.exists(p): os.remove(p)
            continue
        os.makedirs(os.path.dirname(p), exist_ok=True)
        open(p, 'w', encoding='latin-1', newline='').write(text)
    for k, v in sorted(WHY.items()): print('  whole copy:', k, '-', v)
    print(f'objects: {len(ordered)} ({whole} whole copies); High Elves files: {len(he_files) + 2}; levels sharing 2.02 blocks: {sum(len(v) for v in lv_extra.values())}')

def check(before_dir):
    # the plan's four checks, against the tree as it was before the split (before_dir: a copy of data/ini)
    pre, post, van = disk_tree(before_dir), disk_tree(INI), vanilla_tree()
    vanilla_values(pre, van)
    P, Q, V = Tree(pre), Tree(post), Tree(van)
    status, byname, E, rev, owner, elv, root = analyse(P, V, None)
    seed, clone, hooks, reverted = inventory(P, status, byname, E, rev, owner, elv, root)
    names = {realname(P.blocks[b][3]) for b in clone} | LAYOUTS; ren = renamer(names); fails = []
    fixes = fixes_of(status)
    # 1. the vanilla side: every block in a 2.02 file is vanilla's, but for the KEEP list, the hook, the shared levels and the faction
    other = []; kinds = collections.Counter()
    for rel, segs in Q.segs.items():
        if rel not in V.segs: continue
        for s in segs:
            if s[0] != 'block': continue
            t = V.match(s[4])
            if t is not None and t[2] == s[2]: continue
            pb = P.match(s[4])
            if pb is not None and pb[4] in fixes and pb[2] == s[2]: kinds['fix'] += 1; continue
            if s[1] == 'playertemplate factionhighelves': kinds['faction'] += 1; continue
            if t is not None and s[1].startswith('experiencelevel') and [l for l in s[2].split('\n') if not l.startswith('targetnames')] == [l for l in t[2].split('\n') if not l.startswith('targetnames')]: kinds['shared level'] += 1; continue
            if t is not None and nm(s[1]) in HOOKS: kinds['hook'] += 1; continue
            if t is None and s[1].startswith('#define'): other.append(('macro in a 2.02 file', rel, s[1])); continue
            other.append((rel, s[1]))
    print('check 1 (vanilla side):', dict(kinds), 'other:', other[:12])
    if other: fails.append('1')
    # 2. each High Elves object resolves to the mod's object: a ChildObject of a vanilla Object composed on its parent; the others compared directly
    def composed(parent_text, child_text):
        vh, vf, vm, vs = object_parts(parent_text); ch, cf, cm, cs = object_parts(child_text)
        f = collections.OrderedDict(vf); f.update({k: v for k, v in cf.items() if k not in ('equivalentto', 'removemodule')})
        mods = {t.lower(): (c, ls) for t, (c, ls) in vm.items()}
        for l in cf.get('removemodule', []): mods.pop(strip(l).split()[1].lower(), None)
        for b in cs.get('replacemodule', []):
            old = strip(b[0]).split()[1].lower(); inner = b[1:-1]; m = MODULE.match(strip(inner[0]))
            mods.pop(old, None); mods[m.group(3).lower()] = (m.group(2).lower(), inner)
        for t, (c, ls) in cm.items(): mods[t.lower()] = (c, ls)
        sets = {k: v for k, v in vs.items()}
        for k in ('weaponset', 'armorset', 'unitspecificsounds', 'unitspecificfx'):
            if cs.get(k): sets[k] = cs[k]
        return f, mods, sets
    def shape(f, mods, sets):
        tagless = lambda c, ls: (c, tuple(norm([MODULE.sub(lambda m: m.group(1) + ' = ' + m.group(2) + ' TAG', strip(ls[0]))] + ls[1:])))
        return ({k: norm(v) for k, v in f.items() if k != 'equivalentto'},
                collections.Counter(tagless(c, ls) for c, ls in mods.values()),
                {k: [norm(b) for b in v] for k, v in sets.items() if k in ('weaponset', 'armorset', 'unitspecificsounds', 'unitspecificfx')})
    bad2, n2 = [], 0
    for b in clone:
        if not b[1].startswith('object '): continue
        name = realname(P.blocks[b][3]); hb = [x for x in Q.blocks.values() if x[1] == 'object he' + name.lower()]
        if len(hb) != 1: bad2.append((name, 'missing')); continue
        hb = hb[0]; n2 += 1
        mod = ren(expand(P.blocks[b][3], b[0], pre))
        h = hb[3].split('\n')[0].split()
        if h[0].lower() == 'childobject' and h[2].lower() == name.lower():
            t = V.match(b)
            try: got = shape(*composed(expand(t[3], t[4][0], van), hb[3]))
            except Unplaceable as e: bad2.append((name, f'unreadable: {e}')); continue
            _, mf, mm, ms = object_parts(mod); want = shape(mf, {t.lower(): v for t, v in mm.items()}, ms)
        else:
            body = lambda x: norm([l for l in x.split('\n')[1:] if not strip(l).lower().startswith(('equivalentto', '#include'))])
            got, want = body(hb[3]), body(re.sub(r'(?m)^\s*#include.*$', '', P.blocks[b][3] if False else ren(P.blocks[b][3])))
        if got != want:
            which = [i for i in range(3) if isinstance(got, tuple) and got[i] != want[i]] if isinstance(got, tuple) else 'body'
            bad2.append((name, which))
    print(f'check 2 (High Elves objects): {n2} compared, differ: {bad2[:10]}')
    if bad2: fails.append('2')
    # 3. labels stay as written: no label names a High Elves block
    he_text = '\n'.join(s[3] for rel, segs in Q.segs.items() for s in segs if s[0] == 'block' and (rel.startswith((OBJDIR, HEDIR + '/')) or nm(s[1]) and nm(s[1]).startswith('he')))
    pre_labels = {m.lower() for t in pre.values() for m in re.findall(r'\b[A-Za-z]+:[A-Za-z0-9_]+', t.decode('latin-1'))}
    renamed_labels = sorted({m for m in re.findall(r'\b[A-Za-z]+:[A-Za-z0-9_]+', he_text) if m.lower() not in pre_labels})  # a label the mod never had
    print(f'check 3 (labels): {len(re.findall(r"[A-Za-z]+:[A-Za-z0-9_]+", he_text))} label tokens, renamed by mistake: {renamed_labels[:8]}')
    if renamed_labels: fails.append('3')
    # 4. nothing of the mod is lost: every block the mod added or changed is in the new tree (renamed), objects through check 2
    have = collections.Counter(re.sub(r'(?m)^#include.*$', '#include', s[2]) for segs in Q.segs.values() for s in segs if s[0] == 'block')
    lost = []; in_van = {x for v in van.values() for l in v.decode('latin-1').split('\n') for x in TOK.findall(strip(l).lower())}
    for b, st in status.items():
        if b[0] in STRAY or b[1].startswith(('object ', 'playertemplate ')) or '=' in b[1]: continue  # the faction: FactionHighElves, its own fields
        if st == 'new' or b in clone:
            want = re.sub(r'(?m)^#include.*$', '#include', '\n'.join(strip(l).lower() for l in ren(P.blocks[b][3]).split('\n') if strip(l)))
            if b[1].startswith('experiencelevel') and b in clone: continue  # a copied level keeps only its High Elves targets
            if b[1].startswith('#define') and b[1].split()[1] in in_van: continue  # a macro only 2.02's text uses goes (SAURON)
            if have[want] < 1: lost.append(b[1])
    print(f'check 4 (nothing lost): {len(lost)} lost {lost[:10]}')
    if lost: fails.append('4')
    # 5. one faction more: the player templates are 2.02's and FactionHighElves
    pts = [s[1] for segs in Q.segs.values() for s in segs if s[0] == 'block' and s[1].startswith('playertemplate ')]
    extra = sorted(collections.Counter(pts) - collections.Counter([s[1] for segs in V.segs.values() for s in segs if s[0] == 'block' and s[1].startswith('playertemplate ')]))
    print('check 5 (factions): added', extra)
    if extra != ['playertemplate factionhighelves']: fails.append('5')
    # 6. levels per object: a High Elves copy has as many experience levels as the mod's object had, the mod's own objects too, 2.02's as in 2.02
    def levels(T):
        D, n = macros(T), collections.Counter()
        for b in T.blocks.values():
            if b[1].startswith('experiencelevel'):
                for l in b[2].split('\n'):
                    if l.startswith('targetnames'): n.update(set(targets(l, D)))
        return n
    lp, lq, lv = levels(P), levels(Q), levels(V)
    own = {nm(b[1]) for b, st in status.items() if st == 'new' and b[1].startswith('object ')}
    want = {**{o: lv[o] for o in lv}, **{'he' + nm(b[1]): lp[nm(b[1])] for b in clone if b[1].startswith('object ')}, **{o: lp[o] for o in own}}
    bad6 = sorted((o, w, lq[o]) for o, w in want.items() if lq[o] != w)
    print(f'check 6 (levels per object): {len(want)} objects, differ (object, want, got): {bad6[:10]}')
    if bad6: fails.append('6')
    # 7. every High Elves spell can be cast: each spell-book button's power needs a science the High Elves store sells
    def fieldof(T, key, field):
        b = T.byname.get(key)
        return [] if not b else [x for l in T.blocks[b[0]][2].split('\n') if l.startswith(field) for x in TOK.findall(l.split('=', 1)[1])]
    slots = lambda key: [l.split('=', 1)[1].strip() for l in Q.blocks[Q.byname[key][0]][2].split('\n')[1:] if '=' in l] if Q.byname.get(key) else []
    sold = {s for btn in slots('commandset heelvesspellstorecommandset') for s in fieldof(Q, 'commandbutton ' + btn, 'science')}
    buttons = slots('commandset heelvesspellbookcommandset')
    # one owned RequiredScience is enough (openbfme-godot SpellBookUI.cpp / ControlBar.cpp, RW 0x943343)
    bad7 = [(btn, need) for btn in buttons for p in fieldof(Q, 'commandbutton ' + btn, 'specialpower') for need in [set(fieldof(Q, 'specialpower ' + p, 'requiredscience'))] if not need & sold]
    print(f'check 7 (spells): {len(buttons)} spell-book buttons, {len(sold)} sciences sold, uncastable: {bad7[:6]}')
    if bad7 or not buttons: fails.append('7')
    # 8. the mod's own objects keep the names they were EquivalentTo (and add the High Elves copy's)
    eq = lambda T, o: {x for l in T.blocks[T.byname['object ' + o][0]][2].split('\n') if l.startswith('equivalentto') for x in l.split('=', 1)[1].split()}
    bad8 = sorted(o for o in own if Q.byname.get('object ' + o) and not eq(P, o) <= eq(Q, o))
    print(f'check 8 (EquivalentTo of the mod\'s objects): lost names on {bad8[:8]}')
    if bad8: fails.append('8')
    print('FAIL:', fails) if fails else print('all checks pass')
    sys.exit(1 if fails else 0)

if len(sys.argv) == 2: split()
elif sys.argv[2] == '--check': check(sys.argv[3])
