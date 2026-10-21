import sys, os, re, struct, subprocess, json, collections
# usage: merge.py <mod repo> <out dir> <patch big>
# Block-level three-way merge of the mod's INI tree onto 2.02 v9.8.0's:
#   base = the mod's first commit (2.02 ~v8.4 + the first edits), ours = the mod before the rebase (REBASE_OURS), theirs = v9.8.0's data\ini (complete in __patch202.big).
# The mod's files are the skeleton (comments, #includes, the data/ini/mod/*.inc layout); each block's content is picked by who changed it.
# Writes <out>/data/ini/... and <out>/merge-report.json. Blocks are matched by (file, name, occurrence), else by name when unique in the tree (moves).
repo, out, big = sys.argv[1:4]
sys.path.insert(0, os.path.join(repo, 'openbfme/tools')); from iniblocks import strip
INI = ('.ini', '.inc')
ELVEN = re.compile(r'elv|elf|lorien|rivendell|mirkwood|galadh|noldor|haldir|elrond|legolas|glorfindel|arwen|thranduil|tauriel|imladris|lothlorien|celeborn|cirdan')

def git(*a): return subprocess.run(['git', '-C', repo, *a], capture_output=True, check=True).stdout

TOP = {'object', 'childobject', 'objectreskin', 'weapon', 'armor', 'upgrade', 'commandbutton', 'commandset', 'experiencelevel', 'specialpower',
       'fxlist', 'fxparticlesystem', 'audioevent', 'multisound', 'musictrack', 'dialogevent', 'modifierlist', 'science', 'locomotor',
       'objectcreationlist', 'mappedimage', 'rank', 'playertemplate', 'crowdresponse', 'animationsoundclientbehaviorglobalsetting', 'emotionnugget',
       'linearcampaign', 'livingworldcampaign', 'aibase', 'region', 'terrain', 'roads', 'bridge', 'damagefx', 'createaheroability', 'stancetemplate'}
def blockkey(s):
    # type and name; Object, ChildObject and ObjectReskin name one template namespace (2.02 turned Object MirkBridge into a ChildObject)
    # a module header in a fragment .inc ("Behavior = AISpecialPowerUpdate BattleRageL1AI") is named by the whole line, its tag included
    if '=' in s: return ' '.join(s.replace('=', ' = ').split()).lower()
    w = s.split()[:2]; w[0] = 'object' if w[0].lower() in ('childobject', 'objectreskin') else w[0]
    return ' '.join(w).lower()
def parse(data):
    # segments: ['raw', text] or ['block', key, norm, text]; #define is a one-line block, #include stays raw.
    # A block ends at an End in column 0, as iniblocks.blocks() reads it, with two repairs for files the game's depth-counting reader accepts:
    # indented lines after that End belong to the block (a module End typed in column 0, 2.02's mordorfighter.ini), and a column-0 block start
    # after an End starts a new block (an object End typed indented).
    segs, cur, key, norm = [], [], None, []
    for raw in data.decode('latin-1').splitlines(keepends=True):
        s = strip(raw); sl = s.lower()
        if key is None:
            if sl.startswith('#define'):
                p = s.split(None, 2); segs.append(['block', ('#define ' + (p[1] if len(p) > 1 else '')).lower(), sl, raw]); continue
            opens = '=' not in s and s.split()[0].lower() in TOP if s else False  # an indented block start (2.02's "\tWeapon GondorTrebuchetRockWarhead_Structural")
            if opens and raw[:1].isspace():
                key = blockkey(s); cur, norm = [raw], [sl]
                continue
            if s and (raw[:1].isspace() or sl == 'end') and not sl.startswith('#include'):
                i = len(segs) - 1
                while i >= 0 and segs[i][0] == 'raw' and not strip(segs[i][1]): i -= 1
                if i >= 0 and segs[i][0] == 'block' and not segs[i][1].startswith('#define'):
                    b = segs[i]; key, norm = b[1], b[2].split('\n'); cur = [b[3]] + [x[1] for x in segs[i + 1:]]; del segs[i:]
                    cur.append(raw); norm.append(sl)
                    if sl == 'end' and not raw[:1].isspace(): segs.append(['block', key, '\n'.join(norm), ''.join(cur)]); key = None
                    continue
            if not s or sl.startswith('#include') or raw[:1].isspace() or sl == 'end':
                segs.append(['raw', raw]); continue
            key = blockkey(s); cur, norm = [raw], [sl]
            continue
        if s and not raw[:1].isspace() and '=' not in s and s.split()[0].lower() in TOP and norm and norm[-1] == 'end':
            segs.append(['block', key, '\n'.join(norm), ''.join(cur)])
            key = blockkey(s); cur, norm = [raw], [sl]
            continue
        cur.append(raw)
        if s: norm.append(sl)
        if sl == 'end' and not raw[:1].isspace():
            segs.append(['block', key, '\n'.join(norm), ''.join(cur)]); key = None
    if key: segs.append(['block', key, '\n'.join(norm), ''.join(cur)])
    assert ''.join(x[1] if x[0] == 'raw' else x[3] for x in segs) == data.decode('latin-1'), 'parse lost text'
    return segs

