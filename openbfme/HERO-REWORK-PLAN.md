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
| Levels | 25. The High Elves heroes already went to 25 through a table shared by six heroes (`HighElvesHeroLevel11-25`); each reworked hero gets its own levels 2-25 and leaves that table. |
| HP per level | +60, flat |
| Damage per level | The same each level (`HEReworkHeroLevelN`): **+1.7%** damage (`DAMAGE_MULT`, `SPELL_DAMAGE` for magic) and **+2 flat** (`DAMAGE_ADD`), which only the bow's arrows take: powers and item blocks say `AcceptDamageAdd = No`. Level 25: powers x1.50, Thranduil's arrow (120 + 48) x 1.499 = 252 (210%). The flat bonus is added before the percentage, so it grows with it. |
| Weapon upgrades | split shot, splash, extra damage blocks come from **items only**, never from levels |
| Item tiers | Thranduil's (Deepak, 2026-11-10): tier 1 200-300, tier 2 500-1000, tier 3 1000-2500; about 20,000 for a whole tree; each higher item requires the one before; tiers add up |
| XP curve | `H_RW_HERO_LVLn_EXP_NEEDED`, the same for every reworked hero: 145 to level 2, each next level 25 more up to level 10, then 47 more a level: level 5 at 730, 10 at 2,205, 15 at 4,635, 20 at 8,240, 25 at 13,020. Killing the hero awards 2.02's factor continued (+10% a level). |
| Items vs heroes | items are player upgrades, so they survive death and revival |

## 3. The Hero Armory (overlay)

An OpenBFME overlay (dj-dev, `godot/scripts/armory_overlay.gd`; engine row `OpenBFMEArmory = <hero> <CommandSet>` in
`data/ini/openbfme.ini`) opens from a gold button above the Palantir's Powers button: the heroes on the left (portrait,
level, items owned, a dot per tier), the chosen hero's lines (tier I -> II -> III, what each line gives now), the chosen
item's details with Research / Cancel, a big Close at the bottom left. Each hero's items are the PLAYER_UPGRADE buttons
of `HEArmory<Hero>CommandSet` (no object shows these sets); the lines follow the `NeededUpgrade` chains; an item's effect
line is its tooltip's middle line, so tooltips keep the "Name \n effect \n Cost: N" form.

No building takes part: each hero has a research queue of his own, kept by the game (MSG_OPENBFME_ARMORY): paid when
queued, refunded when cancelled, granted at the end of its research time (10 s); one item at a time per hero, the heroes
in parallel, usable from the game start; nothing waits behind the citadel's upgrades or recruits. The fortress ring is the
original game's again (the prototype pages of 20a50a0 are removed).

Pending for the Armory: final icons; the computer player does not use it; a real multiplayer check; Legolas's and
Elrond's items.

## 4. Thranduil (decided)

**Built (pass 1, in game by demo; Deepak's check pending).** Start: 800 cost, 1100 HP, arrow 120 (before: 3000, 2000 HP,
arrow 200). His bow keeps its range (420), 1 shot/s and draw. The old level-3 extra hit, level-7 splash + knockback and
level-10 magic splash are **removed** (they become items); his bow has its own warhead. Move Unseen, Wild Walk, the hidden
Elf Cloak, the automatic Deadeye and the melee switch are removed.

**Levels**

| Level | Unlock |
|---|---|
| 1 | **Rampage** tier 1 (replaces the dead Elf Cloak button) |
| 3 | **Call of the Woodland Realm**: 5 Mirkwood archers (half battalion) for **40 s**, 90 s recharge |
| 5 | **Pinning Shot**: pins a hero or monster 3 s (`ParalyzeNugget`), 300 damage, 60 s |
| 8 | **Elvenking's Command** (passive): every Mirkwood archer on the map +10% damage, +10% range |
| 10 | Rampage tier 2; **Thorn of Vengeance**: 1500 hero + 600 magic + a 600 magic burst (radius 60), his bow's range (420), 120 s |
| 15 | The summon grows to **10 archers** |
| 18 | Elvenking's Command tier 2: +15% / +15% (replaces tier 1) |
| 20 | Rampage tier 3 |
| 25 | **Rampage permanent (passive)**, **Thorn recharge 60 s** |

**Rampage**

- Duration 8 / 14 / 20 s (tiers at levels 1 / 10 / 20), recharge **60 s**, cast by hand.
- **Measured 2026-11-10 (single troll, attack order or self-picked): every 4th logic frame (x1.25)**, not the 3rd measured
  before the horde-chain change (x1.67). Probably the same missing frame as the horde case below; open.
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
- The engine row `OpenBFMEFireWaitsForReload` (see 7) lets the fast bow fire without a per-shot wind-up (the wind-up version
  animated badly: wind-up after each shot, very brief firing).

