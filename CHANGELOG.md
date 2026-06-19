# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.0.1] - 2026-06-19

### Fixed
- **macOS 26 / SDL3 Compatibility**: Fixed visual corruption (black screen, missing graphics) on macOS 26 with SDL3 (sdl2-compat)
  - Root cause: Metal renderer in sdl2-compat had issues with large textures (494x420 background, 482x338 paper backgrounds)
  - Solution: Force OpenGL renderer via `SDL_HINT_RENDER_DRIVER=opengl`

- **Transparency/Color Key Handling**: Fixed incorrect transparency rendering
  - Replaced `SDL_CreateTextureFromSurface` (which relies on SDL's internal color key → alpha conversion) with manual texture creation
  - Manually read first pixel as color key, convert 24-bit BGR BMP to RGBA buffer with alpha=0 for color-keyed pixels
  - Uses `SDL_UpdateTexture` for direct pixel upload

- **useColorKey Parameter**: Now properly respected in `HAL_DrawSurface`/`HAL_DrawSurfaceEx`
  - `useColorKey=TRUE` (bubbles, paper backgrounds, buttons) → `SDL_BLENDMODE_BLEND` (transparency active)
  - `useColorKey=FALSE` (main background) → `SDL_BLENDMODE_NONE` (fully opaque, no transparency artifacts)

### Added
- **GitHub Auto-Update Check**: Application checks for new releases on startup
  - Queries GitHub Releases API: `https://api.github.com/repos/mnkhprre/Bubblet-rebuilt/releases/latest`
  - Compares semantic version (tag format: `v1.0.1`) with current version
  - Logs update availability to console with download URL and release notes
  - Non-blocking: runs during startup, doesn't delay game launch
  - Requires `libcurl` (system library on macOS)

### Changed
- `Makefile.mac`: Added `-lcurl` linker flag and `bubblet_update.c` to sources
- Window title still shows "macOS/SDL2" for compatibility

### Technical Details
- **Renderer**: OpenGL (forced via hint) instead of default Metal
- **Texture Format**: `SDL_PIXELFORMAT_ABGR8888` (OpenGL compatible)
- **Color Key Processing**: Manual per-pixel alpha assignment during texture creation
- **Blend Mode**: Per-draw call based on `useColorKey` parameter

### Compatibility
- macOS 26 (Sequoia) ✅
- macOS 13+ (Ventura) ✅
- Linux (SDL2) ✅
- Windows (MinGW cross-compile) - untested

## [1.0.0] - 2026-06-18 (Original Release)

### Initial Release
- Bubblet! Rebuilt: Clean-room port of 1999 Windows DirectDraw game
- SDL2-based cross-platform implementation (macOS, Linux)
- Hardware Abstraction Layer (HAL) architecture
- Original game assets (BMP sprites, WAV sounds)
- Shareware features: registration prompts, high scores, multiple game modes