class Tree:
    def __init__(self, files):  # files: {path as written: bytes}
        self.path = {p.lower(): p for p in files}
        self.segs = {p.lower(): parse(b) for p, b in files.items()}
        self.blocks, self.byname = {}, collections.defaultdict(list)
        for rel, segs in self.segs.items():
            # a nameless block type repeated in a file (HouseColor) is told apart by its first field (BaseTexture = ...), not its position:
            # the two sides add entries in different places
            reps = collections.Counter(s[1] for s in segs if s[0] == 'block')
            for s in segs:
                if s[0] == 'block' and reps[s[1]] > 1 and ' ' not in s[1] and '\n' in s[2]: s[1] += ' | ' + s[2].split('\n')[1]
            n = collections.Counter()
            for s in segs:
                if s[0] != 'block': continue
                n[s[1]] += 1; bid = (rel, s[1], n[s[1]]); s.append(bid)
                self.blocks[bid] = s; self.byname[s[1]].append(bid)
    def match(self, bid):
        if bid in self.blocks: return self.blocks[bid]
        c = self.byname.get(bid[1], [])
        return self.blocks[c[0]] if len(c) == 1 else None

def rev_tree(rev):
    names = [n for n in git('ls-tree', '-r', '--name-only', rev, 'data/ini').decode().splitlines() if n.lower().endswith(INI)]
    return {n[len('data/ini/'):]: git('show', f'{rev}:{n}') for n in names}
def big_tree(path):
    f = open(path, 'rb'); f.read(8); count = struct.unpack('>I', f.read(4))[0]; f.read(4); ents, outd = [], {}
    for _ in range(count):
        off, size = struct.unpack('>II', f.read(8)); name = b''
        while (c := f.read(1)) != b'\0': name += c
        ents.append((off, size, name.decode('latin-1').replace('\\', '/')))
    for off, size, n in ents:
        if n.lower().startswith('data/ini/') and n.lower().endswith(INI): f.seek(off); outd[n[len('data/ini/'):]] = f.read(size)
    return outd

first = git('rev-list', '--max-parents=0', 'HEAD').decode().split()[0]
B, T = Tree(rev_tree(first)), Tree(big_tree(big))
O = Tree(rev_tree(os.environ['REBASE_OURS']))  # the mod before the rebase (rebase.sh: REBASE_OURS); HEAD holds the rebased tree since 2026-10-21
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__))); from resolve import merge3
# hand-merged blocks (resolutions/*.ini, whole blocks): each replaces the merge's choice for its name
strip_file = re.compile(r'\s*;\s*rebase202-file:\s*(\S+)')
HAND = {}; HD = os.environ.get('RESOLUTIONS', 'none')  # the folder of hand-merged blocks (rebase.sh: $OUT/resolutions); none: the plain merge
for n in (sorted(os.listdir(HD)) if HD != 'none' else []):
    where = None
    for x in parse(open(os.path.join(HD, n), 'rb').read()):
        # a "; rebase202-file: <path>" line before a block limits it to that file (a name can live in two files: LegolasKnifeModeMS)
        if x[0] == 'raw' and strip_file.match(x[1]): where = strip_file.match(x[1]).group(1).lower(); continue
        if x[0] == 'block': k = (where, x[1]); assert k not in HAND, k; HAND[k] = x[3]; where = None

