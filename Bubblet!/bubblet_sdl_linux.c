#include "bubblet_globals.h"
#include <SDL2/SDL_mixer.h>
#ifdef _WIN32
#include <SDL2/SDL_syswm.h>
#include "bubblet_resource.h"
#endif
#include <SDL2/SDL_ttf.h>
#ifdef _WIN32
#include <direct.h>
#endif

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
static Mix_Chunk *sfx_Nehehe = NULL;
static TTF_Font *gameFont = NULL;
static SDL_Cursor *gameCursor = NULL;
#ifdef _WIN32
static HICON gameWindowIcon = NULL;
static HICON gameSmallWindowIcon = NULL;
#endif
static BOOL sdlInitialized = FALSE;
static BOOL audioInitialized = FALSE;
static BOOL ttfInitialized = FALSE;

static void DestroyTexture(SurfaceHandle *texture) {
  if (*texture) {
    SDL_DestroyTexture((SDL_Texture *)*texture);
    *texture = NULL;
  }
}

#ifdef _WIN32
static void SetWindowIcon(SDL_Window *window) {
  SDL_SysWMinfo windowInfo;
  SDL_VERSION(&windowInfo.version);
  if (!SDL_GetWindowWMInfo(window, &windowInfo)) {
    fprintf(stderr, "Unable to get Windows window handle: %s\n",
            SDL_GetError());
    return;
  }

  HINSTANCE instance = GetModuleHandle(NULL);
  gameWindowIcon =
      (HICON)LoadImage(instance, MAKEINTRESOURCE(IDI_BUBBLET_ICON),
                       IMAGE_ICON, 32, 32, LR_DEFAULTCOLOR);
  gameSmallWindowIcon =
      (HICON)LoadImage(instance, MAKEINTRESOURCE(IDI_BUBBLET_ICON),
                       IMAGE_ICON, 16, 16, LR_DEFAULTCOLOR);
  if (!gameWindowIcon || !gameSmallWindowIcon) {
    fprintf(stderr, "Unable to load embedded Bubblet window icon.\n");
    if (gameWindowIcon)
      DestroyIcon(gameWindowIcon);
    if (gameSmallWindowIcon)
      DestroyIcon(gameSmallWindowIcon);
    gameWindowIcon = NULL;
    gameSmallWindowIcon = NULL;
    return;
  }

  SendMessage(windowInfo.info.win.window, WM_SETICON, ICON_BIG,
              (LPARAM)gameWindowIcon);
  SendMessage(windowInfo.info.win.window, WM_SETICON, ICON_SMALL,
              (LPARAM)gameSmallWindowIcon);
}

static BOOL SetWorkingDirectoryToExecutable(void) {
  char *basePath = SDL_GetBasePath();
  if (!basePath) {
    fprintf(stderr, "Unable to determine executable directory: %s\n",
            SDL_GetError());
    return FALSE;
  }

  int widePathLength =
      MultiByteToWideChar(CP_UTF8, 0, basePath, -1, NULL, 0);
  wchar_t *widePath =
      widePathLength > 0 ? malloc((size_t)widePathLength * sizeof(*widePath))
                         : NULL;
  if (!widePath ||
      !MultiByteToWideChar(CP_UTF8, 0, basePath, -1, widePath,
                           widePathLength)) {
    fprintf(stderr, "Unable to convert executable directory to UTF-16.\n");
    free(widePath);
    SDL_free(basePath);
    return FALSE;
  }

  int result = _wchdir(widePath);
  if (result != 0)
    perror("Unable to set working directory to executable directory");

  free(widePath);
  SDL_free(basePath);
  return result == 0;
}
#endif

BOOL HAL_Init(void) {
#ifdef _WIN32
  if (!SetWorkingDirectoryToExecutable())
    return FALSE;
#endif

  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
    printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
    return FALSE;
  }
  sdlInitialized = TRUE;

  if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
    printf("SDL_mixer could not initialize! SDL_Error: %s\n", Mix_GetError());
  } else {
    audioInitialized = TRUE;
  }

  if (TTF_Init() == -1) {
    printf("SDL_ttf could not initialize! TTF_Error: %s\n", TTF_GetError());
  } else {
    ttfInitialized = TRUE;
  }

#ifdef _WIN32
  sdlWindow = SDL_CreateWindow("Bubblet! Rebuilt", SDL_WINDOWPOS_CENTERED,
                               SDL_WINDOWPOS_CENTERED, 493, 419,
                               SDL_WINDOW_SHOWN);
#else
  sdlWindow =
      SDL_CreateWindow("Bubblet! Rebuilt (Linux/SDL2)", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, 493, 419, SDL_WINDOW_SHOWN);
#endif
  if (!sdlWindow)
    return FALSE;
#ifdef _WIN32
  SetWindowIcon(sdlWindow);
#endif

#ifdef _WIN32
  hal_Context = SDL_CreateRenderer(
      sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
  if (!hal_Context)
    hal_Context = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_SOFTWARE);
