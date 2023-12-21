#include <winsdk-10/Windows.h>
#include <winsdk-10/winapifamily.h>
#include <winsdk-10/windef.h>
#include <winsdk-10/wingdi.h>

void ShowTextCenter(int param_1, int param_2, int param_3, int *param_4, int param_5, int param_6, const uint16_t * param_7, COLORREF param_8)

{
    int c;

    (**(code **)(*param_4 + 0x44))();
    SetBkMode(param_3, 1);
    SetBkColor(param_3, 1);
    SetTextColor(param_3, param_8);
    SetTextAlign(param_3, 6);
    c = lstrlenA(param_7);
    int TextOutA( param_3, param_5, param_6, param_7, c);
    (**(code **)(*param_4 + 0x68))();
    return;
}
void  ShowText(int param_1, int param_2, int param_3, int *param_4, int param_5, int param_6, const uint16_t * param_7, COLORREF param_8)

{
    int c;

    (**(code **)(*param_4 + 0x44))();
    SetBkMode(param_3, 1);
    SetBkColor(param_3, 1);
    SetTextColor(param_3, param_8);
    SetTextAlign(param_3, 0);
    c = lstrlenA(param_7);
    TextOutA(param_3, param_5, param_6, param_7, c);
    (**(code **)(*param_4 + 0x68))();
    return;
}
bool  mci_OpenWave(int param_1, int param_2, int param_3, int param_4, int param_5)

{
    CHAR local_104[256];

    wsprintfA(local_104, s_open__s_type_waveaudio_alias__s_00420a2c, param_4, param_5);
    mci_LastError = mciSendStringA(local_104, (uint16_t *)0x0, 0, (HWND)0x0);
    return mci_LastError == 0;
}
bool  mci_PlayWave(int param_1, int param_2, int param_3, int param_4)

{
    CHAR local_104[256];

    wsprintfA(local_104, s_play__s_from_0_00420a55, param_4);
    mci_LastError = mciSendStringA(local_104, (uint16_t *)0x0, 0, (HWND)0x0);
    return mci_LastError == 0;
}
bool  mci_PlayWaveWait(int param_1, int param_2, int param_3, int param_4)

{
    CHAR local_104[256];

    wsprintfA(local_104, s_play__s_from_0_wait_00420a64, param_4);
    mci_LastError = mciSendStringA(local_104, (uint16_t *)0x0, 0, (HWND)0x0);
    return mci_LastError == 0;
}
void mci_PlayCD(void)

{
    int uVar1;
    CHAR local_104[256];

    wsprintfA(local_104, s_open_cdaudio_00420a80);
    mci_LastError = mciSendStringA(local_104, (uint16_t *)0x0, 0, (HWND)0x0);
    if (mci_LastError == 0)
    {
        wsprintfA(local_104, s_play_cdaudio_00420a8d);
        mci_LastError = mciSendStringA(local_104, (uint16_t *)0x0, 0, (HWND)0x0);
        if (mci_LastError == 0)
        {
            wsprintfA(local_104, s_close_cdaudio_00420a9a);
            mci_LastError = mciSendStringA(local_104, (uint16_t *)0x0, 0, (HWND)0x0);
            if (mci_LastError == 0)
            {
                uVar1 = 1;
            }
            else
            {
                uVar1 = 0;
            }
        }
        else
        {
            uVar1 = 0;
        }
    }
    else
    {
        uVar1 = 0;
    }
    return uVar1;
}

bool  mci_StopWave(int param_1, int param_2, int param_3, int param_4)

{
    CHAR local_104[256];

    wsprintfA(local_104, s_stop__s_00420a78, param_4);
    mci_LastError = mciSendStringA(local_104, (uint16_t *)0x0, 0, (HWND)0x0);
    return mci_LastError == 0;
}

bool  mci_CloseWave(int param_1, int param_2, int param_3, int param_4)

{
    CHAR local_104[256];

    wsprintfA(local_104, s_close__s_00420a4c, param_4);
    mci_LastError = mciSendStringA(local_104, (uint16_t *)0x0, 0, (HWND)0x0);
    return mci_LastError == 0;
}

void  mci_PlayCDFromTrack(int param_1, int param_2, int param_3, int param_4)

{
    int uVar1;
    CHAR local_104[256];

    wsprintfA(local_104, s_open_cdaudio_00420afc);
    mci_LastError = mciSendStringA(local_104, (uint16_t *)0x0, 0, (HWND)0x0);
    if (mci_LastError == 0)
    {
        wsprintfA(local_104, s_set_cdaudio_time_format_track_00420b09);
        mci_LastError = mciSendStringA(local_104, (uint16_t *)0x0, 0, (HWND)0x0);
        if (mci_LastError == 0)
        {
            wsprintfA(local_104, s_play_cdaudio_from__u_00420b27, param_4);
            mci_LastError = mciSendStringA(local_104, (uint16_t *)0x0, 0, (HWND)0x0);
            if (mci_LastError == 0)
            {
                wsprintfA(local_104, s_close_cdaudio_00420b3c);
                mci_LastError = mciSendStringA(local_104, (uint16_t *)0x0, 0, (HWND)0x0);
                if (mci_LastError == 0)
                {
                    uVar1 = 1;
                }
                else
                {
                    uVar1 = 0;
                }
            }
            else
            {
                uVar1 = 0;
            }
        }
        else
        {
            uVar1 = 0;
        }
    }
    else
    {
        uVar1 = 0;
    }
    return uVar1;
}
void  mci_PlayCDTrack(int param_1, int param_2, int param_3, int param_4)

{
    int uVar1;
    CHAR local_104[256];

    wsprintfA(local_104, s_open_cdaudio_00420aa8);
    mci_LastError = mciSendStringA(local_104, (uint16_t *)0x0, 0, (HWND)0x0);
    if (mci_LastError == 0)
    {
        wsprintfA(local_104, s_set_cdaudio_time_format_track_00420ab5);
        mci_LastError = mciSendStringA(local_104, (uint16_t *)0x0, 0, (HWND)0x0);
        if (mci_LastError == 0)
        {
            wsprintfA(local_104, s_play_cdaudio_from__u_to__u_00420ad3, param_4, param_4);
            mci_LastError = mciSendStringA(local_104, (uint16_t *)0x0, 0, (HWND)0x0);
            if (mci_LastError == 0)
            {
                wsprintfA(local_104, s_close_cdaudio_00420aee);
                mci_LastError = mciSendStringA(local_104, (uint16_t *)0x0, 0, (HWND)0x0);
                if (mci_LastError == 0)
                {
                    uVar1 = 1;
                }
                else
                {
                    uVar1 = 0;
                }
            }
            else
            {
                uVar1 = 0;
            }
        }
        else
        {
            uVar1 = 0;
        }
    }
    else
    {
        uVar1 = 0;
    }
    return uVar1;
}
void mci_StopC(void)

{
    int uVar1;
    CHAR local_104[256];

    wsprintfA(local_104, s_open_cdaudio_00420b4a);
    mci_LastError = mciSendStringA(local_104, (uint16_t *)0x0, 0, (HWND)0x0);
    if (mci_LastError == 0)
    {
        wsprintfA(local_104, s_stop_cdaudio_00420b57);
        mci_LastError = mciSendStringA(local_104, (uint16_t *)0x0, 0, (HWND)0x0);
        if (mci_LastError == 0)
        {
            wsprintfA(local_104, s_close_cdaudio_00420b64);
            mci_LastError = mciSendStringA(local_104, (uint16_t *)0x0, 0, (HWND)0x0);
            if (mci_LastError == 0)
            {
                uVar1 = 1;
            }
            else
            {
                uVar1 = 0;
            }
        }
        else
        {
            uVar1 = 0;
        }
    }
    else
    {
        uVar1 = 0;
    }
    return uVar1;
}
void  mci_ExecStr(int param_1, int param_2, int param_3, const uint16_t * param_4)

{
    mci_LastError = mciSendStringA(param_4, (uint16_t *)0x0, 0, (HWND)0x0);
    if (mci_LastError != 0)
    {
        return 0;
    }
    return 1;
}
void CreateSetup(void)

{
    int in_AL;
    int uVar1;
    int uVar2;
    int in_CL;
    HDC extraout_CL;
    HDC extraout_CL_00;
    HDC extraout_ECX;
    HDC extraout_ECX_00;
    HDC extraout_ECX_01;
    HDC extraout_ECX_02;
    HDC extraout_ECX_03;
    HDC extraout_ECX_04;
    HDC extraout_ECX_05;
    HDC pHVar3;
    int in_DL;
    HDC extraout_DL;
    HDC extraout_DL_00;
    HDC extraout_EDX;
    HDC extraout_EDX_00;
    HDC extraout_EDX_01;
    HDC extraout_EDX_02;
    HDC extraout_EDX_03;
    HDC extraout_EDX_04;
    HDC extraout_EDX_05;
    HDC uVar4;

    uVar1 = PutSurface(in_AL, in_DL, in_CL, 0, 0, bk_pic_0, v_screen);
    uVar1 = PutSurfaceCC(uVar1, extraout_DL, extraout_CL, 8, 6, paper_pic_0, v_screen);
    uVar2 = PutSurfaceCC(uVar1, extraout_DL_00, extraout_CL_00, 0x49, 0x41, setup_map_pic_0, v_screen);
    pHVar3 = extraout_ECX;
    uVar4 = extraout_EDX;
    if (_Str_00421ee8 == (void *)0x0)
    {
        uVar2 = PutSurfaceCC((char)uVar2, (char)extraout_EDX, (char)extraout_ECX, 99, 0x61, checked_box_pic_0,
                             v_screen);
        pHVar3 = extraout_ECX_00;
        uVar4 = extraout_EDX_00;
    }
    if (_Str_00421ee8 == (void *)0x1)
    {
        uVar2 = PutSurfaceCC((char)uVar2, (char)uVar4, (char)pHVar3, 99, 0x7e, checked_box_pic_0, v_screen);
        pHVar3 = extraout_ECX_01;
        uVar4 = extraout_EDX_01;
    }
    if (_Str_00421ee8 == (void *)0x2)
    {
        uVar2 = PutSurfaceCC((char)uVar2, (char)uVar4, (char)pHVar3, 99, 0x9f, checked_box_pic_0, v_screen);
        pHVar3 = extraout_ECX_02;
        uVar4 = extraout_EDX_02;
    }
    if (_Str_00421ee8 == (void *)0x3)
    {
        uVar2 = PutSurfaceCC((char)uVar2, (char)uVar4, (char)pHVar3, 99, 0xbe, checked_box_pic_0, v_screen);
        pHVar3 = extraout_ECX_03;
        uVar4 = extraout_EDX_03;
    }
    if (change_mode+150 == 1)
    {
        uVar2 = PutSurfaceCC((char)uVar2, (char)uVar4, (char)pHVar3, 0x117, 0x4d, checked_box_pic_0, v_screen);
        pHVar3 = extraout_ECX_04;
        uVar4 = extraout_EDX_04;
    }
    if (Check_Button_Up+26A == 1)
    {
        uVar2 = PutSurfaceCC((char)uVar2, (char)uVar4, (char)pHVar3, 0x118, 0x77, checked_box_pic_0, v_screen);
        pHVar3 = extraout_ECX_05;
        uVar4 = extraout_EDX_05;
    }
    Status_Text_0 = s_Let_s_change_something____00420212;
    ShowText(uVar2, uVar4, pHVar3, v_screen, 10, 0x160, s_Let_s_change_something____00420212,
                 0xffffff);
    Draw_Buttons();
    Update_Screen();
    return;
}
void Create_Screen(void)
{
    int uVar1;
    int uVar2;
    int in_CL;
    HDC extraout_CL;
    HDC extraout_CL_00;
    HDC extraout_CL_01;
    HDC extraout_CL_02;
    HDC extraout_CL_03;
    HDC extraout_ECX;
    HDC extraout_ECX_00;
    HDC extraout_ECX_01;
    HDC extraout_ECX_02;
    HDC extraout_ECX_03;
    HDC extraout_ECX_04;
    HDC extraout_ECX_05;
    HDC extraout_ECX_06;
    HDC extraout_ECX_07;
    HDC extraout_ECX_08;
    HDC extraout_ECX_09;
    HDC extraout_ECX_10;
    HDC extraout_ECX_11;
    HDC extraout_ECX_12;
    HDC extraout_ECX_13;
    HDC extraout_ECX_14;
    HDC extraout_ECX_15;
    HDC extraout_ECX_16;
    HDC extraout_ECX_17;
    HDC extraout_ECX_18;
    HDC extraout_ECX_19;
    HDC extraout_ECX_20;
    HDC extraout_ECX_21;
    HDC extraout_ECX_22;
    HDC extraout_ECX_23;
    HDC extraout_ECX_24;
    HDC extraout_ECX_25;
    HDC extraout_ECX_26;
    HDC extraout_ECX_27;
    HDC extraout_ECX_28;
    HDC extraout_ECX_29;
    HDC extraout_ECX_30;
    HDC extraout_ECX_31;
    HDC extraout_ECX_32;
    HDC extraout_ECX_33;
    HDC extraout_ECX_34;
    HDC extraout_ECX_35;
    HDC extraout_ECX_36;
    HDC extraout_ECX_37;
    HDC extraout_ECX_38;
    HDC extraout_ECX_39;
    HDC extraout_ECX_40;
    HDC extraout_ECX_41;
    HDC extraout_ECX_42;
    HDC extraout_ECX_43;
    HDC extraout_ECX_44;
    HDC extraout_ECX_45;
    HDC extraout_ECX_46;
    HDC extraout_ECX_47;
    HDC extraout_ECX_48;
    HDC extraout_ECX_49;
    HDC extraout_ECX_50;
    HDC extraout_ECX_51;
    HDC extraout_ECX_52;
    HDC extraout_ECX_53;
    HDC extraout_ECX_54;
    HDC extraout_ECX_55;
    char in_DL;
    HDC extraout_DL;
    HDC extraout_DL_00;
    HDC extraout_DL_01;
    HDC extraout_DL_02;
    HDC extraout_DL_03;
    HDC extraout_EDX;
    HDC extraout_EDX_00;
    HDC extraout_EDX_01;
    HDC extraout_EDX_02;
    HDC extraout_EDX_03;
    HDC extraout_EDX_04;
    HDC extraout_EDX_05;
    HDC extraout_EDX_06;
    HDC extraout_EDX_07;
    HDC extraout_EDX_08;
    HDC extraout_EDX_09;
    HDC extraout_EDX_10;
    HDC extraout_EDX_11;
    HDC extraout_EDX_12;
    HDC extraout_EDX_13;
    HDC extraout_EDX_14;
    HDC extraout_EDX_15;
    HDC extraout_EDX_16;
    HDC extraout_EDX_17;
    HDC extraout_EDX_18;
    HDC extraout_EDX_19;
    HDC extraout_EDX_20;
    HDC extraout_EDX_21;
    HDC extraout_EDX_22;
    HDC extraout_EDX_23;
    HDC extraout_EDX_24;
    HDC extraout_EDX_25;
    HDC extraout_EDX_26;
    HDC extraout_EDX_27;
    HDC extraout_EDX_28;
    HDC extraout_EDX_29;
    HDC extraout_EDX_30;
    HDC extraout_EDX_31;
    HDC extraout_EDX_32;
    HDC extraout_EDX_33;
    HDC extraout_EDX_34;
    HDC extraout_EDX_35;
    HDC extraout_EDX_36;
    HDC extraout_EDX_37;
    HDC extraout_EDX_38;
    HDC extraout_EDX_39;
    HDC extraout_EDX_40;
    HDC extraout_EDX_41;
    HDC extraout_EDX_42;
    HDC extraout_EDX_43;
    HDC extraout_EDX_44;
    HDC extraout_EDX_45;
    HDC extraout_EDX_46;
    HDC extraout_EDX_47;
    HDC extraout_EDX_48;
    HDC extraout_EDX_49;
    HDC extraout_EDX_50;
    HDC extraout_EDX_51;
    HDC extraout_EDX_52;
    HDC extraout_EDX_53;
    HDC extraout_EDX_54;
    HDC extraout_EDX_55;

    uVar1 = (char)mode_0;
    switch (mode_0)
    {
    case 0:
        uVar1 = PutSurface(uVar1, in_DL, in_CL, 0, 0, bk_pic_0, v_screen);
        uVar2 = PutSurfaceCC(uVar1, extraout_DL, extraout_CL, 0x14, 0x32, pic_0, v_screen);
        info1_0 = s_SHAREWARE_VERSION_0042022c;
        info2_0 = s_This_is_the_Shareware_Version_of_0042023e;
        info3_0 = s_Feel_free_to_distribute_it_how_e_00420268;
        info4_0 = s_For_the_actual_version_of_Bubble_00420296;
        info5_0 = s_www_hobsoft_de_004202cc;
        info6_0 = s_Please_support_the_concept_of_Sh_004202db;
        info7_0 = &aClickNewToStar;
        uVar2 = ShowTextCenter(uVar2, extraout_EDX, extraout_ECX, v_screen, 400, 0x9e,
                               s_SHAREWARE_VERSION_0042022c, 0xffffff);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_00, extraout_ECX_00, v_screen, 0xfa, 200, info2_0,
                               0xffffff);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_01, extraout_ECX_01, v_screen, 0xfa, 0xd7, info3_0,
                               0xffffff);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_02, extraout_ECX_02, v_screen, 0xfa, 0xf5, info4_0,
                               0xffffff);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_03, extraout_ECX_03, v_screen, 0xfa, 0x104, info5_0,
                               0xffffff);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_04, extraout_ECX_04, v_screen, 0xfa, 0x127, info6_0,
                               0xffffff);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_05, extraout_ECX_05, v_screen, 0xfa, 0x136, info7_0,
                               0xffffff);
        Status_Text_0 = s_Click__New__to_start_a_new_game__0042031a;
        ShowText(uVar2, extraout_EDX_06, extraout_ECX_06, v_screen, 10, 0x160,
                 s_Click__New__to_start_a_new_game__0042031a, 0xffffff);
        Draw_Buttons();
        Update_Screen();
        return;
    case 2:
        Create_Game_Screen();
        return;
    case 3:
        info1_0 = s_Bubblet_v1_0_0042033b;
        info2_0 = s__________________________________asc_420348 ;
        info3_0 = s_Programming__Daniel_Klein_aProgrammingDan;
        info4_0 = s_Copyright__c__1999_by_House_of_B_004203c7;
        info5_0 = s_All_rights_reserved__004203f5;
        info6_0 = s__________________________________0042040a;
        info7_0 = s_Testers__Martin_Boese__Markus_Ja_0042046f;
        info8_0 = s_Original_game_created_by_Frank_F_004204a9;
        info20_0 = s_Greetings_to__004204e2;
        info21_0 = s_Heidi_Amling__Daniel_Gerber__Pet_004204f0;
        info22_0 = &DAT_0042051d;
        info23_0 = &DAT_0042054b;
        info24_0 = s_Eva_and_Peter_Weber____hey_ho_Ho_00420581;
        uVar1 = PutSurface(uVar1, in_DL, in_CL, 0, 0, bk_pic_0, v_screen);
        uVar2 = PutSurfaceCC(uVar1, extraout_DL_00, extraout_CL_00, 8, 6, paper_x_pic_0, v_screen);
        uVar2 = ShowText(uVar2, extraout_EDX_07, extraout_ECX_07, v_screen, 0x32, 0x28, info1_0, 0);
        uVar2 = ShowText(uVar2, extraout_EDX_08, extraout_ECX_08, v_screen, 0x32, 0x37, info2_0, 0);
        uVar2 = ShowText(uVar2, extraout_EDX_09, extraout_ECX_09, v_screen, 0x32, 0x46, info3_0, 0);
        uVar2 = ShowText(uVar2, extraout_EDX_10, extraout_ECX_10, v_screen, 0x32, 0x55, info4_0, 0);
        uVar2 = ShowText(uVar2, extraout_EDX_11, extraout_ECX_11, v_screen, 0x32, 100, info5_0, 0);
        uVar2 = ShowText(uVar2, extraout_EDX_12, extraout_ECX_12, v_screen, 0x32, 0x73, info6_0, 0);
        uVar2 = ShowText(uVar2, extraout_EDX_13, extraout_ECX_13, v_screen, 0x32, 0x82, info7_0, 0);
        uVar2 = ShowText(uVar2, extraout_EDX_14, extraout_ECX_14, v_screen, 0x32, 0x91, info8_0, 0);
        uVar2 = ShowText(uVar2, extraout_EDX_15, extraout_ECX_15, v_screen, 0x32, 0xbe, info20_0, 0);
        uVar2 = ShowText(uVar2, extraout_EDX_16, extraout_ECX_16, v_screen, 0x32, 0xcd, info21_0, 0);
        uVar2 = ShowText(uVar2, extraout_EDX_17, extraout_ECX_17, v_screen, 0x32, 0xdc, info22_0, 0);
        uVar2 = ShowText(uVar2, extraout_EDX_18, extraout_ECX_18, v_screen, 0x32, 0xeb, info23_0, 0);
        uVar2 = ShowText(uVar2, extraout_EDX_19, extraout_ECX_19, v_screen, 0x32, 0xfa, info24_0, 0);
        Status_Text_0 = s_The_creators_of_Bubblet____aTheCreatorsOfB;
        ShowText(uVar2, extraout_EDX_20, extraout_ECX_20, v_screen, 10, 0x160,
                 s_The_creators_of_Bubblet____aTheCreatorsOfB, 0xffffff);
        Draw_Buttons();
        Update_Screen();
        return;
    case 4:
        CreateSetup();
        return;
    case 5:
        Create_Scores();
        return;
    case 6:
        uVar1 = PutSurface(uVar1, in_DL, in_CL, 0, 0, bk_pic_0, v_screen);
        info1_0 = &DAT_004205c7;
        info2_0 = &DAT_004205c8;
        info3_0 = &DAT_004205c9;
        info4_0 = &DAT_004205ca;
        info5_0 = &DAT_004205cb;
        info6_0 = s_Undo_is_the_only_thing_that_s_no_004205cc;
        info7_0 = s_in_the_Shareware_Version_of_Bubb_004205f6;
        info8_0 = &DAT_0042061f;
        info9_0 = s_Please_Register__00420620;
        info10_0 = &DAT_00420631;
        info11_0 = &DAT_00420632;
        info12_0 = &DAT_00420633;
        info20_0 = &DAT_00420634;
        info21_0 = &DAT_00420635;
        info22_0 = &DAT_00420636;
        info23_0 = &DAT_00420637;
        uVar1 = PutSurface(uVar1, extraout_DL_01, extraout_CL_01, 0, 0, bk_pic_0, v_screen);
        uVar2 = PutSurfaceCC(uVar1, extraout_DL_02, extraout_CL_02, 8, 6, paper_x_pic_0, v_screen);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_21, extraout_ECX_21, v_screen, 0xfa, 0x28, info1_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_22, extraout_ECX_22, v_screen, 0xfa, 0x37, info2_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_23, extraout_ECX_23, v_screen, 0xfa, 0x3c, info3_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_24, extraout_ECX_24, v_screen, 0xfa, 0x4b, info4_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_25, extraout_ECX_25, v_screen, 0xfa, 0x5a, info5_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_26, extraout_ECX_26, v_screen, 0xfa, 0x69, info6_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_27, extraout_ECX_27, v_screen, 0xfa, 0x78, info7_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_28, extraout_ECX_28, v_screen, 0xfa, 0x87, info8_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_29, extraout_ECX_29, v_screen, 0xfa, 0x96, info9_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_30, extraout_ECX_30, v_screen, 0xfa, 0xa5, info10_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_31, extraout_ECX_31, v_screen, 0xfa, 0xb4, info11_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_32, extraout_ECX_32, v_screen, 0xfa, 0xc3, info12_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_33, extraout_ECX_33, v_screen, 0xfa, 0xd7, info20_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_34, extraout_ECX_34, v_screen, 0xfa, 0xe6, info21_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_35, extraout_ECX_35, v_screen, 0xfa, 0xf5, info22_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_36, extraout_ECX_36, v_screen, 0xfa, 0x104, info23_0,0);
        Status_Text_0 = s_hehe____00420638;
        ShowText(uVar2, extraout_EDX_37, extraout_ECX_37, v_screen, 10, 0x160, s_hehe____00420638,
                 0xffffff);
        Draw_Buttons();
        Update_Screen();
        return;
    case 7:
        info1_0 = s_Bubblet_is_Shareware_and_costs_o_00420640;
        info2_0 = &DAT_00420670;
        info3_0 = s_In_order_to_register_Bubblet_sen_00420671;
        info4_0 = s__________________________________004206ae;
        info5_0 = s_House_of_Bytes_Software_004206d8;
        info6_0 = s_c_o_Daniel_Klein_004206f0;
        info7_0 = s_Walzenrather_Str__5_00420701;
        info8_0 = s_53819_Neunkirchen_00420715;
        info9_0 = s_Germany_00420727;
        info10_0 = s__________________________________0042072f;
        info11_0 = s_Please_include_your_E_Mail_Addre_00420759;
        info12_0 = s_The_registered_Version_will_be_s_0042077d;
        info20_0 = s_Once_registered__you_re_register_004207b4;
        info21_0 = s_All_registered_Users_receive_fut_004207e0;
        info22_0 = &DAT_00420821;
        info23_0 = s_Thank_you_for_supporting_the_con_00420822;
        uVar1 = PutSurface(uVar1, in_DL, in_CL, 0, 0, bk_pic_0, v_screen);
        uVar2 = PutSurfaceCC(uVar1, extraout_DL_03, extraout_CL_03, 8, 6, paper_x_pic_0, v_screen);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_38, extraout_ECX_38, v_screen, 0xfa, 0x28, info1_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_39, extraout_ECX_39, v_screen, 0xfa, 0x37, info2_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_40, extraout_ECX_40, v_screen, 0xfa, 0x3c, info3_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_41, extraout_ECX_41, v_screen, 0xfa, 0x4b, info4_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_42, extraout_ECX_42, v_screen, 0xfa, 0x5a, info5_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_43, extraout_ECX_43, v_screen, 0xfa, 0x69, info6_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_44, extraout_ECX_44, v_screen, 0xfa, 0x78, info7_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_45, extraout_ECX_45, v_screen, 0xfa, 0x87, info8_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_46, extraout_ECX_46, v_screen, 0xfa, 0x96, info9_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_47, extraout_ECX_47, v_screen, 0xfa, 0xa5, info10_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_48, extraout_ECX_48, v_screen, 0xfa, 0xb4, info11_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_49, extraout_ECX_49, v_screen, 0xfa, 0xc3, info12_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_50, extraout_ECX_50, v_screen, 0xfa, 0xd7, info20_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_51, extraout_ECX_51, v_screen, 0xfa, 0xe6, info21_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_52, extraout_ECX_52, v_screen, 0xfa, 0xf5, info22_0, 0);
        uVar2 = ShowTextCenter(uVar2, extraout_EDX_53, extraout_ECX_53, v_screen, 0xfa, 0x104, info23_0,
                               0);
        Status_Text_0 = s_How_to_register_Bubblet____00420855;
        ShowText(uVar2, extraout_EDX_54, extraout_ECX_54, v_screen, 10, 0x160,
                 s_How_to_register_Bubblet____00420855, 0xffffff);
        Draw_Buttons();
        Update_Screen();
        return;
    case 8:
        uVar2 = PutSurface(uVar1, in_DL, in_CL, 0, 0, bk_pic_0, v_screen);
        Status_Text_0 = s_Mode__HELP_00420870;
        ShowText(uVar2, extraout_EDX_55, extraout_ECX_55, v_screen, 10, 0x160, s_Mode__HELP_00420870,
                 0xffffff);
        Draw_Buttons();
        Update_Screen();
        return;
    case 9:
        uint();
    }
    return;
}
void Draw_Buttons(void)

