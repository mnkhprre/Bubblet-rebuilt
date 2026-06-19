#include "bubblet_globals.h"

extern int CheckForUpdates(void);

int main(int argc, char* argv[]) {
    if (!HAL_Init()) {
        printf("Failed to initialize HAL!\n");
        return -1;
    }

    if (!Game_Init()) {
        printf("Failed to initialize Game!\n");
        return -1;
    }

    HAL_PlaySound("Intro");

    // Check for updates on startup (non-blocking)
    CheckForUpdates();

    game_initialized = TRUE;
    
    // Main Loop
    while (1) {
        uint32_t frameStart = HAL_GetTicks();
        
        // 1. Process Events (Input)
        HAL_ProcessEvents();
        
        // 1.5 Update Animations
        Update_Animations(0.033f); // 33ms delta time at 30 FPS
        
        // 2. Render to Backbuffer
        Create_Screen();
        
        // 3. Present to Screen
        HAL_Present();
        
        // 4. Cap to 30 FPS
        uint32_t frameTime = HAL_GetTicks() - frameStart;
        if (frameTime < 33) {
            SDL_Delay(33 - frameTime);
        }
    }

    HAL_Shutdown();
    return 0;
}
