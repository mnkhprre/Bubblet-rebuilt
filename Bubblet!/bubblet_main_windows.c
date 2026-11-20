#include "bubblet_globals.h"
#include <SDL2/SDL.h>
#include <direct.h>

extern int CheckForUpdates(void);

int main(int argc, char* argv[]) {
    // Assets and bubblet.cfg are loaded relative to the working directory;
    // make that the folder the exe lives in, regardless of how it was launched.
    char *basePath = SDL_GetBasePath();
    if (basePath) {
        _chdir(basePath);
        SDL_free(basePath);
    }

    if (!HAL_Init()) {
        printf("Failed to initialize HAL!\n");
        return -1;
    }

    if (!Game_Init()) {
        printf("Failed to initialize Game!\n");
        return -1;
    }

    HAL_PlaySound("Intro");

    // Check for updates on startup
    CheckForUpdates();

    game_initialized = TRUE;

    // Main Loop
    while (1) {
        uint32_t frameStart = HAL_GetTicks();

        HAL_ProcessEvents();

        Update_Animations(0.033f);
        if (waitanim_0 && !animations_active) {
            Check_End_Game();
        }

        Create_Screen();
        HAL_Present();

        uint32_t frameTime = HAL_GetTicks() - frameStart;
        if (frameTime < 33) {
            SDL_Delay(33 - frameTime);
        }
    }

    HAL_Shutdown();
    return 0;
}