{
    HDC in_AL;
    HDC in_CL;
    HDC extraout_CL;
    HDC extraout_CL_00;
    HDC extraout_CL_01;
    HDC extraout_CL_02;
    HDC extraout_CL_03;
    HDC extraout_CL_04;
    HDC extraout_CL_05;
    HDC extraout_CL_06;
    HDC extraout_DL;
    HDC extraout_DL_00;
    HDC extraout_DL_01;
    HDC extraout_DL_02;
    HDC extraout_DL_03;
    HDC extraout_DL_04;
    HDC in_EDX;
    HDC extraout_EDX;
    HDC extraout_EDX_00;
    int iVar1;
    bool bVar2;
    int uVar3;

    iVar1 = 1;
    while (true)
    {
        uVar3 = (int)in_EDX;
        if (DAT_0042013c < iVar1)
            break;
        bVar2 = *(int *)(&DAT_00422d5c + iVar1 * 0x20) == 0xff;
        in_EDX = (uint)bVar2;
        in_AL = *(int *)(&DAT_00422d5c + iVar1 * 0x20) == DAT_0042010c || bVar2;
        if ((bool)in_AL)
        {
            if ((&DAT_00422d58)[iVar1 * 8] == 0)
            {
                in_AL = PutSurface((char)iVar1 * ' ', bVar2, in_CL, (&DAT_00422d40)[iVar1 * 8],
                                     (&DAT_00422d44)[iVar1 * 8],
                                     *(int *)(&DAT_00422d50 + iVar1 * 0x20), v_screen);
                in_CL = extraout_CL_00;
                in_EDX = extraout_EDX_00;
            }
            else
            {
                in_AL = PutSurface((char)iVar1 * ' ', bVar2, in_CL, (&DAT_00422d40)[iVar1 * 8],
                                     (&DAT_00422d44)[iVar1 * 8],
                                     *(int *)(&DAT_00422d54 + iVar1 * 0x20), v_screen);
                in_CL = extraout_CL;
                in_EDX = extraout_EDX;
            }
        }
        iVar1 = iVar1 + 1;
    }
    if (DAT_00420110 != 0)
    {
        uVar3 = DAT_0042010c != 0;
        in_AL = DAT_00420110 == 2 && (bool)uVar3;
        if (DAT_00420110 == 2 && (bool)uVar3)
        {
            in_AL = PutSurface(in_AL, uVar3, in_CL, DAT_00422e00, DAT_00422e04, DAT_00422e10, v_screen);
            in_CL = extraout_CL_01;
            uVar3 = extraout_DL;
        }
    }
    if (DAT_00420118 != 0)
    {
        uVar3 = PutSurfaceCC(in_AL, uVar3, in_CL, DAT_00422d60, DAT_00422d64, DAT_00421e8c, v_screen);
        uVar3 = PutSurfaceCC(uVar3, extraout_DL_00, extraout_CL_02, DAT_00422d80, DAT_00422d84, DAT_00421e8c,
                             v_screen);
        uVar3 = PutSurfaceCC(uVar3, extraout_DL_01, extraout_CL_03, DAT_00422da0, DAT_00422da4, DAT_00421e8c,
                             v_screen);
        uVar3 = PutSurfaceCC(uVar3, extraout_DL_02, extraout_CL_04, DAT_00422dc0, DAT_00422dc4, DAT_00421e8c,
                             v_screen);
        uVar3 = PutSurfaceCC(uVar3, extraout_DL_03, extraout_CL_05, DAT_00422de0, DAT_00422de4, DAT_00421e8c,
                             v_screen);
        PutSurfaceCC(uVar3, extraout_DL_04, extraout_CL_06, DAT_00422e00, DAT_00422e04, DAT_00421e8c,
                     v_screen);
    }
    return;
}
void  Update_Button(int param_1, int param_2, int param_3, int param_4)

{
    char cVar1;

    if ((main_btn_mask_0 == 0 || 4 < param_4) &&
        (*(int *)(Check_Button_Down + param_4 * 0x20) == DAT_0042010c ||
         *(int *)(Check_Button_Down + param_4 * 0x20) == 0xff))
    {
        cVar1 = (char)param_4;
        if ((&DAT_00422d58)[param_4 * 8] != 0)
        {
            PutSurfacePrimary(cVar1 * ' ', 0x40, cVar1 * ' ',
                         (&DAT_00422d40)[param_4 * 8],
                         (&DAT_00422d44)[param_4 * 8],
                         *(int *)(&DAT_00422d54 + param_4 * 0x20));
            return;
        }
        PutSurfacePrimary(cVar1 * ' ', 0x40, cVar1 * ' ', (&DAT_00422d40)[param_4 * 8],
                     (&DAT_00422d44)[param_4 * 8], *(int *)(&DAT_00422d50 + param_4 * 0x20));
    }
    return;
}
void  DrawLine(int param_1, int param_2, HDC param_3, int *param_4, int param_5, int param_6, int param_7, int param_8, COLORREF param_9)

{
    int iVar1;
    HPEN h;
    HGDIOBJ h_00;
    HDC extraout_CL;
    HDC extraout_DL;

    iVar1 = (**(code **)(*param_4 + 0x44))();
    if (iVar1 != 0)
    {
        Error_Message((char)iVar1, extraout_DL, extraout_CL, &DAT_00420a19);
    }
    h = CreatePen(0, 0, param_9);
    h_00 = SelectObject(param_3, h);
    MoveToEx(param_3, param_5, param_6, (LPPOINT)0x0);
    LineTo(param_3, param_7, param_8);
    SelectObject(param_3, h_00);
    DeleteObject(h);
    (**(code **)(*param_4 + 0x68))();
    return;
}
void  Execute_Button(int param_1, int param_2, int param_3, int param_4)

{
    int unaff_EBP;

    switch (param_4)
    {
    case 1:
        PostMessageA(hWnd_00421e58, 0x10, 0, 0);
        return;
    case 2:
        change_mode(param_4, param_2, param_3, 3, unaff_EBP);
        DAT_00420114 = DAT_00420110;
        return;
    case 3:
        change_mode(param_4, param_2, param_3, 4, unaff_EBP);
        return;
    case 4:
        change_mode(param_4, param_2, param_3, 5, unaff_EBP);
        return;
    case 5:
        change_mode(param_4, param_2, param_3, 2, unaff_EBP);
        return;
    case 6:
        if (DAT_00420134 == 0)
        {
            _Str_00421eb0 = (void *)((int)_Str_00421eb0 + 1);
        }
        if (DAT_00420134 == 1)
        {
            DAT_00421ebc = DAT_00421ebc + 1;
        }
        if (DAT_00420134 == 2)
        {
            DAT_00421ec8 = DAT_00421ec8 + 1;
        }
        if (DAT_00420134 == 3)
        {
            DAT_00421ed4 = DAT_00421ed4 + 1;
        }
        DAT_00420128 = 0;
        change_mode(0, param_2, param_3, 9, unaff_EBP);
        return;
    case 7:
        change_mode(param_4, param_2, param_3, 0x100, unaff_EBP);
        return;
    case 8:
        change_mode(param_4, param_2, param_3, 0x100, unaff_EBP);
        return;
    case 9:
        change_mode(param_4, param_2, param_3, 0x100, unaff_EBP);
        _DAT_00420138 = 0;
        return;
    case 10:
        Reset_Scores();
        return;
    case 0xb:
        change_mode(param_4, param_2, param_3, 0, unaff_EBP);
        return;
    case 0xc:
        change_mode(param_4, param_2, param_3, 2, unaff_EBP);
        return;
    case 0xd:
        change_mode(param_4, param_2, param_3, 7, unaff_EBP);
        return;
    case 0xe:
        change_mode(param_4, param_2, param_3, 6, unaff_EBP);
        return;
    case 0xf:
        change_mode(param_4, param_2, param_3, 3, unaff_EBP);
        DAT_00420110 = DAT_00420114;
        return;
    case 0x10:
        change_mode(param_4, param_2, param_3, 0x100, unaff_EBP);
    }
    return;
}
void  change_mode(int param_1, int param_2, int param_3, int param_4, int param_5)

{
    int uVar1;
    int uVar2;

    uVar1 = last_mode_0;
    last_mode_0 = mode_0;
    if (param_4 < 6)
    {
        switch (param_4)
        {
        case 0:
            mode_0 = 0;
            main_btn_mask_0 = 0;
            void Create_Screen();
            return;
        case 1:
            goto switchD_00411ccf_caseD_1;
        case 2:
            mode_0 = 2;
            main_btn_mask_0 = 0;
            New_Game();
            Create_Screen();
            return;
        case 3:
            mode_0 = 3;
            main_btn_mask_0 = 1;
            Create_Screen();
            return;
        case 4:
            mode_0 = 4;
            main_btn_mask_0 = 1;
            Create_Screen();
            return;
        default:
            mode_0 = 5;
            main_btn_mask_0 = 1;
            Create_Screen();
            return;
        }
    }
    if (param_4 < 9)
    {
        if (param_4 != 8)
        {
            if (param_4 == 6)
            {
                mode_0 = 6;
                main_btn_mask_0 = 1;
                Create_Screen();
                return;
            }
            if (param_4 == 7)
            {
                mode_0 = 7;
                main_btn_mask_0 = 1;
                Create_Screen();
                return;
            }
            return;
        }
    }
    else
    {
        if (param_4 == 9)
        {
            mode_0 = 9;
            main_btn_mask_0 = 1;
            uVar2 = (int)uVar1;
            if (DAT_00420128 == 0)
            {
                if (change_mode+150 != 0)
                {
                    mci_PlayWaveWait(uVar2, 0, (char)param_3, s_score_00420885);
                }
            }
            else if (change_mode+150 != 0)
            {
                mci_PlayWaveWait(uVar2, 0, (char)param_3, s_highscore_0042087b);
            }
            Create_Screen();
            return;
        }
        if (param_4 != 0x100)
        {
            return;
        }
        mode_0 = uVar1;
        main_btn_mask_0 = 0;
        Create_Screen();
        last_mode_0 = 0;
    }
switchD_00411ccf_caseD_1:
    return;
}
void Update_Screen(void)

{
    int in_AL;
    int in_CL;
    int in_DL;

    PutSurfacePrimary(in_AL, in_DL, in_CL, 0, 0, v_screen);
    return;
}
int  DDLoadBitmap(int param_1, int param_2, int param_3, int param_4, const uint16_t * param_5)

{
    HANDLE h;
    HMODULE hInst;
    BOOL BVar1;
    HDC extraout_CL;
    HDC extraout_CL_00;
    HDC extraout_CL_01;
    HDC extraout_DL;
    HDC extraout_DL_00;
    HDC extraout_DL_01;
    UINT type;
    int iVar2;
    int cy;
    UINT fuLoad;
    char local_1c[4];
    char local_18;
    char local_14;

    h = LoadImageA((HINSTANCE)0x0, param_5, 0, 0, 0, 0x2010);
    if (h == (HANDLE)0x0)
    {
        fuLoad = 0x2000;
        cy = 0;
        iVar2 = 0;
        type = 0;
        hInst = GetModuleHandleA((const uint16_t *)0x0);
        h = LoadImageA(hInst, param_5, type, iVar2, cy, fuLoad);
    }
    if (h == (HANDLE)0x0)
    {
        iVar2 = 0;
    }
    else
    {
        iVar2 = GetObjectA(h, 0x18, local_1c);
        iVar2 = CreateOffScreenSurface((char)iVar2, extraout_DL, extraout_CL, param_4, local_18, local_14);
        if (iVar2 != 0)
        {
            DDCopyBitmap((char)iVar2, extraout_DL_00, extraout_CL_00, iVar2, h, local_18, local_14);
        }
        BVar1 = DeleteObject(h);
        if (iVar2 == 0)
        {
            Error_Message((char)BVar1, extraout_DL_01, extraout_CL_01,
                         s_Fehler_beim_laden_eines_Bildes__004209d4);
        }
    }
    return iVar2;
}
int  DDReLoadBitmap(int param_1, int param_2, int param_3, int param_4, const uint16_t * param_5)

{
    HMODULE hInst;
    HGDIOBJ ho;
    HDC extraout_CL;
    HDC extraout_CL_00;
    int uVar1;
    HDC extraout_DL;
    HDC extraout_DL_00;
    char uVar2;
    const uint16_t * name;
    UINT type;
    int iVar3;
    int cy;
    UINT fuLoad;

    fuLoad = 0x2000;
    cy = 0;
    iVar3 = 0;
    type = 0;
    name = param_5;
    hInst = GetModuleHandleA((const uint16_t *)0x0);
    ho = LoadImageA(hInst, name, type, iVar3, cy, fuLoad);
    uVar1 = extraout_CL;
    uVar2 = extraout_DL;
    if (ho == (HANDLE)0x0)
    {
        ho = LoadImageA((HINSTANCE)0x0, param_5, 0, 0, 0, 0x2010);
        uVar1 = extraout_CL_00;
        uVar2 = extraout_DL_00;
    }
    if (ho == (HGDIOBJ)0x0)
    {
        OutputDebugStringA(s_handle_is_null_004209f4);
        iVar3 = -0x7fffbffb;
    }
    else
    {
        iVar3 = DDCopyBitmap((char)ho, uVar2, uVar1, param_4, ho, 0, 0);
        if (iVar3 != 0)
        {
            OutputDebugStringA(s_ddcopybitmap_failed_00420a04);
        }
        DeleteObject(ho);
    }
    return iVar3;
}
int  DDCopyBitmap(int param_1, int param_2, int param_3, int *param_4, HGDIOBJ param_5,int param_6, int param_7)

{
    HDC hdc;
    HGDIOBJ h;
    int iVar1;
    HDC local_8;

    hdc = CreateCompatibleDC((HDC)0x0);
    h = SelectObject(hdc, param_5);
    iVar1 = (**(code **)(*param_4 + 0x44))();
    if (iVar1 == 0)
    {
        BitBlt(local_8, 0, 0, param_6, param_7, hdc, 0, 0, 0xcc0020);
        (**(code **)(*param_4 + 0x68))();
    }
    SelectObject(hdc, h);
    DeleteDC(hdc);
    return iVar1;
}
void  New_Game(void)

