#!/usr/bin/env bash
# Build a self-contained Bubblet.app and DMG on macOS.
# Run from the Bubblet! folder with Homebrew installed:
#   brew install sdl2 sdl2_mixer sdl2_ttf dylibbundler
# Usage: packaging/build_macos.sh <version>   -> dist/Bubblet-<version>-macOS-<arch>.dmg
set -euo pipefail

VERSION="${1:?usage: build_macos.sh <version>}"
ARCH="$(uname -m)"
BREW="$(brew --prefix)"
APP="dist/mac/Bubblet.app"
OUT="dist/Bubblet-${VERSION}-macOS-${ARCH}.dmg"

make -f Makefile.mac clean
make -f Makefile.mac \
  CFLAGS="-Wall -O2 $("$BREW/bin/sdl2-config" --cflags) -I$BREW/include -I." \
  LDFLAGS="$("$BREW/bin/sdl2-config" --libs) -L$BREW/lib -lSDL2_mixer -lSDL2_ttf -lcurl"

# Homebrew bottles target the build machine's macOS, so that is the minimum.
MIN_MACOS="$(sw_vers -productVersion | cut -d. -f1).0"

rm -rf dist/mac
mkdir -p "$APP/Contents/MacOS" "$APP/Contents/Resources" "$APP/Contents/Frameworks"
cp bubblet_mac "$APP/Contents/MacOS/"
cp -r bubblet_bmps "$APP/Contents/Resources/"
cp ./*.wav cursor.bmp bubblet.icns "$APP/Contents/Resources/"

# Copy every Homebrew dylib the game needs into the bundle and point the
# binary at them. Homebrew's SDL2 is sdl2-compat, which loads SDL3 at run
# time, so bundle SDL3 (and its own deps) explicitly as well.
dylibbundler -od -b -cd \
  -x "$APP/Contents/MacOS/bubblet_mac" \
  -d "$APP/Contents/Frameworks/" -p @executable_path/../Frameworks/
SDL3="$(ls "$BREW"/lib/libSDL3.0.dylib 2>/dev/null || true)"
if [ -n "$SDL3" ]; then
  cp "$SDL3" "$APP/Contents/Frameworks/"
  chmod u+w "$APP/Contents/Frameworks/libSDL3.0.dylib"
  # No -od here: that would wipe the Frameworks folder filled above.
  dylibbundler -b \
    -x "$APP/Contents/Frameworks/libSDL3.0.dylib" \
    -d "$APP/Contents/Frameworks/" -p @executable_path/../Frameworks/
fi

# Launcher: run from Resources (assets + bubblet.cfg live there) and let
# sdl2-compat find the bundled SDL3.
cat > "$APP/Contents/MacOS/launcher.sh" <<'EOF'
#!/bin/bash
DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
export DYLD_LIBRARY_PATH="$DIR/../Frameworks"
cd "$DIR/../Resources"
exec "$DIR/bubblet_mac" "$@"
EOF
chmod 755 "$APP/Contents/MacOS/launcher.sh"

cat > "$APP/Contents/Info.plist" <<EOF
<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">
<plist version="1.0">
<dict>
  <key>CFBundleExecutable</key><string>launcher.sh</string>
  <key>CFBundleIconFile</key><string>bubblet</string>
  <key>CFBundleName</key><string>Bubblet</string>
  <key>CFBundleDisplayName</key><string>Bubblet! Rebuilt</string>
  <key>CFBundleIdentifier</key><string>com.houseofbytes.bubblet</string>
  <key>CFBundlePackageType</key><string>APPL</string>
  <key>CFBundleShortVersionString</key><string>${VERSION}</string>
  <key>CFBundleVersion</key><string>${VERSION}</string>
  <key>LSMinimumSystemVersion</key><string>${MIN_MACOS}</string>
  <key>NSHighResolutionCapable</key><true/>
</dict>
</plist>
EOF

# dylibbundler rewrote install names, so re-sign everything (ad-hoc).
codesign --force --deep --sign - "$APP"
codesign --verify --deep --strict "$APP"

# Fail if anything still points outside the bundle/system.
if otool -L "$APP/Contents/MacOS/bubblet_mac" "$APP"/Contents/Frameworks/*.dylib \
     | grep -E "$BREW|/usr/local/(opt|Cellar|lib)"; then
  echo "ERROR: unbundled Homebrew dylib reference found" >&2
  exit 1
fi

STAGE="dist/mac/dmg"
mkdir -p "$STAGE"
cp -R "$APP" "$STAGE/"
ln -s /Applications "$STAGE/Applications"
rm -f "$OUT"
hdiutil create -volname "Bubblet" -srcfolder "$STAGE" -fs HFS+ -format UDZO "$OUT"
echo "Built $OUT"