# names only the mod defines (its added blocks): a v8.4 block naming one carries a first-commit edit
modonly = {bid[1].split()[-1] for bid in O.blocks if B.match(bid) is None and T.match(bid) is None}
# the first commit's own names: its H_* macros and Upgrade_New* upgrades (in the base, never in v9.8.0) are the mod's too
modonly |= {bid[1].split()[-1] for bid in B.blocks if T.match(bid) is None and re.match(r'(#define h_|upgrade upgrade_new)', bid[1])}
# and the first commit's blocks v9.8.0 never had that the mod went on changing (its Gondolin tower and its button, the Noldor archers ...)
modonly |= {bid[1].split()[-1] for bid, b in B.blocks.items() if T.match(bid) is None and O.match(bid) is not None and O.match(bid)[2] != b[2]}
modonly = {m for m in modonly if len(m) > 3}
modrx = re.compile(r'\b(' + '|'.join(map(re.escape, sorted(modonly, key=len, reverse=True))) + r')\b', re.I)

# held blocks reviewed as plain 2.02 changes (no edit of the mod's in the v8.4 version), taken from v9.8.0:
# the expansions' parents, which v9.8.0's ...Custom children need (they remove ModuleTag_SpawnRefundObject, which only v9.8.0's parent has)
TAKE = {'object elvenfloodgateexpansion', 'object elvenvigilantentexpansion'}
review = []  # conflicts and held blocks with their three versions (review.json)
report = collections.defaultdict(list); used_theirs = set(); used_base = set(); placed = {}; kept = set()  # placed: theirs bid -> (out file, ours bid)
def decide(rel, bid, o):
    b, t = B.match(bid), T.match(bid)
    if b: used_base.add(b[4])
    if t: used_theirs.add(t[4]); placed[t[4]] = (rel, bid)
    name = bid[1]
    h = HAND.get((rel, name), HAND.get((None, name)))
    if h is not None: report['hand-merged (resolutions/)'].append(name); return h
    if b is None and t is None: report['ours added'].append(name); return o[3]
    if b is None: report['both added same' if o[2] == t[2] else 'CONFLICT both added (kept ours)'].append(name); return o[3]
    if t is None:
        # not in v9.8.0: 2.02 removed it after v8.4, or the first commit added it (the H_* tables); the base cannot tell, so it stays
        if o[2] == b[2]: report['KEPT: not in v9.8.0 (2.02 removed it, or a first-commit addition)'].append(name); kept.add(bid); return o[3]
        report['CONFLICT ours changed, v9.8.0 removed (kept ours)'].append(name); review.append(dict(kind='ours changed, v9.8.0 removed', name=name, file=rel, base=b[3], ours=o[3], theirs=None)); return o[3]
    if o[2] == b[2]:
        if t[2] == b[2]: return o[3]
        if name in TAKE: report['taken from v9.8.0 by review'].append(name); return t[3]
        if ELVEN.search(name) or (modrx.search(b[2]) and not modrx.search(t[2])):
            report['HELD: v9.8.0 changed it, may hold a first-commit edit (kept ours)'].append(name); review.append(dict(kind='held', name=name, file=rel, base=b[3], ours=o[3], theirs=t[3])); return o[3]
        report['taken from v9.8.0'].append(name); return t[3]
    if t[2] == b[2]: report['ours changed'].append(name); return o[3]
    if t[2] == o[2]: report['both changed same'].append(name); return o[3]
    text, spots = merge3(b[3], o[3], t[3], modrx)
    open_ = any(x['how'].startswith('REVIEW') for x in spots)
    report['CONFLICT both changed, a spot kept ours (review)' if open_ else 'both changed, merged by line'].append(name)
    review.append(dict(kind='both changed', name=name, file=rel, base=b[3], ours=o[3], theirs=t[3], merged=text, spots=spots)); return text

outfiles = {}  # rel -> [[ours bid or None, text]]
for rel, segs in O.segs.items():
    outfiles[rel] = [[None, s[1]] if s[0] == 'raw' else [s[4], decide(rel, s[4], s)] for s in segs]
# blocks the mod removed stay removed; a v9.8.0 change to one is listed
for bid, b in B.blocks.items():
    if bid in used_base or O.match(bid): continue
    t = T.match(bid)
    if t: used_theirs.add(t[4]); report['ours removed' + ('' if t[2] == b[2] else ', v9.8.0 changed it (CONFLICT, stays removed)')].append(bid[1])
