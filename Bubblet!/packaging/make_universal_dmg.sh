#!/usr/bin/env bash
# Merge an arm64 and an x86_64 Bubblet.app (each made by build_macos.sh)
# into one universal app and DMG.
# Usage: packaging/make_universal_dmg.sh <version> <arm64 Bubblet.app> <x86_64 Bubblet.app>
#   -> dist/Bubblet-<version>-macOS-universal.dmg
set -euo pipefail

VERSION="${1:?usage: make_universal_dmg.sh <version> <arm64 app> <x86_64 app>}"
ARM="${2:?arm64 app missing}"
X86="${3:?x86_64 app missing}"
APP="dist/universal/Bubblet.app"
OUT="dist/Bubblet-${VERSION}-macOS-universal.dmg"

rm -rf dist/universal
mkdir -p dist/universal
cp -R "$ARM" "$APP"

# Every Mach-O file in either app becomes a fat file with both slices.
merge() {
  local rel="$1" a="$ARM/$1" x="$X86/$1" dst="$APP/$1"
  if [ -f "$a" ] && [ -f "$x" ]; then
    lipo -create "$a" "$x" -output "$dst"
    echo "$dst" >> dist/universal/merged.txt
  elif [ -f "$x" ]; then
    mkdir -p "$(dirname "$dst")"; cp "$x" "$dst"
    echo "note: $rel only exists in the x86_64 build"
  else
    echo "note: $rel only exists in the arm64 build"
  fi
}
( cd "$ARM" && find . -type f ) > dist/universal/files.txt
( cd "$X86" && find . -type f ) >> dist/universal/files.txt
sort -u dist/universal/files.txt | while read -r rel; do
  rel="${rel#./}"
  f="$ARM/$rel"; [ -f "$f" ] || f="$X86/$rel"
  if file -b "$f" | grep -q "Mach-O"; then merge "$rel"; fi
done

# The arm64 build sets the minimum macOS; use the higher of the two.
ARM_MIN="$(/usr/libexec/PlistBuddy -c 'Print :LSMinimumSystemVersion' "$ARM/Contents/Info.plist")"
X86_MIN="$(/usr/libexec/PlistBuddy -c 'Print :LSMinimumSystemVersion' "$X86/Contents/Info.plist")"
MIN="$(printf '%s\n%s\n' "$ARM_MIN" "$X86_MIN" | sort -V | tail -1)"
/usr/libexec/PlistBuddy -c "Set :LSMinimumSystemVersion $MIN" "$APP/Contents/Info.plist"

codesign --force --deep --sign - "$APP"
codesign --verify --deep --strict "$APP"

# Files present in both builds must now hold both architectures. Files that
# exist in only one build (Homebrew can ship different versions per arch)
# are only loaded by that architecture's slice, so they stay single-arch.
bad=0
while read -r f; do
  archs="$(lipo -archs "$f")"
  case "$archs" in *arm64*x86_64*|*x86_64*arm64*) ;; *) echo "ERROR: $f is only $archs" >&2; bad=1 ;; esac
done < dist/universal/merged.txt
[ "$bad" = 0 ]
# The main binary must be universal.
lipo -archs "$APP/Contents/MacOS/bubblet_mac" | grep -q arm64
lipo -archs "$APP/Contents/MacOS/bubblet_mac" | grep -q x86_64

STAGE="dist/universal/dmg"
mkdir -p "$STAGE"
cp -R "$APP" "$STAGE/"
ln -s /Applications "$STAGE/Applications"
rm -f "$OUT"
hdiutil create -volname "Bubblet" -srcfolder "$STAGE" -fs HFS+ -format UDZO "$OUT"
echo "Built $OUT"
