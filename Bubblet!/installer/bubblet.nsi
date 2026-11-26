; Bubblet! Rebuilt - Windows installer (NSIS)
; Build: make -f Makefile.windows installer   (run from the Bubblet! folder)
;
; Installs per-user (no admin prompt) into %LOCALAPPDATA%\Programs\Bubblet,
; so the game can write bubblet.cfg (settings/high scores) next to the exe.

Unicode true
!include "MUI2.nsh"

!define APPNAME     "Bubblet! Rebuilt"
!define APPEXE      "Bubblet.exe"
!define VERSION     "1.2.1"
!define PUBLISHER   "mnkhprre"
!define URL         "https://github.com/mnkhprre/Bubblet-rebuilt"
!define UNINSTKEY   "Software\Microsoft\Windows\CurrentVersion\Uninstall\BubbletRebuilt"
!define SRCDIR      "dist\windows"

Name "${APPNAME}"
OutFile "dist\Bubblet-${VERSION}-Setup.exe"
InstallDir "$LOCALAPPDATA\Programs\Bubblet"
InstallDirRegKey HKCU "Software\BubbletRebuilt" "InstallDir"
RequestExecutionLevel user
SetCompressor /SOLID lzma

VIProductVersion "${VERSION}.0"
VIAddVersionKey "ProductName" "${APPNAME}"
VIAddVersionKey "FileDescription" "${APPNAME} Setup"
VIAddVersionKey "FileVersion" "${VERSION}"
VIAddVersionKey "ProductVersion" "${VERSION}"
VIAddVersionKey "CompanyName" "${PUBLISHER}"
VIAddVersionKey "LegalCopyright" "${PUBLISHER}"

!define MUI_ICON   "bubblet.ico"
!define MUI_UNICON "bubblet.ico"
!define MUI_ABORTWARNING
!define MUI_FINISHPAGE_RUN "$INSTDIR\${APPEXE}"

!insertmacro MUI_PAGE_WELCOME
!insertmacro MUI_PAGE_DIRECTORY
!insertmacro MUI_PAGE_INSTFILES
!insertmacro MUI_PAGE_FINISH

!insertmacro MUI_UNPAGE_CONFIRM
!insertmacro MUI_UNPAGE_INSTFILES

!insertmacro MUI_LANGUAGE "English"
!insertmacro MUI_LANGUAGE "Turkish"

Section "Install"
  SetOutPath "$INSTDIR"
  File /r "${SRCDIR}\*.*"
  File "bubblet.ico"

  WriteUninstaller "$INSTDIR\Uninstall.exe"
  WriteRegStr HKCU "Software\BubbletRebuilt" "InstallDir" "$INSTDIR"

  CreateDirectory "$SMPROGRAMS\${APPNAME}"
  CreateShortcut "$SMPROGRAMS\${APPNAME}\${APPNAME}.lnk" "$INSTDIR\${APPEXE}" "" "$INSTDIR\${APPEXE}" 0
  CreateShortcut "$SMPROGRAMS\${APPNAME}\Uninstall.lnk" "$INSTDIR\Uninstall.exe"
  CreateShortcut "$DESKTOP\${APPNAME}.lnk" "$INSTDIR\${APPEXE}" "" "$INSTDIR\${APPEXE}" 0

  WriteRegStr   HKCU "${UNINSTKEY}" "DisplayName" "${APPNAME}"
  WriteRegStr   HKCU "${UNINSTKEY}" "DisplayVersion" "${VERSION}"
  WriteRegStr   HKCU "${UNINSTKEY}" "Publisher" "${PUBLISHER}"
  WriteRegStr   HKCU "${UNINSTKEY}" "URLInfoAbout" "${URL}"
  WriteRegStr   HKCU "${UNINSTKEY}" "DisplayIcon" "$INSTDIR\${APPEXE}"
  WriteRegStr   HKCU "${UNINSTKEY}" "InstallLocation" "$INSTDIR"
  WriteRegStr   HKCU "${UNINSTKEY}" "UninstallString" '"$INSTDIR\Uninstall.exe"'
  WriteRegDWORD HKCU "${UNINSTKEY}" "NoModify" 1
  WriteRegDWORD HKCU "${UNINSTKEY}" "NoRepair" 1
SectionEnd

Section "Uninstall"
  Delete "$DESKTOP\${APPNAME}.lnk"
  RMDir /r "$SMPROGRAMS\${APPNAME}"
  ; Removes the game files and the saved settings/high scores (bubblet.cfg)
  RMDir /r "$INSTDIR"
  DeleteRegKey HKCU "${UNINSTKEY}"
  DeleteRegKey HKCU "Software\BubbletRebuilt"
SectionEnd
