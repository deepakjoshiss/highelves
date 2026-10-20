import sys, os, re, difflib
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from iniblocks import base_reader
# usage: gen_cah_stats.py rotwk bfme2 rpol bpol mod out   (writes the override file; reads the game archives and the mod)
rotwk, bfme2, rpol, bpol, mod, out = sys.argv[1:7]
read = base_reader(rotwk, bfme2, rpol, bpol)
def text(b): return b.decode('latin-1').replace('\r\n', '\n')
DEF = re.compile(r'^\s*#define\s+(\w+)[ \t]+([^\n]*)$', re.M | re.I)
def clean(v): return re.split(r'\s*(;|//)', v)[0].strip()
def defs(t): return {m.group(1).upper(): clean(m.group(2)) for m in DEF.finditer(t)}
MODULE = re.compile(r'^\s*(Behavior|Draw|Body|ClientUpdate|ClientBehavior|ArmorSet|WeaponSet|LocomotorSet)\b', re.I)
KEYWORDS = {'object', 'childobject', 'objectreskin', 'weapon', 'specialpower', 'modifierlist', 'experiencelevel', 'upgrade', 'commandbutton',
            'commandset', 'armor', 'locomotor', 'fxlist', 'fxparticlesystem', 'objectcreationlist', 'science', 'audioevent', 'multisound',
            'mappedimage', 'crowdresponse', 'emotionnugget', 'awardsystem', 'damagefx', 'createaherosystem'}
def blocks_of(t):
    """top-level blocks: a column-0 header (a block keyword and a name) up to the last column-0 End before the next header; nested Ends
    and #include lines (whose fragments carry their own Ends) cannot cut a block short"""
    lines = t.split('\n')
    def header(raw):
        s = re.sub(r'(;|//).*', '', raw).strip()
        return not raw[:1].isspace() and len(s.split()) >= 2 and '=' not in s and s.split()[0].lower() in KEYWORDS
    heads = [i for i, raw in enumerate(lines) if header(raw)] + [len(lines)]
    out = []
    for a, b in zip(heads, heads[1:]):
        last_end = max((i for i in range(a + 1, b) if re.sub(r'(;|//).*', '', lines[i]).strip().lower() == 'end'), default=None)
        if last_end is None: raise SystemExit('no column-0 End for ' + lines[a])
        s = re.sub(r'(;|//).*', '', lines[a]).strip().split()
        out.append((s[0], s[1], '\n'.join(lines[a:last_end + 1])))
    return out
base_g = defs(text(read('data/ini/createaherogamedata.inc')))
mod_g = defs(text(open(os.path.join(mod, 'data/ini/createaherogamedata.inc'), 'rb').read()))
changed = {k: v for k, v in mod_g.items() if base_g.get(k) != v}
# the mod's design fragment and the mod-only macros it needs
FRAGMENTS_FROM_MOD = {f: text(open(os.path.join(mod, 'data/ini/object/createahero', f), 'rb').read()) for f in ('createaherodesign.inc', 'createaherorespawn.inc', 'createaheroweaponupgrades.inc')}
# the weapon upgrades: the mod's is 2.01's with WS_38's bow swapped for its super bow (10-createahero-archer.ini); anything else would be 2.02 content
_wu = [l for l in difflib.unified_diff(text(read('data/ini/object/createahero/createaheroweaponupgrades.inc')).split('\n'), FRAGMENTS_FROM_MOD['createaheroweaponupgrades.inc'].split('\n'), lineterm='', n=0)
       if l[:1] in '+-' and l[:3] not in ('+++', '---')]
assert _wu == ['-\tWeapon\t\t\t  =\tPRIMARY CreateAHeroBasicRangedWeapon', '+\tWeapon\t\t\t  =\tPRIMARY CreateAHeroSuperRangedWeapon'], _wu
design = '\n'.join(FRAGMENTS_FROM_MOD.values())  # every mod fragment, for the macro scan
base_all = {}
for f in ('data/ini/gamedata.ini', 'data/ini/createaherogamedata.inc'):
    base_all.update(defs(text(read(f) or b'')))