{
    int iVar1;
    int iVar2;
    int iVar3;

    game_type_0 = setup_data_0;

    game_score_0 = 0;
    Create_Game_Score = 0;
    iVar3 = 0;
    do
    {
        iVar2 = 0;
        do
        {
            iVar1 = __lrand();
            (PlayField_0)[iVar2 * 0x2a + iVar3 * 6] = iVar1 % 5 + 1;
            (DAT_00421f08)[iVar2 * 0x2a + iVar3 * 6] = 0xffff;
            (DAT_00421f0c)[iVar2 * 0x2a + iVar3 * 6] = 0xffff;
            (Check_Bubble)[iVar2 * 0x2a + iVar3 * 6] = 0;
            iVar2 = iVar2 + 1;
        } while (iVar2 < 10);
        iVar3 = iVar3 + 1;
    } while (iVar3 < 7);
    return;
}
void  CreateOffScreenSurface(int param_1, int param_2, int param_3, int *param_4, int param_5, int param_6)

{
    int iVar1;
    char local_74;
    char local_70;
    char local_6c;
    char local_68;
    char local_c;
    char local_8;

    _memset(&local_74, 0, 0x6c);
    local_74 = 0x6c;
    local_70 = 7;
    local_c = 0x40;
    local_68 = param_5;
    local_6c = param_6;
    iVar1 = (**(code **)(*param_4 + 0x18))();
    if (iVar1 != 0)
    {
        local_8 = 0;
    }
    return local_8;
}
void Create_Game_Screen(void)

{
    char in_AL;
    int iVar1;
    char in_CL;
    uint param2;
    HDC extraout_ECX;
    char in_DL;
    char *param1;
    HDC extraout_EDX;
    int iVar2;
    int iVar3;
    int iVar4;
    char local_64[80];
    int *local_14;
    char local_10;
    int local_c;
    int local_8;

    PutSurface(in_AL, in_DL, in_CL, 0, 0, bk_pic_0, v_screen);
    _sprintf(local_64, param1, param2, (uint)local_64, 0x420144);
    Status_Text_0 = local_64;
    ShowText(Status_Text_0, extraout_EDX, extraout_ECX, v_screen, 10, 0x160, Status_Text_0, 0xffffff);
    Draw_Buttons();
    iVar4 = 0;
    do
    {
        iVar3 = 0;
        do
        {
            if ((&DAT_00421f04)[iVar3 * 0x2a + iVar4 * 6] != 0)
            {
                iVar1 = iVar3 * 0x30 + 8;
                local_8 = iVar4 * 0x30 + 8;
                if (DAT_00420120 != 0)
                {
                    if ((&DAT_00421f08)[iVar3 * 0x2a + iVar4 * 6] != 0xffff)
                    {
                        iVar1 = (&DAT_00421f08)[iVar3 * 0x2a + iVar4 * 6];
                    }
                    if ((&DAT_00421f0c)[iVar3 * 0x2a + iVar4 * 6] != 0xffff)
                    {
                        local_8 = (&DAT_00421f0c)[iVar3 * 0x2a + iVar4 * 6];
                    }
                }
                if ((&DAT_00421f04)[iVar3 * 0x2a + iVar4 * 6] == 1)
                {
                    local_14 = &DAT_00421e90;
                }
                if ((&DAT_00421f04)[iVar3 * 0x2a + iVar4 * 6] == 2)
                {
                    local_14 = &DAT_00421e94;
                }
                if ((&DAT_00421f04)[iVar3 * 0x2a + iVar4 * 6] == 3)
                {
                    local_14 = &DAT_00421e98;
                }
                if ((&DAT_00421f04)[iVar3 * 0x2a + iVar4 * 6] == 4)
                {
                    local_14 = &DAT_00421e9c;
                }
                if ((&DAT_00421f04 + iVar3 * 0x2a)[iVar4 * 6] == 5)
                {
                    local_14 = &DAT_00421ea0;
                }
                PutSurfaceClipCC((char)iVar1, (char)local_14, (char)(&DAT_00421f04 + iVar3 * 0x2a), iVar1, local_8,
                             *local_14, v_screen, DAT_00421ef4, DAT_00421ef8, DAT_00421efc, DAT_00421f00);
                if ((DAT_0042011c != 0) && ((&DAT_00421f18)[iVar3 * 0x2a + iVar4 * 6] != 0))
                {
                    if ((&DAT_00421f00)[iVar3 * 0x2a + iVar4 * 6] == 0 && 0 < iVar4 || iVar4 == 0)
                    {
                        iVar1 = iVar3 * 0x30 + 7;
                        iVar2 = iVar4 * 0x30 + 7;
                        local_c = (iVar3 + 1) * 0x30 + 7;
                        local_10 = (HDC)(iVar4 * 0x30 + 7);
                        DrawLine(iVar1, iVar2, local_10, v_screen, iVar1, iVar2, local_c, (int)local_10, 0xff);
                    }
                    if ((&DAT_00421f30)[iVar3 * 0x2a + iVar4 * 6] == 0 && iVar4 < 6 || iVar4 == 6)
                    {
                        iVar1 = iVar3 * 0x30 + 7;
                        iVar2 = (iVar4 + 1) * 0x30 + 6;
                        local_c = (iVar3 + 1) * 0x30 + 7;
                        local_10 = (HDC)((iVar4 + 1) * 0x30 + 6);
                        DrawLine(iVar1, iVar2, local_10, v_screen, iVar1, iVar2, local_c, (int)local_10, 0xff);
                    }
                    if ((&paper_pic_0)[iVar3 * 0x2a + iVar4 * 6] == 0 && 0 < iVar3 || iVar3 == 0)
                    {
                        iVar1 = iVar3 * 0x30 + 7;
                        iVar2 = iVar4 * 0x30 + 7;
                        local_c = iVar3 * 0x30 + 7;
                        local_10 = (HDC)((iVar4 + 1) * 0x30 + 7);
                        DrawLine(iVar1, iVar2, local_10, v_screen, iVar1, iVar2, local_c, (int)local_10, 0xff);
                    }
                    if ((&DAT_00421fc0)[iVar3 * 0x2a + iVar4 * 6] == 0 && iVar3 < 9 || iVar3 == 9)
                    {
                        iVar1 = (iVar3 + 1) * 0x30 + 6;
                        iVar2 = iVar4 * 0x30 + 7;
                        local_c = (iVar3 + 1) * 0x30 + 6;
                        local_10 = (HDC)((iVar4 + 1) * 0x30 + 7);
                        DrawLine(iVar1, iVar2, local_10, v_screen, iVar1, iVar2, local_c, (int)local_10, 0xff);
                    }
                }
            }
            iVar3 = iVar3 + 1;
        } while (iVar3 < 10);
        iVar4 = iVar4 + 1;
    } while (iVar4 < 7);
    Update_Screen();
    return;
}
void  LoadSurface(int param_1, int param_2, int param_3, int param_4)

{
    DDLoadBitmap(param_1, param_2, param_3, dd_Object, param_4);
    return;
}
void  ReLoadSurface(int param_1, int param_2, int param_3, int param_4,int param_5)
{
    void  DDReLoadBitmap(param_1, param_2, param_3, param_4, param_5);
    return;
}
void  FillSurface(int param_1, int param_2, int param_3, int *param_4, int param_5, int param_6, int param_7, int param_8, int param_9)

{
    int iVar1;
    tagRECT local_14;

    SetRect(&local_14, param_5, param_6, param_7, param_8);
    iVar1 = (**(code **)(*param_4 + 0x14))();
    if (iVar1 == -0x7ff8ffa9)
    {
        Beep(1000, 100);
    }
    return;
}
void  PutSurfacePrimary(int param_1, int param_2, int param_3, int param_4, int param_5, int *param_6)
{
    int iVar1;
    char local_ec[2];
    int local_e4;
    int local_e0;
    char local_80[2];
    uint local_78;
    uint local_74;
    tagRECT local_14;

    _memset(local_80, 0, 0x6c);
    local_80[0] = 0x6c;
    (**(code **)(*param_6 + 0x58))();
    _memset(local_ec, 0, 0x6c);
    local_ec[0] = 0x6c;
    (**(code **)(*public dd_Primary + 0x58))();
    if ((uint)(local_74 + param_4) < local_e0 && (uint)(local_78 + param_5) < local_e4)
    {
        SetRect(&local_14, param_4 + public _Client_Pos, param_5 + _public _Client_Pos,
                local_74 + param_4 + public _Client_Pos, local_78 + param_5 + _public _Client_Pos);
    }
    else
    {
        SetRect(&local_14, param_4 + _Client_Pos, param_5 + _public _Client_Pos, local_e0 + _Client_Pos,
                local_e4 + _public _Client_Pos);
    }
    iVar1 = (**(code **)(*param_6 + 0x60))();
    if (iVar1 == -0x7789fe3e)
    {
        PostMessageA(main_hWnd, 9999, 0, 0);
    }
    iVar1 = (**(code **)(*public dd_Primary + 0x60))();
    if (iVar1 == -0x7789fe3e)
    {
        PostMessageA(main_hWnd, 9999, 0, 0);
    }
    iVar1 = (**(code **)(*public dd_Primary + 0x14))();
    if (iVar1 == -0x7ff8ffa9)
    {
        Beep(1000, 100);
    }
    return;
}
void  PutSurface(int param_1, int param_2, int param_3, int param_4, int param_5, int *param_6, int *param_7)

{
    int iVar1;
    char local_ec[2];
    int local_e4;
    int local_e0;
    char local_80[2];
    int local_78;
    int local_74;
    tagRECT local_14;

    _memset(local_80, 0, 0x6c);
    local_80[0] = 0x6c;
    (**(code **)(*param_6 + 0x58))();
    _memset(local_ec, 0, 0x6c);
    local_ec[0] = 0x6c;
    (**(code **)(*param_7 + 0x58))();
    if ((uint)(local_74 + param_4) < local_e0 && (uint)(local_78 + param_5) < local_e4)
    {
        SetRect(&local_14, param_4, param_5, local_74 + param_4, local_78 + param_5);
    }
    else
    {
        SetRect(&local_14, param_4, param_5, local_e0, local_e4);
    }
    iVar1 = (**(code **)(*param_6 + 0x60))();
    if (iVar1 == -0x7789fe3e)
    {
        PostMessageA(hWnd_00421e58, 9999, 0, 0);
    }
    iVar1 = (**(code **)(*param_7 + 0x60))();
    if (iVar1 == -0x7789fe3e)
    {
        PostMessageA(hWnd_00421e58, 9999, 0, 0);
    }
    iVar1 = (**(code **)(*param_7 + 0x14))();
    if (iVar1 == -0x7ff8ffa9)
    {
        Beep(1000, 100);
    }
    return;
}
void  PutSurfaceCC(int param_1, int param_2, int param_3, int param_4, int param_5,int *param_6, int *param_7)

{
    int iVar1;
    char local_ec[2];
    int local_e4;
    int local_e0;
    char local_80[2];
    int local_78;
    int local_74;
    tagRECT local_14;

    _memset(local_80, 0, 0x6c);
    local_80[0] = 0x6c;
    (**(code **)(*param_6 + 0x58))();
    _memset(local_ec, 0, 0x6c);
    local_ec[0] = 0x6c;
    (**(code **)(*param_7 + 0x58))();
    if ((uint)(local_74 + param_4) < local_e0 && (uint)(local_78 + param_5) < local_e4)
    {
        SetRect(&local_14, param_4, param_5, local_74 + param_4, local_78 + param_5);
        iVar1 = (**(code **)(*param_6 + 0x60))();
        if (iVar1 == -0x7789fe3e)
        {
            PostMessageA(hWnd_00421e58, 9999, 0, 0);
        }
        iVar1 = (**(code **)(*param_7 + 0x60))();
        if (iVar1 == -0x7789fe3e)
        {
            PostMessageA(hWnd_00421e58, 9999, 0, 0);
        }
        iVar1 = (**(code **)(*param_7 + 0x14))();
        if (iVar1 == -0x7ff8ffa9)
        {
            Beep(1000, 100);
        }
    }
    return;
}
void  PutSurfaceClipCC(int param_1, int param_2, int param_3, int param_4, int param_5, int *param_6, int *param_7, int param_8, int param_9, int param_10, int param_11)

{
    int iVar1;
    int iVar2;
    char local_ec[27];
    char local_80[2];
    int local_78;
    int local_74;
    tagRECT local_14;

    _memset(local_80, 0, 0x6c);
    local_80[0] = 0x6c;
    (**(code **)(*param_6 + 0x58))();
    _memset(local_ec, 0, 0x6c);
    local_ec[0] = 0x6c;
    (**(code **)(*param_7 + 0x58))();
    iVar1 = param_4 + local_74;
    iVar2 = param_5 + local_78;
    if (((param_8 < param_4 && param_9 < param_5) && iVar1 < param_10) && iVar2 < param_11)
    {
        SetRect(local_14, param_4, param_5, local_74 + param_4, local_78 + param_5);
        iVar1 = (**(code **)(*param_6 + 0x60))();
        if (iVar1 == -0x7789fe3e)
        {
            PostMessageA(main_hWnd, 9999, 0, 0);
        }
        iVar1 = (**(code **)(*param_7 + 0x60))();
        if (iVar1 == -0x7789fe3e)
        {
            PostMessageA(main_hWnd, 9999, 0, 0);
        }
        iVar1 = (**(code **)(*param_7 + 0x14))();
    }
    else
    {
        SetRect(&local_14, param_4, param_5, local_74 + param_4, local_78 + param_5);
        if (param_4 < param_8)
        {
            local_14.left = local_14.left + (param_8 - param_4);
        }
        if (param_5 < param_9)
        {
            local_14.top = local_14.top + (param_9 - param_5);
        }
        if (param_10 < iVar1)
        {
            local_14.right = local_14.right - (iVar1 - param_10);
        }
        if (param_11 < iVar2)
        {
            local_14.bottom = local_14.bottom - (iVar2 - param_11);
        }
        iVar1 = (**(code **)(*param_6 + 0x60))();
        if (iVar1 == -0x7789fe3e)
        {
            PostMessageA(main_hWnd, 9999, 0, 0);
        }
        iVar1 = (**(code **)(*param_7 + 0x60))();
        if (iVar1 == -0x7789fe3e)
        {
            PostMessageA(hWnd_00421e58, 9999, 0, 0);
        }
        iVar1 = (**(code **)(*param_7 + 0x14))();
    }
    if (iVar1 == -0x7ff8ffa9)
    {
        Beep(1000, 100);
    }
    return;
}
void  PutSurfaceClipCC(int param_1, int param_2, int param_3, int param_4, int param_5, int *param_6, int *param_7, int param_8, int param_9, int param_10, int param_11)
{
}
void  Fill_Rows(int param_1, int param_2, int param_3, int param_4)

{
    int iVar1;
    int iVar2;
    int iVar3;

    iVar3 = param_4;
    if (-1 < param_4)
    {
        do
        {
            iVar2 = 0;
            do
            {
                iVar1 = __lrand(param_1, param_2, param_3);
                (Create_Game_Screen)[iVar3 * 0x2a + iVar2 * 6] = iVar1 % 5 + 1;
                (Check_Button_Down)[iVar3 * 0x2a + iVar2 * 6] = ((param_4 - iVar3) + 1) * -0x30 + 8;
                (DAT_00421f0c)[iVar3 * 0x2a + iVar2 * 6] = 0xffff;
                param_1 = iVar2 * 3;
                param_2 = (int)(Check_Bubble + iVar3 * 0x2a);
                param_3 = 0;
                *(int *)(param_2 + iVar2 * 6 * 4) = 0;
                iVar2 = iVar2 + 1;
            } while (iVar2 < 7);
            iVar3 = iVar3 + -1;
        } while (-1 < iVar3);
    }
    return;
}
void  DirectDrawInit(int param_1, int param_2, int param_3, HINSTANCE param_4, int param_5)

{
    HWND hWnd;
    DWORD dwExStyle;
    DWORD dwStyle;
    uint uVar1;
    int iVar2;
    int iVar3;
    HDC extraout_CL;
    HDC extraout_CL_00;
    HDC extraout_CL_01;
    HDC extraout_CL_02;
    HDC extraout_CL_03;
    HDC extraout_CL_04;
    uint uVar4;
    HDC extraout_DL;
    HDC extraout_DL_00;
    HDC extraout_DL_01;
    HDC extraout_DL_02;
    HDC extraout_DL_03;
    HDC extraout_DL_04;
    int uVar5;
    int iVar6;
    int iVar7;
    BOOL bMenu;
    tagPOINT local_b8[2];
    tagRECT local_a8;
    char local_98;
    char local_94;
    char local_30;
    WNDCLASSA local_2c;

    local_2c.style = 3;
    local_2c.lpfnWndProc = WindowProc;
    local_2c.cbClsExtra = 0;
    local_2c.cbWndExtra = 0;
    local_2c.hInstance = param_4;
    local_2c.hIcon = LoadIconA(param_4, s_BUBBLET_ICON_004200b2);
    local_2c.hCursor = LoadCursorA(param_4, (const uint16_t *)0x2);
    local_2c.hbrBackground = (HBRUSH)0x0;
    local_2c.lpszMenuName = &DAT_004200bf;
    local_2c.lpszClassName = &DAT_004200c3;
    RegisterClassA(&local_2c);
    hWnd = CreateWindowExA(0, &DAT_004200c7, s_Bubblet___Shareware__004200cb, 0xca0000, 0, 0, 0, 0, (HWND)0x0,
                           (HMENU)0x0, param_4, (LPVOID)0x0);
    if (hWnd != (HWND)0x0)
    {
        main_hWnd = hWnd;
        SetRect(&local_a8, 0, 0, 0x1ed, 0x1a3);
        dwExStyle = GetWindowLongA(hWnd, -0x14);
        bMenu = 0;
        dwStyle = GetWindowLongA(hWnd, -0x10);
        AdjustWindowRectEx(&local_a8, dwStyle, bMenu, dwExStyle);
        uVar1 = GetSystemMetrics(0);
        iVar7 = (int)uVar1 >> 1;
        if (iVar7 < 0)
        {
            iVar7 = iVar7 + (uint)((uVar1 & 1) != 0);
        }
        iVar2 = local_a8.right - local_a8.left >> 1;
        if (iVar2 < 0)
        {
            iVar2 = iVar2 + (uint)((local_a8.right - local_a8.left & 1U) != 0);
        }
        uVar1 = GetSystemMetrics(1);
        iVar3 = (int)uVar1 >> 1;
        if (iVar3 < 0)
        {
            iVar3 = iVar3 + (uint)((uVar1 & 1) != 0);
        }
        iVar6 = local_a8.bottom - local_a8.top >> 1;
        if (iVar6 < 0)
        {
            iVar6 = iVar6 + (uint)((local_a8.bottom - local_a8.top & 1U) != 0);
        }
        MoveWindow(hWnd, iVar7 - iVar2, iVar3 - iVar6, local_a8.right - local_a8.left,
                   local_a8.bottom - local_a8.top, 0);
        local_b8[0].x = 0;
        local_b8[0].y = 0;
        ClientToScreen(hWnd, local_b8);
        _DAT_00421e50 = local_b8[0].x;
        _DAT_00421e54 = local_b8[0].y;
        ShowWindow(hWnd, param_5);
        UpdateWindow(hWnd);
        iVar7 = DirectDrawCreate();
        uVar4 = extraout_CL;
        uVar5 = extraout_DL;
        if ((iVar7 == 0) &&
            (iVar7 = (**(code **)(*DAT_00421e3c + 0x50))(), uVar4 = extraout_CL_00,
             uVar5 = extraout_DL_00, iVar7 == 0))
        {
            local_98 = 0x6c;
            local_94 = 1;
            local_30 = 0x200;
            iVar7 = (**(code **)(*DAT_00421e3c + 0x18))();
            uVar4 = extraout_CL_01;
            uVar5 = extraout_DL_01;
            if ((iVar7 == 0) &&
                (((iVar7 = (**(code **)(*DAT_00421e3c + 0x10))(), uVar4 = extraout_CL_02,
                   uVar5 = extraout_DL_02, iVar7 == 0 && (iVar7 = (**(code **)(*DAT_00421e44 + 0x20))(), uVar4 = extraout_CL_03, uVar5 = extraout_DL_03, iVar7 == 0)) &&
                  (iVar7 = (**(code **)(*DAT_00421e40 + 0x70))(), uVar4 = extraout_CL_04,
                   uVar5 = extraout_DL_04, iVar7 == 0))))
            {
                (**(code **)(*DAT_00421e44 + 8))();
                return 1;
            }
        }
        Error_Message(0xe0, uVar5, uVar4, s_Direct_Draw_Initialisierung_fehl_004200e0);
        DestroyWindow(hWnd);
    }
    return 0;
}
void Game_Init(void)

