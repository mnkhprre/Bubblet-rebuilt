#include "bubblet_globals.h"

// Helper to setup a button structure
void SetupButton(int i, int x, int y, int res_n, int res_p, int vis) {
    buttons_0[i].x1 = x;
    buttons_0[i].y1 = y;
    buttons_0[i].x2 = x + 62;
    buttons_0[i].y2 = y + 38;
    buttons_0[i].lpSurfaceNormal = HAL_LoadResource(res_n);
    buttons_0[i].lpSurfacePressed = HAL_LoadResource(res_p);
    buttons_0[i].isPressed = FALSE;
    buttons_0[i].visibilityMode = vis;
}

// Game_Init: Main initialization function using SDL2 HAL
BOOL Game_Init(void) {
    srand((unsigned int)time(NULL));

    // Load Game Configuration
    FILE* fp = fopen("bubblet.cfg", "rb");
    if (fp) {
        // fread for config etc...
        fclose(fp);
    }

    // Load Bitmaps via HAL (matches resource IDs from ASM)
    bubble_pics[0] = HAL_LoadResource(129);
    bubble_pics[1] = HAL_LoadResource(130);
    bubble_pics[2] = HAL_LoadResource(131);
    bubble_pics[3] = HAL_LoadResource(132);
    bubble_pics[4] = HAL_LoadResource(133);

    bk_pic_0 = HAL_LoadResource(100);
    paper_x_pic_0 = HAL_LoadResource(101);
    paper_pic_0 = HAL_LoadResource(102);
    setup_map_pic_0 = HAL_LoadResource(106);
    checked_box_pic_0 = HAL_LoadResource(107);
    pic_0 = HAL_LoadResource(103); // Correct high-res logo ID instead of 128

    // Initialize Buttons based on original mapping
    // Bottom navigation
    SetupButton(0, 6,   376, 108, 109, 0xFF); // Exit
    SetupButton(1, 74,  376, 110, 111, 0xFF); // Help (?)
    SetupButton(2, 142, 376, 112, 113, 0xFF); // Setup
    SetupButton(3, 210, 376, 114, 115, 0xFF); // Scores
    
    // Bottom button 4: New (in menus) or End (in play)
    SetupButton(4, 278, 376, 118, 119, 0xF0); // Testing 118 for 'New'
    
    // Play-mode specific buttons
    SetupButton(5, 278, 376, 134, 135, MODE_PLAY); // Testing 134 for 'Undo'
    SetupButton(6, 210, 376, 120, 121, MODE_PLAY); // Menu
    SetupButton(7, 278, 376, 116, 117, MODE_PLAY); // 116 = End
    
    // Scoreboard paper buttons
    SetupButton(8, 180, 277, 122, 123, MODE_HIGHSCORES); // 122 = Done
    SetupButton(9, 250, 277, 118, 119, MODE_HIGHSCORES); // Testing 118 for 'New'
    
    // Info screen paper buttons (OK)
    SetupButton(10, 180, 210, 134, 135, MODE_HELP);
    SetupButton(11, 180, 210, 134, 135, MODE_CREDITS);
    SetupButton(12, 180, 210, 134, 135, MODE_UNDO_INFO);
    SetupButton(13, 180, 210, 134, 135, MODE_REGISTER_INFO);
    
    // Register button on Credits/Intro
    SetupButton(14, 250, 210, 126, 127, MODE_CREDITS);
    
    button_ctr_0 = 15;
    
    // Start with a new game ready (logic-wise)
    New_Game(); 
    
    return TRUE;
}