mod_water = defs(text(open(os.path.join(mod, 'data/ini/default/water.ini'), 'rb').read()))
mod_gd = defs(text(open(os.path.join(mod, 'data/ini/gamedata.ini'), 'rb').read()))
extra = {}
for tok in set(re.findall(r'\b[A-Z][A-Z0-9_]{4,}\b', re.sub(r'(;|//)[^\n]*', '', design))):
    v = mod_water.get(tok) or mod_gd.get(tok) or mod_g.get(tok)
    if v is not None and base_all.get(tok) != v and tok not in changed: extra[tok] = v
pat = re.compile(r'\b(' + '|'.join(sorted(changed, key=len, reverse=True)) + r')\b')
OWNED = {('weapon', 'createaherobasicrangedweapon'), ('weapon', 'createaherobasicrangedwarhead')}  # 10-createahero-archer.ini
sources = ['data/ini/attributemodifier.ini', 'data/ini/createaherospecialpowers.ini', 'data/ini/experiencelevels_createahero.inc',
           'data/ini/weapon.ini', 'data/ini/object/createahero/createaheroobjects.inc']
MERGE_KINDS = {'specialpower', 'experiencelevel'}  # retail's reload refuses these: merged like a map.ini, only the lines that change
picked = []
for f in sources:
    for kind, name, body in blocks_of(text(read(f))):
        if (kind.lower(), name.lower()) in OWNED: continue
        if pat.search(re.sub(r'(;|//)[^\n]*', '', body)): picked.append((f, kind, name, body))
# the mod's own melee weapons: it moved the basic melee onto the CREATE_A_HERO_* timings and the Olog-hai onto new CREATE_A_HERO_OLOG_*
# ones (and limits the poison bonus to the Servants of Sauron class), so the constants only mean what the mod meant with its blocks
FROM_MOD = {'createaherobasicmeleeweapon', 'createaheroologhaimeleeweapon'}
mod_weapons = {n.lower(): b for k, n, b in blocks_of(text(open(os.path.join(mod, 'data/ini/weapon.ini'), 'rb').read())) if k.lower() == 'weapon' and n.lower() in FROM_MOD}
assert set(mod_weapons) == FROM_MOD, 'mod melee weapons not found'
picked = [x for x in picked if not (x[1].lower() == 'weapon' and x[2].lower() in FROM_MOD)]
picked += [('the mod: data/ini/weapon.ini', 'Weapon', n, b) for n, b in sorted(mod_weapons.items())]
# Object CreateAHero from the game's file, its includes pointed at the game's folder, the design, respawn and weapon upgrade includes replaced by the mod's fragments
cah_file = blocks_of(text(read('data/ini/object/createahero/createahero.ini')))
cah = [b for b in cah_file if b[0].lower() == 'object' and b[1].lower() == 'createahero']
# a ChildObject copies its parent when it is parsed: the mounted hero is parsed again after the new CreateAHero
children = [b for b in cah_file if b[0].lower() == 'childobject' and re.search(r'^ChildObject\s+\w+\s+CreateAHero\b', b[2], re.I)]
assert len(cah) == 1, 'Object CreateAHero not found once'
obj = cah[0][2]
def fix_include(m):
    target = m.group(1)
    if target.lower() in FRAGMENTS_FROM_MOD:
        return '; the mod\'s ' + target + ' (highelves data/ini/object/createahero):\n' + FRAGMENTS_FROM_MOD[target.lower()].strip('\n')
    return '#include "..\\Object\\CreateAHero\\' + target + '"'