{
    int uVar1;
    time_t *_Seed;
    int iVar2;
    int uVar3;
    HDC extraout_CL;
    HDC extraout_CL_00;
    HDC extraout_CL_01;
    HDC extraout_CL_02;
    HDC extraout_CL_03;
    HDC extraout_CL_04;
    HDC extraout_CL_05;
    HDC extraout_CL_06;
    HDC extraout_CL_07;
    HDC extraout_CL_08;
    HDC extraout_CL_09;
    HDC extraout_CL_10;
    HDC extraout_CL_11;
    HDC extraout_CL_12;
    HDC extraout_CL_13;
    HDC extraout_CL_14;
    HDC extraout_CL_15;
    HDC extraout_CL_16;
    HDC extraout_CL_17;
    HDC extraout_CL_18;
    HDC extraout_CL_19;
    HDC extraout_CL_20;
    HDC extraout_CL_21;
    HDC extraout_ECX;
    HDC extraout_DL;
    HDC extraout_DL_00;
    HDC extraout_DL_01;
    HDC extraout_DL_02;
    HDC extraout_DL_03;
    HDC extraout_DL_04;
    HDC extraout_DL_05;
    HDC extraout_DL_06;
    HDC extraout_DL_07;
    HDC extraout_DL_08;
    HDC extraout_DL_09;
    HDC extraout_DL_10;
    HDC extraout_DL_11;
    HDC extraout_DL_12;
    HDC extraout_DL_13;
    HDC extraout_DL_14;
    HDC extraout_DL_15;
    HDC extraout_DL_16;
    HDC extraout_DL_17;
    HDC extraout_DL_18;
    HDC extraout_DL_19;
    HDC extraout_DL_20;
    HDC extraout_DL_21;
    HDC extraout_DL_22;
    HDC extraout_DL_23;
    HDC extraout_DL_24;
    HDC extraout_DL_25;
    HDC extraout_DL_26;
    HDC extraout_DL_27;
    HDC extraout_DL_28;
    HDC extraout_DL_29;
    HDC extraout_DL_30;
    HDC extraout_DL_31;
    HDC extraout_DL_32;
    HDC extraout_DL_33;
    HDC extraout_DL_34;
    HDC extraout_DL_35;
    HDC extraout_DL_36;
    HDC extraout_DL_37;
    HDC extraout_DL_38;
    HDC extraout_DL_39;
    char extraout_EDX;
    time_t *unaff_EDI;
    char uVar4;
    time_t *ptVar5;
    FILE *pFVar6;
    CHAR *pCVar7;
    CHAR local_104[256];

    _Seed = _time((time_t *)0x0, unaff_EDI);
    ptVar5 = _Seed;
    _srand((uint)_Seed);
    FillSurface((char)_Seed, extraout_DL, (char)ptVar5, v_screen, 0, 0, 0x1ed, 0x1a3, 0);
    uVar1 = ShowTextCenter(s_Loading_Bubblet____004208a3, extraout_EDX, extraout_ECX, v_screen, 0xf5,
                         0xc3, s_Loading_Bubblet____004208a3, 0xffffff);
    PutSurfacePrimary(uVar1, extraout_DL_00, extraout_CL, 0, 0, v_screen);
    DAT_00421ef4 = 7;
    DAT_00421ef8 = 7;
    DAT_00421efc = 0x1e6;
    DAT_00421f00 = 0x156;
    _File_00421e64 = _fopen(s_bubblet_cfg_004208b6, &DAT_004208c2);
    _fread(&_Str_00421ee8, 0xc, 1, _File_00421e64);
    _fread(&_Str_00421eb0, 0x30, 1, _File_00421e64);
    pFVar6 = _File_00421e64;
    iVar2 = _fclose(_File_00421e64);
    uVar1 = 0x81;
    DAT_00421e90 = LoadSurface((char)iVar2, extraout_DL_01, (char)pFVar6, 0x81);
    uVar4 = 0x82;
    DAT_00421e94 = LoadSurface((char)DAT_00421e90, extraout_DL_02, uVar1, 0x82);
    uVar1 = 0x83;
    DAT_00421e98 = LoadSurface((char)DAT_00421e94, extraout_DL_03, uVar4, 0x83);
    uVar4 = 0x84;
    DAT_00421e9c = LoadSurface((char)DAT_00421e98, extraout_DL_04, uVar1, 0x84);
    uVar1 = 0x85;
    DAT_00421ea0 = LoadSurface((char)DAT_00421e9c, extraout_DL_05, uVar4, 0x85);
    uVar1 = SetColorKey((char)DAT_00421ea0, extraout_DL_06, uVar1, DAT_00421e90, 0);
    uVar1 = SetColorKey(uVar1, extraout_DL_07, extraout_CL_00, DAT_00421e94, 0);
    uVar1 = SetColorKey(uVar1, extraout_DL_08, extraout_CL_01, DAT_00421e98, 0);
    uVar1 = SetColorKey(uVar1, extraout_DL_09, extraout_CL_02, DAT_00421e9c, 0);
    uVar1 = SetColorKey(uVar1, extraout_DL_10, extraout_CL_03, DAT_00421ea0, 0);
    uVar4 = 100;
    bk_pic_0 = LoadSurface(uVar1, extraout_DL_11, extraout_CL_04, 100);
    uVar1 = 0x65;
    paper_x_pic_0 = LoadSurface((char)bk_pic_0, extraout_DL_12, uVar4, 0x65);
    uVar1 = SetColorKey((char)paper_x_pic_0, extraout_DL_13, uVar1, paper_x_pic_0, 0);
    uVar4 = 0x66;
    paper_pic_0 = LoadSurface(uVar1, extraout_DL_14, extraout_CL_05, 0x66);
    uVar1 = SetColorKey((char)paper_pic_0, extraout_DL_15, uVar4, paper_pic_0, 0);
    uVar4 = 0x68;
    DAT_00421e78 = LoadSurface(uVar1, extraout_DL_16, extraout_CL_06, 0x68);
    uVar1 = SetColorKey((char)DAT_00421e78, extraout_DL_17, uVar4, DAT_00421e78, 0xffffff);
    uVar4 = 0x69;
    DAT_00421e7c = LoadSurface(uVar1, extraout_DL_18, extraout_CL_07, 0x69);
    uVar1 = SetColorKey((char)DAT_00421e7c, extraout_DL_19, uVar4, DAT_00421e7c, 0xffffff);
    uVar4 = 0x6a;
    setup_map_pic_0 = LoadSurface(uVar1, extraout_DL_20, extraout_CL_08, 0x6a);
    uVar1 = SetColorKey((char)setup_map_pic_0, extraout_DL_21, uVar4, setup_map_pic_0, 0xffffff);
    uVar4 = 0x6b;
    checked_box_pic_0 = LoadSurface(uVar1, extraout_DL_22, extraout_CL_09, 0x6b);
    uVar1 = SetColorKey((char)checked_box_pic_0, extraout_DL_23, uVar4, checked_box_pic_0, 0xffffff);
    uVar4 = 0x67;
    DAT_00421e6c = LoadSurface(uVar1, extraout_DL_24, extraout_CL_10, 0x67);
    uVar1 = SetColorKey((char)DAT_00421e6c, extraout_DL_25, uVar4, DAT_00421e6c, 0);
    uVar4 = 0x80;
    DAT_00421e8c = LoadSurface(uVar1, extraout_DL_26, extraout_CL_11, 0x80);
    uVar1 = SetColorKey((char)DAT_00421e8c, extraout_DL_27, uVar4, DAT_00421e8c, 0xffffff);
    DAT_0042013c = DAT_0042013c + 1;
    uVar4 = 0x6c;
    uVar3 = LoadSurface(uVar1, extraout_DL_28, extraout_CL_12, 0x6c);
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d50 + iVar2) = uVar3;
    uVar1 = 0x6d;
    uVar3 = LoadSurface((char)uVar3, (char)iVar2, uVar4, 0x6d);
    *(char4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
    (&DAT_00422d40)[DAT_0042013c * 8] = 6;
    (&DAT_00422d44)[DAT_0042013c * 8] = 0x178;
    (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
    (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
    (&DAT_00422d58)[DAT_0042013c * 8] = 0;
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d5c + iVar2) = 0xff;
    DAT_0042013c = DAT_0042013c + 1;
    uVar4 = 0x6e;
    uVar3 = LoadSurface((char)iVar2, 0, uVar1, 0x6e);
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d50 + iVar2) = uVar3;
    uVar1 = 0x6f;
    uVar3 = LoadSurface((char)uVar3, (char)iVar2, uVar4, 0x6f);
    *(char4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
    (&DAT_00422d40)[DAT_0042013c * 8] = 0x4a;
    (&DAT_00422d44)[DAT_0042013c * 8] = 0x178;
    (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
    (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
    (&DAT_00422d58)[DAT_0042013c * 8] = 0;
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d5c + iVar2) = 0xff;
    DAT_0042013c = DAT_0042013c + 1;
    uVar4 = 0x70;
    uVar3 = LoadSurface((char)iVar2, 0, uVar1, 0x70);
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d50 + iVar2) = uVar3;
    uVar1 = 0x71;
    uVar3 = LoadSurface((char)uVar3, (char)iVar2, uVar4, 0x71);
    *(char4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
    (&DAT_00422d40)[DAT_0042013c * 8] = 0x8e;
    (&DAT_00422d44)[DAT_0042013c * 8] = 0x178;
    (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
    (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
    (&DAT_00422d58)[DAT_0042013c * 8] = 0;
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d5c + iVar2) = 0xff;
    DAT_0042013c = DAT_0042013c + 1;
    uVar4 = 0x72;
    uVar3 = LoadSurface((char)iVar2, 0, uVar1, 0x72);
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d50 + iVar2) = uVar3;
    uVar1 = 0x73;
    uVar3 = LoadSurface((char)uVar3, (char)iVar2, uVar4, 0x73);
    *(char4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
    (&DAT_00422d40)[DAT_0042013c * 8] = 0xd2;
    (&DAT_00422d44)[DAT_0042013c * 8] = 0x178;
    (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
    (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
    (&DAT_00422d58)[DAT_0042013c * 8] = 0;
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d5c + iVar2) = 0xff;
    DAT_0042013c = DAT_0042013c + 1;
    uVar4 = 0x74;
    uVar3 = LoadSurface((char)iVar2, 0, uVar1, 0x74);
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d50 + iVar2) = uVar3;
    uVar1 = 0x75;
    uVar3 = LoadSurface((char)uVar3, (char)iVar2, uVar4, 0x75);
    *(char4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
    (&DAT_00422d40)[DAT_0042013c * 8] = 0x116;
    (&DAT_00422d44)[DAT_0042013c * 8] = 0x178;
    (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
    (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
    (&DAT_00422d58)[DAT_0042013c * 8] = 0;
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d5c + iVar2) = 0;
    DAT_0042013c = DAT_0042013c + 1;
    uVar4 = 0x76;
    uVar3 = LoadSurface((char)iVar2, 0, uVar1, 0x76);
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d50 + iVar2) = uVar3;
    uVar1 = 0x77;
    uVar3 = LoadSurface((char)uVar3, (char)iVar2, uVar4, 0x77);
    *(char4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
    (&DAT_00422d40)[DAT_0042013c * 8] = 0x116;
    (&DAT_00422d44)[DAT_0042013c * 8] = 0x178;
    (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
    (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
    (&DAT_00422d58)[DAT_0042013c * 8] = 0;
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d5c + iVar2) = 2;
    DAT_0042013c = DAT_0042013c + 1;
    uVar4 = 0x78;
    uVar3 = LoadSurface((char)iVar2, 0, uVar1, 0x78);
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d50 + iVar2) = uVar3;
    uVar1 = 0x79;
    uVar3 = LoadSurface((char)uVar3, (char)iVar2, uVar4, 0x79);
    *(char4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
    (&DAT_00422d40)[DAT_0042013c * 8] = 0xd7;
    (&DAT_00422d44)[DAT_0042013c * 8] = 0x115;
    (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
    (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
    (&DAT_00422d58)[DAT_0042013c * 8] = 0;
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d5c + iVar2) = 4;
    DAT_0042013c = DAT_0042013c + 1;
    uVar4 = 0x78;
    uVar3 = LoadSurface((char)iVar2, 0, uVar1, 0x78);
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d50 + iVar2) = uVar3;
    uVar1 = 0x79;
    uVar3 = LoadSurface((char)uVar3, (char)iVar2, uVar4, 0x79);
    *(char4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
    (&DAT_00422d40)[DAT_0042013c * 8] = 0xaa;
    (&DAT_00422d44)[DAT_0042013c * 8] = 0x115;
    (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
    (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
    (&DAT_00422d58)[DAT_0042013c * 8] = 0;
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d5c + iVar2) = 3;
    DAT_0042013c = DAT_0042013c + 1;
    uVar4 = 0x78;
    uVar3 = LoadSurface((char)iVar2, 0, uVar1, 0x78);
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d50 + iVar2) = uVar3;
    uVar1 = 0x79;
    uVar3 = LoadSurface((char)uVar3, (char)iVar2, uVar4, 0x79);
    *(char4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
    (&DAT_00422d40)[DAT_0042013c * 8] = 0xb4;
    (&DAT_00422d44)[DAT_0042013c * 8] = 0x115;
    (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
    (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
    (&DAT_00422d58)[DAT_0042013c * 8] = 0;
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d5c + iVar2) = 5;
    DAT_0042013c = DAT_0042013c + 1;
    uVar4 = 0x7c;
    uVar3 = LoadSurface((char)iVar2, 0, uVar1, 0x7c);
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d50 + iVar2) = uVar3;
    uVar1 = 0x7d;
    uVar3 = LoadSurface((char)uVar3, (char)iVar2, uVar4, 0x7d);
    *(char4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
    (&DAT_00422d40)[DAT_0042013c * 8] = 0xfa;
    (&DAT_00422d44)[DAT_0042013c * 8] = 0x115;
    (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
    (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
    (&DAT_00422d58)[DAT_0042013c * 8] = 0;
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d5c + iVar2) = 5;
    DAT_0042013c = DAT_0042013c + 1;
    uVar4 = 0x7a;
    uVar3 = LoadSurface((char)iVar2, 0, uVar1, 0x7a);
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d50 + iVar2) = uVar3;
    uVar1 = 0x7b;
    uVar3 = LoadSurface((char)uVar3, (char)iVar2, uVar4, 0x7b);
    *(char4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
    (&DAT_00422d40)[DAT_0042013c * 8] = 0xb4;
    (&DAT_00422d44)[DAT_0042013c * 8] = 0x115;
    (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
    (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
    (&DAT_00422d58)[DAT_0042013c * 8] = 0;
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d5c + iVar2) = 9;
    DAT_0042013c = DAT_0042013c + 1;
    uVar4 = 0x74;
    uVar3 = LoadSurface((char)iVar2, 0, uVar1, 0x74);
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d50 + iVar2) = uVar3;
    uVar1 = 0x75;
    uVar3 = LoadSurface((char)uVar3, (char)iVar2, uVar4, 0x75);
    *(char4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
    (&DAT_00422d40)[DAT_0042013c * 8] = 0xfa;
    (&DAT_00422d44)[DAT_0042013c * 8] = 0x115;
    (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
    (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
    (&DAT_00422d58)[DAT_0042013c * 8] = 0;
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d5c + iVar2) = 9;
    DAT_0042013c = DAT_0042013c + 1;
    uVar4 = 0x7e;
    uVar3 = LoadSurface((char)iVar2, 0, uVar1, 0x7e);
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d50 + iVar2) = uVar3;
    uVar1 = 0x7f;
    uVar3 = LoadSurface((char)uVar3, (char)iVar2, uVar4, 0x7f);
    *(char4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
    (&DAT_00422d40)[DAT_0042013c * 8] = 0xf0;
    (&DAT_00422d44)[DAT_0042013c * 8] = 0x115;
    (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x5c;
    (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
    (&DAT_00422d58)[DAT_0042013c * 8] = 0;
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d5c + iVar2) = 3;
    DAT_0042013c = DAT_0042013c + 1;
    uVar4 = 0x86;
    uVar3 = LoadSurface((char)iVar2, 0, uVar1, 0x86);
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d50 + iVar2) = uVar3;
    uVar1 = 0x87;
    uVar3 = LoadSurface((char)uVar3, (char)iVar2, uVar4, 0x87);
    *(char4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
    (&DAT_00422d40)[DAT_0042013c * 8] = 0x1aa;
    (&DAT_00422d44)[DAT_0042013c * 8] = 0x178;
    (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
    (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
    (&DAT_00422d58)[DAT_0042013c * 8] = 0;
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d5c + iVar2) = 2;
    DAT_0042013c = DAT_0042013c + 1;
    uVar4 = 0x78;
    uVar3 = LoadSurface((char)iVar2, 0, uVar1, 0x78);
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d50 + iVar2) = uVar3;
    uVar1 = 0x79;
    uVar3 = LoadSurface((char)uVar3, (char)iVar2, uVar4, 0x79);
    *(char4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
    (&DAT_00422d40)[DAT_0042013c * 8] = 0xd7;
    (&DAT_00422d44)[DAT_0042013c * 8] = 0x11b;
    (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
    (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
    (&DAT_00422d58)[DAT_0042013c * 8] = 0;
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d5c + iVar2) = 7;
    DAT_0042013c = DAT_0042013c + 1;
    uVar4 = 0x78;
    uVar3 = LoadSurface((char)iVar2, 0, uVar1, 0x78);
    iVar2 = DAT_0042013c * 0x20;
    *(char4 *)(&DAT_00422d50 + iVar2) = uVar3;
    uVar1 = 0x79;
    uVar3 = LoadSurface((char)uVar3, (char)iVar2, uVar4, 0x79);
    *(char4 *)(&DAT_00422d54 + DAT_0042013c * 0x20) = uVar3;
    (&DAT_00422d40)[DAT_0042013c * 8] = 0xd7;
    (&DAT_00422d44)[DAT_0042013c * 8] = 0x115;
    (&DAT_00422d48)[DAT_0042013c * 8] = (&DAT_00422d40)[DAT_0042013c * 8] + 0x3e;
    (&DAT_00422d4c)[DAT_0042013c * 8] = (&DAT_00422d44)[DAT_0042013c * 8] + 0x26;
    (&DAT_00422d58)[DAT_0042013c * 8] = 0;
    *(char4 *)(&DAT_00422d5c + DAT_0042013c * 0x20) = 6;
    mci_OpenWave(0xc5, 0, uVar1, s_intro_wav_004208c5, s_intro_004208cf);
    mci_OpenWave(0xd5, extraout_DL_29, extraout_CL_13, s_click_wav_004208d5, s_click_004208df);
    mci_OpenWave(0xe5, extraout_DL_30, extraout_CL_14, s_pop_wav_004208e5, &DAT_004208ed);
    mci_OpenWave(0xf1, extraout_DL_31, extraout_CL_15, s_megapop_wav_004208f1, s_megapop_004208fd);
    mci_OpenWave(5, extraout_DL_32, extraout_CL_16, s_score_wav_00420905, s_score_0042090f);
    mci_OpenWave(0x15, extraout_DL_33, extraout_CL_17, s_higscore_wav_00420915, s_highscore_00420922);
    mci_OpenWave(0x2c, extraout_DL_34, extraout_CL_18, s_sharewar_wav_0042092c, s_shareware_00420939);
    wsprintfA(local_104, s_set__s_time_format_tms_00420943, &DAT_0042095a);
    mci_ExecStr((char)local_104, extraout_DL_35, extraout_CL_19, local_104);
    wsprintfA(local_104, s_seek__s_to_end_0042095e, &DAT_0042096d);
    pCVar7 = local_104;
    mci_ExecStr((char)pCVar7, extraout_DL_36, extraout_CL_20, pCVar7);
    mci_PlayWave(0x71, extraout_DL_37, (char)pCVar7, &DAT_00420971);
    wsprintfA(local_104, s_seek__s_to_start_00420975, &DAT_00420986);
    pCVar7 = local_104;
    mci_ExecStr((char)pCVar7, extraout_DL_38, extraout_CL_21, pCVar7);
    if (change_mode+150 != 0)
    {
        mci_PlayWave(0x8a, extraout_DL_39, (char)pCVar7, s_click_0042098a);
    }
    Create_Screen();
    DAT_004200a8 = 1;
    return;
}
void  Check_In_Box(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7, int param_8, int param_9)
    {
    if ((((param_4 < param_8) && (param_8 < param_6)) && (param_5 < param_9)) && (param_9 < param_7))
    {
        return 1;
    }
    return 0;
}
void  Check_Bubble(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6)

{
    int iVar1;
    char *extraout_ECX;
    char *extraout_ECX_00;
    char *extraout_ECX_01;
    int *puVar2;
    char *extraout_EDX;
    char *extraout_EDX_00;
    char *extraout_EDX_01;
    int *puVar3;

    if ((param_6 != 0) &&
        (puVar2 = Check_Bubble + param_4 * 0x2a, (Create_Game_Screen)[param_4 * 0x2a + param_5 * 6] == param_6 && puVar2[param_5 * 6] == 0))
    {
        iVar1 = param_5 * 3;
        puVar3 = Check_Bubbles + param_4 * 0x2a;
        puVar3[param_5 * 6] = 1;
        if (0 < param_5)
        {
            iVar1 = param_5 + -1;
            Check_Bubble(iVar1, (int)puVar3, (int)puVar2, param_4, iVar1, param_6);
            puVar2 = extraout_ECX;
            puVar3 = extraout_EDX;
        }
        if (param_5 < 6)
        {
            iVar1 = param_5 + 1;
            Check_Bubbles(iVar1, (int)puVar3, (int)puVar2, param_4, iVar1, param_6);
            puVar2 = extraout_ECX_00;
            puVar3 = extraout_EDX_00;
        }
        if (0 < param_4)
        {
            iVar1 = param_4 + -1;
            Check_Bubble(iVar1, (int)puVar3, (int)puVar2, iVar1, param_5, param_6);
            puVar2 = extraout_ECX_01;
            puVar3 = extraout_EDX_01;
        }
        if (param_4 < 9)
        {
            Check_Bubble(iVar1, (int)puVar3, (int)puVar2, param_4 + 1, param_5, param_6);
        }
    }
    return;
}
void  Check_Bubbles_Clicked(byte param_1, byte param_2, byte param_3, byte param_4, byte param_5)

{
    double dVar1;
    char cVar2;
    int iVar3;
    int iVar4;
    int iVar5;
    int iVar6;
    int unaff_EDI;
    int in_stack_00000005;
    int in_stack_00000009;

    dVar1 = (double)((_param_4 + -8) / 0x30);
    _floor(SUB84(dVar1, 0), (double)CONCAT44(unaff_EDI, (int)((ulonglong)dVar1 >> 0x20)));
    iVar3 = __ftol();
    dVar1 = (double)((_param_5 + -8) / 0x30);
    _floor(SUB84(dVar1, 0), (double)CONCAT44(unaff_EDI, (int)((ulonglong)dVar1 >> 0x20)));
    iVar4 = __ftol();
    if ((DAT_0042011c == 0) || ((&DAT_00421f18)[iVar3 * 0x2a + iVar4 * 6] == 0))
    {
        iVar6 = 0;
        do
        {
            iVar5 = 0;
            do
            {
                cVar2 = (char)iVar6;
                (&DAT_00421f18)[iVar5 * 0x2a + iVar6 * 6] = 0;
                iVar5 = iVar5 + 1;
            } while (iVar5 < 10);
            iVar6 = iVar6 + 1;
        } while (iVar6 < 7);
        if (DAT_0042011c == 0)
        {
            iVar3 = Check_Bubble((char)iVar4 * '\x03', (char)(&DAT_00421f04 + iVar3 * 0x2a), cVar2 * '\x03',
                                 iVar3, iVar4, (&DAT_00421f04 + iVar3 * 0x2a)[iVar4 * 6]);
            if (1 < iVar3)
            {
                DAT_0042011c = 1;
                DAT_00421eac = (iVar3 + -1) * iVar3;
                DAT_00420130 = iVar3;
            }
        }
        else
        {
            DAT_0042011c = 0;
            DAT_00420130 = 0;
            DAT_00421eac = 0;
        }
        Create_Screen();
    }
    else
    {
        Update_Bubbles();
        DAT_0042012c = 1;
    }
    return;
}
void  Check_Button_Up(int param_1, int param_2, int param_3, int param_4,int param_5)

{
    char cVar1;
    int iVar2;
    HDC extraout_CL;
    int uVar3;
    HDC extraout_CL_00;
    HDC extraout_CL_01;
    HDC extraout_CL_02;
    HDC extraout_CL_03;
    HDC extraout_CL_04;
    HDC extraout_CL_05;
    HDC extraout_CL_06;
    HDC extraout_CL_07;
    HDC extraout_CL_08;
    HDC extraout_CL_09;
    HDC extraout_DL;
    HDC extraout_DL_00;
    HDC extraout_DL_01;
    HDC extraout_DL_02;
    HDC extraout_DL_03;
    HDC extraout_DL_04;
    HDC extraout_DL_05;
    HDC extraout_DL_06;
    HDC extraout_DL_07;
    HDC extraout_DL_08;
    HDC extraout_DL_09;
    HDC extraout_DL_10;
    HDC extraout_DL_11;
    int uVar4;

    iVar2 = Check_In_Box((char)pressed_button_0 * ' ', param_2, param_3, (&buttons_0)[pressed_button_0 * 8],
                         (&Check_Button_Down+31)[pressed_button_0 * 8], (&Check_Button_Up + 22)[pressed_button_0 * 8],
                         (&Check_Button_Up+1C)[pressed_button_0 * 8], param_4, param_5);
    uVar3 = extraout_CL;
    uVar4 = extraout_DL;
    if (((iVar2 != 0) &&
         (uVar4 = *(int *)(&Check_Button_Down + 4E + pressed_button_0 * 0x20) == 0xff,
          *(int *)(&Check_Button_Down + 4E + pressed_button_0 * 0x20) == DAT_0042010c || (bool)uVar4)) &&
        (uVar4 = 4 < pressed_button_0, DAT_00420118 == 0 || (bool)uVar4))
    {
        cVar1 = (char)pressed_button_0;
        (&DAT_00422d58)[pressed_button_0 * 8] = 0;
        iVar2 = pressed_button_0;
        uVar4 = Update_Button(cVar1 * ' ', 0, extraout_CL, pressed_button_0);
        Execute_Button(uVar4, extraout_DL_00, (char)iVar2, pressed_button_0);
        uVar3 = (int)pressed_button_0;
        uVar4 = extraout_DL_01;
    }
    pressed_button_0 = 0;
    if (DAT_0042010c == 4)
    {
        iVar2 = Check_In_Box(0, uVar4, uVar3, 0x61, 0x65, 0xd2, 0x78, param_4, param_5);
        uVar4 = extraout_CL_00;
        uVar3 = extraout_DL_02;
        if (iVar2 != 0)
        {
            _Str_00421ee8 = (void *)0x0;
            iVar2 = Create_Screen();
            uVar4 = extraout_CL_01;
            uVar3 = extraout_DL_03;
        }
        iVar2 = Check_In_Box((char)iVar2, uVar3, uVar4, 0x61, 0x84, 0xe5, 0x97, param_4, param_5);
        uVar4 = extraout_CL_02;
        uVar3 = extraout_DL_04;
        if (iVar2 != 0)
        {
            _Str_00421ee8 = (void *)0x1;
            iVar2 = Create_Screen();
            uVar4 = extraout_CL_03;
            uVar3 = extraout_DL_05;
        }
        iVar2 = Check_In_Box((char)iVar2, uVar3, uVar4, 0x61, 0xa3, 0xbd, 0xb6, param_4, param_5);
        uVar4 = extraout_CL_04;
        uVar3 = extraout_DL_06;
        if (iVar2 != 0)
        {
            _Str_00421ee8 = (void *)0x2;
            iVar2 = Create_Screen();
            uVar4 = extraout_CL_05;
            uVar3 = extraout_DL_07;
        }
        iVar2 = Check_In_Box((char)iVar2, uVar3, uVar4, 0x61, 0xc2, 0xdb, 0xd9, param_4, param_5);
        uVar4 = extraout_CL_06;
        uVar3 = extraout_DL_08;
        if (iVar2 != 0)
        {
            _Str_00421ee8 = (void *)0x3;
            iVar2 = Create_Screen();
            uVar4 = extraout_CL_07;
            uVar3 = extraout_DL_09;
        }
        iVar2 = Check_In_Box((char)iVar2, uVar3, uVar4, 0x115, 0x51, 0x1a0, 0x65, param_4, param_5);
        uVar4 = extraout_CL_08;
        uVar3 = extraout_DL_10;
        if (iVar2 != 0)
        {
            change_mode+150 = (uint)(change_mode+150 == 0);
            iVar2 = Create_Screen();
            uVar4 = extraout_CL_09;
            uVar3 = extraout_DL_11;
        }
        iVar2 = Check_In_Box((char)iVar2, uVar3, uVar4, 0x116, 0x7c, 0x196, 0x8f, param_4, param_5);
        if (iVar2 != 0)
        {
            Check_Button_Up+26A = (uint)(Check_Button_Up+26A == 0);
            Create_Screen();
        }
    }
    return;
}
void  Check_Button_Down(int param_1, int param_2, int param_3, int param_4, int param_5)

{
    bool bVar1;
    uint uVar2;
    uint uVar3;
    HDC extraout_CL;
    uint extraout_ECX;
    uint uVar4;
    uint extraout_EDX;
    uint extraout_EDX_00;
    uint uVar5;

    uVar4 = (uint)param_2;
    uVar3 = (uint)param_3;
    uVar2 = (uint)param_1;
    uVar5 = 1;
    while (true)
    {
        if (DAT_0042013c < (int)uVar5)
            break;
        uVar2 = Check_In_Box((char)uVar5 * ' ', (char)uVar4, (char)uVar3, (&DAT_00422d40)[uVar5 * 8],
                             (&DAT_00422d44)[uVar5 * 8], (&DAT_00422d48)[uVar5 * 8],
                             (&DAT_00422d4c)[uVar5 * 8], param_4, param_5);
        uVar3 = extraout_ECX;
        uVar4 = extraout_EDX;
        if (uVar2 != 0)
        {
            uVar4 = (uint)(*(int *)(&DAT_00422d5c + uVar5 * 0x20) == 0xff);
            uVar2 = (uint)(*(int *)(&DAT_00422d5c + uVar5 * 0x20) == DAT_0042010c ||
                           *(int *)(&DAT_00422d5c + uVar5 * 0x20) == 0xff);
            if (uVar2 != 0)
            {
                bVar1 = 4 < (int)uVar5;
                uVar4 = (uint)bVar1;
                uVar2 = (uint)(DAT_00420118 == 0 || bVar1);
                if (uVar2 != 0)
                {
                    DAT_00420140 = uVar5;
                    (&DAT_00422d58)[uVar5 * 8] = 1;
                    uVar3 = uVar5;
                    uVar2 = Update_Button((char)uVar5 * ' ', bVar1, (char)extraout_ECX, uVar5);
                    uVar4 = extraout_EDX_00;
                }
            }
        }
        uVar5 = uVar5 + 1;
    }
    uVar3 = Check_In_Box((char)uVar2, (char)uVar4, (char)uVar3, 7, 7, 0x1e6, 0x156, param_4, param_5);
    uVar3 = uVar3 & DAT_0042010c == 2;
    if ((uVar3 != 0) && (DAT_00420120 == 0))
    {
        Check_Bubbles_Clicked((char)uVar3, DAT_0042010c == 2, extraout_CL, param_4, param_5);
    }
    return;
}
void  Check_Button_Move(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6)

{
    char cVar1;
    int iVar2;
    HDC extraout_CL;
    HDC extraout_CL_00;
    HDC extraout_DL;
    HDC extraout_DL_00;
    HDC extraout_DL_01;
    int uVar3;
    int uVar4;

    uVar4 = int pressed_button_0 != 0;
    if (param_6 != 1 && (bool)uVar4)
    {
        cVar1 = (char)int pressed_button_0;
        (int Check_Button_Up + A6)[int pressed_button_0 * 8] = 0;
        void Update_Button(cVar1 * ' ', 0, param_3, int pressed_button_0);
        param_3 = int pressed_button_0;
        int pressed_button_0 = 0;
        uVar4 = extraout_DL;
    }
    if (int pressed_button_0 != 0)
    {
        iVar2 = void Check_In_Box(int pressed_button_0 * ' ', uVar4, param_3, (Update_Button + 7)[int pressed_button_0 * 8],
                                  (Check_Button_Down + 30)[int pressed_button_0 * 8], (Check_Button_Down + 26)[int pressed_button_0 * 8],
                                  (Check_Button_Down + 20)[int pressed_button_0 * 8], param_4, param_5);
        uVar4 = extraout_CL;
        uVar3 = extraout_DL_00;
        if (iVar2 != 0)
        {
            cVar1 = int pressed_button_0;
            (Check_Button_Up + A6)[int pressed_button_0 * 8] = 1;
            iVar2 = int pressed_button_0;
            Update_Button(cVar1 * ' ', extraout_DL_00, extraout_CL, int pressed_button_0);
            uVar4 = (int)iVar2;
            uVar3 = extraout_DL_01;
        }
        iVar2 = void  Check_In_Box(int pressed_button_0 * ' ', uVar3, uVar4, (Update_Button + 7)[int pressed_button_0 * 8],
                                          (Check_Button_Down + 30)[int pressed_button_0 * 8], (&Check_Button_Down + 26)[int pressed_button_0 * 8],
                                          (Check_Button_Down + 20)[int pressed_button_0 * 8], param_4, param_5);
        if (iVar2 == 0)
        {
            cVar1 = int pressed_button_0;
            (Check_Button_Up + A6)[int pressed_button_0 * 8] = 0;
            void Update_Buttons(cVar1 * ' ', 0, extraout_CL_00, int pressed_button_0);
        }
    }
    return;
}
void Undo_Move(void)

{
    int iVar1;
    int iVar2;

    if (DAT_0042012c != 0)
    {
        iVar2 = 0;
        do
        {
            iVar1 = 0;
            do
            {
                (DAT_00422594)[iVar1 * 0x2a + iVar2 * 6] = 0;
                (DAT_00422594)
                    [(DAT_00421f10)[iVar1 * 0x2a + iVar2 * 6] * 0x2a +
                     (&DAT_00421f14)[iVar1 * 0x2a + iVar2 * 6] * 6] = (&DAT_00421f04)[iVar1 * 0x2a + iVar2 * 6];
                (&DAT_00422598)
                    [(&DAT_00421f10)[iVar1 * 0x2a + iVar2 * 6] * 0x2a +
                     (&DAT_00421f14)[iVar1 * 0x2a + iVar2 * 6] * 6] = iVar1 * 0x30 + 8;
                (&DAT_0042259c)
                    [(&DAT_00421f10)[iVar1 * 0x2a + iVar2 * 6] * 0x2a +
                     (&DAT_00421f14)[iVar1 * 0x2a + iVar2 * 6] * 6] = iVar2 * 0x30 + 8;
                (&DAT_004225a0)
                    [(&DAT_00421f10)[iVar1 * 0x2a + iVar2 * 6] * 0x2a +
                     (&DAT_00421f14)[iVar1 * 0x2a + iVar2 * 6] * 6] = 0xffffffff;
                (&DAT_004225a4)
                    [(&DAT_00421f10)[iVar1 * 0x2a + iVar2 * 6] * 0x2a +
                     (&DAT_00421f14)[iVar1 * 0x2a + iVar2 * 6] * 6] = 0xffffffff;
                (&DAT_004225a8)
                    [(&DAT_00421f10)[iVar1 * 0x2a + iVar2 * 6] * 0x2a +
                     (&DAT_00421f14)[iVar1 * 0x2a + iVar2 * 6] * 6] = 0;
                iVar1 = iVar1 + 1;
            } while (iVar1 < 10);
            iVar2 = iVar2 + 1;
        } while (iVar2 < 7);
        iVar2 = 0;
        do
        {
            iVar1 = 0;
            do
            {
                if ((&DAT_00422594)[iVar1 * 0x2a + iVar2 * 6] == 0)
                {
                    (&DAT_00422594)[iVar1 * 0x2a + iVar2 * 6] = (&DAT_00422c24)[iVar1 * 7 + iVar2];
                    (&DAT_00422598)[iVar1 * 0x2a + iVar2 * 6] = iVar1 * 0x30 + 8;
                    (&DAT_0042259c)[iVar1 * 0x2a + iVar2 * 6] = iVar2 * 0x30 + 8;
                    (&DAT_004225a0)[iVar1 * 0x2a + iVar2 * 6] = 0xffffffff;
                    (&DAT_004225a4)[iVar1 * 0x2a + iVar2 * 6] = 0xffffffff;
                    (&DAT_004225a8)[iVar1 * 0x2a + iVar2 * 6] = 0;
                }
                iVar1 = iVar1 + 1;
            } while (iVar1 < 10);
            iVar2 = iVar2 + 1;
        } while (iVar2 < 7);
        iVar2 = 0;
        do
        {
            iVar1 = 0;
            do
            {
                (&DAT_00421f04)[iVar1 * 0x2a + iVar2 * 6] = (&DAT_00422594)[iVar1 * 0x2a + iVar2 * 6];
                (&DAT_00421f08)[iVar1 * 0x2a + iVar2 * 6] = (&DAT_00422598)[iVar1 * 0x2a + iVar2 * 6];
                (&DAT_00421f0c)[iVar1 * 0x2a + iVar2 * 6] = (&DAT_0042259c)[iVar1 * 0x2a + iVar2 * 6];
                (&DAT_00421f10)[iVar1 * 0x2a + iVar2 * 6] = (&DAT_004225a0)[iVar1 * 0x2a + iVar2 * 6];
                (&DAT_00421f14)[iVar1 * 0x2a + iVar2 * 6] = (&DAT_004225a4)[iVar1 * 0x2a + iVar2 * 6];
                (&DAT_00421f18)[iVar1 * 0x2a + iVar2 * 6] = (&DAT_004225a8)[iVar1 * 0x2a + iVar2 * 6];
                iVar1 = iVar1 + 1;
            } while (iVar1 < 10);
            iVar2 = iVar2 + 1;
        } while (iVar2 < 7);
        DAT_00421ee0 = DAT_00421ee0 - DAT_00422d3c;
        DAT_00422d3c = 0;
        DAT_0042012c = 0;
        DAT_00420120 = 1;
        Create_Screen();
    }
    return;
}
uint  ColorMatch(int param_1, int param_2, int param_3, int *param_4, COLORREF param_5)

{
    int iVar1;
    uint uVar2;
    uint *local_54;
    uint local_24;
    HDC local_c;
    COLORREF local_8;

    uVar2 = 0xffffffff;
    if ((param_5 != 0xffffffff) && (iVar1 = (**(code **)(*param_4 + 0x44))(), iVar1 == 0))
    {
        local_8 = GetPixel(local_c, 0, 0);
        SetPixel(local_c, 0, 0, param_5);
        (**(code **)(*param_4 + 0x68))();
    }
    do
    {
        iVar1 = (**(code **)(*param_4 + 100))();
    } while (iVar1 == -0x7789fde4);
    if (iVar1 == 0)
    {
        uVar2 = *local_54;
        if (local_24 < 0x20)
        {
            uVar2 = uVar2 & (1 << ((byte)local_24 & 0x1f)) - 1U;
        }
        (**(code **)(*param_4 + 0x80))();
    }
    if ((param_5 != 0xffffffff) && (iVar1 = (**(code **)(*param_4 + 0x44))(), iVar1 == 0))
    {
        SetPixel(local_c, 0, 0, local_8);
        (**(code **)(*param_4 + 0x68))();
    }
    return uVar2;
}
void  SetColorKey(int param_1, int param_2, int param_3, int *param_4, int param_5)

{
    ColorMatch(param_1, param_2, param_3, param_4, param_5);
    (**(code **)(*param_4 + 0x74))();
    return;
}
void  Move_Bubble(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7)
{
    (PlayField_0)[param_4 * 0x2a + param_5 * 6] = (PlayField_0)[param_6 * 0x2a + param_7 * 6];
    (&DAT_00421f08)[param_4 * 0x2a + param_5 * 6] = (&DAT_00421f08)[param_6 * 0x2a + param_7 * 6];
    (&DAT_00421f0c)[param_4 * 0x2a + param_5 * 6] = (&DAT_00421f0c)[param_6 * 0x2a + param_7 * 6];
    (&DAT_00421f10)[param_4 * 0x2a + param_5 * 6] = (&DAT_00421f10)[param_6 * 0x2a + param_7 * 6];
    (&DAT_00421f14)[param_4 * 0x2a + param_5 * 6] = (&DAT_00421f14)[param_6 * 0x2a + param_7 * 6];
    (Check_Bubble)[param_4 * 0x2a + param_5 * 6] = (Check_Bubble)[param_6 * 0x2a + param_7 * 6];
    (PlayField_0)[param_6 * 0x2a + param_7 * 6] = 0;
    (&DAT_00421f08)[param_6 * 0x2a + param_7 * 6] = 0xffff;
    (&DAT_00421f0c)[param_6 * 0x2a + param_7 * 6] = 0xffff;
    (&DAT_00421f10)[param_6 * 0x2a + param_7 * 6] = 0xffffffff;
    (&DAT_00421f14)[param_6 * 0x2a + param_7 * 6] = 0xffffffff;
    (Check_Bubble)[param_6 * 0x2a + param_7 * 6] = 0;
    return;
}
void heck_all_bubbles_moved(void)

{
    int iVar1;
    int iVar2;

    iVar2 = 0;
    do
    {
        iVar1 = 0;
        do
        {
            if ((&DAT_00421f08)[iVar1 * 0x2a + iVar2 * 6] != 0xffff ||
                (&DAT_00421f0c)[iVar1 * 0x2a + iVar2 * 6] != 0xffff)
            {
                return;
            }
            iVar1 = iVar1 + 1;
        } while (iVar1 < 10);
        iVar2 = iVar2 + 1;
    } while (iVar2 < 7);
    return;
}
void Update_Bubble(void)

{
    HDC extraout_CL;
    HDC extraout_CL_00;
    HDC extraout_CL_01;
    HDC extraout_CL_02;
    HDC extraout_CL_03;
    HDC extraout_CL_04;
    HDC extraout_CL_05;
    HDC extraout_CL_06;
    HDC extraout_CL_07;
    HDC extraout_CL_08;
    HDC extraout_CL_09;
    HDC extraout_CL_10;
    HDC extraout_CL_11;
    HDC extraout_CL_12;
    HDC extraout_CL_13;
    HDC extraout_CL_14;
    HDC extraout_CL_15;
    HDC extraout_CL_16;
    HDC extraout_CL_17;
    HDC extraout_CL_18;
    HDC extraout_CL_19;
    HDC extraout_CL_20;
    HDC extraout_CL_21;
    HDC extraout_CL_22;
    HDC extraout_CL_23;
    HDC extraout_CL_24;
    HDC extraout_CL_25;
    HDC extraout_CL_26;
    HDC extraout_CL_27;
    HDC extraout_CL_28;
    HDC extraout_CL_29;
    HDC extraout_CL_30;
    HDC extraout_CL_31;
    HDC extraout_CL_32;
    HDC extraout_CL_33;
    HDC extraout_CL_34;
    HDC extraout_CL_35;
    HDC extraout_CL_36;
    HDC extraout_CL_37;
    HDC extraout_CL_38;
    HDC extraout_CL_39;
    HDC extraout_CL_40;
    HDC extraout_CL_41;
    HDC extraout_CL_42;
    HDC extraout_CL_43;
    HDC extraout_CL_44;
    HDC extraout_CL_45;
    HDC extraout_CL_46;
    HDC extraout_CL_47;
    HDC extraout_CL_48;
    HDC extraout_CL_49;
    HDC extraout_CL_50;
    HDC extraout_CL_51;
    HDC extraout_CL_52;
    HDC extraout_CL_53;
    HDC extraout_CL_54;
    HDC extraout_CL_55;
    HDC extraout_CL_56;
    HDC extraout_CL_57;
    HDC extraout_CL_58;
    HDC extraout_CL_59;
    HDC extraout_CL_60;
    HDC extraout_CL_61;
    HDC extraout_CL_62;
    HDC extraout_CL_63;
    HDC extraout_CL_64;
    HDC extraout_CL_65;
    HDC extraout_CL_66;
    HDC extraout_CL_67;
    HDC extraout_CL_68;
    HDC extraout_CL_69;
    HDC extraout_CL_70;
    HDC extraout_CL_71;
    HDC extraout_CL_72;
    HDC extraout_CL_73;
    HDC extraout_CL_74;
    HDC extraout_CL_75;
    HDC extraout_CL_76;
    HDC extraout_CL_77;
    HDC extraout_CL_78;
    HDC extraout_CL_79;
    HDC extraout_CL_80;
    HDC extraout_CL_81;
    HDC extraout_CL_82;
    HDC extraout_CL_83;
    HDC extraout_CL_84;
    HDC extraout_CL_85;
    HDC extraout_CL_86;
    char *extraout_ECX;
    char *extraout_ECX_00;
    char *extraout_ECX_01;
    char *extraout_ECX_02;
    char *extraout_ECX_03;
    char *extraout_ECX_04;
    char *extraout_ECX_05;
    char *extraout_ECX_06;
    char *extraout_ECX_07;
    char *extraout_ECX_08;
    char *extraout_ECX_09;
    char *extraout_ECX_10;
    char *extraout_ECX_11;
    char *extraout_ECX_12;
    char *extraout_ECX_13;
    char *extraout_ECX_14;
    char *extraout_ECX_15;
    char *extraout_ECX_16;
    char *extraout_ECX_17;
    char *extraout_ECX_18;
    char *extraout_ECX_19;
    char *extraout_ECX_20;
    char *extraout_ECX_21;
    char *extraout_ECX_22;
    char *extraout_ECX_23;
    char *extraout_ECX_24;
    char *extraout_ECX_25;
    char *extraout_ECX_26;
    char *extraout_ECX_27;
    char *extraout_ECX_28;
    HDC extraout_DL;
    HDC extraout_DL_00;
    HDC extraout_DL_01;
    HDC extraout_DL_02;
    HDC extraout_DL_03;
    HDC extraout_DL_04;
    HDC extraout_DL_05;
    HDC extraout_DL_06;
    HDC extraout_DL_07;
    HDC extraout_DL_08;
    HDC extraout_DL_09;
    HDC extraout_DL_10;
    HDC extraout_DL_11;
    HDC extraout_DL_12;
    HDC extraout_DL_13;
    HDC extraout_DL_14;
    HDC extraout_DL_15;
    HDC extraout_DL_16;
    HDC extraout_DL_17;
    HDC extraout_DL_18;
    HDC extraout_DL_19;
    HDC extraout_DL_20;
    HDC extraout_DL_21;
    HDC extraout_DL_22;
    HDC extraout_DL_23;
    HDC extraout_DL_24;
    HDC extraout_DL_25;
    HDC extraout_DL_26;
    HDC extraout_DL_27;
    HDC extraout_DL_28;
    HDC extraout_DL_29;
    HDC extraout_DL_30;
    HDC extraout_DL_31;
    HDC extraout_DL_32;
    HDC extraout_DL_33;
    HDC extraout_DL_34;
    HDC extraout_DL_35;
    HDC extraout_DL_36;
    HDC extraout_DL_37;
    HDC extraout_DL_38;
    HDC extraout_DL_39;
    HDC extraout_DL_40;
    HDC extraout_DL_41;
    HDC extraout_DL_42;
    HDC extraout_DL_43;
    HDC extraout_DL_44;
    HDC extraout_DL_45;
    HDC extraout_DL_46;
    HDC extraout_DL_47;
    HDC extraout_DL_48;
    HDC extraout_DL_49;
    HDC extraout_DL_50;
    HDC extraout_DL_51;
    HDC extraout_DL_52;
    HDC extraout_DL_53;
    HDC extraout_DL_54;
    HDC extraout_DL_55;
    HDC extraout_DL_56;
    HDC extraout_DL_57;
    HDC extraout_DL_58;
    HDC extraout_DL_59;
    HDC extraout_DL_60;
    HDC extraout_DL_61;
    HDC extraout_DL_62;
    HDC extraout_DL_63;
    HDC extraout_DL_64;
    HDC extraout_DL_65;
    HDC extraout_DL_66;
    HDC extraout_DL_67;
    HDC extraout_DL_68;
    HDC extraout_DL_69;
    HDC extraout_DL_70;
    HDC extraout_DL_71;
    HDC extraout_DL_72;
    HDC extraout_DL_73;
    HDC extraout_DL_74;
    HDC extraout_DL_75;
    HDC extraout_DL_76;
    HDC extraout_DL_77;
    HDC extraout_DL_78;
    HDC extraout_DL_79;
    HDC extraout_DL_80;
    HDC extraout_DL_81;
    HDC extraout_DL_82;
    HDC extraout_DL_83;
    HDC extraout_DL_84;
    HDC extraout_DL_85;
    HDC extraout_DL_86;
    int cVar1;
    int uVar2;
    int *puVar3;
    int uVar4;
    int *puVar5;
    int iVar6;
    int *puVar7;
    int iVar8;
    char *extraout_EDX;
    char *extraout_EDX_00;
    char *extraout_EDX_01;
    char *extraout_EDX_02;
    char *extraout_EDX_03;
    char *extraout_EDX_04;
    char *extraout_EDX_05;
    char *extraout_EDX_06;
    char *extraout_EDX_07;
    char *extraout_EDX_08;
    char *extraout_EDX_09;
    char *extraout_EDX_10;
    char *extraout_EDX_11;
    char *extraout_EDX_12;
    char *extraout_EDX_13;
    char *extraout_EDX_14;
    char *extraout_EDX_15;
    char *extraout_EDX_16;
    char *extraout_EDX_17;
    char *extraout_EDX_18;
    char *extraout_EDX_19;
    char *extraout_EDX_20;
    char *extraout_EDX_21;
    char *extraout_EDX_22;
    char *extraout_EDX_23;
    char *extraout_EDX_24;
    char *extraout_EDX_25;
    char *extraout_EDX_26;
    char *extraout_EDX_27;
    char *extraout_EDX_28;
    char *extraout_EDX_29;
    char *extraout_EDX_30;
    char *extraout_EDX_31;
    char *extraout_EDX_32;
    char *extraout_EDX_33;
    char *extraout_EDX_34;
    char *extraout_EDX_35;

    int local_8;

    iVar8 = 0;
    do
    {
        iVar6 = 0;
        do
        {
            (undo_bubble_types_0)[iVar6 * 7 + iVar8] = (Create_Game_Screen)[iVar6 * 0x2a + iVar8 * 6];
            (&DAT_00421f10)[iVar6 * 0x2a + iVar8 * 6] = iVar6;
            (&DAT_00421f14)[iVar6 * 0x2a + iVar8 * 6] = iVar8;
            (&DAT_00421f08)[iVar6 * 0x2a + iVar8 * 6] = iVar6 * 0x30 + 8;
            (&DAT_00421f0c)[iVar6 * 0x2a + iVar8 * 6] = iVar8 * 0x30 + 8;
            puVar3 = Check_Bubble + iVar6 * 0x2a;
            if (puVar3[iVar8 * 6] != 0)
            {
                (Check_Bubble)[iVar6 * 0x2a + iVar8 * 6] = 0;
                (&Create_Game_Screen)[iVar6 * 0x2a + iVar8 * 6] = 0;
                (&DAT_00421f08)[iVar6 * 0x2a + iVar8 * 6] = 0xffff;
                puVar3 = &DAT_00421f0c + iVar6 * 0x2a;
                puVar3[iVar8 * 6] = 0xffff;
            }
            puVar5 = (char *)(iVar8 * 3);
            iVar6 = iVar6 + 1;
        } while (iVar6 < 10);
        iVar8 = iVar8 + 1;
    } while (iVar8 < 7);
    if (game_type_0 == 0)
    {
        iVar8 = 9;
        do
        {
            local_8 = 0;
            do
            {
                cVar1 = (char)iVar8;
                if ((&DAT_00421f94)[iVar8 * 0x2a] == 0)
                {
                    uVar2 = Move_Bubble(cVar1 * '\x15', (char)puVar5, (char)puVar3, iVar8, 6, iVar8, 5);
                    uVar2 = Move_Bubble(uVar2, extraout_DL, extraout_CL, iVar8, 5, iVar8, 4);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_00, extraout_CL_00, iVar8, 4, iVar8, 3);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_01, extraout_CL_01, iVar8, 3, iVar8, 2);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_02, extraout_CL_02, iVar8, 2, iVar8, 1);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_03, extraout_CL_03, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX;
                    puVar5 = extraout_EDX;
                }
                if ((&DAT_00421f7c)[iVar8 * 0x2a] == 0)
                {
                    uVar2 = Move_Bubble(cVar1 * '\x15', (char)puVar5, (char)puVar3, iVar8, 5, iVar8, 4);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_04, extraout_CL_04, iVar8, 4, iVar8, 3);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_05, extraout_CL_05, iVar8, 3, iVar8, 2);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_06, extraout_CL_06, iVar8, 2, iVar8, 1);
                    Move_Bubble(uVar2, extraout_DL_07, extraout_CL_07, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX_00;
                    puVar5 = extraout_EDX_00;
                }
                if ((&DAT_00421f64)[iVar8 * 0x2a] == 0)
                {
                    uVar2 = Move_Bubble(cVar1 * '\x15', (char)puVar5, (char)puVar3, iVar8, 4, iVar8, 3);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_08, extraout_CL_08, iVar8, 3, iVar8, 2);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_09, extraout_CL_09, iVar8, 2, iVar8, 1);
                    Move_Bubble(uVar2, extraout_DL_10, extraout_CL_10, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX_01;
                    puVar5 = extraout_EDX_01;
                }
                if ((&DAT_00421f4c)[iVar8 * 0x2a] == 0)
                {
                    uVar2 = Move_Bubble(cVar1 * '\x15', (char)puVar5, (char)puVar3, iVar8, 3, iVar8, 2);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_11, extraout_CL_11, iVar8, 2, iVar8, 1);
                    Move_Bubble(uVar2, extraout_DL_12, extraout_CL_12, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX_02;
                    puVar5 = extraout_EDX_02;
                }
                if ((&DAT_00421f34)[iVar8 * 0x2a] == 0)
                {
                    uVar2 = Move_Bubble(cVar1 * '\x15', (char)puVar5, (char)puVar3, iVar8, 2, iVar8, 1);
                    Move_Bubble(uVar2, extraout_DL_13, extraout_CL_13, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX_03;
                    puVar5 = extraout_EDX_03;
                }
                iVar6 = iVar8 * 0x15;
                if ((&DAT_00421f1c)[iVar8 * 0x2a] == 0)
                {
                    iVar6 = Move_Bubble((char)iVar6, (char)puVar5, (char)puVar3, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX_04;
                    puVar5 = extraout_EDX_04;
                }
                local_8 = local_8 + 1;
            } while (local_8 < 7);
            iVar8 = iVar8 + -1;
        } while (-1 < iVar8);
        local_8 = 9;
        do
        {
            puVar7 = (char *)0x9;
            do
            {
                uVar2 = SUB41(puVar3, 0);
                puVar3 = puVar7;
                iVar6 = Check_Free_Row((char)iVar6, (char)puVar5, uVar2, puVar7);
                puVar5 = extraout_EDX_05;
                if (iVar6 != 0)
                {
                    Move_Bubble((char)((int)puVar7 + -1), (char)extraout_EDX_05, (char)puVar3, puVar7, 0,
                                (int)puVar7 + -1, 0);
                    Move_Bubble((char)((int)puVar7 + -1), extraout_DL_14, extraout_CL_14, puVar7, 1,
                                (int)puVar7 + -1, 1);
                    Move_Bubble((char)((int)puVar7 + -1), extraout_DL_15, extraout_CL_15, puVar7, 2,
                                (int)puVar7 + -1, 2);
                    Move_Bubble((char)((int)puVar7 + -1), extraout_DL_16, extraout_CL_16, puVar7, 3,
                                (int)puVar7 + -1, 3);
                    Move_Bubble((char)((int)puVar7 + -1), extraout_DL_17, extraout_CL_17, puVar7, 4,
                                (int)puVar7 + -1, 4);
                    Move_Bubble((char)((int)puVar7 + -1), extraout_DL_18, extraout_CL_18, puVar7, 5,
                                (int)puVar7 + -1, 5);
                    iVar6 = Move_Bubble((char)((int)puVar7 + -1), extraout_DL_19, extraout_CL_19, puVar7, 6,
                                        (int)puVar7 + -1, 6);
                    puVar3 = extraout_ECX_05;
                    puVar5 = extraout_EDX_06;
                }
                puVar7 = (char *)((int)puVar7 + -1);
            } while (0 < (int)puVar7);
            local_8 = local_8 + -1;
        } while (0 < local_8);
        uVar2 = SUB41(puVar3, 0);
        puVar3 = (char *)0x0;
        iVar8 = Check_Free_Row((char)iVar6, (char)puVar5, uVar2, 0);
        puVar5 = extraout_EDX_07;
        if (iVar8 != 0)
        {
            Create_Game_Screen = 0;
            DAT_00421f1c = 0;
            DAT_00421f34 = 0;
            DAT_00421f4c = 0;
            DAT_00421f64 = 0;
            DAT_00421f7c = 0;
            DAT_00421f94 = 0;
        }
    }
    if (game_type_0 == 1)
    {
        iVar8 = 9;
        do
        {
            local_8 = 0;
            do
            {
                cVar1 = (char)iVar8;
                if ((&DAT_00421f94)[iVar8 * 0x2a] == 0)
                {
                    uVar2 = Move_Bubble(cVar1 * '\x15', (char)puVar5, (char)puVar3, iVar8, 6, iVar8, 5);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_20, extraout_CL_20, iVar8, 5, iVar8, 4);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_21, extraout_CL_21, iVar8, 4, iVar8, 3);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_22, extraout_CL_22, iVar8, 3, iVar8, 2);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_23, extraout_CL_23, iVar8, 2, iVar8, 1);
                    Move_Bubble(uVar2, extraout_DL_24, extraout_CL_24, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX_06;
                    puVar5 = extraout_EDX_08;
                }
                if ((&DAT_00421f7c)[iVar8 * 0x2a] == 0)
                {
                    uVar2 = Move_Bubble(cVar1 * '\x15', (char)puVar5, (char)puVar3, iVar8, 5, iVar8, 4);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_25, extraout_CL_25, iVar8, 4, iVar8, 3);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_26, extraout_CL_26, iVar8, 3, iVar8, 2);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_27, extraout_CL_27, iVar8, 2, iVar8, 1);
                    Move_Bubble(uVar2, extraout_DL_28, extraout_CL_28, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX_07;
                    puVar5 = extraout_EDX_09;
                }
                if ((&DAT_00421f64)[iVar8 * 0x2a] == 0)
                {
                    uVar2 = Move_Bubble(cVar1 * '\x15', (char)puVar5, (char)puVar3, iVar8, 4, iVar8, 3);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_29, extraout_CL_29, iVar8, 3, iVar8, 2);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_30, extraout_CL_30, iVar8, 2, iVar8, 1);
                    Move_Bubble(uVar2, extraout_DL_31, extraout_CL_31, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX_08;
                    puVar5 = extraout_EDX_10;
                }
                if ((&DAT_00421f4c)[iVar8 * 0x2a] == 0)
                {
                    uVar2 = Move_Bubble(cVar1 * '\x15', (char)puVar5, (char)puVar3, iVar8, 3, iVar8, 2);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_32, extraout_CL_32, iVar8, 2, iVar8, 1);
                    Move_Bubble(uVar2, extraout_DL_33, extraout_CL_33, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX_09;
                    puVar5 = extraout_EDX_11;
                }
                if ((&DAT_00421f34)[iVar8 * 0x2a] == 0)
                {
                    uVar2 = Move_Bubble(cVar1 * '\x15', (char)puVar5, (char)puVar3, iVar8, 2, iVar8, 1);
                    Move_Bubble(uVar2, extraout_DL_34, extraout_CL_34, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX_10;
                    puVar5 = extraout_EDX_12;
                }
                iVar6 = iVar8 * 0x15;
                if ((&DAT_00421f1c)[iVar8 * 0x2a] == 0)
                {
                    iVar6 = Move_Bubble((char)iVar6, (char)puVar5, (char)puVar3, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX_11;
                    puVar5 = extraout_EDX_13;
                }
                local_8 = local_8 + 1;
            } while (local_8 < 7);
            iVar8 = iVar8 + -1;
        } while (-1 < iVar8);
        local_8 = 9;
        do
        {
            puVar7 = (char *)0x9;
            do
            {
                uVar2 = SUB41(puVar3, 0);
                puVar3 = puVar7;
                iVar6 = 00411f46((char)iVar6, (char)puVar5, uVar2, puVar7);
                puVar5 = extraout_EDX_14;
                if (iVar6 != 0)
                {
                    Move_Bubble((char)((int)puVar7 + -1), (char)extraout_EDX_14, (char)puVar3, puVar7, 0,
                                (int)puVar7 + -1, 0);
                    Move_Bubble((char)((int)puVar7 + -1), extraout_DL_35, extraout_CL_35, puVar7, 1,
                                (int)puVar7 + -1, 1);
                    Move_Bubble((char)((int)puVar7 + -1), extraout_DL_36, extraout_CL_36, puVar7, 2,
                                (int)puVar7 + -1, 2);
                    Move_Bubble((char)((int)puVar7 + -1), extraout_DL_37, extraout_CL_37, puVar7, 3,
                                (int)puVar7 + -1, 3);
                    Move_Bubble((char)((int)puVar7 + -1), extraout_DL_38, extraout_CL_38, puVar7, 4,
                                (int)puVar7 + -1, 4);
                    Move_Bubble((char)((int)puVar7 + -1), extraout_DL_39, extraout_CL_39, puVar7, 5,
                                (int)puVar7 + -1, 5);
                    iVar6 = Move_Bubble((char)((int)puVar7 + -1), extraout_DL_40, extraout_CL_40, puVar7, 6,
                                        (int)puVar7 + -1, 6);
                    puVar3 = extraout_ECX_12;
                    puVar5 = extraout_EDX_15;
                }
                puVar7 = (char *)((int)puVar7 + -1);
            } while (0 < (int)puVar7);
            local_8 = local_8 + -1;
        } while (0 < local_8);
        puVar7 = (char *)0x9;
        do
        {
            uVar2 = SUB41(puVar3, 0);
            puVar3 = puVar7;
            iVar8 = 00411f46((char)iVar6, (char)puVar5, uVar2, puVar7);
            if (iVar8 != 0)
            {
                uVar2 = SUB41(puVar3, 0);
                puVar3 = puVar7;
                00411fd1((char)iVar8, (char)extraout_EDX_16, uVar2, puVar7);
                puVar5 = extraout_EDX_17;
                break;
            }
            puVar7 = (char *)((int)puVar7 + -1);
            iVar6 = 0;
            puVar5 = extraout_EDX_16;
        } while (-1 < (int)puVar7);
    }
    if (game_type_0 == 2)
    {
        iVar8 = 9;
        do
        {
            local_8 = 0;
            do
            {
                cVar1 = (char)iVar8;
                if ((&DAT_00421f94)[iVar8 * 0x2a] == 0)
                {
                    uVar2 = Move_Bubble(cVar1 * '\x15', (char)puVar5, (char)puVar3, iVar8, 6, iVar8, 5);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_41, extraout_CL_41, iVar8, 5, iVar8, 4);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_42, extraout_CL_42, iVar8, 4, iVar8, 3);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_43, extraout_CL_43, iVar8, 3, iVar8, 2);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_44, extraout_CL_44, iVar8, 2, iVar8, 1);
                    Move_Bubble(uVar2, extraout_DL_45, extraout_CL_45, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX_13;
                    puVar5 = extraout_EDX_18;
                }
                if ((&DAT_00421f7c)[iVar8 * 0x2a] == 0)
                {
                    uVar2 = Move_Bubble(cVar1 * '\x15', (char)puVar5, (char)puVar3, iVar8, 5, iVar8, 4);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_46, extraout_CL_46, iVar8, 4, iVar8, 3);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_47, extraout_CL_47, iVar8, 3, iVar8, 2);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_48, extraout_CL_48, iVar8, 2, iVar8, 1);
                    Move_Bubble(uVar2, extraout_DL_49, extraout_CL_49, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX_14;
                    puVar5 = extraout_EDX_19;
                }
                if ((&DAT_00421f64)[iVar8 * 0x2a] == 0)
                {
                    uVar2 = Move_Bubble(cVar1 * '\x15', (char)puVar5, (char)puVar3, iVar8, 4, iVar8, 3);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_50, extraout_CL_50, iVar8, 3, iVar8, 2);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_51, extraout_CL_51, iVar8, 2, iVar8, 1);
                    Move_Bubble(uVar2, extraout_DL_52, extraout_CL_52, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX_15;
                    puVar5 = extraout_EDX_20;
                }
                if ((&DAT_00421f4c)[iVar8 * 0x2a] == 0)
                {
                    uVar2 = Move_Bubble(cVar1 * '\x15', (char)puVar5, (char)puVar3, iVar8, 3, iVar8, 2);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_53, extraout_CL_53, iVar8, 2, iVar8, 1);
                    Move_Bubble(uVar2, extraout_DL_54, extraout_CL_54, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX_16;
                    puVar5 = extraout_EDX_21;
                }
                if ((&DAT_00421f34)[iVar8 * 0x2a] == 0)
                {
                    uVar2 = Move_Bubble(cVar1 * '\x15', (char)puVar5, (char)puVar3, iVar8, 2, iVar8, 1);
                    Move_Bubble(uVar2, extraout_DL_55, extraout_CL_55, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX_17;
                    puVar5 = extraout_EDX_22;
                }
                iVar6 = iVar8 * 0x15;
                if ((&DAT_00421f1c)[iVar8 * 0x2a] == 0)
                {
                    iVar6 = Move_Bubble((char)iVar6, (char)puVar5, (char)puVar3, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX_18;
                    puVar5 = extraout_EDX_23;
                }
                local_8 = local_8 + 1;
            } while (local_8 < 7);
            iVar8 = iVar8 + -1;
        } while (-1 < iVar8);
        local_8 = 9;
        do
        {
            puVar7 = (char *)0x9;
            do
            {
                uVar2 = SUB41(puVar3, 0);
                puVar3 = puVar7;
                iVar6 = 00411f46((char)iVar6, (char)puVar5, uVar2, puVar7);
                puVar5 = extraout_EDX_24;
                if (iVar6 != 0)
                {
                    Move_Bubble((char)((int)puVar7 + -1), (char)extraout_EDX_24, (char)puVar3, puVar7, 0,
                                (int)puVar7 + -1, 0);
                    Move_Bubble((char)((int)puVar7 + -1), extraout_DL_56, extraout_CL_56, puVar7, 1,
                                (int)puVar7 + -1, 1);
                    Move_Bubble((char)((int)puVar7 + -1), extraout_DL_57, extraout_CL_57, puVar7, 2,
                                (int)puVar7 + -1, 2);
                    Move_Bubble((char)((int)puVar7 + -1), extraout_DL_58, extraout_CL_58, puVar7, 3,
                                (int)puVar7 + -1, 3);
                    Move_Bubble((char)((int)puVar7 + -1), extraout_DL_59, extraout_CL_59, puVar7, 4,
                                (int)puVar7 + -1, 4);
                    Move_Bubble((char)((int)puVar7 + -1), extraout_DL_60, extraout_CL_60, puVar7, 5,
                                (int)puVar7 + -1, 5);
                    iVar6 = Move_Bubble((char)((int)puVar7 + -1), extraout_DL_61, extraout_CL_61, puVar7, 6,
                                        (int)puVar7 + -1, 6);
                    puVar3 = extraout_ECX_19;
                    puVar5 = extraout_EDX_25;
                }
                puVar7 = (char *)((int)puVar7 + -1);
            } while (0 < (int)puVar7);
            local_8 = local_8 + -1;
        } while (0 < local_8);
        uVar2 = SUB41(puVar3, 0);
        puVar3 = (char *)0x0;
        iVar8 = 00411f46((char)iVar6, (char)puVar5, uVar2, 0);
        if (iVar8 != 0)
        {
            Create_Game_Screen = 0;
            DAT_00421f1c = 0;
            DAT_00421f34 = 0;
            DAT_00421f4c = 0;
            DAT_00421f64 = 0;
            DAT_00421f7c = 0;
            DAT_00421f94 = 0;
        }
        local_8 = 0;
        do
        {
            iVar8 = 0;
            do
            {
                iVar6 = 0;
                do
                {
                    puVar5 = &DAT_00421fac + iVar8 * 0x2a;
                    if (puVar5[iVar6 * 6] == 0)
                    {
                        Move_Bubble((char)(iVar8 + 1), (char)puVar5, (char)puVar3, iVar8 + 1, iVar6, iVar8, iVar6);
                        puVar3 = extraout_ECX_20;
                        puVar5 = extraout_EDX_26;
                    }
                    iVar6 = iVar6 + 1;
                } while (iVar6 < 7);
                iVar8 = iVar8 + 1;
            } while (iVar8 < 9);
            local_8 = local_8 + 1;
        } while (local_8 < 10);
    }
    if (game_type_0 == 3)
    {
        iVar8 = 9;
        do
        {
            local_8 = 0;
            do
            {
                cVar1 = (char)iVar8;
                if ((&DAT_00421f94)[iVar8 * 0x2a] == 0)
                {
                    uVar2 = Move_Bubble(cVar1 * '\x15', (char)puVar5, (char)puVar3, iVar8, 6, iVar8, 5);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_62, extraout_CL_62, iVar8, 5, iVar8, 4);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_63, extraout_CL_63, iVar8, 4, iVar8, 3);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_64, extraout_CL_64, iVar8, 3, iVar8, 2);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_65, extraout_CL_65, iVar8, 2, iVar8, 1);
                    Move_Bubble(uVar2, extraout_DL_66, extraout_CL_66, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX_21;
                    puVar5 = extraout_EDX_27;
                }
                if ((&DAT_00421f7c)[iVar8 * 0x2a] == 0)
                {
                    uVar2 = Move_Bubble(cVar1 * '\x15', (char)puVar5, (char)puVar3, iVar8, 5, iVar8, 4);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_67, extraout_CL_67, iVar8, 4, iVar8, 3);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_68, extraout_CL_68, iVar8, 3, iVar8, 2);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_69, extraout_CL_69, iVar8, 2, iVar8, 1);
                    Move_Bubble(uVar2, extraout_DL_70, extraout_CL_70, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX_22;
                    puVar5 = extraout_EDX_28;
                }
                if ((&DAT_00421f64)[iVar8 * 0x2a] == 0)
                {
                    uVar2 = Move_Bubble(cVar1 * '\x15', (char)puVar5, (char)puVar3, iVar8, 4, iVar8, 3);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_71, extraout_CL_71, iVar8, 3, iVar8, 2);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_72, extraout_CL_72, iVar8, 2, iVar8, 1);
                    Move_Bubble(uVar2, extraout_DL_73, extraout_CL_73, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX_23;
                    puVar5 = extraout_EDX_29;
                }
                if ((&DAT_00421f4c)[iVar8 * 0x2a] == 0)
                {
                    uVar2 = Move_Bubble(cVar1 * '\x15', (char)puVar5, (char)puVar3, iVar8, 3, iVar8, 2);
                    uVar2 = Move_Bubble(uVar2, extraout_DL_74, extraout_CL_74, iVar8, 2, iVar8, 1);
                    Move_Bubble(uVar2, extraout_DL_75, extraout_CL_75, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX_24;
                    puVar5 = extraout_EDX_30;
                }
                if ((&DAT_00421f34)[iVar8 * 0x2a] == 0)
                {
                    uVar2 = Move_Bubble(cVar1 * '\x15', (char)puVar5, (char)puVar3, iVar8, 2, iVar8, 1);
                    Move_Bubble(uVar2, extraout_DL_76, extraout_CL_76, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX_25;
                    puVar5 = extraout_EDX_31;
                }
                iVar6 = iVar8 * 0x15;
                if ((&DAT_00421f1c)[iVar8 * 0x2a] == 0)
                {
                    iVar6 = Move_Bubble((char)iVar6, (char)puVar5, (char)puVar3, iVar8, 1, iVar8, 0);
                    puVar3 = extraout_ECX_26;
                    puVar5 = extraout_EDX_32;
                }
                local_8 = local_8 + 1;
            } while (local_8 < 7);
            iVar8 = iVar8 + -1;
        } while (-1 < iVar8);
        local_8 = 9;
        do
        {
            puVar7 = (char *)0x9;
            do
            {
                uVar2 = SUB41(puVar3, 0);
                puVar3 = puVar7;
                iVar6 = Check_Free_Row((char)iVar6, (char)puVar5, uVar2, puVar7);
                puVar5 = extraout_EDX_33;
                if (iVar6 != 0)
                {
                    Move_Bubble((char)((int)puVar7 + -1), (char)extraout_EDX_33, (char)puVar3, puVar7, 0,
                                (int)puVar7 + -1, 0);
                    Move_Bubble((char)((int)puVar7 + -1), extraout_DL_77, extraout_CL_77, puVar7, 1,
                                (int)puVar7 + -1, 1);
                    Move_Bubble((char)((int)puVar7 + -1), extraout_DL_78, extraout_CL_78, puVar7, 2,
                                (int)puVar7 + -1, 2);
                    Move_Bubble((char)((int)puVar7 + -1), extraout_DL_79, extraout_CL_79, puVar7, 3,
                                (int)puVar7 + -1, 3);
                    Move_Bubble((char)((int)puVar7 + -1), extraout_DL_80, extraout_CL_80, puVar7, 4,
                                (int)puVar7 + -1, 4);
                    Move_Bubble((char)((int)puVar7 + -1), extraout_DL_81, extraout_CL_81, puVar7, 5,
                                (int)puVar7 + -1, 5);
                    iVar6 = Move_Bubble((char)((int)puVar7 + -1), extraout_DL_82, extraout_CL_82, puVar7, 6,
                                        (int)puVar7 + -1, 6);
                    puVar3 = extraout_ECX_27;
                    puVar5 = extraout_EDX_34;
                }
                puVar7 = (char *)((int)puVar7 + -1);
            } while (0 < (int)puVar7);
            local_8 = local_8 + -1;
        } while (0 < local_8);
        puVar7 = (char *)0x9;
        do
        {
            uVar2 = SUB41(puVar3, 0);
            puVar3 = puVar7;
            iVar8 = Check_Free_Row((char)iVar6, (char)puVar5, uVar2, puVar7);
            if (iVar8 != 0)
            {
                uVar2 = SUB41(puVar3, 0);
                puVar3 = puVar7;
                Fill_Rows((char)iVar8, (char)extraout_EDX_35, uVar2, puVar7);
                break;
            }
            puVar7 = (char *)((int)puVar7 + -1);
            iVar6 = 0;
            puVar5 = extraout_EDX_35;
        } while (-1 < (int)puVar7);
        local_8 = 0;
        do
        {
            iVar8 = 0;
            do
            {
                iVar6 = 0;
                do
                {
                    if ((&DAT_00421fac + iVar8 * 0x2a)[iVar6 * 6] == 0)
                    {
                        Move_Bubble((char)(iVar8 + 1), (char)(&DAT_00421fac + iVar8 * 0x2a), (char)puVar3,
                                    iVar8 + 1, iVar6, iVar8, iVar6);
                        puVar3 = extraout_ECX_28;
                    }
                    iVar6 = iVar6 + 1;
                } while (iVar6 < 7);
                iVar8 = iVar8 + 1;
            } while (iVar8 < 9);
            local_8 = local_8 + 1;
        } while (local_8 < 10);
    }
    bubbles_marked = 0;
    number_bubbles_marked_0 = 0;
    game_score_0 = game_score_0 + bubble_points_0;
    undo_score_0 = bubble_points_0;
    bubble_points_0 = 0;
    game_busy_0 = (uint)(Check_Button_Up != 0);
    uVar2 = Create_Game_Screen();
    if (change_mode + 150 != 0)
    {
        void mci_PlayWave(uVar2, extraout_DL_83, extraout_CL_83, &DAT_0042088b);
    }
    iVar8 = Check_Game_Over();
    if (iVar8 != 0)
    {
        iVar8 = 0;
        highscore_0 = 0;
        uVar2 = extraout_CL_84;
        uVar4 = extraout_DL_84;
        if (game_type_0 == 0)
        {
            iVar8 = Count_Bubbles();
            if (iVar8 == 4)
            {
                Create_Game_Score + 7B = 0x19;
            }
            iVar8 = Count_Bubbles();
            if (iVar8 == 3)
            {
                Create_Game_Score + 7B = 0x32;
            }
            iVar8 = Count_Bubbles();
            if (iVar8 == 2)
            {
                Create_Game_Score + 7B = 100;
            }
            iVar8 = Count_Bubbles();
            if (iVar8 == 1)
            {
                Create_Game_Score + 7B = 200;
            }
            iVar8 = Count_Bubbles();
            if (iVar8 == 0)
            {
                Create_Game_Score + 7B = 500;
            }
            _Str_00421eb0 = (void *)((int)_Str_00421eb0 + 1);
            Update_Bubble = Update_Bubble + game_score_0 + Create_Game_Score + 7B;
            iVar8 = game_score_0 + Create_Game_Score + 7B;
            uVar2 = extraout_CL_85;
            uVar4 = extraout_DL_85;
            if (Update_Bubble < iVar8)
            {
                iVar8 = game_score_0 + Create_Game_Score + 7B;
                highscore_0 = 1;
                Update_Bubble = iVar8;
            }
        }
        if (game_type_0 == 1)
        {
            DAT_00421ebc = DAT_00421ebc + 1;
            DAT_00421ec0 = DAT_00421ec0 + game_score_0 + Create_Game_Score + 7B;
            iVar8 = game_score_0 + Create_Game_Score + 7B;
            if (DAT_00421ec4 < iVar8)
            {
                iVar8 = game_score_0 + Create_Game_Score + 7B;
                highscore_0 = 1;
                DAT_00421ec4 = iVar8;
            }
        }
        if (game_type_0 == 2)
        {
            iVar8 = Count_Bubbles();
            if (iVar8 == 4)
            {
                Create_Game_Score + 7B = 0x19;
            }
            iVar8 = Count_Bubbles();
            if (iVar8 == 3)
            {
                Create_Game_Score + 7B = 0x32;
            }
            iVar8 = Count_Bubbles();
            if (iVar8 == 2)
            {
                Create_Game_Score + 7B = 100;
            }
            iVar8 = Count_Bubbles();
            if (iVar8 == 1)
            {
                Create_Game_Score + 7B = 200;
            }
            iVar8 = Count_Bubbles();
            if (iVar8 == 0)
            {
                Create_Game_Score + 7B = 500;
            }
            DAT_00421ec8 = DAT_00421ec8 + 1;
            DAT_00421ecc = DAT_00421ecc + game_score_0 + Create_Game_Score + 7B;
            iVar8 = game_score_0 + Create_Game_Score + 7B;
            uVar2 = extraout_CL_86;
            uVar4 = extraout_DL_86;
            if (Update_Bubble < iVar8)
            {
                iVar8 = game_score_0 + Create_Game_Score + 7B;
                Create_Game_Score = 1;
                Update_Bubble = iVar8;
            }
        }
        if (game_type_0 == 3)
        {
            Update_Bubble = Update_Bubble + 1;
            DAT_00421ed8 = DAT_00421ed8 + game_score_0 + Create_Game_Score + 7B;
            iVar8 = game_score_0 + Create_Game_Score + 7B;
            if (Update_Bubble + D30 < iVar8)
            {
                iVar8 = game_score_0 + Create_Game_Score + 7B;
                highscore_0 = 1;
                Update_Bubble + D30 = iVar8;
            }
        }
        _DAT_00420138 = 1;
        if (game_busy_0 == 0)
        {
            Update_Bubble((char)iVar8, uVar4, uVar2, 9);
        }
        else
        {
            waitanim_0 = 1;
        }
    }
    return;
}
void  Check_Free_Row(int param_1, int param_2, int param_3, int param_4)

