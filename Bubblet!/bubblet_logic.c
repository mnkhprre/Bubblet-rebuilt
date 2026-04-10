#include "bubblet_globals.h"

// New_Game: Starts a new game by randomizing the grid
void New_Game(void) {
    game_score_0 = 0;
    number_bubbles_marked_0 = 0;
    bubbles_marked_0 = 0;
    game_busy_0 = 0;

    // Initialize random grid
    for (int col = 0; col < GRID_COLS; col++) {
        for (int row = 0; row < GRID_ROWS; row++) {
            int index = col * 42 + row * 6;
            PlayField_0[index] = (unsigned char)(rand() % 5 + 1);
            // Initialize other grid-related arrays (offsets, check flags)
            // PlayField_X[index] = 0xFFFF;
            // PlayField_Y[index] = 0xFFFF;
            // CheckGrid[index] = 0;
        }
    }
}

// Check_Bubble: Recursive flood-fill to find connected same-colored bubbles
int FloodFillGrid(int col, int row, int color, unsigned char* checkGrid) {
    if (col < 0 || col >= GRID_COLS || row < 0 || row >= GRID_ROWS) return 0;
    
    int index = col * 42 + row * 6;
    if (PlayField_0[index] != color || checkGrid[index] != 0) return 0;

    checkGrid[index] = 1; // Mark as part of selection
    int count = 1;

    // Recurse in 4 directions
    count += FloodFillGrid(col + 1, row, color, checkGrid);
    count += FloodFillGrid(col - 1, row, color, checkGrid);
    count += FloodFillGrid(col, row + 1, color, checkGrid);
    count += FloodFillGrid(col, row - 1, color, checkGrid);

    return count;
}

// Update_Bubble: Handles gravity and column shifting
void Update_Bubble(void) {
    // 1. Gravity: For each column, move bubbles down to fill gaps
    for (int col = 0; col < GRID_COLS; col++) {
        int targetRow = GRID_ROWS - 1;
        for (int row = GRID_ROWS - 1; row >= 0; row--) {
            int curIdx = col * 42 + row * 6;
            if (PlayField_0[curIdx] != 0) {
                if (row != targetRow) {
                    int targetIdx = col * 42 + targetRow * 6;
                    PlayField_0[targetIdx] = PlayField_0[curIdx];
                    PlayField_0[curIdx] = 0;
                    
                    // Initialize vertical animation offset (start at old position)
                    anim_offset_y[targetIdx] = (row - targetRow) * BUBBLE_SIZE;
                    anim_offset_x[targetIdx] = 0;
                    animations_active = TRUE;
                }
                targetRow--;
            }
        }
    }

    // 2. Column Shifting: Branch based on Style
    if (setup_data_0 == 3) { // MegaShift
        // Left half: shift right towards index 4
        for (int c = 3; c >= 0; c--) {
            BOOL isEmpty = TRUE;
            for (int r = 0; r < GRID_ROWS; r++) if (PlayField_0[c * 42 + r * 6] != 0) { isEmpty = FALSE; break; }
            if (isEmpty) {
                // Find first non-empty column to the left
                for (int c2 = c - 1; c2 >= 0; c2--) {
                    BOOL isOtherEmpty = TRUE;
                    for (int r = 0; r < GRID_ROWS; r++) if (PlayField_0[c2 * 42 + r * 6] != 0) { isOtherEmpty = FALSE; break; }
                    if (!isOtherEmpty) {
                        for (int r = 0; r < GRID_ROWS; r++) {
                            PlayField_0[c * 42 + r * 6] = PlayField_0[c2 * 42 + r * 6];
                            PlayField_0[c2 * 42 + r * 6] = 0;
                            if (PlayField_0[c * 42 + r * 6] != 0) {
                                anim_offset_x[c * 42 + r * 6] = (c2 - c) * BUBBLE_SIZE;
                                anim_offset_y[c * 42 + r * 6] = 0;
                                animations_active = TRUE;
                            }
                        }
                        break;
                    }
                }
            }
        }
        // Right half: shift left towards index 5
        for (int c = 6; c < GRID_COLS; c++) {
            BOOL isEmpty = TRUE;
            for (int r = 0; r < GRID_ROWS; r++) if (PlayField_0[c * 42 + r * 6] != 0) { isEmpty = FALSE; break; }
            if (isEmpty) {
                // Find first non-empty column to the right
                for (int c2 = c + 1; c2 < GRID_COLS; c2++) {
                    BOOL isOtherEmpty = TRUE;
                    for (int r = 0; r < GRID_ROWS; r++) if (PlayField_0[c2 * 42 + r * 6] != 0) { isOtherEmpty = FALSE; break; }
                    if (!isOtherEmpty) {
                        for (int r = 0; r < GRID_ROWS; r++) {
                            PlayField_0[c * 42 + r * 6] = PlayField_0[c2 * 42 + r * 6];
                            PlayField_0[c2 * 42 + r * 6] = 0;
                            if (PlayField_0[c * 42 + r * 6] != 0) {
                                anim_offset_x[c * 42 + r * 6] = (c2 - c) * BUBBLE_SIZE;
                                anim_offset_y[c * 42 + r * 6] = 0;
                                animations_active = TRUE;
                            }
                        }
                        break;
                    }
                }
            }
        }
    } else { // Standard / Other
        int targetCol = 0;
        for (int col = 0; col < GRID_COLS; col++) {
            BOOL isEmpty = TRUE;
            for (int row = 0; row < GRID_ROWS; row++) if (PlayField_0[col * 42 + row * 6] != 0) { isEmpty = FALSE; break; }
            if (!isEmpty) {
                if (col != targetCol) {
                    for (int row = 0; row < GRID_ROWS; row++) {
                        PlayField_0[targetCol * 42 + row * 6] = PlayField_0[col * 42 + row * 6];
                        PlayField_0[col * 42 + row * 6] = 0;
                        if (PlayField_0[targetCol * 42 + row * 6] != 0) {
                            anim_offset_x[targetCol * 42 + row * 6] = (col - targetCol) * BUBBLE_SIZE;
                            anim_offset_y[targetCol * 42 + row * 6] = 0;
                            animations_active = TRUE;
                        }
                    }
                }
                targetCol++;
            }
        }
    }
}

