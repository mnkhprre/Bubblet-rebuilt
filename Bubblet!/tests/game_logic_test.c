#include "bubblet_globals.h"

#include <assert.h>

static int sounds_played;
static int screens_created;

void HAL_PlaySound(const char *alias) {
  (void)alias;
  sounds_played++;
}

void Create_Screen(void) { screens_created++; }

static int GridIndex(int col, int row) { return col * 42 + row * 6; }

static void ClearGameStats(void) {
  memset(games_played_0, 0, sizeof(games_played_0));
  memset(average_score_0, 0, sizeof(average_score_0));
  memset(high_score_0, 0, sizeof(high_score_0));
  memset(total_score_history_0, 0, sizeof(total_score_history_0));
}

static void TestColumnCompaction(void) {
  memset(PlayField_0, 0, sizeof(PlayField_0));
  memset(anim_offset_x, 0, sizeof(anim_offset_x));
  memset(anim_offset_y, 0, sizeof(anim_offset_y));
  animations_active = FALSE;
  setup_data_0 = 0;
  game_type_0 = 0;
  PlayField_0[GridIndex(2, 0)] = 1;
  PlayField_0[GridIndex(2, GRID_ROWS - 1)] = 2;
  PlayField_0[GridIndex(5, GRID_ROWS - 1)] = 3;

  Update_Bubble();
  assert(PlayField_0[GridIndex(8, GRID_ROWS - 2)] == 1);
  assert(PlayField_0[GridIndex(8, GRID_ROWS - 1)] == 2);
  assert(PlayField_0[GridIndex(9, GRID_ROWS - 1)] == 3);
  assert(PlayField_0[GridIndex(2, GRID_ROWS - 1)] == 0);
  assert(anim_offset_y[GridIndex(8, GRID_ROWS - 2)] ==
         -5 * BUBBLE_SIZE);
  assert(animations_active);

  memset(PlayField_0, 0, sizeof(PlayField_0));
  memset(anim_offset_x, 0, sizeof(anim_offset_x));
  memset(anim_offset_y, 0, sizeof(anim_offset_y));
  animations_active = FALSE;
  setup_data_0 = 1;
  game_type_0 = 1;
  PlayField_0[GridIndex(2, GRID_ROWS - 1)] = 2;
  PlayField_0[GridIndex(5, GRID_ROWS - 1)] = 3;
  Update_Bubble();

  int bubbleCount = 0;
  for (int col = 0; col < GRID_COLS; col++) {
    for (int row = 0; row < GRID_ROWS; row++) {
      unsigned char bubble = PlayField_0[GridIndex(col, row)];
      if (bubble != 0)
        bubbleCount++;
      if (col < 8)
        assert(bubble >= 1 && bubble <= 5);
    }
  }
  assert(bubbleCount == 8 * GRID_ROWS + 2);
  assert(PlayField_0[GridIndex(8, GRID_ROWS - 1)] == 2);
  assert(PlayField_0[GridIndex(9, GRID_ROWS - 1)] == 3);
  assert(anim_offset_x[GridIndex(0, 0)] == -8 * BUBBLE_SIZE);
  assert(anim_offset_x[GridIndex(7, 0)] == -BUBBLE_SIZE);
  assert(animations_active);
}

static void TestShifterModes(void) {
  for (int mode = 2; mode <= 3; mode++) {
    memset(PlayField_0, 0, sizeof(PlayField_0));
    memset(anim_offset_x, 0, sizeof(anim_offset_x));
    memset(anim_offset_y, 0, sizeof(anim_offset_y));
    animations_active = FALSE;
    setup_data_0 = mode;
    game_type_0 = mode;
    PlayField_0[GridIndex(2, 0)] = 1;
    PlayField_0[GridIndex(2, GRID_ROWS - 1)] = 2;
    PlayField_0[GridIndex(5, GRID_ROWS - 1)] = 3;

    Update_Bubble();
    assert(PlayField_0[GridIndex(9, GRID_ROWS - 2)] == 1);
    assert(PlayField_0[GridIndex(8, GRID_ROWS - 1)] == 2);
    assert(PlayField_0[GridIndex(9, GRID_ROWS - 1)] == 3);
    assert(anim_offset_y[GridIndex(9, GRID_ROWS - 2)] ==
           -5 * BUBBLE_SIZE);

    int bubbleCount = 0;
    for (int col = 0; col < GRID_COLS; col++) {
      for (int row = 0; row < GRID_ROWS; row++) {
        if (PlayField_0[GridIndex(col, row)] != 0)
          bubbleCount++;
      }
    }
    assert(bubbleCount == (mode == 3 ? 8 * GRID_ROWS + 3 : 3));
    assert(animations_active);
  }
}

int main(void) {
  srand(1);
  setup_data_0 = 0;
  New_Game();

  int initializedBubbles = 0;
  for (int col = 0; col < GRID_COLS; col++) {
    for (int row = 0; row < GRID_ROWS; row++) {
      unsigned char bubble = PlayField_0[GridIndex(col, row)];
      assert(bubble >= 1 && bubble <= 5);
      initializedBubbles++;
    }
  }
  assert(initializedBubbles == GRID_COLS * GRID_ROWS);

  TestColumnCompaction();
  TestShifterModes();

  memset(PlayField_0, 0, sizeof(PlayField_0));
  memset(CheckGrid, 0, sizeof(CheckGrid));
  memset(anim_offset_x, 0, sizeof(anim_offset_x));
  memset(anim_offset_y, 0, sizeof(anim_offset_y));
  ClearGameStats();
  PlayField_0[GridIndex(0, 0)] = 2;
  PlayField_0[GridIndex(1, 0)] = 2;
  setup_data_0 = 0;
  game_type_0 = 0;
  mode_0 = MODE_PLAY;
  animations_active = FALSE;

  Check_Bubbles_Clicked(GRID_X_OFFSET, GRID_Y_OFFSET);
  assert(number_bubbles_marked_0 == 2);
  assert(mode_0 == MODE_PLAY);
  assert(games_played_0[0] == 0);

  Check_Bubbles_Clicked(GRID_X_OFFSET, GRID_Y_OFFSET);
  assert(mode_0 == MODE_GAMEOVER);
  assert(current_game_score == 2);
  assert(bubble_bonus_0 == 500);
  assert(last_total_score_0 == 502);
  assert(games_played_0[0] == 1);
  Check_End_Game();
  assert(games_played_0[0] == 1);

  ClearGameStats();
  setup_data_0 = 1;
  game_type_0 = 1;
  mode_0 = MODE_PLAY;
  current_game_score = 42;
  bubble_bonus_0 = 0;
  memset(PlayField_0, 0, sizeof(PlayField_0));
  PlayField_0[GridIndex(0, 0)] = 1;
  Check_End_Game();
  assert(mode_0 == MODE_PLAY);
  assert(games_played_0[1] == 0);

  Execute_Button(7);
  assert(mode_0 == MODE_GAMEOVER);
  assert(last_total_score_0 == 42);
  assert(bubble_bonus_0 == 0);
  assert(games_played_0[1] == 1);

  ClearGameStats();
  setup_data_0 = 0;
  game_type_0 = 0;
  mode_0 = MODE_PLAY;
  animations_active = TRUE;
  memset(PlayField_0, 0, sizeof(PlayField_0));
  PlayField_0[GridIndex(0, 0)] = 1;
  Check_End_Game();
  assert(mode_0 == MODE_PLAY);
  animations_active = FALSE;
  Check_End_Game();
  assert(mode_0 == MODE_GAMEOVER);
  assert(games_played_0[0] == 1);

  puts("Game logic tests passed.");
  return 0;
}
