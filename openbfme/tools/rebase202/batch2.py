import sys, json, re, os
# usage: batch2.py <review.json> <resolutions dir> : batch 2, approved 2026-10-21; runs after batch1.py and edits two of its drafts.
#   Haldir: the rest of 2.02's Haldir changes into ElvenHaldirInterface (it still had v8.4's values for all of them); the mod's
#   SpellBookHighElvenGifts stays, SpecialEnemySenseUpdate stays out (OpenBFME lacks it); respawn: 2.02's per-level table at 2.02's speed
#   (Haldir never used the mod's H_HERO_RESPAWNTIME). Statue leadership: DAMAGE_MULT 125%, 2.02's 25% read as a slip (only the statue and
#   a handicap list use 25% in v9.8.0; its leadership value is 125%).
# The 17 blocks the mod changed and v9.8.0 lacks are the mod's own first-commit content: the merge keeps them, nothing to do here.
R = json.load(open(sys.argv[1])); D = sys.argv[2]

def edit(text, rx, new, n=1):
    out, k = re.subn(rx, new, text, flags=re.M)
    assert k == n, (rx, k); return out

p = os.path.join(D, 'haldir.ini'); h = open(p, encoding='latin-1').read()
# the golden arrow and leadership unlock at levels 8 and 5 (the mod's hero levels grant Upgrade_HaldirGoldenArrow / Leadership at 8 and 5 too)
h = edit(h, r'(SpecialPowerTemplate\s*=\s*SpecialAbilityHaldirGoldenArrow\s*\n\s*TriggeredBy\s*=\s*)Upgrade_HaldirGoldenArrow', r'\1Upgrade_ObjectLevel8 ; 2.02 v9.8.0: Upgrade_HaldirGoldenArrow')
h = edit(h, r'(TriggeredBy\s*=\s*)Upgrade_HaldirLeadership', r'\1Upgrade_ObjectLevel5 ; 2.02 v9.8.0: Upgrade_HaldirLeadership', 2)
h = edit(h, r'^(\s*Behavior\s*=\s*WeaponFireSpecialAbilityUpdate\s+ModuleTag_HaldirGoldenArrowWeaponFireUpdate[^\n]*\n)',
         r'\1\t\tTriggerAttributeModifier = Rider1Tracker ; 2.02 v9.8.0\n\t\tAttributeModifierDuration = 2000\n')
h = edit(h, r'^(\s*MustFinishAbility\s*=\s*Yes[^\n]*\n)(\s*SpecialWeapon\s*=\s*HaldirGoldenArrow)', r'\1\t\tApproachRequiresLOS = No ; 2.02 v9.8.0\n\2')
h = edit(h, r'(PathfindDiameter\s*=\s*)40\.0', r'\1HERO_PATHFIND_DIAMETER ; 2.02 v9.8.0: 40.0')
h = edit(h, r'^(\s*#include "\.\.\\\.\.\\\.\.\\includes\\StandardUnitEvaEvents\.inc"[^\n]*\n)', r'\1\t#include "..\\..\\..\\includes\\customherostuff.inc" ; 2.02 v9.8.0\n')
h = edit(h, r'(AILuaEventsList\s*=\s*)LegolasFunctions', r'\1HaldirFunctions ; 2.02 v9.8.0: LegolasFunctions')
h = edit(h, r'(CommandButtonName\s*=\s*)Command_AttackMove(\s*;;,;; Command_SetStanceAggressive)', r'\1Command_SetStanceAggressive ; 2.02 v9.8.0\2')
# locomotors: the hero locomotor and speeds; 2.02 drops the panic and scared sets
h = edit(h, r'(Locomotor\s*=\s*)HumanLocomotor(\s*\n\s*Condition\s*=\s*SET_NORMAL\s*\n\s*Speed\s*=\s*)NORMAL_ELVEN_FAST_MEMBER_SPEED',
         r'\1HeroHumanLocomotor ; 2.02 v9.8.0\2NORMAL_GOOD_FAST_HERO_SPEED')
h = edit(h, r'(Condition\s*=\s*SET_WANDER\s*\n\s*Speed\s*=\s*)NORMAL_GOOD_FAST_MEMBER_SPEED', r'\1NORMAL_GOOD_FAST_HERO_SPEED ; 2.02 v9.8.0')
h = edit(h, r'^\s*LocomotorSet\s*\n\s*Locomotor\s*=\s*Human(Panic|Scared)Locomotor\s*\n\s*Condition\s*=\s*SET_(PANIC|SCARED)\s*\n[^\n]*\n\s*End[^\n]*\n', '', 2)
# respawn: 2.02's per-level table, as 2.02 wrote it
theirs = [r for r in R if r['name'] == 'object elvenhaldir'][0]['theirs'].replace('\r\n', '\n')
table = ''.join(l + '\n' for l in theirs.split('\n') if re.match(r'\s*(RespawnRules|RespawnEntry)\s*=', l))
assert table.count('RespawnEntry') == 9, table.count('RespawnEntry')
h = edit(h, r'^\s*RespawnRules\s*=\s*AutoSpawn:No\s+Cost:#DIVIDE\( #MULTIPLY\( HALDIR_BUILDCOST HERO_REVIVE_SCALAR_TIER_2 \)[^\n]*\n', table.replace('\\', '\\\\'))
open(p, 'w', encoding='latin-1').write(h)
print('haldir: 2.02 changes ported')

p = os.path.join(D, 'statue.ini'); s = open(p, encoding='latin-1').read()
s = edit(s, r'DAMAGE_MULT 25% ;,;150%', 'DAMAGE_MULT 125% ; 2.02 v9.8.0: 25% ;,;150%')
open(p, 'w', encoding='latin-1').write(s)
print('statue: DAMAGE_MULT 125%')
