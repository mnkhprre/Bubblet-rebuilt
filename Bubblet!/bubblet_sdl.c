#include "bubblet_globals.h"
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_ttf.h>

// HAL Globals
void *hal_Context = NULL; // SDL_Renderer*
static SDL_Window *sdlWindow = NULL;
static Mix_Chunk *sfx_Click = NULL;
static Mix_Chunk *sfx_Pop = NULL;
static Mix_Chunk *sfx_Megapop = NULL;
static Mix_Chunk *sfx_Intro = NULL;
static Mix_Chunk *sfx_Score = NULL;
static Mix_Chunk *sfx_Highscore = NULL;
static Mix_Chunk *sfx_Boing = NULL;
static TTF_Font *gameFont = NULL;

BOOL HAL_Init(void) {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return FALSE;
  }

  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    printf("SDL_mixer could not initialize! SDL_Error: %s\n", Mix_GetError());
  }

  if (TTF_Init() == -1) {
    printf("SDL_ttf could not initialize! TTF_Error: %s\n", TTF_GetError());
  }

  sdlWindow =
      SDL_CreateWindow("Bubblet! Rebuilt (macOS/SDL2)", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 493, 419, SDL_WINDOW_SHOWN);
  if (!sdlWindow)
    return FALSE;

  hal_Context = SDL_CreateRenderer(
      sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!hal_Context)
    return FALSE;

  // Preload sounds
  sfx_Click = Mix_LoadWAV("Click.wav");
  if (!sfx_Click)
    printf("[AUDIO] Failed to load Click.wav: %s\n", Mix_GetError());

  sfx_Pop = Mix_LoadWAV("Pop.wav"); // Use original recording for popping
  if (!sfx_Pop)
    printf("[AUDIO] Failed to load Pop.wav handle: %s\n", Mix_GetError());

  sfx_Megapop = sfx_Pop;

  sfx_Intro = Mix_LoadWAV("Intro.wav");
  if (!sfx_Intro)
    printf("[AUDIO] Failed to load Intro.wav: %s\n", Mix_GetError());

  sfx_Score = Mix_LoadWAV("Score.wav");
  if (!sfx_Score)
    printf("[AUDIO] Failed to load Score.wav: %s\n", Mix_GetError());

  sfx_Highscore = Mix_LoadWAV("Higscore.wav");
  if (!sfx_Highscore)
    printf("[AUDIO] Failed to load Higscore.wav: %s\n", Mix_GetError());

  sfx_Boing = Mix_LoadWAV("Boing.wav");
  if (!sfx_Boing) {
    sfx_Boing = sfx_Intro; // Only fallback to Intro if it exists
  }

  // Load a system font as fallback
  const char *fontPaths[] = {
      "/System/Library/Fonts/Supplemental/Arial.ttf",
      "/System/Library/Fonts/Helvetica.ttc", "/Library/Fonts/Arial.ttf",
      "font.ttf" // Local fallback
  };
  for (int i = 0; i < 4; i++) {
    gameFont = TTF_OpenFont(fontPaths[i], 16);
    if (gameFont)
      break;
  }

  // Load custom cursor
  SDL_Surface *cursorSurface = SDL_LoadBMP("cursor.bmp");
  if (cursorSurface) {
    SDL_Cursor *cursor = SDL_CreateColorCursor(cursorSurface, 0, 0);
    if (cursor) {
      SDL_SetCursor(cursor);
    }
    SDL_FreeSurface(cursorSurface);
  } else {
    printf("Warning: Could not load custom cursor: %s\n", SDL_GetError());
  }

  main_hWnd = sdlWindow;
  return TRUE;
}

void HAL_Shutdown(void) {
  if (gameFont)
    TTF_CloseFont(gameFont);
  if (hal_Context)
    SDL_DestroyRenderer((SDL_Renderer *)hal_Context);
  if (sdlWindow)
    SDL_DestroyWindow(sdlWindow);
  Mix_CloseAudio();
  TTF_Quit();
  SDL_Quit();
}

SurfaceHandle HAL_LoadSurface(const char *filename) {
  SDL_Surface *loadedSurface = SDL_LoadBMP(filename);
  if (!loadedSurface) {
    printf("Unable to load image %s! SDL Error: %s\n", filename,
           SDL_GetError());
    return NULL;
  }

  // Set color key from the first pixel (often (0,0) in old game sprites)
  Uint32 colorkey;
  if (SDL_LockSurface(loadedSurface) == 0) {
    Uint8 *pixels = (Uint8 *)loadedSurface->pixels;
    colorkey = *(Uint32 *)pixels;
    SDL_UnlockSurface(loadedSurface);
    SDL_SetColorKey(loadedSurface, SDL_TRUE, colorkey);
  }

  SDL_Texture *texture =
      SDL_CreateTextureFromSurface((SDL_Renderer *)hal_Context, loadedSurface);
  SDL_FreeSurface(loadedSurface);
  return texture;
}

// Map Windows resource IDs to files in bubblet_bmps
SurfaceHandle HAL_LoadResource(int resourceId) {
  char path[256];
  sprintf(path, "bubblet_bmps/Bitmap_%d.bmp", resourceId);
  return HAL_LoadSurface(path);
}