{
    if (((((((DAT_00421f04)[param_4 * 0x2a] == 0 && (DAT_00421f1c)[param_4 * 0x2a] == 0) &&
            (DAT_00421f34)[param_4 * 0x2a] == 0) &&
           (DAT_00421f4c)[param_4 * 0x2a] == 0) &&
          (DAT_00421f64)[param_4 * 0x2a] == 0) &&
         (DAT_00421f7c)[param_4 * 0x2a] == 0) &&
        (DAT_00421f94)[param_4 * 0x2a] == 0)
    {
        return;
    }
    return;
}
int Count_Bubbles(void)

{
    int iVar1;
    int iVar2;
    int iVar3;

    iVar2 = 0;
    iVar3 = 0;
    do
    {
        iVar1 = 0;
        do
        {
            if ((&DAT_00421f04)[iVar1 * 0x2a + iVar3 * 6] != 0)
            {
                iVar2 = iVar2 + 1;
            }
            iVar1 = iVar1 + 1;
        } while (iVar1 < 10);
        iVar3 = iVar3 + 1;
    } while (iVar3 < 7);
    return iVar2;
}
void Check_Game_Over(void)

{
    int iVar1;
    int in_CL;
    int extraout_CL;
    int iVar2;
    int iVar3;

    iVar3 = 0;
    do
    {
        iVar2 = 0;
        do
        {
            iVar1 = Check_Bubble((char)iVar3 * '\x03', (char)(PlayField_0 + iVar2 * 0x2a), in_CL, iVar2,
                                 iVar3, (PlayField_0 + iVar2 * 0x2a)[iVar3 * 6]);
            if (1 < iVar1)
            {
                return;
            }
            iVar2 = iVar2 + 1;
            in_CL = extraout_CL;
        } while (iVar2 < 10);
        iVar3 = iVar3 + 1;
    } while (iVar3 < 7);
    return;
}
void Create_Scores(void)

