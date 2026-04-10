#include "bubblet_globals.h"

// ShowText: Renders text using HAL
void ShowText(SurfaceHandle dest, int x, int y, const char *szText,
              COLORREF color) {
  HAL_DrawText(dest, x, y, szText, color, FALSE);
}

// ShowTextCenter: Renders centered text using HAL
void ShowTextCenter(SurfaceHandle dest, int x, int y, const char *szText,
                    COLORREF color) {
  HAL_DrawText(dest, x, y, szText, color, TRUE);
}

// DrawLine: Renders a line using HAL
void DrawLine(int x1, int y1, int x2, int y2, COLORREF color,
              SurfaceHandle dest) {
  HAL_DrawLine(dest, x1, y1, x2, y2, color);
}

// Draw_Buttons: Iterates through defined buttons and renders them based on
// visibility and state
void Draw_Buttons(void) {
  for (int i = 0; i < button_ctr_0; i++) {
    GameButton *btn = &buttons_0[i];

    // Visibility & State Rules:
    BOOL isDisabled = FALSE;
    BOOL isOverlayMode = (mode_0 != MODE_INTRO && mode_0 != MODE_PLAY);

    if (btn->visibilityMode == 0xFF) {
      // Main navigation buttons are visible but DIMMED when an overlay is
      // active.
      if (isOverlayMode)
        isDisabled = TRUE;
    } else if (btn->visibilityMode == 0xF0) {
      // 'New' button (0xF0) is hidden in Play mode, but dimmed in overlays.
      if (mode_0 == MODE_PLAY)
        continue;
      if (isOverlayMode)
        isDisabled = TRUE;
    } else if (btn->visibilityMode == MODE_PLAY) {
      // Play-mode buttons (End/Undo) are ONLY visible in Play mode.
      // Hidden entirely in overlays like Setup, Help, Scores.
      if (mode_0 != MODE_PLAY)
        continue;
    } else {
      // Menu-specific buttons (OK, Reset) must match current mode exactly.
      if (btn->visibilityMode != (int)mode_0)
        continue;
    }

    // Apply dimming if disabled
    if (isDisabled) {
      if (btn->lpSurfaceNormal)
        SDL_SetTextureColorMod((SDL_Texture *)btn->lpSurfaceNormal, 80, 80, 80);
      if (btn->lpSurfacePressed)
        SDL_SetTextureColorMod((SDL_Texture *)btn->lpSurfacePressed, 80, 80,
                               80);
    }

    // Draw the button
    SurfaceHandle surface =
        btn->isPressed ? btn->lpSurfacePressed : btn->lpSurfaceNormal;
    if (surface) {
      HAL_DrawSurface(surface, NULL, btn->x1, btn->y1, TRUE);
    }

    // Reset color mod
    if (isDisabled) {
      if (btn->lpSurfaceNormal)
        SDL_SetTextureColorMod((SDL_Texture *)btn->lpSurfaceNormal, 255, 255,
                               255);
      if (btn->lpSurfacePressed)
        SDL_SetTextureColorMod((SDL_Texture *)btn->lpSurfacePressed, 255, 255,
                               255);
    }
  }
}

