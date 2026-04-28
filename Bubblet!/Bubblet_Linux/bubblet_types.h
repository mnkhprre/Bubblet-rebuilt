#ifndef BUBBLET_TYPES_H
#define BUBBLET_TYPES_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifdef _WIN32
#include <windows.h>
#include <ddraw.h>
typedef LPDIRECTDRAWSURFACE SurfaceHandle;
typedef HWND WindowHandle;
#else
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
typedef SDL_Texture* SurfaceHandle;
typedef SDL_Window* WindowHandle;
#define BOOL int
#define TRUE 1
#define FALSE 0
#define RGB(r,g,b) ((uint32_t)(((uint8_t)(r)|((uint16_t)((uint8_t)(g))<<8))|(((uint32_t)(uint8_t)(b))<<16)))
typedef uint32_t COLORREF;
#endif

// Game Modes
typedef enum {
    MODE_INTRO = 0,
    MODE_PLAY = 2,
    MODE_CREDITS = 3,
    MODE_SETUP = 4,
    MODE_HIGHSCORES = 5,
    MODE_UNDO_INFO = 6,
    MODE_REGISTER_INFO = 7,
    MODE_HELP = 8,
    MODE_GAMEOVER = 9
} GameMode;

// Button structure (32 bytes original, extended for SDL)
typedef struct {
    int x1, y1, x2, y2;
    SurfaceHandle lpSurfaceNormal;
    SurfaceHandle lpSurfacePressed;
    int isPressed;
    int visibilityMode;
} GameButton;

// Grid configuration
#define GRID_COLS 10
#define GRID_ROWS 7
#define BUBBLE_SIZE 48
#define GRID_X_OFFSET 8
#define GRID_Y_OFFSET 8

// Helper macros for DirectDraw calls (matching the virtual offsets in decompiled code)
// Offset 0x14 = 20 -> Blt or Fill
// Offset 0x18 = 24 -> CreateSurface (on IDirectDraw)
// Offset 0x44 = 68 -> GetDC
// Offset 0x68 = 104 -> ReleaseDC
// Offset 0x70 = 112 -> SetClipper

extern float anim_offset_x[512];
extern float anim_offset_y[512];
extern BOOL animations_active;

void Update_Animations(float dt);

#endif // BUBBLET_TYPES_H
