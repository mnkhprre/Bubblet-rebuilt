#ifndef BUBBLET_VERSION_H
#define BUBBLET_VERSION_H

#define BUBBLET_VERSION_MAJOR 1
#define BUBBLET_VERSION_MINOR 0
#define BUBBLET_VERSION_PATCH 0
#define BUBBLET_VERSION_STRING "1.0.0"
#define BUBBLET_VERSION_HEX 0x010000

#define BUBBLET_GITHUB_REPO "mnkhprre/Bubblet-rebuilt"
#define BUBBLET_GITHUB_API_URL "https://api.github.com/repos/mnkhprre/Bubblet-rebuilt/releases/latest"

BOOL CheckForUpdates(void);
BOOL CheckForUpdatesSilent(void);
void ShowUpdateAvailable(const char *latestVersion, const char *releaseUrl, const char *releaseNotes);

#endif