// Create_Game_Screen: Game grid rendering using HAL
void Create_Game_Screen(void) {
  HAL_Clear(NULL); // Clear renderer
  HAL_DrawSurface(bk_pic_0, NULL, 0, 0, FALSE);

  // Draw grid
  for (int col = 0; col < GRID_COLS; col++) {
    for (int row = 0; row < GRID_ROWS; row++) {
      int index = col * 42 + row * 6;
      unsigned char bubbleType = PlayField_0[index];
      if (bubbleType != 0) {
        int x = col * BUBBLE_SIZE + GRID_X_OFFSET + (int)anim_offset_x[index];
        int y = row * BUBBLE_SIZE + GRID_Y_OFFSET + (int)anim_offset_y[index];
        HAL_DrawSurface(bubble_pics[bubbleType - 1], NULL, x, y, TRUE);
      }
    }
  }

  // Draw red perimeter for selected bubbles
  if (number_bubbles_marked_0 > 0) {
    COLORREF red = RGB(255, 0, 0);
    for (int col = 0; col < GRID_COLS; col++) {
      for (int row = 0; row < GRID_ROWS; row++) {
        int index = col * 42 + row * 6;
        if (PlayField_0[index] != 0 && CheckGrid[index] == 1) {
          int x = col * BUBBLE_SIZE + GRID_X_OFFSET + (int)anim_offset_x[index];
          int y = row * BUBBLE_SIZE + GRID_Y_OFFSET + (int)anim_offset_y[index];

          // Top edge
          if (row == 0 || CheckGrid[col * 42 + (row - 1) * 6] == 0) {
            HAL_DrawLine(NULL, x, y, x + BUBBLE_SIZE - 1, y, red);
          }
          // Bottom edge
          if (row == GRID_ROWS - 1 ||
              CheckGrid[col * 42 + (row + 1) * 6] == 0) {
            HAL_DrawLine(NULL, x, y + BUBBLE_SIZE - 1, x + BUBBLE_SIZE - 1,
                         y + BUBBLE_SIZE - 1, red);
          }
          // Left edge
          if (col == 0 || CheckGrid[(col - 1) * 42 + row * 6] == 0) {
            HAL_DrawLine(NULL, x, y, x, y + BUBBLE_SIZE - 1, red);
          }
          // Right edge
          if (col == GRID_COLS - 1 ||
              CheckGrid[(col + 1) * 42 + row * 6] == 0) {
            HAL_DrawLine(NULL, x + BUBBLE_SIZE - 1, y, x + BUBBLE_SIZE - 1,
                         y + BUBBLE_SIZE - 1, red);
          }
        }
      }
    }
  }

  // Draw Status Bar above buttons
  char statusBuf[128];
  int points = 0;
  if (number_bubbles_marked_0 > 1) {
    points = number_bubbles_marked_0 * (number_bubbles_marked_0 - 1);
  }
  const char *modeNames[] = {"Standard", "Continuous", "Shifter", "MegaShift"};
  const char *modeName = (setup_data_0 >= 0 && setup_data_0 <= 3)
                             ? modeNames[setup_data_0]
                             : "Unknown";
  sprintf(statusBuf, "Score: %d  Pts: %d  Sel: %d  [%s]", current_game_score,
          points, number_bubbles_marked_0, modeName);

  // Status box area
  ShowText(NULL, 15, 345, statusBuf, 0xFFFFFF);

  Draw_Buttons();
}

