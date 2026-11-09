#!/bin/zsh
# Builds the folder OpenBFME loads as the mod (-mod / OPENBFME_MOD; openbfme-godot/docs/MODS.md) and prints its path: the game files only,
# art/, data/ and bases/, with apt/'s menus at the top (the game opens a menu by its bare name, SpellStoreHighElves.apt, as retail's apt\*.big
# hold them). OpenBFME fingerprints every file of a mod folder, so the repository itself (.git, tools, the Windows builder) is not one.
# The files are APFS clones (cp -c: no data copied) with their times kept (-p: the mount's md5 cache stays valid), rebuilt on every run.
set -e
mod="${0:A:h:h}"   # highelves (this file is highelves/openbfme/modfolder.sh)
out="$mod/openbfme/build/highelves"
rm -rf "$out"
mkdir -p "$out"
cp -cpR "$mod/art" "$mod/data" "$mod/bases" "$out/"
cp -cpR "$mod/apt/" "$out/"
# Map fixes only, not the mod's whole maps/ (its 203 map folders are not loaded by OpenBFME): 2.02's Southfarthing map.ini, corrected
# (a loose file in the mod folder wins over the patch archive; docs/MODS.md "Which file wins")
mkdir -p "$out/maps"
cp -cpR "$mod/maps/map mp southfarthing" "$out/maps/"
print -r -- "$out"
