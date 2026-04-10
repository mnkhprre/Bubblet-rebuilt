#include "bubblet_globals.h"

// Refactored sound functions using HAL for macOS/SDL2
BOOL mci_PlayWave(const char* alias) {
    HAL_PlaySound(alias);
    return TRUE;
}

// Redirect former MCI calls to HAL
BOOL mci_OpenWave(const char* filename, const char* alias) { return TRUE; }
BOOL mci_PlayWaveWait(const char* alias) { HAL_PlaySound(alias); return TRUE; }
BOOL mci_StopWave(const char* alias) { return TRUE; }
BOOL mci_CloseWave(const char* alias) { return TRUE; }
BOOL mci_PlayCD(void) { return TRUE; }
BOOL mci_PlayCDTrack(int track) { return TRUE; }
BOOL mci_StopCD(void) { return TRUE; }
