# High Elves in OpenBFME

This folder holds what OpenBFME needs to run parts of this mod on top of RotWK
2.01, and the scripts used to compare the mod with the base game. The
engine side lives in OpenBFME's `dj-dev` branch (`../openbfme-godot`):
`docs/OVERRIDES.md` (how overrides and the art folder load),
`docs/HIGHELVES.md` (what the mod changes and what is imported) and
`docs/DJ-DEV.md` (build, test and run on the Mac).

Run the game with the mod (its `data/`, `art/` and `apt/` (menus) folders over the unofficial 2.02 v9.8.0's archives in `~/Games/BFME/Patch202`, plus `openbfme/overrides/`):

```sh
cd ../openbfme-godot
OPENBFME_PATCH_DIR=$HOME/Games/BFME/Patch202 OPENBFME_MOD_DIR=$HOME/work/apps/bfme/highelves ROTWK_INSTALL=$HOME/Games/BFME/RotWK BFME2_INSTALL=$HOME/Games/BFME/BFME2 \
  ../godot-4.7.2/Godot.app/Contents/MacOS/Godot --path godot
```

Or double-click `openbfme/play.command`: it rebuilds the game's library from
`../openbfme-godot` when its sources changed, then starts the game with the mod.

## overrides/

Loaded in name order after the game's own INI files. A plain `.ini` replaces
each block it names (retail's reload); a `.merge.ini` copies the block and
changes only the lines it gives (map.ini's load).

| File | What | How it was made |
|---|---|---|
| `01-openbfme-rules.ini` | OpenBFME's rules for this mod (`GameData` `OpenBFMEAutoAcquireWithinWeaponRange = Yes`: units that auto-acquire shoot, idle or guarding, what their weapon reaches past their vision when their player sees it; `OpenBFMETeamCommandPoints = Yes`: a player's command point cap is its team's share of the game's army, at least the table's cap, at most the two-player cap, raised at every defeat) | written by hand; see OpenBFME's `docs/OVERRIDES.md` |
| `02-command-points.ini` | the command points by player count: a starting base of 200 (retail 100) and caps 1600 1400 1200 1100 1000 900 800 for 2 .. 8 players (retail 1000 875 750 675 625 575 500) | written by hand |

Check the folder loads without an error (from `../openbfme-godot/engine/build`):

```sh
OPENBFME_OVERRIDES_CHECK_DIR=$HOME/work/apps/bfme/highelves/openbfme/overrides \
  ROTWK_INSTALL=$HOME/Games/BFME/RotWK BFME2_INSTALL=$HOME/Games/BFME/BFME2 \
  ./openbfme_tests -tc="*OPENBFME_OVERRIDES_CHECK_DIR*" -s
```

## tools/

Read-only Python (run with `python3 -I`); they read the game's `.big`
archives and this repo. Most take the two install folders and the engine's
archive tables (`$P` above), which give the retail mount order.

| Script | What |
|---|---|
| `iniblocks.py` | shared helpers: BIG archive reader, the base file lookup in mount order, a block splitter |
| `bigfind.py`, `bigget.py` | list or extract files of a `.big` archive |
| `modcompare.py` | every mod file against the base game's: identical, modified, new |
| `commitblocks.py` | each mod commit's added, changed and removed INI blocks |
| `blockdiff.py`, `linediff.py` | the changes of one mod file against the base, by block or by line (fragments) |
| `deps.py` | what a set of mod blocks needs: macros, weapons, projectiles, upgrades, base or mod-only |
| `cahmacros.py` | the changed Create-a-Hero constants and the base blocks using them |
| `gen_cah_stats.py` | wrote the former `overrides/20-…` and `21-…` (the override-era Create-a-Hero import; the mod's own files load now) |
| `artrefs.py`, `artfeatures.py` | the models the mod's INI names: in the mod's `art/`, in 2.01, or nowhere |
| `modulecheck.py` | the module classes the mod's changes use, against OpenBFME's coverage table |
| `w3dchannels.py` | the channels an animation names twice for one bone |