// Create_Screen: Main mode dispatcher
void Create_Screen(void) {
  HAL_Clear(NULL);
  // Always draw background by default to avoid black screens
  HAL_DrawSurface(bk_pic_0, NULL, 0, 0, FALSE);

  switch (mode_0) {
  case MODE_INTRO:
    HAL_DrawSurface(pic_0, NULL, 12, 40, TRUE);
    // Draw SHAREWARE-VERSION text under the exclamation mark
    ShowText(NULL, 267, 145, "SHAREWARE-VERSION", 0xFFFFFF);

    // Shareware Text Block (Centered)
    ShowTextCenter(NULL, 246, 160, "This is the Shareware-Version of Bubblet.",
                   0xFFFFFF);
    ShowTextCenter(NULL, 246, 180,
                   "Feel free to distribute it how ever you want!", 0xFFFFFF);
    ShowTextCenter(NULL, 246, 210, "For the actual version of Bubblet visit",
                   0xFFFFFF);
    ShowTextCenter(NULL, 246, 230, "our Homepage: www.hobsoft.de", 0xFFFFFF);
    ShowTextCenter(NULL, 246, 260, "Please support the concept of Shareware",
                   0xFFFFFF);
    ShowTextCenter(NULL, 246, 280, "and register Bubblet!", 0xFFFFFF);

    // Instruction Status Bar
    ShowText(NULL, 15, 345, "Click 'New' to start a new game!", 0xFFFFFF);

    Draw_Buttons();
    break;
  case MODE_PLAY:
    Create_Game_Screen();
    break;
  case MODE_SETUP:
    HAL_DrawSurface(paper_pic_0, NULL, 8, 6, TRUE);
    HAL_DrawSurface(setup_map_pic_0, NULL, 73, 65, TRUE);

    // Draw game style check
    int styleY[] = {97, 126, 159, 190};
    HAL_DrawSurface(checked_box_pic_0, NULL, 99, styleY[setup_data_0], TRUE);

    // Draw sound check
    if (sound_enabled_0)
      HAL_DrawSurface(checked_box_pic_0, NULL, 279, 77, TRUE);

    // Draw animation check
    if (animations_enabled_0)
      HAL_DrawSurface(checked_box_pic_0, NULL, 279, 120, TRUE);

    ShowText(NULL, 15, 345, "Let's change something...", 0xFFFFFF);
    Draw_Buttons();
    break;
  case MODE_GAMEOVER: {
    HAL_DrawSurface(paper_pic_0, NULL, 8, 6, TRUE);
    HAL_DrawSurface(gameover_labels_pic_0, NULL, 110, 45, TRUE); // Label block
    
    char buf[64];
    int modeIdx = setup_data_0;
    if (modeIdx < 0 || modeIdx > 3) modeIdx = 0;
    
    sprintf(buf, "%d", current_game_score);
    ShowText(NULL, 340, 115, buf, 0x000000);
    
    sprintf(buf, "%d", bubble_bonus_0);
    ShowText(NULL, 340, 147, buf, 0x000000);
    
    sprintf(buf, "%d", last_total_score_0);
    ShowText(NULL, 340, 179, buf, 0x000000);
    
    sprintf(buf, "%d", average_score_0[modeIdx]);
    ShowText(NULL, 340, 211, buf, 0x000000);
    
    sprintf(buf, "%d", games_played_0[modeIdx]);
    ShowText(NULL, 340, 243, buf, 0x000000);
    
    // Status Bar
    ShowText(NULL, 15, 345, "Game Over!", 0xFFFFFF);
    Draw_Buttons();
    break;
  }
  case MODE_HIGHSCORES:
    HAL_DrawSurface(paper_pic_0, NULL, 8, 6, TRUE);

    // Draw the foundational 'base' for the score table (Bitmap 104)
    HAL_DrawSurface(statistics_bg_pic_0, NULL, 73, 62, TRUE);

    // Rows loop follows...
    for (int i = 0; i < 4; i++) {
      int g = games_played_0[i];
      int a = average_score_0[i];
      int h = high_score_0[i];

      char buf[32];

      // Games Column - Using 32px row height and 148px start Y for better
      // alignment
      sprintf(buf, "%d", g);
      ShowTextCenter(NULL, 212, 148 + i * 32, buf, 0x000000);

      // Average Column
      sprintf(buf, "%d", a);
      ShowTextCenter(NULL, 292, 148 + i * 32, buf, 0x000000);

      // High Column
      sprintf(buf, "%d", h);
      ShowTextCenter(NULL, 372, 148 + i * 32, buf, 0x000000);
    }

    ShowText(NULL, 15, 345, "Click 'Reset' to clear the damn thing...",
             0xFFFFFF);
    Draw_Buttons();
    break;

  case MODE_HELP:
    HAL_DrawSurface(paper_pic_0, NULL, 8, 6, TRUE);

    Draw_Buttons();
    break;

  case MODE_CREDITS:
    HAL_DrawSurface(bk_pic_0, NULL, 0, 0, FALSE);
    HAL_DrawSurface(paper_x_pic_0, NULL, 8, 6, TRUE);

    // Development Team
    ShowText(NULL, 50, 40, "Bubblet v1.0", 0x000000);
    HAL_DrawLine(NULL, 50, 60, 420, 60, 0x000000);
    ShowText(NULL, 50, 75, "Programming: Daniel Klein", 0x000000);
    ShowText(NULL, 50, 90, "Testers: M. Boese, M. Jakubasch, C. Heinen",
             0x000000);
    ShowText(NULL, 50, 105,
             "Greetings: Heidi Amling, Daniel Gerber, Peter Gladigau,",
             0x000000);
    ShowText(NULL, 50, 120,
             "Alexander Hegener, Joerg Heil, Sebastian Jude, Tobias Pohl,",
             0x000000);
    ShowText(NULL, 50, 135,
             "Hendrik Pueltz, Tyrell, Nico, Bjoern, Nina, Eva and Peter Weber",
             0x000000);

    HAL_DrawLine(NULL, 160, 155, 330, 155, 0x000000);

    // Registration Details
    ShowTextCenter(NULL, 246, 170, "House of Bytes Software", 0x000000);
    ShowTextCenter(NULL, 246, 185, "c/o Daniel Klein, Walzenrather Str. 5",
                   0x000000);
    ShowTextCenter(NULL, 246, 200, "53819 Neunkirchen, Germany", 0x000000);

    ShowTextCenter(NULL, 246, 225, "Please include your E-Mail Address!",
                   0x000000);
    ShowTextCenter(NULL, 246, 240, "Registered version sent via E-Mail!",
                   0x000000);
    ShowTextCenter(NULL, 246, 265, "Thank you for supporting Shareware!",
                   0x000000);
    ShowText(NULL, 15, 345, "The creators of Bubblet...", 0xFFFFFF);
    Draw_Buttons();
    break;

  case MODE_UNDO_INFO:
    HAL_DrawSurface(paper_x_pic_0, NULL, 8, 6, TRUE);

    ShowTextCenter(NULL, 246, 100, "Undo is the only thing that's not working",
                   0x000000);
    ShowTextCenter(NULL, 246, 120, "in the Shareware-Version of Bubblet! ;-)",
                   0x000000);

    ShowTextCenter(NULL, 246, 170, "Please Register!", 0x000000);

    ShowText(NULL, 15, 345, "hehe...", 0xFFFFFF);
    Draw_Buttons();
    break;

  case MODE_REGISTER_INFO:
    HAL_DrawSurface(paper_pic_0, NULL, 8, 6, TRUE);
    ShowTextCenter(NULL, 246, 50,
                   "Bubblet is Shareware and costs only $10 (15DM).", 0x000000);
    ShowTextCenter(
        NULL, 246, 65,
        "In order to register Bubblet send money (or Money-Order) to:",
        0x000000);

    HAL_DrawLine(NULL, 160, 80, 330, 80, 0x000000);

    ShowTextCenter(NULL, 246, 85, "House of Bytes Software", 0x000000);
    ShowTextCenter(NULL, 246, 100, "c/o Daniel Klein", 0x000000);
    ShowTextCenter(NULL, 246, 115, "Walzenrather Str. 5", 0x000000);
    ShowTextCenter(NULL, 246, 130, "53819 Neunkirchen", 0x000000);
    ShowTextCenter(NULL, 246, 145, "Germany", 0x000000);

    HAL_DrawLine(NULL, 160, 165, 330, 165, 0x000000);

    ShowTextCenter(NULL, 246, 175, "Please include your E-Mail Address!",
                   0x000000);
    ShowTextCenter(NULL, 246, 190,
                   "The registered Version will be sent to you via E-Mail!",
                   0x000000);
    ShowTextCenter(NULL, 246, 205,
                   "Once registered, you're registered forever!", 0x000000);
    ShowTextCenter(
        NULL, 246, 220,
        "All registered Users receive future updates directly via E-Mail!",
        0x000000);

    ShowTextCenter(NULL, 246, 250,
                   "Thank you for supporting the concept of Shareware!",
                   0x000000);

    ShowText(NULL, 15, 345, "How to register Bubblet...", 0xFFFFFF);
    Draw_Buttons();
    break;
  default:
    break;
  }
  // HAL_Present() removed from here to centralize in main loop
}
