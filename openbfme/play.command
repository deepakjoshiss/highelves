#!/bin/zsh
# Double-click to play OpenBFME with the High Elves mod: rebuilds the game's library from ../openbfme-godot when its sources changed (a few seconds
# otherwise), then starts the game with --no-intro (no start-up movies: straight to the main menu). The layout is ~/work/apps/bfme/{highelves,openbfme-godot,godot-4.7.2} (openbfme-godot/docs/DJ-DEV.md).
set -e
mod="${0:A:h:h}"   # highelves (this file is highelves/openbfme/play.command)
root="${mod:h}"
game="$root/openbfme-godot"
export PATH="/opt/homebrew/bin:$PATH"                        # cmake and ninja (a Finder launch has a short PATH)
export DEVELOPER_DIR=/Library/Developer/CommandLineTools     # Xcode's linker cannot read the macOS 27 SDK (DJ-DEV.md)
cmake --build "$game/engine/build" --target openbfme
# the mod is built on the unofficial 2.02: its archives (~/Games/BFME/Patch202: __patch202.big, lang/englishpatch202.big, v9.8.0) give the AI
# bases, art and audio, loaded as a mod installed into the game folder (--mod-install); the mod folder modfolder.sh builds (art/, data/ with the
# whole INI tree and its OpenBFME rules in data/ini/openbfme.ini, bases/, the menus) goes over them as -mod (openbfme-godot/docs/MODS.md)
modfolder="$("$mod/openbfme/modfolder.sh")"   # its own line: set -e stops here when the build fails
export OPENBFME_MOD_INSTALL="$HOME/Games/BFME/Patch202" OPENBFME_MOD="$modfolder" ROTWK_INSTALL="$HOME/Games/BFME/RotWK" BFME2_INSTALL="$HOME/Games/BFME/BFME2"
exec "$root/godot-4.7.2/Godot.app/Contents/MacOS/Godot" --path "$game/godot" -- --no-intro