#else
  SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");
  hal_Context = SDL_CreateRenderer(
      sdlWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
#endif
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

  sfx_Nehehe = Mix_LoadWAV("nehehe.wav");
  if (!sfx_Nehehe)
    printf("[AUDIO] Failed to load nehehe.wav: %s\n", Mix_GetError());

  // Load a system font as fallback
#ifdef _WIN32
  const char *windowsDirectory = getenv("WINDIR");
  char windowsFontPath[MAX_PATH];
  if (!windowsDirectory)
    windowsDirectory = "C:/Windows";
  snprintf(windowsFontPath, sizeof(windowsFontPath), "%s/Fonts/arial.ttf",
           windowsDirectory);
  const char *fontPaths[] = {windowsFontPath, "C:/Windows/Fonts/segoeui.ttf",
                             "font.ttf"};
#else
  const char *fontPaths[] = {
      "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf",
      "/usr/share/fonts/truetype/liberation/LiberationSans-Regular.ttf",
      "/usr/share/fonts/truetype/freefont/FreeSans.ttf",
      "/usr/share/fonts/truetype/ubuntu/Ubuntu-R.ttf",
      "/usr/share/fonts/truetype/noto/NotoSans-Regular.ttf",
      "font.ttf" // Local fallback
  };
#endif
  int numFontPaths = sizeof(fontPaths) / sizeof(fontPaths[0]);
  for (int i = 0; i < numFontPaths; i++) {
    gameFont = TTF_OpenFont(fontPaths[i], 16);
    if (gameFont)
      break;
  }
  if (!gameFont) {
    printf("Warning: Could not load any system font!\n");
  }

  // Load custom cursor
  SDL_Surface *cursorSurface = SDL_LoadBMP("cursor.bmp");
  if (cursorSurface) {
    gameCursor = SDL_CreateColorCursor(cursorSurface, 0, 0);
    if (gameCursor) {
      SDL_SetCursor(gameCursor);
    }
    SDL_FreeSurface(cursorSurface);
  } else {
    printf("Warning: Could not load custom cursor: %s\n", SDL_GetError());
  }

  main_hWnd = sdlWindow;
  return TRUE;
}

void HAL_Shutdown(void) {
  if (gameCursor) {
    SDL_SetCursor(SDL_GetDefaultCursor());
    SDL_FreeCursor(gameCursor);
    gameCursor = NULL;
  }
#ifdef _WIN32
  if (sdlWindow && (gameWindowIcon || gameSmallWindowIcon)) {
    SDL_SysWMinfo windowInfo;
    SDL_VERSION(&windowInfo.version);
    if (SDL_GetWindowWMInfo(sdlWindow, &windowInfo)) {
      SendMessage(windowInfo.info.win.window, WM_SETICON, ICON_BIG, 0);
      SendMessage(windowInfo.info.win.window, WM_SETICON, ICON_SMALL, 0);
    }
  }
  if (gameWindowIcon) {
    DestroyIcon(gameWindowIcon);
    gameWindowIcon = NULL;
  }
  if (gameSmallWindowIcon) {
    DestroyIcon(gameSmallWindowIcon);
    gameSmallWindowIcon = NULL;
  }
#endif
  if (gameFont) {
    TTF_CloseFont(gameFont);
    gameFont = NULL;
  }

  for (int i = 0; i < 20; i++) {
    DestroyTexture(&buttons_0[i].lpSurfaceNormal);
    DestroyTexture(&buttons_0[i].lpSurfacePressed);
  }
  DestroyTexture(&bk_pic_0);
  DestroyTexture(&pic_0);
  DestroyTexture(&paper_pic_0);
  DestroyTexture(&paper_x_pic_0);
  DestroyTexture(&setup_map_pic_0);
  DestroyTexture(&checked_box_pic_0);
  DestroyTexture(&watermark_pic_0);
  DestroyTexture(&statistics_bg_pic_0);
  DestroyTexture(&gameover_labels_pic_0);
  for (int i = 0; i < 5; i++)
    DestroyTexture(&bubble_pics[i]);

  if (sfx_Click)
    Mix_FreeChunk(sfx_Click);
  if (sfx_Pop)
    Mix_FreeChunk(sfx_Pop);
  if (sfx_Megapop && sfx_Megapop != sfx_Pop)
    Mix_FreeChunk(sfx_Megapop);
  if (sfx_Intro)
    Mix_FreeChunk(sfx_Intro);
  if (sfx_Score)
    Mix_FreeChunk(sfx_Score);
  if (sfx_Highscore)
    Mix_FreeChunk(sfx_Highscore);
  if (sfx_Boing && sfx_Boing != sfx_Intro)
    Mix_FreeChunk(sfx_Boing);
  if (sfx_Nehehe)
    Mix_FreeChunk(sfx_Nehehe);
  sfx_Click = NULL;
  sfx_Pop = NULL;
  sfx_Megapop = NULL;
  sfx_Intro = NULL;
  sfx_Score = NULL;
  sfx_Highscore = NULL;
  sfx_Boing = NULL;
  sfx_Nehehe = NULL;

  if (hal_Context) {
    SDL_DestroyRenderer((SDL_Renderer *)hal_Context);
    hal_Context = NULL;
  }
  if (sdlWindow) {
    SDL_DestroyWindow(sdlWindow);
    sdlWindow = NULL;
  }
  if (audioInitialized) {
    Mix_CloseAudio();
    audioInitialized = FALSE;
  }
  if (ttfInitialized) {
    TTF_Quit();
    ttfInitialized = FALSE;
  }
  if (sdlInitialized) {
    SDL_Quit();
    sdlInitialized = FALSE;
  }
  main_hWnd = NULL;
}

