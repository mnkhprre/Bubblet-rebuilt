#include "bubblet_globals.h"

// Check_In_Box: Helper for hit testing
BOOL Check_In_Box(int x, int y, int left, int top, int right, int bottom) {
    return (x >= left && x <= right && y >= top && y <= bottom);
}

// Button handling logic

void Check_Setup_Clicked(int x, int y) {
    // Game Styles
    if (Check_In_Box(x, y, 97, 101, 210, 120)) setup_data_0 = 0; // Standard
    if (Check_In_Box(x, y, 97, 132, 229, 151)) setup_data_0 = 1; // Continuous
    if (Check_In_Box(x, y, 97, 163, 189, 182)) setup_data_0 = 2; // Shifter
    if (Check_In_Box(x, y, 97, 194, 219, 217)) setup_data_0 = 3; // MegaShift
    
    // Play Sounds
    if (Check_In_Box(x, y, 277, 81, 416, 101)) {
        sound_enabled_0 = !sound_enabled_0;
    }
    
    // Animations
    if (Check_In_Box(x, y, 278, 124, 406, 143)) {
        animations_enabled_0 = !animations_enabled_0;
    }
    HAL_PlaySound("Click");
}

// Check_Button_Down: Mouse down handling
void Check_Button_Down(int x, int y) {
    if (animations_active) return;

    if (mode_0 == MODE_SETUP) {
        Check_Setup_Clicked(x, y);
    }

    // Check main grid first if in play mode
    if (mode_0 == MODE_PLAY && Check_In_Box(x, y, GRID_X_OFFSET, GRID_Y_OFFSET, GRID_X_OFFSET + (GRID_COLS * BUBBLE_SIZE), GRID_Y_OFFSET + (GRID_ROWS * BUBBLE_SIZE))) {
        Check_Bubbles_Clicked(x, y);
        return;
    }

    // Check UI buttons
    for (int i = 0; i < button_ctr_0; i++) {
        GameButton* btn = &buttons_0[i];
        if (btn->visibilityMode == 0xFF || btn->visibilityMode == (int)mode_0) {
            if (Check_In_Box(x, y, btn->x1, btn->y1, btn->x2, btn->y2)) {
                btn->isPressed = TRUE;
                pressed_button_0 = i;
                break;
            }
        }
    }
}

// Check_Button_Up: Mouse up handling
void Check_Button_Up(int x, int y) {
    if (pressed_button_0 != -1) {
        GameButton* btn = &buttons_0[pressed_button_0];
        btn->isPressed = FALSE;

        if (Check_In_Box(x, y, btn->x1, btn->y1, btn->x2, btn->y2)) {
            Execute_Button(pressed_button_0);
        }
        pressed_button_0 = -1;
    }
}

// Check_Button_Move: Mouse move handling
void Check_Button_Move(int x, int y) {
    if (pressed_button_0 != -1) {
        GameButton* btn = &buttons_0[pressed_button_0];
        BOOL isInside = Check_In_Box(x, y, btn->x1, btn->y1, btn->x2, btn->y2);
        if (btn->isPressed != isInside) {
            btn->isPressed = isInside;
        }
    }
}