void HAL_DrawSurface(SurfaceHandle src, SurfaceHandle dest, int x, int y,
                     BOOL useColorKey) {
  if (!src)
    return;
  int w, h;
  SDL_QueryTexture((SDL_Texture *)src, NULL, NULL, &w, &h);
  SDL_Rect destRect = {x, y, w, h};
  SDL_RenderCopy((SDL_Renderer *)hal_Context, (SDL_Texture *)src, NULL,
                 &destRect);
}

void HAL_DrawSurfaceEx(SurfaceHandle src, SurfaceHandle dest, int x, int y,
                       int w, int h, BOOL useColorKey) {
  if (!src)
    return;
  SDL_Rect destRect = {x, y, w, h};
  SDL_RenderCopy((SDL_Renderer *)hal_Context, (SDL_Texture *)src, NULL,
                 &destRect);
}

void HAL_Present(void) { SDL_RenderPresent((SDL_Renderer *)hal_Context); }

void HAL_Clear(SurfaceHandle dest) {
  SDL_SetRenderDrawColor((SDL_Renderer *)hal_Context, 0, 0, 0, 255);
  SDL_RenderClear((SDL_Renderer *)hal_Context);
}

void HAL_DrawText(SurfaceHandle dest, int x, int y, const char *text,
                  COLORREF color, BOOL center) {
  if (!gameFont || !text || text[0] == '\0')
    return;

  SDL_Color sdlColor = {(Uint8)(color & 0xFF), (Uint8)((color >> 8) & 0xFF),
                        (Uint8)((color >> 16) & 0xFF), 255};
  SDL_Surface *surface = TTF_RenderText_Blended(gameFont, text, sdlColor);
  if (!surface)
    return;

  SDL_Texture *texture =
      SDL_CreateTextureFromSurface((SDL_Renderer *)hal_Context, surface);
  if (texture) {
    int w, h;
    SDL_QueryTexture(texture, NULL, NULL, &w, &h);
    SDL_Rect rect = {center ? x - w / 2 : x, y, w, h};
    SDL_RenderCopy((SDL_Renderer *)hal_Context, texture, NULL, &rect);
    SDL_DestroyTexture(texture);
  }
  SDL_FreeSurface(surface);
}

void HAL_DrawLine(SurfaceHandle dest, int x1, int y1, int x2, int y2,
                  COLORREF color) {
  SDL_SetRenderDrawColor((SDL_Renderer *)hal_Context, (color & 0xFF),
                         (color >> 8) & 0xFF, (color >> 16) & 0xFF, 255);
  SDL_RenderDrawLine((SDL_Renderer *)hal_Context, x1, y1, x2, y2);
}

void HAL_PlaySound(const char *alias) {
  if (!sound_enabled_0) {
    printf("[AUDIO] Sound disabled, skipping: %s\n", alias);
    return;
  }

  Mix_Chunk *chunk = NULL;
  if (strcmp(alias, "Click") == 0 || strcmp(alias, "click") == 0)
    chunk = sfx_Click;
  else if (strcmp(alias, "Pop") == 0 || strcmp(alias, "pop") == 0)
    chunk = sfx_Pop;
  else if (strcmp(alias, "Megapop") == 0 || strcmp(alias, "megapop") == 0)
    chunk = sfx_Megapop;
  else if (strcmp(alias, "Intro") == 0 || strcmp(alias, "intro") == 0)
    chunk = sfx_Intro;
  else if (strcmp(alias, "Score") == 0 || strcmp(alias, "score") == 0)
    chunk = sfx_Score;
  else if (strcmp(alias, "Highscore") == 0 || strcmp(alias, "highscore") == 0)
    chunk = sfx_Highscore;
  else if (strcmp(alias, "Boing") == 0 || strcmp(alias, "boing") == 0)
    chunk = sfx_Boing;

  if (chunk) {
    printf("[AUDIO] Playing alias: %s\n", alias);
    Mix_PlayChannel(-1, chunk, 0);
  } else {
    // Fallback for other sounds
    char path[256];
    sprintf(path, "%s.wav", alias);
    printf("[AUDIO] Alias %s not preloaded, trying file: %s\n", alias, path);
    Mix_Chunk *temp = Mix_LoadWAV(path);
    if (temp) {
      Mix_PlayChannel(-1, temp, 0);
    } else {
      printf("[AUDIO] FAILED to play %s: %s\n", alias, Mix_GetError());
    }
  }
}

void HAL_ProcessEvents(void) {
  SDL_Event e;
  while (SDL_PollEvent(&e) != 0) {
    if (e.type == SDL_QUIT) {
      exit(0);
    } else if (e.type == SDL_MOUSEBUTTONDOWN) {
      printf("[INPUT] Mouse DOWN at X=%d, Y=%d\n", e.button.x, e.button.y);
      Check_Button_Down(e.button.x, e.button.y);
    } else if (e.type == SDL_MOUSEBUTTONUP) {
      printf("[INPUT] Mouse UP at X=%d, Y=%d\n", e.button.x, e.button.y);
      Check_Button_Up(e.button.x, e.button.y);
    } else if (e.type == SDL_MOUSEMOTION) {
      // Uncomment the line below to also log mouse movements (can be very
      // verbose) printf("[INPUT] Mouse MOVE to X=%d, Y=%d\n", e.motion.x,
      // e.motion.y);
      Check_Button_Move(e.motion.x, e.motion.y);
    }
  }
}

uint32_t HAL_GetTicks(void) { return SDL_GetTicks(); }
