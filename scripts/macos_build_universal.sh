#!/usr/bin/env bash

set -e

source "$(pwd)/.mac_env"

VERSION="$1"
IDENTITY="$2"
shift

if [[ -z "$VERSION" ]]; then
	printf -- "Usage: macos_build_universal.sh VERSION [CODESIGN_IDENTITY]\n\n"
	exit 0
fi

meson install -C "$MESON_BUILD_ROOT_MACOS_X64"
meson install -C "$MESON_BUILD_ROOT_MACOS_AARCH64"

cp -a "$MESON_BUILD_ROOT_MACOS_X64_COMPILED/" "$MESON_BUILD_ROOT_MACOS_COMBINED"
printf -- "Combining x64 and AArch64 binaries...\n\n"
lipo -create -output "$MESON_BUILD_ROOT_MACOS_COMBINED/$TAISEI_BIN_PATH" "$MESON_BUILD_ROOT_MACOS_X64_COMPILED/$TAISEI_BIN_PATH" "$MESON_BUILD_ROOT_MACOS_AARCH64_COMPILED/$TAISEI_BIN_PATH"

if [[ -n "$IDENTITY" ]]; then
	printf -- "Codesigning macOS .app...\n\n"
	codesign --deep --force --sign $IDENTITY $MESON_BUILD_ROOT_MACOS_COMBINED/$TAISEI_BIN_PATH
fi

printf -- "Generating macOS .dmg...\n\n"
"$TAISEI_ROOT/scripts/macos-gen-dmg.py" "$MAC_BUILD_DIR/compiled/Taisei-$VERSION-universal.dmg" "$MESON_BUILD_ROOT_MACOS_X64" "$MESON_BUILD_ROOT_MACOS_COMBINED" "$@"

if [[ -n "$IDENTITY" ]]; then
	printf -- "Codesigning macOS .dmg...\n\n"
	codesign --deep --force --sign $IDENTITY $MAC_BUILD_DIR/compiled/Taisei-$VERSION-universal.dmg
fi
