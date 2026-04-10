#include "bubblet_globals.h"

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

    game_initialized = TRUE;
    
    // Main Loop
    while (1) {
        uint32_t frameStart = HAL_GetTicks();
        
        // 1. Process Events (Input)
        HAL_ProcessEvents();
        
        // 1.5 Update Animations
        Update_Animations(0.016f); // 16ms delta time approximation at 60 FPS
        
        // 2. Render to Backbuffer
        Create_Screen();
        
        // 3. Present to Screen
        HAL_Present();
        
        // 4. Cap to 60 FPS
        uint32_t frameTime = HAL_GetTicks() - frameStart;
        if (frameTime < 16) {
            SDL_Delay(16 - frameTime);
        }
    }

    HAL_Shutdown();
    return 0;
}
