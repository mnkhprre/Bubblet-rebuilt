#include "bubblet_globals.h"

void Save_Config(void) {
    FILE* f = fopen("bubblet.cfg", "wb");
    if (!f) return;
    
    // Header/Version (optional but good practice)
    uint32_t version = 0x0100;
    fwrite(&version, sizeof(version), 1, f);
    
    // Settings
    fwrite(&sound_enabled_0, sizeof(int), 1, f);
    fwrite(&animations_enabled_0, sizeof(int), 1, f);
    fwrite(&setup_data_0, sizeof(int), 1, f);
    
    // Multi-mode Stats
    fwrite(games_played_0, sizeof(int), 4, f);
    fwrite(average_score_0, sizeof(int), 4, f);
    fwrite(high_score_0, sizeof(int), 4, f);
    fwrite(total_score_history_0, sizeof(long long), 4, f);
    
    fclose(f);
}

void Load_Config(void) {
    FILE* f = fopen("bubblet.cfg", "rb");
    if (!f) return;
    
    uint32_t version;
    if (fread(&version, sizeof(version), 1, f) != 1) { fclose(f); return; }
    
    fread(&sound_enabled_0, sizeof(int), 1, f);
    fread(&animations_enabled_0, sizeof(int), 1, f);
    fread(&setup_data_0, sizeof(int), 1, f);
    
    fread(games_played_0, sizeof(int), 4, f);
    fread(average_score_0, sizeof(int), 4, f);
    fread(high_score_0, sizeof(int), 4, f);
    fread(total_score_history_0, sizeof(long long), 4, f);
    
    fclose(f);
}

void Reset_Statistics(void) {
    for (int i = 0; i < 4; i++) {
        games_played_0[i] = 0;
        average_score_0[i] = 0;
        high_score_0[i] = 0;
        total_score_history_0[i] = 0;
    }
    Save_Config();
}

