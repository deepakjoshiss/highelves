#!/bin/zsh
# Double-click to open the OpenBFME model viewer with the High Elves mod mounted (as play.command): every object's model with its states and
# animations, played by the game's own draw runtime. Extra arguments go to the viewer (godot/scripts/model_viewer.gd), e.g. --object=MirkwoodTauriel.
set -e
mod="${0:A:h:h}"   # highelves (this file is highelves/openbfme/viewer.command)
root="${mod:h}"
game="$root/openbfme-godot"
export PATH="/opt/homebrew/bin:$PATH"                        # cmake and ninja (a Finder launch has a short PATH)
export DEVELOPER_DIR=/Library/Developer/CommandLineTools     # Xcode's linker cannot read the macOS 27 SDK (DJ-DEV.md)
cmake --build "$game/engine/build" --target openbfme
export OPENBFME_PATCH_DIR="$HOME/Games/BFME/Patch202" OPENBFME_MOD_DIR="$mod" ROTWK_INSTALL="$HOME/Games/BFME/RotWK" BFME2_INSTALL="$HOME/Games/BFME/BFME2"
exec "$root/godot-4.7.2/Godot.app/Contents/MacOS/Godot" --path "$game/godot" res://scenes/model_viewer.tscn -- "$@"
