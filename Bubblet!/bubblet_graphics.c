#include "bubblet_globals.h"

// PutSurface: Blits a surface to another surface
void PutSurface(int x, int y, LPDIRECTDRAWSURFACE lpSrc, LPDIRECTDRAWSURFACE lpDest) {
    if (!lpSrc || !lpDest) return;

    DDSURFACEDESC ddsd;
    memset(&ddsd, 0, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    
    // Get source dimensions
    if (lpSrc->lpVtbl->GetSurfaceDesc(lpSrc, &ddsd) != DD_OK) return;

    RECT srcRect = { 0, 0, ddsd.dwWidth, ddsd.dwHeight };
    RECT destRect = { x, y, x + (int)ddsd.dwWidth, y + (int)ddsd.dwHeight };

    lpDest->lpVtbl->Blt(lpDest, &destRect, lpSrc, &srcRect, DDBLT_WAIT, NULL);
}

// PutSurfaceCC: Blits with ColorKey (Transparency)
void PutSurfaceCC(int x, int y, LPDIRECTDRAWSURFACE lpSrc, LPDIRECTDRAWSURFACE lpDest) {
    if (!lpSrc || !lpDest) return;

    DDSURFACEDESC ddsd;
    memset(&ddsd, 0, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    
    if (lpSrc->lpVtbl->GetSurfaceDesc(lpSrc, &ddsd) != DD_OK) return;

    RECT srcRect = { 0, 0, ddsd.dwWidth, ddsd.dwHeight };
    RECT destRect = { x, y, x + (int)ddsd.dwWidth, y + (int)ddsd.dwHeight };

    lpDest->lpVtbl->Blt(lpDest, &destRect, lpSrc, &srcRect, DDBLT_WAIT | DDBLT_KEYSRC, NULL);
}

// PutSurfacePrimary: Blits backbuffer to primary surface (screen)
void PutSurfacePrimary(int x, int y, LPDIRECTDRAWSURFACE lpSrc) {
    if (!lpSrc || !dd_Primary) return;

    DDSURFACEDESC ddsd;
    memset(&ddsd, 0, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    
    if (lpSrc->lpVtbl->GetSurfaceDesc(lpSrc, &ddsd) != DD_OK) return;

    RECT srcRect = { 0, 0, ddsd.dwWidth, ddsd.dwHeight };
    
    // Position on screen (using Client_Pos offset)
    int screenX = x + _DAT_00421e50; // TODO: Rename _DAT_00421e50 to client_pos_x
    int screenY = y + _DAT_00421e54; // TODO: Rename _DAT_00421e54 to client_pos_y
    
    RECT destRect = { screenX, screenY, screenX + (int)ddsd.dwWidth, screenY + (int)ddsd.dwHeight };

    dd_Primary->lpVtbl->Blt(dd_Primary, &destRect, lpSrc, &srcRect, DDBLT_WAIT, NULL);
}

// PutSurfaceClipCC: Blits with transparency and clipping
void PutSurfaceClipCC(int x, int y, LPDIRECTDRAWSURFACE lpSrc, LPDIRECTDRAWSURFACE lpDest, int clipX1, int clipY1, int clipX2, int clipY2) {
    if (!lpSrc || !lpDest) return;

    DDSURFACEDESC ddsd;
    memset(&ddsd, 0, sizeof(ddsd));
    ddsd.dwSize = sizeof(ddsd);
    
    if (lpSrc->lpVtbl->GetSurfaceDesc(lpSrc, &ddsd) != DD_OK) return;

    RECT srcRect = { 0, 0, ddsd.dwWidth, ddsd.dwHeight };
    RECT destRect = { x, y, x + (int)ddsd.dwWidth, y + (int)ddsd.dwHeight };

    // Manual clipping logic (simplified for now, original decompiled code has complex clipping)
    // TODO: Implement precise clipping if needed
    
    lpDest->lpVtbl->Blt(lpDest, &destRect, lpSrc, &srcRect, DDBLT_WAIT | DDBLT_KEYSRC, NULL);
}

// Update_Screen: Flips backbuffer to primary
void Update_Screen(void) {
    PutSurfacePrimary(0, 0, v_screen);
}
