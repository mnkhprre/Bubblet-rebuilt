#!/usr/bin/env bash
# Build the Debian/Ubuntu package for Bubblet! Rebuilt.
# Run from the Bubblet! folder on Debian/Ubuntu with:
#   apt-get install build-essential pkg-config libsdl2-dev libsdl2-mixer-dev \
#                   libsdl2-ttf-dev libcurl4-openssl-dev icoutils
# Usage: packaging/build_deb.sh <version>   -> dist/bubblet_<version>_amd64.deb
set -euo pipefail

VERSION="${1:?usage: build_deb.sh <version>}"
ARCH="$(dpkg --print-architecture)"
PKG="dist/deb/bubblet_${VERSION}_${ARCH}"
OUT="dist/bubblet_${VERSION}_${ARCH}.deb"

make -f Makefile.linux clean
make -f Makefile.linux

rm -rf "$PKG"
mkdir -p "$PKG/DEBIAN" "$PKG/usr/lib/bubblet" "$PKG/usr/share/bubblet" \
         "$PKG/usr/games" "$PKG/usr/share/applications" \
         "$PKG/usr/share/icons/hicolor/48x48/apps" "$PKG/usr/share/doc/bubblet"

install -m 755 bubblet_linux "$PKG/usr/lib/bubblet/bubblet"
cp -r bubblet_bmps "$PKG/usr/share/bubblet/"
cp ./*.wav cursor.bmp "$PKG/usr/share/bubblet/"
install -m 644 Readme.txt "$PKG/usr/share/doc/bubblet/README"

# The game reads assets from, and writes bubblet.cfg to, its working directory.
# Give every user their own folder with links to the shared assets.
cat > "$PKG/usr/games/bubblet" <<'EOF'
#!/bin/sh
DATA="${XDG_DATA_HOME:-$HOME/.local/share}/bubblet"
mkdir -p "$DATA"
for f in /usr/share/bubblet/*; do
  ln -sfn "$f" "$DATA/$(basename "$f")"
done
cd "$DATA" && exec /usr/lib/bubblet/bubblet "$@"
EOF
chmod 755 "$PKG/usr/games/bubblet"

# Icon: largest image from the original .ico
ICODIR="$(mktemp -d)"
icotool -x -o "$ICODIR" bubblet.ico
install -m 644 "$(ls -S "$ICODIR"/*.png | head -1)" \
  "$PKG/usr/share/icons/hicolor/48x48/apps/bubblet.png"
rm -rf "$ICODIR"

cat > "$PKG/usr/share/applications/bubblet.desktop" <<'EOF'
[Desktop Entry]
Type=Application
Name=Bubblet! Rebuilt
Comment=Classic bubble-popping puzzle game
Exec=/usr/games/bubblet
Icon=bubblet
Terminal=false
Categories=Game;LogicGame;
EOF

INSTALLED_KB="$(du -sk "$PKG/usr" | cut -f1)"
cat > "$PKG/DEBIAN/control" <<EOF
Package: bubblet
Version: ${VERSION}
Section: games
Priority: optional
Architecture: ${ARCH}
Installed-Size: ${INSTALLED_KB}
Maintainer: mnkhprre <mnkhprre@users.noreply.github.com>
Homepage: https://github.com/mnkhprre/Bubblet-rebuilt
Depends: libsdl2-2.0-0, libsdl2-mixer-2.0-0, libsdl2-ttf-2.0-0, libcurl4 | libcurl4t64, fonts-dejavu-core
Description: Bubblet! Rebuilt - classic bubble-popping puzzle game
 A rebuild of the Windows shareware game Bubblet!, ported to SDL2.
 Click groups of two or more same-coloured bubbles to pop them; bigger
 groups score more. Four game styles: Normal, Shifter, Continuous, MegaShift.
EOF

dpkg-deb --root-owner-group --build "$PKG" "$OUT"
echo "Built $OUT"
