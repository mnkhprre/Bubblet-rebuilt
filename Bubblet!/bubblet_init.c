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
  Load_Config();

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
  watermark_pic_0 = HAL_LoadResource(105);
  statistics_bg_pic_0 = HAL_LoadResource(104);
  pic_0 = HAL_LoadResource(103); // Correct high-res logo ID instead of 128

  // Initialize Buttons — CONFIRMED resource IDs from Diagnostic Mode:
  // 116=New, 118=End, 120=OK, 122=Done, 124=Reset, 126=Register, 134=Undo

  // Bottom navigation (always visible)
  SetupButton(0, 6, 376, 108, 109, 0xFF);   // Exit
  SetupButton(1, 74, 376, 110, 111, 0xFF);  // Help (?)
  SetupButton(2, 142, 376, 112, 113, 0xFF); // Setup
  SetupButton(3, 210, 376, 114, 115, 0xFF); // Scores

  // Bottom button 4: "New" on menu screens (NOT play mode)
  SetupButton(4, 278, 376, 116, 117, 0xF0); // 116 = New ✓

  // Play-mode specific buttons
  SetupButton(5, 420, 376, 134, 135,
              MODE_PLAY); // 134 = Undo (far right in play)
  SetupButton(7, 278, 376, 118, 119, MODE_PLAY); // 118 = End ✓

  // Scoreboard paper buttons (Highscores / Statistics: OK and Reset)
  SetupButton(8, 181, 292, 120, 121, MODE_HIGHSCORES); // 120 = OK
  SetupButton(9, 253, 292, 124, 125, MODE_HIGHSCORES); // 124 = Reset

  // Info screen paper buttons (OK = 120)
  SetupButton(10, 215, 277, 120, 121, MODE_HELP);          // OK
  SetupButton(11, 215, 277, 120, 121, MODE_CREDITS);       // OK
  SetupButton(12, 215, 230, 120, 121, MODE_UNDO_INFO);     // OK
  SetupButton(13, 215, 275, 120, 121, MODE_REGISTER_INFO); // Centered OK

  // Register button on Credits screen
  SetupButton(14, 250, 277, 126, 127, MODE_CREDITS); // 126 = Register

  // OK button for Setup screen
  SetupButton(15, 215, 275, 120, 121, MODE_SETUP); // 120 = OK

  button_ctr_0 = 16;

  // Start with a new game ready (logic-wise)
  New_Game();

  SDL_Delay(100); // Wait 100ms for audio sub-system to be ready
  HAL_PlaySound("Boing");

  return TRUE;
}
