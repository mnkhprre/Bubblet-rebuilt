#include "bubblet_globals.h"

extern int CheckForUpdates(void);

int main(int argc, char* argv[]) {
    if (!HAL_Init()) {
        printf("Failed to initialize HAL!\n");
        HAL_Shutdown();
        return -1;
    }

    if (!Game_Init()) {
        printf("Failed to initialize Game!\n");
        HAL_Shutdown();
        return -1;
    }

    HAL_PlaySound("Intro");

    // Check for updates on startup (non-blocking)
    CheckForUpdates();

    game_initialized = TRUE;
    uint32_t previousFrameTime = HAL_GetTicks();
    
    // Main Loop
    while (game_initialized) {
        uint32_t frameStart = HAL_GetTicks();
        
        // 1. Process Events (Input)
        HAL_ProcessEvents();
        if (!game_initialized)
            break;
        
        uint32_t currentFrameTime = HAL_GetTicks();
        float deltaTime = (currentFrameTime - previousFrameTime) / 1000.0f;
        previousFrameTime = currentFrameTime;
        if (deltaTime > 0.1f)
            deltaTime = 0.1f;

        // 1.5 Update Animations
        Update_Animations(deltaTime);
        if (waitanim_0 && !animations_active) {
            Check_End_Game();
        }

        // 2. Render to Backbuffer
        Create_Screen();
        
        // 3. Present to Screen
        HAL_Present();
        
        // 4. Cap to the original 40 FPS update rate.
        uint32_t frameTime = HAL_GetTicks() - frameStart;
        if (frameTime < 25) {
            SDL_Delay(25 - frameTime);
        }
    }

    HAL_Shutdown();
    return 0;
}
