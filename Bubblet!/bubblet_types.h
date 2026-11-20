#ifndef BUBBLET_TYPES_H
#define BUBBLET_TYPES_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#endif

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

typedef SDL_Texture *SurfaceHandle;
typedef SDL_Window *WindowHandle;

#ifndef _WIN32
typedef int BOOL;
typedef uint32_t COLORREF;
#define TRUE 1
#define FALSE 0
#define RGB(r, g, b)                                                        \
  ((uint32_t)((uint8_t)(r) | ((uint16_t)(uint8_t)(g) << 8) |                \
              ((uint32_t)(uint8_t)(b) << 16)))
#endif

// Game states
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

// Button geometry and SDL-backed visual state
typedef struct {
  int x1;
  int y1;
  int x2;
  int y2;
  SurfaceHandle lpSurfaceNormal;
  SurfaceHandle lpSurfacePressed;
  int isPressed;
  int visibilityMode;
} GameButton;

// Playfield geometry
#define GRID_COLS 10
#define GRID_ROWS 7
#define BUBBLE_SIZE 48
#define GRID_X_OFFSET 8
#define GRID_Y_OFFSET 8

// Animation state
extern float anim_offset_x[512];
extern float anim_offset_y[512];
extern BOOL animations_active;

void Update_Animations(float dt);

#endif // BUBBLET_TYPES_H
