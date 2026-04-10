#ifndef BUBBLET_GLOBALS_H
#define BUBBLET_GLOBALS_H

#include "bubblet_types.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Global Variables (Mappings from bubblet.asm)

// DirectDraw Objects / SDL Equivalents
extern void* hal_Context;                // SDL_Renderer* or DirectDraw Object
extern SurfaceHandle dd_Primary;         // 00421E40
extern void* dd_Clipper;                 // Pointer to clipper
extern SurfaceHandle v_screen;           // 00421E4C (Backbuffer)

// Game State
extern GameMode mode_0;                   // 0042010C
extern GameMode last_mode_0;               // 00420110
extern int main_btn_mask_0;               // 00420118
extern int bubbles_marked_0;              // 0042011C
extern int game_busy_0;                   // 00420120
extern int waitanim_0;                    // 00420124
extern int highscore_0;                   // 00420128
extern int undo_0;                        // 0042012C
extern int number_bubbles_marked_0;       // 00420130
extern int game_type_0;                   // 00420134
// Animation Offsets
// Standardized to 512 to match PlayField_0 and prevent out-of-bounds issues
extern float anim_offset_x[512];
extern float anim_offset_y[512];
extern int show_game_score_0;             // 00420138
extern int button_ctr_0;                  // 0042013C
extern int pressed_button_0;              // 00420140
extern WindowHandle main_hWnd;           // 00421E58

extern int game_score_0;                  // 00421EE0?
extern int current_game_score;            // 00421EE0?
extern int setup_data_0;                  // 00421EE8?

// Grid Data (Original size: col*42 + row*6, max 462)
extern unsigned char PlayField_0[512]; // 00421F04
extern unsigned char CheckGrid[512];  // 00422594
extern unsigned short PlayField_X[512]; // 004216E8
extern unsigned short PlayField_Y[512]; // 00421B28

// Surfaces/Bitmaps
extern SurfaceHandle bk_pic_0;            // 00420C8C
extern SurfaceHandle pic_0;               // 00420C70 (Intro pic)
extern SurfaceHandle paper_pic_0;         // 00420C74
extern SurfaceHandle paper_x_pic_0;       // 00420C78
extern SurfaceHandle setup_map_pic_0;     // 00420C84
extern SurfaceHandle checked_box_pic_0;   // 00420C88
extern SurfaceHandle watermark_pic_0;
extern SurfaceHandle statistics_bg_pic_0;
extern SurfaceHandle bubble_pics[5];      // 00421E90

// Buttons
extern GameButton buttons_0[20]; // 00422D40

// MCI / Sound
extern uint32_t mci_LastError; // 00421E60?

extern int _DAT_00421e50;
extern int _DAT_00421e54;
extern BOOL game_initialized;
extern int sound_enabled_0;         // 00420138?
extern int animations_enabled_0;    // 0042013c?

// Score Tracking (Arrays for 4 modes)
extern int games_played_0[4];
extern int bubble_bonus_0;
extern int last_total_score_0;
extern int average_score_0[4];
extern int high_score_0[4]; 
extern long long total_score_history_0[4];
extern BOOL is_new_highscore;

// --- HAL (Hardware Abstraction Layer) ---
BOOL HAL_Init(void);
void HAL_Shutdown(void);
SurfaceHandle HAL_LoadSurface(const char* filename);
SurfaceHandle HAL_LoadResource(int resourceId);
void HAL_DrawSurface(SurfaceHandle src, SurfaceHandle dest, int x, int y, BOOL useColorKey);
void HAL_DrawSurfaceEx(SurfaceHandle src, SurfaceHandle dest, int x, int y, int w, int h, BOOL useColorKey);
void HAL_Present(void);
void HAL_Clear(SurfaceHandle dest);
void HAL_DrawText(SurfaceHandle dest, int x, int y, const char* text, COLORREF color, BOOL center);
void HAL_DrawLine(SurfaceHandle dest, int x1, int y1, int x2, int y2, COLORREF color);
void HAL_PlaySound(const char* alias);
void HAL_ProcessEvents(void);
uint32_t HAL_GetTicks(void);

// Logic & UI dispatched from HAL
void Create_Screen(void);
void Create_Game_Screen(void);
void Draw_Buttons(void);
void Update_Bubble(void);
void New_Game(void);
void Undo_Move(void);
void Save_Config(void);
void Load_Config(void);
void Reset_Statistics(void);
void Check_Bubbles_Clicked(int mouseX, int mouseY);
void Check_Button_Down(int x, int y);
void Check_Button_Up(int x, int y);
void Check_Button_Move(int x, int y);
void Execute_Button(int buttonIndex);
BOOL Game_Init(void);
BOOL mci_PlayWave(const char* alias);

#endif // BUBBLET_GLOBALS_H