**Armory** (prices and effects set by Deepak 2026-11-10; placeholder icons, 10 s research; each tier requires the one
before and adds to it; the values are the totals; the whole tree 19,900)

| Line | Tier 1 | Tier 2 | Tier 3 |
|---|---|---|---|
| Elvenking's Mail | 250: +15% armor | 700: +25%, no knockback, cannot be trampled (crush level +2) | 1500: +35%; allied soldiers within 200 +20% armor |
| Life of the Greenwood | 250: +400 HP | 700: +1000 HP, heals 20/s in battle too | 1500: +2000 HP, 50/s |
| Swift Feet | 200: +15% speed | 500: +25% speed, +10% range | 1200: **Leap**, a jump within 300, 20 s (its button is not shown yet: see below) |
| Bow of the Elvenking | 300: +10% range | 1000: 2nd arrow at another enemy, +15% range | 2500: 3rd arrow, +25% range (both bows in `OpenBFMESplitShot`) |
| Arrowheads | 300: +80 hero damage to monsters and machines, +50 to heroes | 1000: +50 more to monsters and heroes | 2500: +60 more to monsters, machines and heroes |
| Wrath of Mirkwood | 300: +40 magic per arrow | 1000: +40 siege per arrow | 2500: +80 hero damage per arrow |
| Hunter | 200: Eyes of the Greenwood: +50% shroud clearing, +25% vision | 500: Hunter's Snare: Pinning Shot 5 s, +200 damage | 1000: Hunter's Net (placeholder name): the pin takes every soldier, hero and monster within 50 of the target |

Item damage blocks take the level percentage only (`AcceptDamageAdd = No`) and sit in his warhead, so the Rampage bow has
them too; the 2nd / 3rd arrows use the same warhead (a full arrow with every item). Wrath II's throw-back is gone (its
level is siege damage now). Measured: three trolls in reach each lose 220 per volley with Bow III and Arrowheads I at
level 1 (120 + 80 x 1.25), so the extra arrows carry everything; Hunter's Net pinned the troll and 13 Uruks beside it, none
of a battalion 230 away, and without it only the troll. Earlier values (HP, the 137 -> 287 arrow) were measured at the
old numbers. Not built: Eyes of the Greenwood's stealth reveal (a disabled `StealthDetectorUpdate` has no switch in data),
Hunter's Snare's -25% recharge (recharge modifiers reach every power).

Kingship is dropped (replaced by the Damage line). Cooldown items may stay on his page (the earlier 50% level-25
cooldown idea was dropped).

How pass 1 is built: one power per tier (Rampage 1-3, the summon 5 / 10, Thorn 120 s / 60 s); the hero's
`CommandSetUpgrade`s swap in the next set at levels 10 / 15 / 20 / 25, later tiers start paused until their level (an auto
ability only fires from a button in the current set). Level 25's permanent bow is a `WeaponSetUpgrade` (`PLAYER_UPGRADE`).
Elvenking's Command is two global auras (`Range = 999999`), the second adding the difference.

Checked in demo games (evendim): the buttons per level; HP 1100 / 1220 (L3) / 2540 (L25); arrow before armour 160.6 at
level 10 and 251.8 at level 25; the auras on a Mirkwood horde (both tiers); 5 and 10 summoned archers, gone after 40 s;
Pinning Shot 436 on a troll (349 x its 125% against hero damage); Thorn kills a troll at level 10, its level-25 power hits
2810 (1500 x 1.499 x 1.25); the Rampage bow during Rampage and from level 25.

Pending for Thranduil:

- Deepak's check in game (pass 1); then pass 2: the Armory items (the Arrowhead / Damage blocks go in his warhead; extra
  arrows use their own warhead at 60%), with the two *(check)* items.
- Not checked: that a pinned target cannot move or attack (the test trolls stood still); the casts' look; the computer
  player's use of the new powers.
- Revive costs above level 10 fall back to level 1's (`RespawnEntry` stops at 10), for every High Elves hero.

## 5. Legolas (pass 1 built 2026-11-11)

An infantry killer, bow only (the knives and their toggle are gone). Everything is HEElvenLegolas's own: HERohanLegolas
keeps its powers because ElvenElrohir is a copy of it. Before: 2500 cost (inherited from HERohanLegolas), 2000 HP, bow
150, knives, Hawk Strike 1, Train Archers 3, Knife Fighter 4, Arrow Wind 7, Ram Baan and a splash / throw-back arrow at 7.