obj, nincl = re.subn(r'#include\s+"([^"]+)"', fix_include, obj)
# OpenBFME's own flag (not retail, its docs/OVERRIDES.md): an idle hero answers what its bow reaches and its player sees, not only what its own vision covers
obj, nacq = re.subn(r'^(\s*AutoAcquireEnemiesWhenIdle\s*=[^\n;]*?)[ \t]*$', r'\1 OPENBFME_WEAPON_RANGE', obj, flags=re.M)
assert nacq == 1, 'Object CreateAHero: AutoAcquireEnemiesWhenIdle not found once'
with open(out, 'w', newline='\r\n') as o:
    o.write('''; OpenBFME override: the Create-a-Hero numbers from the High Elves mod (github.com/deepakjoshiss/highelves, data/ini/createaherogamedata.inc and
; data/ini/object/createahero/createaherodesign.inc), applied to the game's own blocks (docs/OVERRIDES.md, docs/HIGHELVES.md).
; Generated: every constant of createaherogamedata.inc whose mod value differs from RotWK 2.01, then every 2.01 block that uses one
; (copied unchanged: the constants make the difference), then Object CreateAHero from the game's createahero.ini with the mod's design
; and respawn fragments (build cost and time, vision, shroud clearing, bounty, crush, command points, health, respawn time) and weapon upgrades
; (2.01's with the Elven Archer's 4th bow, WS_38, firing the super bow). The archer's bow blocks are left to 10-createahero-archer.ini. Not taken from the mod: its 2.02 content (Elven gifts modifiers, per-class leadership auras, garrison rules).

''')
    o.write('; ---- the mod\'s constants ----\n')
    for k in sorted(changed): o.write(f'#define {k:45} {changed[k]}\n')
    for k in sorted(extra): o.write(f'#define {k:45} {extra[k]} ; the mod\'s, used by its design or respawn fragment\n')
    cur = None
    for f, kind, name, body in [x for x in picked if x[1].lower() not in MERGE_KINDS]:
        if f != cur: o.write(f'\n; ---- from {f} ----\n' if f.startswith('the mod') else f'\n; ---- from the game\'s {f.split("/")[-1]} ----\n'); cur = f
        o.write('\n' + body.strip('\n') + '\n')
    o.write('\n; ---- Object CreateAHero (the game\'s createahero.ini, the mod\'s design) ----\n\n' + obj.strip('\n') + '\n')
    for kind, name, body in children:
        o.write('\n; ---- ' + name + ' (the game\'s, parsed again after the new parent) ----\n\n' + re.sub(r'#include\s+"([^"]+)"', lambda m: '#include "..\\Object\\CreateAHero\\' + m.group(1) + '"', body).strip('\n') + '\n')
print(f'{len(children)} child objects; {len(changed)} constants, {len(extra)} extra ({", ".join(sorted(extra))}), {len(picked)} blocks, object with {nincl} includes rewritten')
from collections import Counter
print(Counter(k for _, k, _, _ in picked))

merge = out.replace('20-createahero-stats.ini', '21-createahero-levels-and-powers.merge.ini')
powers = [x for x in picked if x[1].lower() in MERGE_KINDS]
with open(merge, 'w', newline='\r\n') as o:
    o.write("""; OpenBFME override (map.ini merge, docs/OVERRIDES.md): the Create-a-Hero experience levels and special powers that use the High
; Elves mod's constants. Retail's reload refuses these blocks (a SpecialPower is already defined, RW 0x7B212F; an ExperienceLevel reload
; is not ported, S-632), so this file loads like a map.ini: each block is copied and only the lines below change. The constants come
; from 20-createahero-stats.ini, loaded before this file.
""")
    cur = None
    for f, kind, name, body in powers:
        if f != cur: o.write(f'\n; ---- from {f} ----\n' if f.startswith('the mod') else f'\n; ---- from the game\'s {f.split("/")[-1]} ----\n'); cur = f
        lines = body.split('\n')
        changed_lines = [l for l in lines[1:] if pat.search(re.sub(r'(;|//).*', '', l))]
        o.write('\n' + lines[0].rstrip() + '\n' + '\n'.join(changed_lines) + '\nEnd\n')
print(len(powers), 'merged blocks (levels and powers) ->', merge.split('/')[-1])