{
    int in_AL;
    int uVar1;
    int uVar2;
    int in_CL;
    HDC extraout_CL;
    HDC extraout_CL_00;
    int param2;
    int param2_00;
    int param2_01;
    int param2_02;
    int param2_03;
    int param2_04;
    int param2_05;
    int param2_06;
    int param2_07;
    int param2_08;
    int param2_09;
    int param2_10;
    HDC extraout_ECX;
    HDC extraout_ECX_00;
    HDC extraout_ECX_01;
    HDC extraout_ECX_02;
    HDC extraout_ECX_03;
    HDC extraout_ECX_04;
    HDC extraout_ECX_05;
    HDC extraout_ECX_06;
    HDC extraout_ECX_07;
    HDC extraout_ECX_08;
    HDC extraout_ECX_09;
    HDC extraout_ECX_10;
    HDC extraout_ECX_11;
    char in_DL;
    HDC extraout_DL;
    HDC extraout_DL_00;
    char *extraout_EDX;
    char *pcVar3;
    char *param1;
    char *param1_00;
    char *extraout_EDX_00;
    char *param1_01;
    char *param1_02;
    char *extraout_EDX_01;
    char *param1_03;
    char *param1_04;
    char *extraout_EDX_02;
    char *param1_05;
    char *param1_06;
    HDC extraout_EDX_03;
    HDC extraout_EDX_04;
    HDC extraout_EDX_05;
    HDC extraout_EDX_06;
    HDC extraout_EDX_07;
    HDC extraout_EDX_08;
    HDC extraout_EDX_09;
    HDC extraout_EDX_10;
    HDC extraout_EDX_11;
    HDC extraout_EDX_12;
    HDC extraout_EDX_13;
    HDC extraout_EDX_14;
    HDC extraout_EDX_15;
    char local_3c4[80];
    char local_374[80];
    char local_324[80];
    char local_2d4[80];
    char local_284[80];
    char local_234[80];
    char local_1e4[80];
    char local_194[80];
    char local_144[80];
    char local_f4[80];
    char local_a4[80];
    char local_54[80];

    uVar1 = int PutSurface(in_AL, in_DL, in_CL, 0, 0, bk_pic_0, WinMain);
    uVar1 = PutSurfaceCC(uVar1, extraout_DL, extraout_CL, 8, 6, Create_Scores, WinMain);
    PutSurfaceCC(uVar1, extraout_DL_00, extraout_CL_00, 0x4b, 0x28, score_table_pic_0, WinMain);
    pcVar3 = extraout_EDX;
    if (0 < (int)_Str_score_statistic_0)
    {
        pcVar3 = (char *)(Update_Bubbles % (int)_Str_score_statistic_0);
    }
    _sprintf(local_54, pcVar3, param2);
    info1_0 = local_54;
    _sprintf(local_a4, param1, param2_00);
    info2_0 = local_a4;
    _sprintf(local_f4, param1_00, param2_01);
    info3_0 = local_f4;
    pcVar3 = extraout_EDX_00;
    if (0 < Update_Bubbles)
    {
        pcVar3 = (char *)(Update_Bubble % Update_Bubbles);
    }
    _sprintf(local_144, pcVar3, param2_02);
    info4_0 = local_144;
    _sprintf(local_194, param1_01, param2_03);
    info5_0 = local_194;
    _sprintf(local_1e4, param1_02, param2_04);
    info6_0 = local_1e4;
    pcVar3 = extraout_EDX_01;
    if (0 < Execute_Button + C6)
    {
        pcVar3 = (char *)(DAT_00421ecc % Execute_Button + C6);
    }
    _sprintf(local_234, pcVar3, param2_05);
    info7_0 = local_234;
    _sprintf(local_284, param1_03, param2_06);
    info8_0 = local_284;
    _sprintf(local_2d4, param1_04, param2_07);
    info9_0 = local_2d4;
    pcVar3 = extraout_EDX_02;
    if (0 < Update_Bubbles + D0E)
    {
        pcVar3 = (char *)(Update_Bubbles + D1F % Update_Bubbles + D0E);
    }
    _sprintf(local_324, pcVar3, param2_08);
    info10_0 = local_324;
    _sprintf(local_374, param1_05, param2_09);
    info11_0 = local_374;
    _sprintf(local_3c4, param1_06, param2_10);
    info12_0 = local_3c4;
    uVar2 = ShowTextCenter(info12_0, extraout_EDX_03, extraout_ECX, WinMain, 0xf0, 0x87, info1_0, 0);
    uVar2 = ShowTextCenter(uVar2, extraout_EDX_04, extraout_ECX_00, WinMain, 0x13b, 0x87, info2_0, 0);
    uVar2 = ShowTextCenter(uVar2, extraout_EDX_05, extraout_ECX_01, WinMain, 0x181, 0x87, info3_0, 0);
    uVar2 = ShowTextCenter(uVar2, extraout_EDX_06, extraout_ECX_02, WinMain, 0xf0, 0xa7, info4_0, 0);
    uVar2 = ShowTextCenter(uVar2, extraout_EDX_07, extraout_ECX_03, WinMain, 0x13b, 0xa7, info5_0, 0);
    uVar2 = ShowTextCenter(uVar2, extraout_EDX_08, extraout_ECX_04, WinMain, 0x181, 0xa7, info6_0, 0);
    uVar2 = ShowTextCenter(uVar2, extraout_EDX_09, extraout_ECX_05, WinMain, 0xf0, 0xc5, info7_0, 0);
    uVar2 = ShowTextCenter(uVar2, extraout_EDX_10, extraout_ECX_06, WinMain, 0x13b, 0xc5, info8_0, 0);
    uVar2 = ShowTextCenter(uVar2, extraout_EDX_11, extraout_ECX_07, WinMain, 0x181, 0xc5, info9_0, 0);
    uVar2 = ShowTextCenter(uVar2, extraout_EDX_12, extraout_ECX_08, WinMain, 0xf0, 0xe5, info10_0, 0);
    uVar2 = ShowTextCenter(uVar2, extraout_EDX_13, extraout_ECX_09, WinMain, 0x13b, 0xe5, info11_0, 0);
    uVar2 = ShowTextCenter(uVar2, extraout_EDX_14, extraout_ECX_10, WinMain, 0x181, 0xe5, info12_0, 0);
    Status_Text_0 = s_Click__Reset__to_clear_the_damn_t_004201a2;
    ShowText(uVar2, extraout_EDX_15, extraout_ECX_11, WinMain, 10, 0x160,
             s_Click__Reset__to_clear_the_damn_t_004201a2, 0xffffff);
    Draw_Buttons();
    Update_Screen();
    return;
}
void  Game_Message(int param_1, int param_2, int param_3, int param_4,int param_5, uint param_6)