| | Built |
|---|---|
| Base | 800 cost, 1000 HP (+60 a level: 2440 at 25), arrow 90 with the shared growth, **+25% against infantry** (`HEElvenLegolasBowWarhead`) |
| Level 1 | **Fan of Arrows**: 5 full arrows (his bow's warhead) at 5 different enemies within 100 of the target (`OpenBFMESplitShot = HEElvenLegolasFanOfArrows 100 100`), 45 s |
| Level 3 | Hawk Strike (the HE weapon, 300), 30 s |
| Level 7 | **Twin Draw** (passive): a second arrow on every shot (4 with Bow II / III in pass 2) |
| Level 9 | **Piercing Arrow**: 250 hero damage in a line out to 500: 17 arrows (`LinearTarget` points along his facing, radius 15) at the fast arrow speed, each with a light silver-gold trail (`HEElvenLegolasPiercingTrail`, FaramirArrowTrail made light); soldiers it kills are thrown back; his shot plays Faramir's Wounding Arrow sound once (the power's InitiateSound); 60 s. Tried and left (2026-11-11): one visible arrow (Faramir's) plus a damage wave (`DamageSpeed` cone or strip) fired by an `ActivateModuleSpecialPower` chain; the waves work fired directly, but a chained power with a target position starts its own aim instead of firing (only target-less instant powers chain): it needs an engine opt-in |
| Level 10 | Fan of Arrows: 10 arrows |
| Level 15 | Arrow Wind: 70 arrows, 120 s (2.02: 210 s), circle 200 |
| Level 18 | Fan of Arrows: 15 arrows |
| Level 20 | Piercing Arrow II: 30 wide, 30 s (the command set swaps the button) |
| Level 25 | Arrow Wind: two volleys (140 arrows), circle 240 (20% wider) |

Checked in demo games (evendim, an Uruk battalion of 15 x 280 HP): the buttons unlock at their levels and swap at 20 / 25;
the arrow takes 90 off a troll (no infantry bonus) and 225 off an Uruk; Fan of Arrows hits 5 Uruks at level 1, kills 10
at level 10 and 15 at level 18; Twin Draw hits two Uruks a shot; Piercing Arrow kills 8 and 9 of two battalions in line
(250 and 430 away), none of one off the line or one 650 away. Arrow Wind (both levels): it lists the enemies in its circle when it starts and gives each an arrow in turn; the
volley now ends when they are dead (`CanShootEmptyGround = No`: 2.02's arrows into empty ground were the second volley's
misses), and it fires `HEElvenLegolasArrowWindBow`, 2.02's weapon with range 700: its 400 was shorter than the 450 he
starts from plus the circle, so every target beyond 400 used a shot and got no arrow. Measured: trolls 150 / 190 / 230 /
270 from the target: level 15 kills those at 150 and 190, level 25 also the one at 230, none reaches 270 (before: only
the target); 135 Uruks around the target: about 64 killed by the 70 arrows, 129 by the 140 (before: 16 and 44).
Fan of Arrows, Hawk Strike and Piercing Arrow aim 0.3 s and recover 0.15 s (halved, 2026-11-11); Hawk Strike flies at
the fast arrow speed (`HEElvenLegolasHawkStrike`; 2.02's 321). Click to hit at level 9, about 330 away: Hawk Strike 2.0 ->
1.6 s, Fan of Arrows ~1.7 -> ~1.6 s, Piercing Arrow ~1.7 -> ~1.5 s (0.2 s logic frames). Not measured: the casts' look, the AI's use of the powers. The demo's level cheat
takes at most 10 levels a step.

**Pass 2 (items):** the five shared lines (Mail, Life, Swift Feet, Bow, Arrowheads) plus his own infantry line (Orc-bane:
I +30 against infantry and cavalry, II splash 15 against infantry, III kills thrown back); numbers to decide.

## 6. Elrond

Not started: current sheet, role, levels, Armory page.

## 7. Engine work (OpenBFME, dj-dev)

| Feature | State |
|---|---|
| `OpenBFMESplitShot = <Weapon> <near> <far>`: later arrows each to a different enemy unit, radius scaled by range; none if no other enemy | done, openbfme-godot 60be0432 |
| `OpenBFMEMapOverrideReplacesModules`: 2.02 map.ini duplicate module tags replace instead of crashing (25 maps) | done, d053f758 |
| `OpenBFMEFireWaitsForReload = <Weapon>`: the fire state waits for a named weapon's reload instead of bouncing 2 frames | done (openbfme-godot 0aa9f156, 4ee91f2e); in game every 4th frame, not 3rd (open) |
| `OpenBFMEChainHordeMembers = <unit>`: an attack on a horde's soldier moves on to the next soldier in reach | done, 4ee91f2e |
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
