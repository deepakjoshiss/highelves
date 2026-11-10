# High Elves hero rework and the Hero Armory: plan

Status 2026-11-10. Covers the three High Elves heroes (Legolas, Thranduil, Elrond), their 25-level progression and the
item shop on the fortress (the Hero Armory). Order of work: **Thranduil first** (build, then check in game), then Legolas,
then Elrond.

## 1. Goals

- Each hero costs **800**, keeps today's **40 command points**, starts **much weaker** (powers too) and grows over
  **25 levels** and through **items** bought in the fortress.
- Heroes stay **unique** (role, powers, signature items) with **common ground** (shared item lines, the same frame).
- Everything is mod data; an engine change only where data cannot do it, always opt-in from `data/ini/openbfme.ini`
  so retail games stay unchanged.

## 2. Shared frame (all three heroes)

| Rule | Decision |
|---|---|
| Cost / command points | 800 / 40 |
| Levels | 25 (today 10). The engine's level table has no cap. |
| HP per level | +60, flat |
| Damage per level | +2.5% of base for weapons and powers, **additive** (each level's modifier list carries the ratio, so level 25 = x1.60). *Proposed for all three; confirm.* |
| Weapon upgrades | split shot, splash, extra damage blocks come from **items only**, never from levels |
| Item tiers | tier 1 ~500-2000, tier 2 ~2500-6000, tier 3 6000+; each higher item requires the one before; tiers add up |
| XP curve | draft: levels 1-10 as today, then +500 per level (~9,500 to level 25). *Open: level 25 should stay very hard.* |
| Items vs heroes | items are player upgrades, so they survive death and revival |

## 3. The Hero Armory (fortress menu)

Built and checked in a test game (mod commit 20a50a0, PROTOTYPE): a 7th fortress ring button opens the Armory page,
one page per hero (Legolas, Thranduil, Elrond), Back on each; every page has its own 33 button slots, so items are not
limited by the fortress's command set.

How it works (the rules are retail's, as our engine ports them):

- Each button is an instant power (`PlayerUpgradeSpecialPower`) granting a hidden player upgrade: no production queue.
- Each page is a `CommandSetUpgrade` on `HEElvenCitadel`; every update re-applies held pages in module order, the last
  one wins.
- Removing a page's upgrade never removes its buttons (`resetUpgrade` clears "executed" before the removal runs), so
  **Back applies the page it returns to**.
- A module that removes its own trigger stays stuck: **every trigger is removed by another module** (opening a page
  clears the Back upgrades; Back clears the pages).
- A demo test must wait ~1 s after a button press before checking (commands run a few logic frames later).

Pending for the Armory:

- The real item buttons on each hero page (labels, icons, costs, requirements via `NeededUpgrade`).
- The computer player: it may fire these instant powers; its build lists need the items.
- Multiplayer check; Elrond's page.

## 4. Thranduil (decided)

**Start:** 1100 HP, arrow 120 (today 2000 HP, arrow 200, cost 3000). His bow keeps today's range (420), 1 shot/s and
draw. Today's level-3 extra hit, level-7 splash + knockback and level-10 magic splash are **removed** (they become items).

**Levels**

| Level | Unlock |
|---|---|
| 1 | **Rampage** tier 1 (replaces the dead Elf Cloak button) |
| 3 | **Call of the Woodland Realm**: 5 Mirkwood archers (half battalion) for **40 s**, 90 s recharge |
| 5 | **Pinning Shot**: pins a hero or monster 3 s, 300 damage, 60 s |
| 8 | **Elvenking's Command** (passive): every Mirkwood archer on the map +10% damage, +10% range |
| 10 | Rampage tier 2 |
| 15 | **Thorn of Vengeance** (2000 hero + 850 magic in radius 60, 120 s); the summon grows to **10 archers** |
| 18 | Elvenking's Command tier 2: +15% / +15% (replaces tier 1) |
| 20 | Rampage tier 3 |
| 25 | **Rampage permanent (passive)**, **Thorn recharge 60 s** |

**Rampage**

- Duration 8 / 14 / 20 s (tiers at levels 1 / 10 / 20), recharge **60 s**, cast by hand.
- Effect: a timed switch (`WeaponModeSpecialPowerUpdate`, `WEAPONSET_HERO_MODE`) to a faster copy of his bow that
  **fires every 3rd logic frame** (0.6 s reload, named in `OpenBFMEFireWaitsForReload`; about x1.67) with **no draw on
  new targets** (`PreAttackDelay = 0`, decided 2026-11-10: with a draw, each new target in a horde added 0.45 s after the
  reload and Rampage gave nothing against armies). The copy shares the normal bow's **warhead**, so item damage lives in
  one place.
- Measured (single troll): 333 damage/s while firing (x1.67), no shots during the 1.6 s cast animation.
- **Open:** against a horde Rampage gives no gain: about 1 kill per second with or without it. Each kill ends the attack and
  he takes ~1 s to shoot the next soldier. Not the bow, not the draw (0 tested), not the target-check rate
  (`MoodAttackCheckRate` 200 tested), and not wasted arrows (traced: every shot hits a different orc at full health).
  Each kill costs a fixed retarget (attack ends, next soldier, approach / aim, fire): 5 frames between shots with the
  normal bow, 6 with the Rampage bow.
- **Fix in progress (engine, uncommitted):** `OpenBFMEChainHordeMembers = <unit>` keeps the attack on the horde and
  moves to the next member when one dies (no idle, no new attack), in any stance; and a `OpenBFMEFireWaitsForReload`
  weapon fires on entering the fire step when ready. Synthetic test: a kill every 3 frames on a horde of 6 (retail:
  1 kill then idle). In game (Rampage, orc horde): **4 frames per kill, 1.25 kills/s** (was 1/s); one frame per kill
  is unexplained (not the wind-up, not arrow flight: double arrow speed changed nothing). Performance: a 100-archer vs
  30-horde battle ran as fast with the rows as without (within noise). HE Thranduil (and later Legolas) must be named
  in the chain row. The same ~1 s per volley shows with Legolas's
  split shot (3 kills per second with 3 arrows). For now Rampage is a single-target burst (heroes, monsters, buildings).
- The cast plays his 1.6 s Deadeye animation, without today's self-freeze (`NoAttackBonus`).
- Tiers: one power per tier, his button swapped by level (the Armory's command-set mechanism).
- Level 25: a `WeaponSetUpgrade` sets a **different** flag (e.g. `PLAYER_UPGRADE`) for a permanent fast bow, so an
  active Rampage ending cannot switch it off; the Rampage button becomes a passive icon.
- In progress: the engine row `OpenBFMEFireWaitsForReload` (see 7) so the fast bow reaches every 3rd frame without a
  per-shot wind-up (the wind-up version animated badly: wind-up after each shot, very brief firing).

**Armory**

| Line | Tier 1 | Tier 2 | Tier 3 |
|---|---|---|---|
| Armor | 800: +10% armor | 3500: +20%, immune to knockback and trampling | 8000: +30%, nearby troops +20% armor |
| Life | 1000: +300 HP | 3000: +600 HP, regeneration in combat | 7000: +1500 HP, strong regeneration |
| Mobility | 500: +15% speed | 2500: +20% speed, +10% range | 6000: active short teleport *(check)* |
| Bow | 500: +5% range | 3000: **2nd arrow** (split, 60% damage), 10% range total | 8000: **3rd arrow** (60%), 20% range total |
| Arrowheads | 800: +30% vs cavalry and monsters | ~3500: +50% vs machines, +15% vs monsters | ~7000: +50% vs heroes, +15% vs monsters (monsters 60% total) |
| Damage | 1500: +40 magic per arrow | 4500: +80 magic; infantry killed are thrown back (knockback 30, radius 10) | 9000: +80 magic and +80 hero damage |
| Hunter | 1200: Eyes of the Greenwood: shroud clearing + reveals stealthed enemies within 300 *(check)* | 4500: Pinning Shot 5 s, +50% damage, -25% recharge | 9000: Elvenking's Wrath: Thorn recharges when it kills a hero |

Kingship is dropped (replaced by the Damage line). Cooldown items may stay on his page (the earlier 50% level-25
cooldown idea was dropped).

Pending for Thranduil:

- Move Unseen and Wild Walk: replaced by the new powers or kept? (not decided)
- The Arrowhead / Damage lines' damage blocks go in the **shared warhead**; extra arrows use their own warhead at 60%.
- Clean-ups: the dead Elf Cloak and Rampage buttons, the automatic Deadeye, the unused melee switch
  (`DualWeaponBehavior`), the stale tooltips.
- Tests: Rampage against an orc horde (target switching), recorded close up; every power and item in a demo game;
  then Deepak's check in game.

## 5. Legolas (partly decided)

**Today:** cost 2500, 2000 HP, bow 150 (+100 vs machines from level 3, splash from level 7), knives 200 on target / 150
splash; Hawk Strike 1, Train Archers 3, Knife Fighter 4, Arrow Wind 7; a TEST split shot (2 arrows at level 3, 3 at
level 7; mod commit dc758aa) that must become an item.

**Decided:** start 1000 HP, arrow 90, knives 120; the shared growth; split and splash only from items.

**Proposed, not confirmed:** level 1 Hawk Strike, 5 Knife Fighter, 8 Train Archers, 15 Arrow Wind; levels 10 and 20 power
upgrades (Hawk Strike recharge, Arrow Wind arrows); level 25 signature (Arrow Wind fires a second volley).

**Pending:** his Armory page (the shared and archer lines plus his own lines); his level-25 signature.

## 6. Elrond

Not started: current sheet, role, levels, Armory page.

## 7. Engine work (OpenBFME, dj-dev)

| Feature | State |
|---|---|
| `OpenBFMESplitShot = <Weapon> <near> <far>`: later arrows each to a different enemy unit, radius scaled by range; none if no other enemy | done, openbfme-godot 60be0432 |
| `OpenBFMEMapOverrideReplacesModules`: 2.02 map.ini duplicate module tags replace instead of crashing (25 maps) | done, d053f758 |
| `OpenBFMEFireWaitsForReload = <Weapon>`: the fire state waits for a named weapon's reload instead of bouncing 2 frames | **in progress** (code written, test being pinned) |
| `RATE_OF_FIRE` attribute modifier | not ported (stub returns 1.0, S-320); **not** used for Rampage by decision |

Demo tooling added (committed): `alive`, `level`, `select`, `press`, `bar`. Recording: VinDesk API `record_start` /
`record_stop` (`~/work/apps/deskpad/API.md`).

## 8. Discoveries that shape the design

- Soldiers take ~200% from hero damage: one hero arrow kills basic infantry, so single-target bonuses do nothing against
  armies; army items must hit areas or other targets.
- Hero shots come in **logic-frame steps** (5 frames/s): with a one-arrow clip, reload <= 0.4 s fires every 2 frames,
  0.5-1.0 s every 5 frames (1/s). Half the reload is not twice the arrows.
- Level bonus lists stack (added, never removed); all damage bonuses multiply; armor bonuses add.
- Negative HP modifiers are ignored (only positive HEALTH applies): lower HP in the base values.
- `MaxHealthUpgrade` does not run in our engine: HP items use HEALTH modifiers.
- A damage block requiring two upgrades (item + level) relies on an inferred "all names" rule.
- Summons: `LifetimeUpdate` runs; copy retail's `..._Summoned` horde pattern (0 command points, not trainable).
- Global auras: `Range = 999999` with a template filter (the citadel's Ring of Adamant does it).
- Recharge-time modifiers apply to every power type.
- Fire-rate (`RATE_OF_FIRE`) modifiers do nothing in OpenBFME today (15 uses in the mod are inert).

## 9. Other open items

- XP curve to level 25; how the HUD draws ranks above 10 (War of the Ring clamps at 10); the level-up cheat gives at most
  10 levels at once (testing only).
- 2.02 Bywater (and the other 24 fixed maps): game start fails on a locomotor check our engine re-runs (DJ-DEV open item).
