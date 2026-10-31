#!/bin/zsh
# Double-click to play vanilla RotWK 2.01: play.command's start (it rebuilds the game's library, --no-intro: straight to the main menu) without the
# unofficial 2.02 (--mod-install) and without the High Elves mod (-mod). Only those two bring them in, as flags or as OPENBFME_MOD_INSTALL /
# OPENBFME_MOD, so both are removed here even when the shell that started this has them.
set -e
mod="${0:A:h:h}"   # highelves (this file is highelves/openbfme/play-vanilla.command)
root="${mod:h}"
game="$root/openbfme-godot"
export PATH="/opt/homebrew/bin:$PATH"                        # cmake and ninja (a Finder launch has a short PATH)
export DEVELOPER_DIR=/Library/Developer/CommandLineTools     # Xcode's linker cannot read the macOS 27 SDK (DJ-DEV.md)
cmake --build "$game/engine/build" --target openbfme
export ROTWK_INSTALL="$HOME/Games/BFME/RotWK" BFME2_INSTALL="$HOME/Games/BFME/BFME2"
exec env -u OPENBFME_MOD -u OPENBFME_MOD_INSTALL "$root/godot-4.7.2/Godot.app/Contents/MacOS/Godot" --path "$game/godot" -- --no-intro