// Check_End_Game: Determines if any valid moves remain and finalizes score
void Check_End_Game(void) {
    BOOL moves_left = FALSE;
    int remaining_bubbles = 0;
    
    // Efficiently check for any group of >= 2 bubbles without destroying CheckGrid
    for (int col = 0; col < GRID_COLS && !moves_left; col++) {
        for (int row = 0; row < GRID_ROWS && !moves_left; row++) {
            int idx = col * 42 + row * 6;
            unsigned char color = PlayField_0[idx];
            if (color != 0) {
                remaining_bubbles++;
                // Check right neighbor
                if (col + 1 < GRID_COLS && PlayField_0[(col + 1) * 42 + row * 6] == color) moves_left = TRUE;
                // Check bottom neighbor
                if (row + 1 < GRID_ROWS && PlayField_0[col * 42 + (row + 1) * 6] == color) moves_left = TRUE;
            }
        }
    }
    
    // Also count all bubbles to calculate exact remaining if we exited early
    if (!moves_left) {
        remaining_bubbles = 0;
        for (int i = 0; i < 512; i++) {
            if (PlayField_0[i] != 0 && (i % 6) == i % 6) { // naive iteration
                // check if it's actually in grid bounds (0-9 cols, 0-6 rows)
                int c = i / 42;
                int r = (i % 42) / 6;
                if (c < 10 && r < 7 && PlayField_0[i] != 0) {
                    remaining_bubbles++;
                }
            }
        }
        
        // Calculate Bonus (classic Bubblet rule: 0 bubbles = 1000 minus something? Defaulting to 1000 for perfect clear, otherwise 0)
        bubble_bonus_0 = (remaining_bubbles == 0) ? 1000 : 0;
        
        last_total_score_0 = current_game_score + bubble_bonus_0;
        games_played_0++;
        total_score_history_0 += last_total_score_0;
        
        if (games_played_0 > 0) {
            average_score_0 = total_score_history_0 / games_played_0;
        }
        
        // Check Highscore
        if (last_total_score_0 > highscore_0) {
            highscore_0 = last_total_score_0;
            is_new_highscore = TRUE;
            HAL_PlaySound("Highscore");
        } else {
            is_new_highscore = FALSE;
        }
        
        mode_0 = MODE_HIGHSCORES;
        animations_active = FALSE; // Force stop animations
        Create_Screen();
    }
}

// Update_Animations: Smoothly interpolates the bubble render offsets towards 0

