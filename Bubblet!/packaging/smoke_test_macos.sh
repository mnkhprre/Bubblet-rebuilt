#!/usr/bin/env bash
# Start a built Bubblet.app the way Finder does (through launcher.sh) and
# check that the game really got past SDL and game initialisation.
#
# A process that merely exists is not enough: when a library fails to load,
# sdl2-compat shows a "Fatal error" dialog and the process stays alive
# behind it. The game prints "[UPDATE] Checking for updates" only after
# HAL_Init() and Game_Init() succeed, so that line is the success signal.
#
# To mimic a Mac without Homebrew, CI runs "brew unlink sdl3" first, so a
# bare "libSDL3.dylib" can't be found in /usr/local/lib (DYLD_* variables
# can't be used for this: macOS strips them when running system binaries).
# Usage: packaging/smoke_test_macos.sh <Bubblet.app>
set -euo pipefail

APP="${1:?usage: smoke_test_macos.sh <Bubblet.app>}"
LOG="$(mktemp)"

# script(1) gives the game a terminal, so its printf output is line-buffered.
SDL2COMPAT_DEBUG_LOGGING=1 \
  script -q "$LOG" "$APP/Contents/MacOS/launcher.sh" >/dev/null 2>&1 &
PID=$!

ok=0
for _ in $(seq 1 30); do
  if grep -q "Checking for updates" "$LOG"; then ok=1; break; fi
  if grep -qi "Failed loading SDL3\|Fatal error" "$LOG"; then break; fi
  sleep 1
done

pkill -x bubblet_mac || true
kill "$PID" 2>/dev/null || true
echo "----- game output -----"
cat "$LOG"
echo "-----------------------"

if [ "$ok" != 1 ]; then
  echo "ERROR: Bubblet did not finish starting up" >&2
  exit 1
fi
echo "Bubblet started successfully."
