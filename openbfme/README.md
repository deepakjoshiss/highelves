# High Elves in OpenBFME

This folder holds what OpenBFME needs to run parts of this mod on top of RotWK
2.01, and the scripts used to compare the mod with the base game. The
engine side lives in OpenBFME's `dj-dev` branch (`../openbfme-godot`):
`docs/MODS.md` (how a mod's folders load, and `data/ini/openbfme.ini`),
`docs/HIGHELVES.md` (what the mod changes and what is imported) and
`docs/DJ-DEV.md` (build, test and run on the Mac).

Run the game with the mod (its `data/`, `art/`, `apt/` (menus) and `bases/` (castle layouts) as a `-mod` folder over the unofficial 2.02 v9.8.0's archives in `~/Games/BFME/Patch202`, a mod installed into the game folder). `openbfme/modfolder.sh` builds that folder (`openbfme/build/highelves`, ignored: the game files only, the menus at its top) and prints its path; OpenBFME fingerprints every file of a mod folder, so the repository itself is not one:

```sh
cd ../openbfme-godot
OPENBFME_MOD_INSTALL=$HOME/Games/BFME/Patch202 OPENBFME_MOD="$(../highelves/openbfme/modfolder.sh)" ROTWK_INSTALL=$HOME/Games/BFME/RotWK BFME2_INSTALL=$HOME/Games/BFME/BFME2 \
  ../godot-4.7.2/Godot.app/Contents/MacOS/Godot --path godot
```

Or double-click `openbfme/play.command`: it rebuilds the game's library from
`../openbfme-godot` when its sources changed, builds the mod folder, then starts the game with the mod.

`openbfme/viewer.command` opens the model viewer the same way: every object's
model with its model and animation states, played by the game's draw runtime,
and which parts are hidden and why (`--object=MirkwoodTauriel` selects one).

## OpenBFME's rules: `data/ini/openbfme.ini`

OpenBFME reads `data/ini/openbfme.ini` after the game's INI; the original game
never opens it, so the mod's other files stay loadable by it. It holds the
`OpenBFME…` rows only (OpenBFME refuses one anywhere else): the auto-acquire
and team command point switches and the High Elves spell store menu. The
command point table (a starting base of 200, caps 1600 1400 1200 1100 1000 900
800 for 2 .. 8 players; 2.02: 100 and 1000) is in `data/ini/gamedata.ini`.

Check the mod loads without an error and starts (from `../openbfme-godot/engine/build`):

```sh
OPENBFME_MOD_CHECK_DIR="$(../../../highelves/openbfme/modfolder.sh)" OPENBFME_PATCH_CHECK_DIR=$HOME/Games/BFME/Patch202 \
  ROTWK_INSTALL=$HOME/Games/BFME/RotWK BFME2_INSTALL=$HOME/Games/BFME/BFME2 \
  ./openbfme_tests -tc="mod retail*" -s
```

## tools/

Python (run with `python3 -I`), read-only but for `vanilla202.py`, `split.py` and `hebases.py`, which write into this repo; they read the game's `.big`
archives and this repo. Most take the two install folders and the engine's
archive tables (`$P` above), which give the retail mount order.

| Script | What |
|---|---|
| `iniblocks.py` | shared helpers: BIG archive reader, the base file lookup in mount order, a block splitter |
| `bigfind.py`, `bigget.py` | list or extract files of a `.big` archive |
| `vanilla202.py` | commits a 2.02 version's `data/ini` and `data/lotr.str` to the `vanilla` branch (see below) |
| `split.py` | rewrote `data/ini` into the High Elves faction from the pre-split tree (mod commit `f792b52`), and `--check`s the result (openbfme-godot `docs/HIGHELVES.md`, "The High Elves faction") |
| `hebases.py` | writes `bases/hefortress_elves/`: 2.02's elven fortress layout building `HEElvenCitadel` (reads `Bases.big`, writes into this repo) |
| `modcompare.py` | every mod file against the base game's: identical, modified, new |
| `commitblocks.py` | each mod commit's added, changed and removed INI blocks |
| `blockdiff.py`, `linediff.py` | the changes of one mod file against the base, by block or by line (fragments) |
| `deps.py` | what a set of mod blocks needs: macros, weapons, projectiles, upgrades, base or mod-only |
| `cahmacros.py` | the changed Create-a-Hero constants and the base blocks using them |
| `gen_cah_stats.py` | wrote the former `overrides/20-…` and `21-…` (the override-era Create-a-Hero import; the overrides folder is gone, the mod's own files load) |
| `artrefs.py`, `artfeatures.py` | the models the mod's INI names: in the mod's `art/`, in 2.01, or nowhere |
| `modulecheck.py` | the module classes the mod's changes use, against OpenBFME's coverage table |
| `w3dchannels.py` | the channels an animation names twice for one bone |

### 2.02 on the `vanilla` branch

`data/ini/**` and `data/lotr.str` are 2.02 v9.8.0's (branch `vanilla`, tag
`vanilla-v9.8.0`) with the mod's edits on `master`; `git diff vanilla master -- data`
shows every change the mod makes to 2.02. Edit the files directly; the mod's elven content is the faction
`FactionHighElves` (`data/ini/object/zz_highelves/`, `data/ini/highelves/`; OpenBFME's `docs/HIGHELVES.md`, "The High Elves
faction"). A new 2.02:

```sh
python3 -I -B openbfme/tools/vanilla202.py <__patch202.big> <englishpatch202.big> <label>   # commits it to vanilla, tags vanilla-<label>
git merge vanilla                                                                           # on master; then the mod check
```

The rebase tooling of 2026-10-21 (`tools/rebase202/`, its block merge and decisions) is in the history before
its removal; OpenBFME's `docs/HIGHELVES.md` keeps its account.