# v9.8.0's blocks nobody placed: a new one (or #include) goes into the same file right after the block v9.8.0 has before it (names are defined
# before use), at the top when none; a new file comes whole
fix = lambda t: t if t.endswith('\n') else t + '\r\n'
for rel, segs in T.segs.items():
    if rel in outfiles:
        have = {strip(x).lower() for _, x in outfiles[rel] if x and strip(x).lower().startswith('#include')}
        anchor, after = None, collections.defaultdict(list)
        for s in segs:
            if s[0] == 'raw':
                if strip(s[1]).lower().startswith('#include') and strip(s[1]).lower() not in have: after[anchor].append(fix(s[1])); report['v9.8.0 #include added'].append(rel)
                continue
            if s[4] in placed:
                if placed[s[4]][0] == rel: anchor = placed[s[4]][1]
                continue
            if s[4] in used_theirs or s[4] in B.blocks: continue  # the mod removed it (same file only: a fragment .inc reuses names)
            after[anchor].append(fix(s[3])); report['v9.8.0 added'].append(s[1])
        merged = [[None, x] for x in after[None]]
        for e in outfiles[rel]:
            merged.append(e)
            if e[0] in after and e[0] is not None: merged += [[None, x] for x in after[e[0]]]
        outfiles[rel] = merged
    else:
        body = []
        for s in segs:
            if s[0] == 'raw': body.append([None, s[1]]); continue
            if s[4] in used_theirs or s[4] in B.blocks: continue  # the mod removed it (same file only: a fragment .inc reuses names)
            body.append([None, s[3]]); report['v9.8.0 added'].append(s[1])
        outfiles[rel] = body; report['v9.8.0 new file'].append(T.path[rel])

# a kept v8.4 block of a kind only INI names (an upgrade, a button, a weapon, an object: the mod ships no maps) that no other block reaches by
# name goes: the upgrade mask holds 1152 (RW 0x8D2835), and v9.8.0's 1,014 plus the mod's own leave no room for the v8.4 systems 2.02
# dropped, which name only each other (Angmar's basic training tiers). Reached = named, comments aside, by a block that is not kept, or by a
# kept block that is reached.
# ponytail: sciences stay (Lua and map scripts grant them); names in map scripts or Lua are not searched
PRUNE = {'upgrade', 'commandbutton', 'commandset', 'modifierlist', 'weapon', 'armor', 'objectcreationlist', 'fxlist', 'specialpower',
         'experiencelevel', '#define', 'object'}
words = lambda t: set(re.findall(r'[a-z0-9_]+', '\n'.join(strip(l) for l in t.splitlines()).lower()))
cand = {}  # name -> [entry, its words]
reached = set()
for parts in outfiles.values():
    for e in parts:
        if not e[1]: continue
        if e[0] in kept and e[0][1].split()[0] in PRUNE: cand[e[0][1].split()[-1]] = [e, words(e[1])]
        else: reached |= words(e[1])  # every other block, v9.8.0's added ones included (raw comment lines give no words)
todo = [n for n in cand if n in reached]; live = set(todo)
while todo:
    for w in cand[todo.pop()][1]:
        if w in cand and w not in live: live.add(w); todo.append(w)
for n, (e, _) in cand.items():
    if n not in live: report['dropped: kept, nothing names it'].append(e[0][1]); e[1] = None
report['KEPT: not in v9.8.0 (2.02 removed it, or a first-commit addition)'] = [n for n in report['KEPT: not in v9.8.0 (2.02 removed it, or a first-commit addition)'] if n not in set(report['dropped: kept, nothing names it'])]

for rel, parts in outfiles.items():
    path = O.path.get(rel) or T.path[rel]
    dst = os.path.join(out, 'data/ini', path); os.makedirs(os.path.dirname(dst), exist_ok=True)
    texts = [t for _, t in parts if t]
    text = ''.join(fix(t) if i < len(texts) - 1 else t for i, t in enumerate(texts))  # the mod's last End may lack a newline
    open(dst, 'wb').write(text.replace('\r\n', '\n').encode('latin-1'))  # the mod's files are LF, v9.8.0's CRLF
json.dump(report, open(os.path.join(out, 'merge-report.json'), 'w'), indent=0)
json.dump(review, open(os.path.join(out, 'review.json'), 'w'), indent=0)
open(os.path.join(out, 'modonly.txt'), 'w').write('\n'.join(sorted(modonly)) + '\n')  # the mod's own names, for keepnames.py
for k in sorted(report, key=lambda k: -len(report[k])): print(f'{len(report[k]):6}  {k}')
print('files written:', len(outfiles))