// New_Game: Starts a new game by randomizing the grid
void New_Game(void) {
    game_score_0 = 0;
    current_game_score = 0;
    bubble_bonus_0 = 0;
    last_total_score_0 = 0;
    is_new_highscore = FALSE;
    number_bubbles_marked_0 = 0;
    bubbles_marked_0 = 0;
    game_busy_0 = 0;
    waitanim_0 = 0;
    animations_active = FALSE;
    memset(CheckGrid, 0, sizeof(CheckGrid));
    memset(anim_offset_x, 0, sizeof(anim_offset_x));
    memset(anim_offset_y, 0, sizeof(anim_offset_y));

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

static BOOL Is_Column_Empty(int col) {
    for (int row = 0; row < GRID_ROWS; row++) {
        if (PlayField_0[col * 42 + row * 6] != 0) return FALSE;
    }
    return TRUE;
}

static void Move_Column(int destCol, int sourceCol) {
    for (int row = 0; row < GRID_ROWS; row++) {
        int dest = destCol * 42 + row * 6;
        int source = sourceCol * 42 + row * 6;
        PlayField_0[dest] = PlayField_0[source];
        PlayField_0[source] = 0;

        if (PlayField_0[dest] != 0) {
            anim_offset_x[dest] =
                anim_offset_x[source] + (sourceCol - destCol) * BUBBLE_SIZE;
            anim_offset_y[dest] = anim_offset_y[source];
        }
        anim_offset_x[source] = 0.0f;
        anim_offset_y[source] = 0.0f;
    }
}

static void Shift_Empty_Columns_Right(void) {
    int targetCol = GRID_COLS - 1;
    for (int col = GRID_COLS - 1; col >= 0; col--) {
        if (!Is_Column_Empty(col)) {
            if (col != targetCol) Move_Column(targetCol, col);
            targetCol--;
        }
    }
}

static void Fill_Empty_Columns_Left(void) {
    int firstFilledCol = GRID_COLS;
    for (int col = 0; col < GRID_COLS; col++) {
        if (!Is_Column_Empty(col)) {
            firstFilledCol = col;
            break;
        }
    }

    for (int col = 0; col < firstFilledCol; col++) {
        for (int row = 0; row < GRID_ROWS; row++) {
            int index = col * 42 + row * 6;
            PlayField_0[index] = (unsigned char)(rand() % 5 + 1);
            anim_offset_x[index] = (col - firstFilledCol) * BUBBLE_SIZE;
            anim_offset_y[index] = 0.0f;
        }
    }
}

static void Shift_Bubbles_Right(void) {
    for (int pass = 0; pass < GRID_COLS; pass++) {
        for (int col = 0; col < GRID_COLS - 1; col++) {
            for (int row = 0; row < GRID_ROWS; row++) {
                int source = col * 42 + row * 6;
                int dest = (col + 1) * 42 + row * 6;
                if (PlayField_0[source] != 0 && PlayField_0[dest] == 0) {
                    PlayField_0[dest] = PlayField_0[source];
                    PlayField_0[source] = 0;
                    anim_offset_x[dest] = anim_offset_x[source] - BUBBLE_SIZE;
                    anim_offset_y[dest] = anim_offset_y[source];
                    anim_offset_x[source] = 0.0f;
                    anim_offset_y[source] = 0.0f;
                }
            }
        }
    }
}

// Update_Bubble: Handles gravity and column shifting
void Update_Bubble(void) {
    for (int col = 0; col < GRID_COLS; col++) {
        int targetRow = GRID_ROWS - 1;
        for (int row = GRID_ROWS - 1; row >= 0; row--) {
            int source = col * 42 + row * 6;
            if (PlayField_0[source] != 0) {
                if (row != targetRow) {
                    int dest = col * 42 + targetRow * 6;
                    PlayField_0[dest] = PlayField_0[source];
                    PlayField_0[source] = 0;
                    anim_offset_x[dest] = anim_offset_x[source];
                    anim_offset_y[dest] =
                        anim_offset_y[source] + (row - targetRow) * BUBBLE_SIZE;
                    anim_offset_x[source] = 0.0f;
                    anim_offset_y[source] = 0.0f;
                }
                targetRow--;
            }
        }
    }

    Shift_Empty_Columns_Right();
    if (setup_data_0 == 1 || setup_data_0 == 3) {
        Fill_Empty_Columns_Left();
    }
    if (setup_data_0 == 2 || setup_data_0 == 3) {
        Shift_Bubbles_Right();
    }

    animations_active = FALSE;
    for (int col = 0; col < GRID_COLS; col++) {
        for (int row = 0; row < GRID_ROWS; row++) {
            int index = col * 42 + row * 6;
            if (anim_offset_x[index] != 0.0f || anim_offset_y[index] != 0.0f) {
                animations_active = TRUE;
                break;
            }
        }
        if (animations_active) break;
    }

    if (!animations_enabled_0) {
        memset(anim_offset_x, 0, sizeof(anim_offset_x));
        memset(anim_offset_y, 0, sizeof(anim_offset_y));
        animations_active = FALSE;
    }
}

// Check_End_Game: Determines if any valid moves remain and finalizes score
void Check_End_Game(void) {
    if (mode_0 != MODE_PLAY) return;
    
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
        for (int col = 0; col < GRID_COLS; col++) {
            for (int row = 0; row < GRID_ROWS; row++) {
                if (PlayField_0[col * 42 + row * 6] != 0) {
                    remaining_bubbles++;
                }
            }
        }
        
        // Calculate Bonus (classic Bubblet rule: matching original)
        if (setup_data_0 == 0 || setup_data_0 == 2) {
            if (remaining_bubbles == 0) bubble_bonus_0 = 500;
            else if (remaining_bubbles == 1) bubble_bonus_0 = 200;
            else if (remaining_bubbles == 2) bubble_bonus_0 = 100;
            else if (remaining_bubbles == 3) bubble_bonus_0 = 50;
            else if (remaining_bubbles == 4) bubble_bonus_0 = 25;
            else bubble_bonus_0 = 0;
        } else {
            bubble_bonus_0 = 0;
        }

        if (animations_enabled_0 && animations_active) {
            waitanim_0 = 1;
            return;
        }

        waitanim_0 = 0;
        last_total_score_0 = current_game_score + bubble_bonus_0;
        
        // Update stats for the current mode
        int modeIdx = setup_data_0;
        if (modeIdx < 0 || modeIdx > 3) modeIdx = 0;
        
        games_played_0[modeIdx]++;
        total_score_history_0[modeIdx] += last_total_score_0;
        average_score_0[modeIdx] = (int)(total_score_history_0[modeIdx] / games_played_0[modeIdx]);
        
        if (last_total_score_0 > high_score_0[modeIdx]) {
            high_score_0[modeIdx] = last_total_score_0;
            is_new_highscore = TRUE;
            HAL_PlaySound("Highscore");
        } else {
            is_new_highscore = FALSE;
            HAL_PlaySound("Score");
        }
        
        // Persist to disk
        Save_Config();
        
        mode_0 = MODE_GAMEOVER;
        animations_active = FALSE; 
        Create_Screen();
    }
}