SurfaceHandle HAL_LoadSurface(const char *filename) {
  SDL_Surface *surface = SDL_LoadBMP(filename);
  if (!surface) {
    printf("Unable to load image %s! SDL Error: %s\n", filename,
           SDL_GetError());
    return NULL;
  }

  if (SDL_LockSurface(surface) != 0) {
    fprintf(stderr, "Unable to lock image %s: %s\n", filename, SDL_GetError());
    SDL_FreeSurface(surface);
    return NULL;
  }

  Uint32 firstPixel = 0;
  SDL_memcpy(&firstPixel, surface->pixels, surface->format->BytesPerPixel);
  SDL_UnlockSurface(surface);

  if (SDL_SetColorKey(surface, SDL_TRUE, firstPixel) != 0) {
    fprintf(stderr, "Unable to set image color key for %s: %s\n", filename,
            SDL_GetError());
    SDL_FreeSurface(surface);
    return NULL;
  }

  SDL_Surface *rgbaSurface =
      SDL_ConvertSurfaceFormat(surface, SDL_PIXELFORMAT_RGBA32, 0);
  SDL_FreeSurface(surface);
  if (!rgbaSurface) {
    fprintf(stderr, "Unable to convert image %s: %s\n", filename,
            SDL_GetError());
    return NULL;
  }

  SDL_Texture *texture = SDL_CreateTextureFromSurface(
      (SDL_Renderer *)hal_Context, rgbaSurface);
  SDL_FreeSurface(rgbaSurface);
  if (!texture) {
    fprintf(stderr, "Unable to create texture for %s: %s\n", filename,
            SDL_GetError());
    return NULL;
  }

  if (SDL_SetTextureBlendMode(texture, SDL_BLENDMODE_BLEND) != 0) {
    fprintf(stderr, "Unable to set blend mode for %s: %s\n", filename,
            SDL_GetError());
    SDL_DestroyTexture(texture);
    return NULL;
  }
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
  SDL_SetTextureBlendMode((SDL_Texture *)src,
                          useColorKey ? SDL_BLENDMODE_BLEND
                                      : SDL_BLENDMODE_NONE);
  int ret = SDL_RenderCopy((SDL_Renderer *)hal_Context, (SDL_Texture *)src,
                           NULL, &destRect);
  if (ret != 0)
    printf("[DRAW] SDL_RenderCopy FAILED: %s\n", SDL_GetError());
}

void HAL_DrawSurfaceEx(SurfaceHandle src, SurfaceHandle dest, int x, int y,
                       int w, int h, BOOL useColorKey) {
  if (!src)
    return;
  SDL_Rect destRect = {x, y, w, h};
  SDL_SetTextureBlendMode((SDL_Texture *)src,
                          useColorKey ? SDL_BLENDMODE_BLEND
                                      : SDL_BLENDMODE_NONE);
  int ret = SDL_RenderCopy((SDL_Renderer *)hal_Context, (SDL_Texture *)src,
                           NULL, &destRect);
  if (ret != 0)
    printf("[DRAW] SDL_RenderCopyEx FAILED: %s\n", SDL_GetError());
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
  else if (strcmp(alias, "Nehehe") == 0 || strcmp(alias, "nehehe") == 0)
    chunk = sfx_Nehehe;

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
      game_initialized = FALSE;
      break;
    } else if (e.type == SDL_MOUSEBUTTONDOWN) {
      printf("[INPUT] Mouse DOWN at X=%d, Y=%d\n", e.button.x, e.button.y);
      Check_Button_Down(e.button.x, e.button.y);
    } else if (e.type == SDL_MOUSEBUTTONUP) {
      printf("[INPUT] Mouse UP at X=%d, Y=%d\n", e.button.x, e.button.y);
      Check_Button_Up(e.button.x, e.button.y);
    } else if (e.type == SDL_MOUSEMOTION) {
      Check_Button_Move(e.motion.x, e.motion.y);
    }
  }
}

uint32_t HAL_GetTicks(void) { return SDL_GetTicks(); }
