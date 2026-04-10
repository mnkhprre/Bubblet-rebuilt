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
    // Rules for visibility:
    // vis == 0xFF: Always visible in "Menu-like" modes (Intro, Help, Setup,
    // Scores) vis == 0: Only in MODE_INTRO vis == 2: Only in MODE_PLAY vis ==
    // 3: Only in MODE_SETUP vis == 4: Only in MODE_HIGHSCORES

    BOOL visible = FALSE;
    if (btn->visibilityMode == 0xFF)
      visible = TRUE;
    else if (btn->visibilityMode == 0 && mode_0 == MODE_INTRO)
      visible = TRUE;
    else if (btn->visibilityMode == MODE_PLAY && mode_0 == MODE_PLAY)
      visible = TRUE;
    else if (btn->visibilityMode == MODE_SETUP && mode_0 == MODE_SETUP)
      visible = TRUE;
    else if (btn->visibilityMode == MODE_HIGHSCORES &&
             mode_0 == MODE_HIGHSCORES)
      visible = TRUE;
    else if (btn->visibilityMode == 0xF0 && mode_0 != MODE_PLAY)
      visible = TRUE;

    if (visible) {
      SurfaceHandle surface =
          btn->isPressed ? btn->lpSurfacePressed : btn->lpSurfaceNormal;
      if (surface) {
        HAL_DrawSurface(surface, NULL, btn->x1, btn->y1, TRUE);
      }
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

        // Show selection by shifting bubbles slightly
        if (CheckGrid[index] == 1) {
          x -= 2;
          y -= 2;
        }

        HAL_DrawSurface(bubble_pics[bubbleType - 1], NULL, x, y, TRUE);
      }
    }
  }

  // Draw Status Bar above buttons
  char statusBuf[128];
  int points = 0;
  if (number_bubbles_marked_0 > 1) {
    points = number_bubbles_marked_0 * (number_bubbles_marked_0 - 1);
  }
  sprintf(statusBuf, "Score: %d Bubble-Points: %d -- %d Bubbles selected.",
          current_game_score, points, number_bubbles_marked_0);

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
    HAL_DrawSurface(pic_0, NULL, 50, 40, TRUE);

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

    Draw_Buttons();
    break;
  case MODE_HIGHSCORES:
    HAL_DrawSurface(paper_pic_0, NULL, 8, 6, TRUE);

    ShowTextCenter(NULL, 256, 50, "Your Score:", 0x000000);

    char buf[64];
    sprintf(buf, "%d", current_game_score);
    ShowText(NULL, 130, 100, "Game Score:", 0x000000);
    ShowText(NULL, 300, 100, buf, 0x000000);

    sprintf(buf, "%d", bubble_bonus_0);
    ShowText(NULL, 130, 125, "Bubble Bonus:", 0x000000);
    ShowText(NULL, 300, 125, buf, 0x000000);

    sprintf(buf, "%d", last_total_score_0);
    ShowText(NULL, 130, 150, "Total Score:", 0x000000);
    ShowText(NULL, 300, 150, buf, 0xFF0000); // Red text

    sprintf(buf, "%d", average_score_0);
    ShowText(NULL, 130, 175, "Average Score:", 0x000000);
    ShowText(NULL, 300, 175, buf, 0x000000);

    sprintf(buf, "%d", games_played_0);
    ShowText(NULL, 130, 200, "Games Played:", 0x000000);
    ShowText(NULL, 300, 200, buf, 0x000000);

    if (is_new_highscore) {
      ShowText(NULL, 20, 280, "You have a new highscore!!", 0xFFFFFF);
    }

    Draw_Buttons();
    break;
  case MODE_HELP:
    HAL_DrawSurface(paper_pic_0, NULL, 8, 6, TRUE);
    ShowTextCenter(NULL, 256, 40, "How to Play", 0x000000);
    ShowText(NULL, 50, 80, "The goal of Bubblet is to remove groups of",
             0x000000);
    ShowText(NULL, 50, 100, "identically colored bubbles. The larger the",
             0x000000);
    ShowText(NULL, 50, 120, "group, the more points you get!", 0x000000);
    ShowText(NULL, 50, 150, "Click once to select a group, click again",
             0x000000);
    ShowText(NULL, 50, 170, "to remove it. Bubbles will fall down and",
             0x000000);
    ShowText(NULL, 50, 190, "collapse to the left.", 0x000000);
    ShowTextCenter(NULL, 256, 240, "Clear the board for a big bonus!",
                   0x000000);

    Draw_Buttons();
    break;

  case MODE_CREDITS:
    HAL_DrawSurface(paper_pic_0, NULL, 8, 6, TRUE);
    ShowText(NULL, 60, 40, "Bubblet v1.0", 0x000000);
    ShowText(NULL, 60, 70, "Programming: Daniel Klein", 0x000000);
    ShowText(NULL, 60, 90, "Copyright (c) 1999 by House of Bytes Software",
             0x000000);
    ShowText(NULL, 60, 110, "All rights reserved.", 0x000000);
    ShowText(NULL, 60, 140, "Testers: Martin Boese, Markus Jakubasch,",
             0x000000);
    ShowText(NULL, 60, 160, "Christian Heinen.", 0x000000);
    ShowText(NULL, 60, 180, "Original game by Frank Fejes (oopdreams.com)",
             0x000000);
    ShowText(NULL, 60, 210, "Greetings to: Heidi Amling, Daniel Gerber,",
             0x000000);
    ShowText(NULL, 60, 230, "Peter Gladigau, Alexander Hegener, Jörg Heil.",
             0x000000);

    Draw_Buttons();
    break;
  default:
    break;
  }
  // HAL_Present() removed from here to centralize in main loop
}
