#!/bin/zsh
# Rebases the mod's INI tree (data/ini, committed HEAD) onto the unofficial 2.02 v9.8.0's, block by block, then checks it in OpenBFME.
#   ./rebase.sh            merge and check; the result stays in $OUT (default: $TMPDIR/highelves-rebase202)
#   ./rebase.sh --apply    the same, then copies the checked tree into data/ini (uncommitted)
# Steps: the plain merge (merge.py; its review.json lists every block left to decide), the approved hand merges (batch*.py write whole blocks
# into $OUT/resolutions), the merge again with them, the check that every H_* / Upgrade_New* name of the mod is still used (keepnames.py),
# then OpenBFME's mod check on a copy of the mod carrying the merged INI. Inspect a block's open spots with spots.py <review.json> <block name>.
T=${0:A:h}; H=${T:h:h:h}; OUT=${OUT:-${TMPDIR:-/tmp}/highelves-rebase202}
BIG=${BIG:-$HOME/Games/BFME/Patch202/__patch202.big}; ENGINE=${ENGINE:-${H:h}/openbfme-godot/engine/build}
mkdir -p $OUT/resolutions $OUT/mod/openbfme
rm -rf $OUT/m0 $OUT/m1 $OUT/resolutions/*(N) $OUT/mod/data/ini
RESOLUTIONS=none python3 -I -B $T/merge.py $H $OUT/m0 $BIG > /dev/null || exit 1
for b in $T/batch*.py(N); do python3 -I -B $b $OUT/m0/review.json $OUT/resolutions || exit 1; done
RESOLUTIONS=$OUT/resolutions python3 -I -B $T/merge.py $H $OUT/m1 $BIG || exit 1
python3 -I -B $T/keepnames.py $H $OUT/m1/data/ini $OUT/m1/modonly.txt || exit 1
python3 -I -B $T/checkheroes.py $H $OUT/m1/data/ini $BIG || exit 1  # every hero power's level unlock granted
# the mod as OpenBFME mounts it (data/ art/ apt/ and the overrides), with the merged INI
rsync -a --delete --exclude 'ini/' $H/data/ $OUT/mod/data/ && rsync -a --delete $H/art $H/apt $OUT/mod/ && rsync -a --delete $H/openbfme/overrides $OUT/mod/openbfme/
cp -R $OUT/m1/data/ini $OUT/mod/data/ini
(cd $ENGINE && ROTWK_INSTALL=$HOME/Games/BFME/RotWK BFME2_INSTALL=$HOME/Games/BFME/BFME2 OPENBFME_PATCH_CHECK_DIR=${BIG:h} \
  OPENBFME_MOD_CHECK_DIR=$OUT/mod ./openbfme_tests -tc="mod retail*" -s > $OUT/check.log 2>&1); rc=$?
echo "mod check: exit $rc, load errors $(grep -c 'load error' $OUT/check.log) (log: $OUT/check.log)"; grep -E "templates,|skirmish:" $OUT/check.log
grep "load error" $OUT/check.log | sed 's/.*load error //' | cut -c1-230 | head -25
[[ $rc == 0 && $1 == --apply ]] && rsync -a $OUT/m1/data/ini/ $H/data/ini/ && echo "applied to $H/data/ini"
exit $rc