{
    int uVar1;

    uVar1 = (uint)param_6;
    if (param_4 < 0x202)
    {
        if (param_4 == 0x201)
        {
            Check_Button_Down(uVar1, param_2, param_3, param_6 & 0xffff, param_6 >> 0x10);
            return;
        }
        if (param_4 != 1)
        {
            if (param_4 == 0xf)
            {
                if (DAT_004200a8 != 0)
                {
                    Update_Screen();
                    return;
                }
            }
            else
            {
                if (param_4 != 0x10)
                {
                    if (param_4 != 0x200)
                    {
                        return;
                    }
                    Check_Button_Move(uVar1, param_2, param_3, param_6 & 0xffff, param_6 >> 0x10, param_5);
                    return;
                }
                Game_Shutdown();
            }
        }
        return;
    }
    if (param_4 == 0x202)
    {
        Check_Button_Up(uVar1, param_2, param_3, param_6 & 0xffff, param_6 >> 0x10);
        return;
    }
    if (param_4 != 999)
    {
        if (param_4 != 9999)
        {
            return;
        }
        Game_Reload();
        return;
    }
    change_mode(0, param_2, param_3, 9);
    return;
}
void  Error_Message(int param_1, int param_2, int param_3, const uint16_t * param_4)

{
    MessageBoxA((HWND)0x0, param_4, s_ERROR_004200ac, 0);
    return;
}
void Game_Reload(void)

