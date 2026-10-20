#!/bin/zsh
# Double-click to play OpenBFME with the High Elves mod: rebuilds the game's library from ../openbfme-godot when its sources changed (a few seconds
# otherwise), then starts the game. The layout is ~/work/apps/bfme/{highelves,openbfme-godot,godot-4.7.2} (openbfme-godot/docs/DJ-DEV.md).
set -e
mod="${0:A:h:h}"   # highelves (this file is highelves/openbfme/play.command)
root="${mod:h}"
game="$root/openbfme-godot"
export PATH="/opt/homebrew/bin:$PATH"                        # cmake and ninja (a Finder launch has a short PATH)
export DEVELOPER_DIR=/Library/Developer/CommandLineTools     # Xcode's linker cannot read the macOS 27 SDK (DJ-DEV.md)
cmake --build "$game/engine/build" --target openbfme
export OPENBFME_MOD_DIR="$mod" ROTWK_INSTALL="$HOME/Games/BFME/RotWK" BFME2_INSTALL="$HOME/Games/BFME/BFME2"
exec "$root/godot-4.7.2/Godot.app/Contents/MacOS/Godot" --path "$game/godot"
