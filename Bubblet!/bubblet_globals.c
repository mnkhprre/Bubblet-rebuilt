#include "bubblet_globals.h"

// SDL2 HAL Globals
SurfaceHandle dd_Primary = NULL;
void *dd_Clipper = NULL;
SurfaceHandle v_screen = NULL;

GameMode mode_0 = MODE_INTRO;
GameMode last_mode_0 = MODE_INTRO;
int main_btn_mask_0 = 0;
int bubbles_marked_0 = 0;
int game_busy_0 = 0;
int waitanim_0 = 0;
int highscore_0 = 0;
int undo_0 = 0;
int number_bubbles_marked_0 = 0;
int game_type_0 = 0;
int show_game_score_0 = 0;

// PlayField and Grid data
// Original size based on indexing: col*42 + row*6. max index 462.
unsigned char PlayField_0[512] = {0};
unsigned char CheckGrid[512] = {0};
unsigned short PlayField_Y[512] = {0};
unsigned char *buttons_ptr_0 = NULL;
int button_ctr_0 = 0;
GameButton buttons_0[20] = {{0}};
int pressed_button_0 = -1;

// Score Tracking (Arrays for 4 modes: Normal, Continuous, Shifter, MegaShift)
int games_played_0[4] = {0, 0, 0, 0};
int bubble_bonus_0 = 0;
int last_total_score_0 = 0;
int average_score_0[4] = {0, 0, 0, 0};
int high_score_0[4] = {0, 0, 0, 0};
long long total_score_history_0[4] = {0, 0, 0, 0};
BOOL is_new_highscore = FALSE;

// Animation Offsets
float anim_offset_x[512] = {0};
float anim_offset_y[512] = {0};
BOOL animations_active = FALSE;
WindowHandle main_hWnd = NULL;

int game_score_0 = 0;
int current_game_score = 0;
int setup_data_0 = 0;

// Surfaces
SurfaceHandle bk_pic_0 = NULL;
SurfaceHandle pic_0 = NULL;
SurfaceHandle paper_pic_0 = NULL;
SurfaceHandle paper_x_pic_0 = NULL;
SurfaceHandle setup_map_pic_0 = NULL;
SurfaceHandle checked_box_pic_0 = NULL;
SurfaceHandle watermark_pic_0 = NULL;
SurfaceHandle statistics_bg_pic_0 = NULL;
SurfaceHandle gameover_labels_pic_0 = NULL;
SurfaceHandle bubble_pics[5] = {NULL};

// Sound
uint32_t mci_LastError = 0;

// Internal tracking
int _DAT_00421e50 = 0;
int _DAT_00421e54 = 0;
BOOL game_initialized = FALSE;
int sound_enabled_0 = 1;
int animations_enabled_0 = 1;
