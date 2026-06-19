#include "bubblet_globals.h"
#include "bubblet_version.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

typedef struct {
    char *data;
    size_t size;
} CurlBuffer;

static size_t CurlWriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
    size_t realsize = size * nmemb;
    CurlBuffer *buf = (CurlBuffer *)userp;
    char *ptr = realloc(buf->data, buf->size + realsize + 1);
    if (!ptr) return 0;
    buf->data = ptr;
    memcpy(&(buf->data[buf->size]), contents, realsize);
    buf->size += realsize;
    buf->data[buf->size] = '\0';
    return realsize;
}

static BOOL ParseVersion(const char *tagName, int *major, int *minor, int *patch) {
    if (!tagName) return FALSE;
    while (*tagName && (*tagName < '0' || *tagName > '9')) tagName++;
    if (!*tagName) return FALSE;
    return sscanf(tagName, "%d.%d.%d", major, minor, patch) == 3;
}

static int CompareVersion(int m1, int mi1, int p1, int m2, int mi2, int p2) {
    if (m1 != m2) return m1 - m2;
    if (mi1 != mi2) return mi1 - mi2;
    return p1 - p2;
}

static char *ExtractJsonString(const char *json, const char *key) {
    char searchKey[256];
    snprintf(searchKey, sizeof(searchKey), "\"%s\":\"", key);
    const char *start = strstr(json, searchKey);
    if (!start) return NULL;
    start += strlen(searchKey);
    const char *end = strchr(start, '"');
    if (!end) return NULL;
    size_t len = end - start;
    char *result = malloc(len + 1);
    if (!result) return NULL;
    strncpy(result, start, len);
    result[len] = '\0';
    return result;
}

static char *ExtractJsonArrayString(const char *json, const char *key) {
    char searchKey[256];
    snprintf(searchKey, sizeof(searchKey), "\"%s\":[", key);
    const char *start = strstr(json, searchKey);
    if (!start) return NULL;
    start += strlen(searchKey);
    if (*start == ']') return NULL;
    const char *end = strchr(start, ']');
    if (!end) return NULL;
    size_t len = end - start;
    char *result = malloc(len + 1);
    if (!result) return NULL;
    strncpy(result, start, len);
    result[len] = '\0';
    return result;
}

BOOL CheckForUpdatesSilent(void) {
    CURL *curl = curl_easy_init();
    if (!curl) return FALSE;

    CurlBuffer buffer = {NULL, 0};
    curl_easy_setopt(curl, CURLOPT_URL, BUBBLET_GITHUB_API_URL);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlWriteCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &buffer);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
    curl_easy_setopt(curl, CURLOPT_USERAGENT, "Bubblet/" BUBBLET_VERSION_STRING);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
    curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);

    CURLcode res = curl_easy_perform(curl);
    curl_easy_cleanup(curl);

    if (res != CURLE_OK) {
        if (buffer.data) free(buffer.data);
        return FALSE;
    }

    char *tagName = ExtractJsonString(buffer.data, "tag_name");
    char *releaseUrl = ExtractJsonString(buffer.data, "html_url");
    char *releaseNotes = ExtractJsonString(buffer.data, "body");

    free(buffer.data);

    if (!tagName) return FALSE;

    int latestMajor, latestMinor, latestPatch;
    if (!ParseVersion(tagName, &latestMajor, &latestMinor, &latestPatch)) {
        free(tagName);
        if (releaseUrl) free(releaseUrl);
        if (releaseNotes) free(releaseNotes);
        return FALSE;
    }

    int cmp = CompareVersion(latestMajor, latestMinor, latestPatch,
                             BUBBLET_VERSION_MAJOR, BUBBLET_VERSION_MINOR, BUBBLET_VERSION_PATCH);

    if (cmp > 0) {
        ShowUpdateAvailable(tagName, releaseUrl ? releaseUrl : "", releaseNotes ? releaseNotes : "");
    }

    free(tagName);
    if (releaseUrl) free(releaseUrl);
    if (releaseNotes) free(releaseNotes);
    return TRUE;
}

BOOL CheckForUpdates(void) {
    printf("[UPDATE] Checking for updates...\n");
    if (CheckForUpdatesSilent()) {
        printf("[UPDATE] Check complete.\n");
        return TRUE;
    } else {
        printf("[UPDATE] Check failed or no update available.\n");
        return FALSE;
    }
}

void ShowUpdateAvailable(const char *latestVersion, const char *releaseUrl, const char *releaseNotes) {
    printf("\n========== UPDATE AVAILABLE ==========\n");
    printf("Current version: %s\n", BUBBLET_VERSION_STRING);
    printf("Latest version:  %s\n", latestVersion);
    if (releaseUrl && *releaseUrl) {
        printf("Download: %s\n", releaseUrl);
    }
    if (releaseNotes && *releaseNotes) {
        printf("\nRelease notes:\n%s\n", releaseNotes);
    }
    printf("======================================\n\n");
}