// Update_Animations: Smoothly interpolates the bubble render offsets towards 0

void Update_Animations(float dt) {
    if (!animations_enabled_0) {
        memset(anim_offset_x, 0, sizeof(anim_offset_x));
        memset(anim_offset_y, 0, sizeof(anim_offset_y));
        animations_active = FALSE;
        return;
    }

    if (!animations_active) return;
    
    BOOL any_active = FALSE;
    float speed = 320.0f; // 8 px/frame @ 40 FPS = 320 px/sec (matches original)
    
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
    BOOL didPop = FALSE;

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
        didPop = TRUE;
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
        } else {
            bubbles_marked_0 = 0;
            number_bubbles_marked_0 = 0;
        }
    }
    
    if (didPop) Check_End_Game();
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
                int modeIdx = setup_data_0;
                if (modeIdx < 0 || modeIdx > 3) modeIdx = 0;
                games_played_0[modeIdx]++;
                bubble_bonus_0 = 0;
                last_total_score_0 = current_game_score;
                is_new_highscore = FALSE;
                waitanim_0 = 0;
                Save_Config();
                HAL_PlaySound("Score");
                mode_0 = MODE_GAMEOVER;
                Create_Screen();
            }
            break;
        case 5: // "Undo"
            // Originally disabled in shareware, shows info screen
            HAL_PlaySound("Nehehe");
            mode_0 = MODE_UNDO_INFO;
            break;
        case 2: // "Setup"
            mode_0 = MODE_SETUP;
            break;
        case 3: // "Scores"
            mode_0 = MODE_HIGHSCORES;
            break;
        case 1: // "Logo" button opens Credits/Register Info
            mode_0 = MODE_CREDITS;
            break;
        case 0: // "Exit"
            exit(0);
            break;
        case 6: // "Menu" (Returns to intro)
        case 8: // "Done" (from Scoreboard)
            mode_0 = MODE_INTRO;
            break;
        case 16: // "Done" (from GameOver)
            mode_0 = MODE_INTRO;
            break;
        case 17: // "New" (from GameOver)
            New_Game();
            mode_0 = MODE_PLAY;
            break;
        case 9: // "Reset" (from Statistics)
            if (mode_0 == MODE_HIGHSCORES) {
                Reset_Statistics();
            } else {
                New_Game();
                mode_0 = MODE_PLAY;
            }
            break;
        case 10: // "OK" (Help)
        case 11: // OK (Credits)
        case 12: // OK (Undo Info)
        case 13: // OK (Register Info)
        case 15: // OK (Setup)
            if (mode_0 == MODE_HELP || mode_0 == MODE_HIGHSCORES || mode_0 == MODE_CREDITS || mode_0 == MODE_UNDO_INFO || mode_0 == MODE_REGISTER_INFO || mode_0 == MODE_SETUP) {
                mode_0 = MODE_INTRO;
            }
            break;
        case 14: // Register (from Credits)
            mode_0 = MODE_REGISTER_INFO;
            break;
        default:
            break;
    }
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