void Update_Animations(float dt) {
    if (!animations_active) return;
    
    BOOL any_active = FALSE;
    float speed = 700.0f; // Snappy feel
    
    // Safety: Iterate through valid game field indices only
    for (int col = 0; col < GRID_COLS; col++) {
        for (int row = 0; row < GRID_ROWS; row++) {
            int i = col * 42 + row * 6;
            if (anim_offset_x[i] != 0.0f) {
                float move = speed * dt;
                if (anim_offset_x[i] > 0) { anim_offset_x[i] -= move; if (anim_offset_x[i] < 0) anim_offset_x[i] = 0.0f; }
                else { anim_offset_x[i] += move; if (anim_offset_x[i] > 0) anim_offset_x[i] = 0.0f; }
                if (anim_offset_x[i] != 0.0f) any_active = TRUE;
            }
            if (anim_offset_y[i] != 0.0f) {
                float move = speed * dt;
                if (anim_offset_y[i] > 0) { anim_offset_y[i] -= move; if (anim_offset_y[i] < 0) anim_offset_y[i] = 0.0f; }
                else { anim_offset_y[i] += move; if (anim_offset_y[i] > 0) anim_offset_y[i] = 0.0f; }
                if (anim_offset_y[i] != 0.0f) any_active = TRUE;
            }
        }
    }
    
    animations_active = any_active;
}

// Check_Bubbles_Clicked: Handle grid interaction
void Check_Bubbles_Clicked(int mouseX, int mouseY) {
    // Convert screen coordinates to grid coordinates
    int col = (mouseX - GRID_X_OFFSET) / BUBBLE_SIZE;
    int row = (mouseY - GRID_Y_OFFSET) / BUBBLE_SIZE;

    if (col < 0 || col >= GRID_COLS || row < 0 || row >= GRID_ROWS) return;

    int index = col * 42 + row * 6;
    int color = PlayField_0[index];

    if (color == 0) return;

    // If bubbles were already marked and user clicked a marked bubble, pop them
    if (bubbles_marked_0 && CheckGrid[index] == 1) {
        // Popping action
        int n = number_bubbles_marked_0;
        current_game_score += (n - 1) * n;

        for (int i = 0; i < 512; i++) {
            if (CheckGrid[i] == 1) {
                PlayField_0[i] = 0;
                CheckGrid[i] = 0;
            }
        }
        
        bubbles_marked_0 = 0;
        number_bubbles_marked_0 = 0;
        
        Update_Bubble(); 
        HAL_PlaySound("Megapop"); 
    } else {
        // Selection action
        memset(CheckGrid, 0, 512);
        int count = FloodFillGrid(col, row, color, CheckGrid);
        if (count >= 2) {
            bubbles_marked_0 = 1;
            number_bubbles_marked_0 = count;
            HAL_PlaySound("Click"); // Selection should be a click, not megapop
        } else {
            bubbles_marked_0 = 0;
            number_bubbles_marked_0 = 0;
        }
    }
    
    Check_End_Game();
    Create_Screen(); // Ensure immediate update
}

// Execute_Button: Dispatches actions based on which button was clicked
void Execute_Button(int buttonIndex) {
    switch (buttonIndex) {
        case 4: // "New" (Main Menus)
            New_Game();
            mode_0 = MODE_PLAY;
            break;
        case 7: // "End" (Play Mode)
            if (mode_0 == MODE_PLAY) {
                Check_End_Game();
                if (mode_0 == MODE_PLAY) mode_0 = MODE_HIGHSCORES;
            }
            break;
        case 5: // "Undo"
            // Originally disabled in shareware, shows info screen
            mode_0 = MODE_UNDO_INFO;
            break;
        case 2: // "Setup"
            mode_0 = MODE_SETUP;
            break;
        case 3: // "Scores"
            mode_0 = MODE_HIGHSCORES;
            HAL_PlaySound("Highscore");
            break;
        case 1: // "Help"
            mode_0 = MODE_HELP;
            break;
        case 0: // "Exit"
            exit(0);
            break;
        case 6: // "Menu" (Returns to intro)
        case 8: // "Done" (from Scoreboard)
            mode_0 = MODE_INTRO;
            HAL_PlaySound("Intro");
            break;
        case 9: // "New" (from Scoreboard)
            New_Game();
            mode_0 = MODE_PLAY;
            break;
        case 10: // "OK" (Help)
            // Original: clicking somewhere in Help might go to Credits
            mode_0 = MODE_CREDITS; 
            break;
        case 12: // "OK" (Undo Info)
        case 13: // "OK" (Register Info)
            mode_0 = MODE_INTRO;
            HAL_PlaySound("Intro");
            break;
        case 14: // "Register" (Credits)
            mode_0 = MODE_REGISTER_INFO;
            break;
        default:
            break;
    }
    HAL_PlaySound("Click");
    Create_Screen();
}

// Undo_Move: Restores the previous grid state
void Undo_Move(void) {
    if (undo_0 != 0) {
        // Restore PlayField from undo buffer
        // ... (Logic to copy undo_buffer to PlayField_0)
        undo_0 = 0;
        bubbles_marked_0 = 0;
        Create_Screen();
    }
}