{
  return;
}
void Reset_Scores(void)

{
    int iVar1;

    iVar1 = MessageBoxA((HWND)0x0, s_Are_you_sure__0042088f, s_Reset_0042089d, 0x11001);
    if (iVar1 == 1)
    {
        _Str_00421eb0 = (void *)0x0;
        DAT_00421eb4 = 0;
        DAT_00421eb8 = 0;
        DAT_00421ebc = 0;
        DAT_00421ec0 = 0;
        DAT_00421ec4 = 0;
        DAT_00421ec8 = 0;
        DAT_00421ecc = 0;
        DAT_00421ed0 = 0;
        DAT_00421ed4 = 0;
        DAT_00421ed8 = 0;
        DAT_00421edc = 0;
    }
    Create_Screen();
    return;
}
void uint(void)

{
    int in_AL;
    int uVar1;
    const uint16_t * pCVar2;
    int uVar3;
    int uVar4;
    char *pcVar5;
    int in_CL;
    HDC extraout_CL;
    HDC extraout_CL_00;
    uint param2;
    uint param2_00
        uint param2_01
            HDC param2_02;
    uint param2_03;
    HDC extraout_ECX;
    uint param2_04
        HDC extraout_ECX_00;
    uint param2_05;
    HDC extraout_ECX_01;
    uint param2_06;
    HDC extraout_ECX_02;
    HDC extraout_ECX_03;
    HDC extraout_ECX_04;
    HDC extraout_ECX_05;
    HDC extraout_ECX_06;
    HDC pHVar6;
    HDC extraout_ECX_07;
    HDC extraout_ECX_08;
    char in_DL;
    HDC extraout_DL;
    HDC extraout_DL_00;
    char *param1;
    char *param1_00;
    char *param1_01;
    HDC extraout_EDX;
    char *param1_02;
    HDC extraout_EDX_00;
    char *param1_03;
    HDC extraout_EDX_01;
    char *param1_04;
    HDC extraout_EDX_02;
    char *param1_05;
    HDC extraout_EDX_03;
    HDC extraout_EDX_04;
    HDC extraout_EDX_05;
    HDC extraout_EDX_06;
    HDC extraout_EDX_07;
    HDC extraout_EDX_08;
    HDC extraout_EDX_09;
    char local_194[80];
    char local_144[80];
    char local_f4[80];
    char local_a4[80];
    char local_54[80];

    uVar1 = PutSurface(in_AL, in_DL, in_CL, 0, 0, bk_pic_0, v_screen);
    uVar1 = PutSurfaceCC(uVar1, extraout_DL, extraout_CL, 8, 6, paper_pic_0, v_screen);
    PutSurfaceCC(uVar1, extraout_DL_00, extraout_CL_00, 0x87, 0x28, game_score_table_pic_0, v_screen);
    _sprintf(local_54, param1, param2);
    info1_0 = local_54;
    _sprintf(local_a4, param1_00, param2_00);
    info2_0 = local_a4;
    _sprintf(local_f4, param1_01, param2_01);
    pCVar2 = local_f4;
    pHVar6 = param2_02;
    uVar3 = extraout_EDX;
    info3_0 = pCVar2;
    if (game_type_0 == 0)
    {
        _sprintf(local_144, (char *)(Update_Bubbles + BD3 % (int)_Str_00421eb0), (uint)param2_02);
        info4_0 = local_144;
        _sprintf(local_194, param1_02, param2_03);
        pCVar2 = local_194;
        pHVar6 = extraout_ECX;
        uVar3 = extraout_EDX_00;
        info5_0 = pCVar2;
    }
    if (game_type_0 == 1)
    {
        _sprintf(local_144, (char *)(Update_Bubbles + C20 % Update_Bubbles + C0F), (uint)pHVar6);
        info4_0 = local_144;
        _sprintf(local_194, param1_03, param2_04);
        pCVar2 = local_194;
        pHVar6 = extraout_ECX_00;
        uVar3 = extraout_EDX_01;
        info5_0 = pCVar2;
    }
    if (game_type_0 == 2)
    {
        _sprintf(local_144, (char *)(Update_Bubbles + CD2 % Update_Bubbles : loc_412E76 + CD2), (uint)pHVar6);
        info4_0 = local_144;
        _sprintf(local_194, param1_04, param2_05);
        pCVar2 = local_194;
        pHVar6 = extraout_ECX_01;
        uVar3 = extraout_EDX_02;
        info5_0 = pCVar2;
    }
    if (game_type_0 == 3)
    {
        _sprintf(local_144, (char *)(Update_Bubbles + D1F % DAT_00421ed4), (uint)pHVar6);
        info4_0 = local_144;
        _sprintf(local_194, param1_05, param2_06);
        pCVar2 = local_194;
        pHVar6 = extraout_ECX_02;
        uVar3 = extraout_EDX_03;
        info5_0 = pCVar2;
    }
    uVar3 = ShowTextCenter(pCVar2, uVar3, pHVar6, v_screen, 0x14f, 0x73, info1_0, 0);
    uVar3 = ShowTextCenter(uVar3, extraout_EDX_04, extraout_ECX_03, v_screen, 0x14f, 0x92, info2_0, 0);
    if (DAT_00420128 == 0)
    {
        uVar4 = ShowTextCenter(uVar3, extraout_EDX_05, extraout_ECX_04, v_screen, 0x14f, 0xb0, info3_0,
                             0);
        pHVar6 = extraout_ECX_06;
        uVar3 = extraout_EDX_07;
    }
    else
    {
        uVar4 = ShowTextCenter(uVar3, extraout_EDX_05, extraout_ECX_04, v_screen, 0x14f, 0xb0, info3_0,
                             0xff);
        pHVar6 = extraout_ECX_05;
        uVar3 = extraout_EDX_06;
    }
    uVar3 = ShowTextCenter(uVar4, uVar3, pHVar6, v_screen, 0x14f, 0xd0, info4_0, 0);
    ShowTextCenter(uVar3, extraout_EDX_08, extraout_ECX_07, v_screen, 0x14f, 0xee, info5_0, 0);
    if (DAT_00420128 == 0)
    {
        pcVar5 = s_Game_Over__00420207;
        Status_Text_0 = s_Game_Over__00420207;
    }
    else
    {
        pcVar5 = s_You_have_a_new_highscore___004201ec;
        Status_Text_0 = s_You_have_a_new_highscore___004201ec;
    }
    ShowText(pcVar5, extraout_EDX_09, extraout_ECX_08, v_screen, 10, 0x160, Status_Text_0, 0xffffff);
    Draw_Buttons();
    Update_Screen();
    return;
}
WPARAM __stdcall WinMain(int param_1, int param_2, int param_3, int param_4, int param_5, int param_6, int param_7)

{
    int iVar1;
    BOOL BVar2;
    HDC extraout_CL;
    HDC extraout_DL;
    MSG local_20;

    _hInst = param_4;
    iVar1 = DirectDrawInit(param_1, param_2, param_3, param_4, param_7);
    if (iVar1 == 0)
    {
        local_20.wParam = 0;
    }
    else
    {
        uTimerID_00421e5c = timeSetEvent(0x19, 0, fptc_004133ba, 0, 1);
        v_screen = int CreateOffScreenSurface((char)uTimerID_00421e5c, extraout_DL, extraout_CL, DAT_00421e3c, 0x1ee,
                                          0x1a4);
        Game_Init();
        while (BVar2 = GetMessageA(&local_20, (HWND)0x0, 0, 0), BVar2 != 0)
        {
            TranslateMessage(&local_20);
            DispatchMessageA(&local_20);
        }
    }
    return local_20.wParam;
}
void __stdcall WindowProc(int param_1, int param_2, int param_3, HWND param_4, UINT param_5, WPARAM param_6, LPARAM param_7)

{
    int iVar1;
    HDC extraout_CL;
    HDC extraout_CL_00;
    HDC extraout_CL_01;
    HDC extraout_DL;
    HDC extraout_DL_00;
    HDC extraout_DL_01;
    tagPOINT local_14[2];

    if (param_5 == 2)
    {
        iVar1 = void Shutdown();
        PostQuitMessage(0);
        param_3 = extraout_CL_01;
        param_2 = extraout_DL_01;
    }
    else if (param_5 == 3)
    {
        local_14[0].x = 0;
        local_14[0].y = 0;
        ClientToScreen(main_hWnd, local_14);
        Client_Pos = local_14[0].x;
        _Client_Pos = local_14[0].y;
        iVar1 = local_14[0].y;
        param_3 = extraout_CL;
        param_2 = extraout_DL;
        if (game_initialized != 0)
        {
            iVar1 = Update_Screen();
            param_3 = extraout_CL_00;
            param_2 = extraout_DL_00;
        }
    }
    else if (param_5 == 0x1c)
    {
        _bActive = param_6;
        iVar1 = 0;
    }
    else
    {
        iVar1 = param_5 - 9999;
    }
    Game_Message((char)iVar1, param_2, param_3, param_5, param_6, param_7);
    DefWindowProcA(param_4, param_5, param_6, param_7);
    return;
}
void Game_Shutdown(void)

{
    HDC extraout_DL;
    HDC extraout_DL_00;
    HDC extraout_DL_01;
    HDC extraout_DL_02;
    HDC extraout_DL_03;
    HDC extraout_DL_04;
    HDC extraout_DL_05;
    int uVar1;
    int uVar2;
    FILE *pFVar3;

    _File_00421e64 = _fopen(s_bubblet_cfg_00420990, &DAT_0042099c);
    _fwrite(&_Str_00421ee8, 0xc, 1, _File_00421e64);
    _fwrite(&_Str_00421eb0, 0x30, 1, _File_00421e64);
    pFVar3 = _File_00421e64;
    _fclose(_File_00421e64);
    uVar1 = 0x9f;
    mci_CloseWave(0x9f, extraout_DL, (char)pFVar3, s_intro_0042099f);
    uVar2 = 0xa5;
    mci_CloseWave(0xa5, extraout_DL_00, uVar1, s_click_004209a5);
    uVar1 = 0xab;
    mci_CloseWave(0xab, extraout_DL_01, uVar2, &DAT_004209ab);
    uVar2 = 0xaf;
    mci_CloseWave(0xaf, extraout_DL_02, uVar1, s_megapop_004209af);
    uVar1 = 0xb7;
    mci_CloseWave(0xb7, extraout_DL_03, uVar2, s_score_004209b7);
    uVar2 = 0xbd;
    mci_CloseWave(0xbd, extraout_DL_04, uVar1, s_highscore_004209bd);
    mci_CloseWave(199, extraout_DL_05, uVar2, s_shareware_004209c7);
    timeKillEvent(uTimerID_00421e5c);
    return;
}
void set_unexpected (int param_1, int param_2, int param_3, int param_4)

{
    int uVar1;
    int in_FS_OFFSET;

    uVar1 = *(int *)(*(int *)(*(int *)(in_FS_OFFSET + 4) + -8) + 0xc);
    if (param_4 != 0)
    {
        *(int *)(*(int *)(*(int *)(in_FS_OFFSET + 4) + -8) + 0xc) = param_4;
    }
    return uVar1;
}
void set_terminate(int param_1, int param_2, int param_3, int param_4)

{
    int uVar1;
    int in_FS_OFFSET;

    uVar1 = *(int *)(*(int *)(*(int *)(in_FS_OFFSET + 4) + -8) + 8);
    if (param_4 != 0)
    {
        *(int *)(*(int *)(*(int *)(in_FS_OFFSET + 4) + -8) + 8) = param_4;
    }
    return uVar1;
}
void ___call_terminate(void)

{
    int in_CL;
    int in_DL;
    int unaff_DI;
    int in_FS_OFFSET;

    void __InitExceptBlock(0x420c38, in_DL, in_CL, unaff_DI);
    _flushall();
    (**(code **)(*(int *)(*(int *)(in_FS_OFFSET + 4) + -8) + 8))();
    /* WARNING: Subroutine does not return */
    _abort();
}
void Shutdown(void)

{
    if (dd_Object != (int *)0x0)
    {
        if (dd_Primary != (int *)0x0)
        {
            (**(code **)(*dd_Primary + 8))();
            dd_Primary = (int *)0x0;
        }
        (**(code **)(*dd_Object + 8))();
        dd_Object = (int *)0x0;
    }
    return;
}
void __GetExceptDLLinfoIntern(int param_1, int param_2, int param_3, int *param_4)

{
    int in_FS_OFFSET;

    _DAT_00420b90 = *(int *)(*(int *)(in_FS_OFFSET + 4) + -8) + 0x24;
    *param_4 = 0x82727349;
    param_4[1] = &DAT_00420b74;
    return;
}

void @__InitExceptBlock(int param_1, int param_2, int param_3, int param_4)

{
    int *puVar1;
    int *puVar2;
    int unaff_EBP;
    char in_FS;

    puVar2 = (int *)(unaff_EBP + *(int *)(param_1 + 4));
    puVar2[2] = param_1;
    puVar2[3] = &param_4;
    puVar2[1] = __ExceptionHandler;
    puVar2[4] = 0;
    *(int *)((int)puVar2 + 0x12) = 0;
    puVar2[7] = *DAT_0042303c;
    puVar1 = (int *)segment(in_FS, 0);
    *puVar2 = *puVar1;
    puVar1 = (int *)segment(in_FS, 0);
    *puVar1 = puVar2;
    return;
}

void __ExceptInit(int param_1, int param_2, int param_3, int param_4)

{
    HMODULE hModule;
    HDC extraout_CL;
    HDC extraout_CL_00;
    HDC extraout_DL;
    HDC extraout_DL_00;
    HDC extraout_DL_01;
    FARPROC pFVar1;
    int in_FS_OFFSET;
    bool bVar2;
    uint local_c;
    int local_8;

    bVar2 = param_4 == 0;
    if (param_4 == 0)
    {
        if (DAT_00420058 != '\0')
        {
            pFVar1 = (FARPROC)0x0;
            hModule = GetModuleHandleA((const uint16_t *)0x0);
            param_3 = extraout_CL;
            param_2 = extraout_DL;
            if (hModule != (HMODULE)0x0)
            {
                pFVar1 = GetProcAddress(hModule, s___GetExceptDLLinfo_00420c50);
                param_3 = extraout_CL_00;
                param_2 = extraout_DL_00;
            }
            if (pFVar1 != (FARPROC)0x0)
            {
                param_3 = SUB41(&local_c, 0);
                (*pFVar1)();
                param_2 = extraout_DL_01;
                if ((0x82727348 < local_c) && (local_c < 0x8272735a))
                {
                    param_4 = local_8;
                }
            }
        }
        if (param_4 == 0)
        {
            __GetExceptDLLinfoInternal((char)&local_c, param_2, param_3, &local_c);
            param_4 = local_8;
        }
    }
    else
    {
        *(int **)(param_4 + 8) = &LAB_004158ec;
        *(int **)(param_4 + 0xc) = &LAB_00415965;
    }
    *(int *)(*(int *)(in_FS_OFFSET + 4) + -8) = param_4;
    if (bVar2)
    {
        DAT_0042303c = *(int *)(in_FS_OFFSET + 4) + -4;
    }
    *(int *)(*(int *)(in_FS_OFFSET + 4) + -4) = 0;
    *(int *)(*(int *)(*(int *)(in_FS_OFFSET + 4) + -8) + 4) = 0;
    return;
}

void __GetPolymorphicDTC(int param_1, int param_2, int param_3, int param_4, int param_5)

{
    if (param_4 == 0)
    {
        return 0;
    }
    return *(int *)(*(int *)((*(int *)(param_4 + param_5) - *(int *)(*(int *)(param_4 + param_5) + -4)) +
                             -0xc) +
                    0x20);
}

void  _matherr(int param_1, int param_2, int param_3, int *param_4)

{
    if (*param_4 == 4)
    {
        param_4[6] = 0;
        param_4[7] = 0;
        return;
    }
    if (*param_4 == 5)
    {
        return;
    }
}
