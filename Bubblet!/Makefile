# Windows 11 build using the MSYS2 UCRT64 toolchain.

CC = gcc
WINDRES ?= windres
PKG_CONFIG ?= pkg-config
LDD ?= ldd
UCRT64_BIN ?= $(shell $(PKG_CONFIG) --variable=prefix sdl2)/bin
PKGS = sdl2 SDL2_mixer SDL2_ttf libcurl

CFLAGS ?= -O2 -Wall -Wextra
CPPFLAGS += -I. $(shell $(PKG_CONFIG) --cflags $(PKGS)) -D_WIN32_WINNT=0x0601
LDLIBS += $(shell $(PKG_CONFIG) --libs $(PKGS)) -lm
LDFLAGS += -mwindows

TARGET = bubblet.exe
BUILD_DIR = build/windows
TEST_TARGET = $(BUILD_DIR)/game_logic_test.exe
SOURCES = bubblet_main_linux.c \
          bubblet_globals.c \
          bubblet_sdl_linux.c \
          bubblet_init.c \
          bubblet_input.c \
          bubblet_logic.c \
          bubblet_sound.c \
          bubblet_ui.c \
          bubblet_update.c
OBJECTS = $(patsubst %.c,$(BUILD_DIR)/%.o,$(SOURCES))
RESOURCE_OBJECTS = $(BUILD_DIR)/bubblet.res.o

all: $(TARGET) bundle-runtime

$(TARGET): $(OBJECTS) $(RESOURCE_OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)

bundle-runtime: $(TARGET)
	@set -eu; \
	dependencies="$$($(LDD) $(TARGET))"; \
	missing="$$(printf '%s\n' "$$dependencies" | grep 'not found' || true)"; \
	if [ -n "$$missing" ]; then \
		printf 'Unresolved runtime dependencies:\n%s\n' "$$missing" >&2; \
		exit 1; \
	fi; \
	dlls="$$(printf '%s\n' "$$dependencies" | awk '$$1 ~ /\.dll$$/ { print $$1 }' | sort -u)"; \
	if [ -z "$$dlls" ]; then \
		echo "No runtime DLL dependencies found for $(TARGET)." >&2; \
		exit 1; \
	fi; \
	printf '%s\n' "$$dlls" | while IFS= read -r dll; do \
		source_dll="$(UCRT64_BIN)/$$dll"; \
		if [ -f "$$source_dll" ]; then cp -u "$$source_dll" .; fi; \
	done; \
	dependencies="$$($(LDD) $(TARGET))"; \
	missing="$$(printf '%s\n' "$$dependencies" | grep 'not found' || true)"; \
	if [ -n "$$missing" ]; then \
		printf 'Unresolved runtime dependencies after bundling:\n%s\n' "$$missing" >&2; \
		exit 1; \
	fi

$(BUILD_DIR)/%.o: %.c bubblet_types.h bubblet_globals.h bubblet_version.h
	mkdir -p $(BUILD_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/bubblet.res.o: bubblet.rc bubblet_resource.h bubblet_bmps/Icon\ Entry_1.ico
	mkdir -p $(BUILD_DIR)
	$(WINDRES) -I. -i $< -o $@

$(TEST_TARGET): $(BUILD_DIR)/bubblet_globals.o $(BUILD_DIR)/bubblet_logic.o tests/game_logic_test.c
	$(CC) $(filter-out -Dmain=SDL_main,$(CPPFLAGS)) $(CFLAGS) -DSDL_MAIN_HANDLED -mconsole -o $@ $^ -lm

test: $(TEST_TARGET)
	cd $(BUILD_DIR) && ./game_logic_test.exe

run: bundle-runtime
	./$(TARGET)

clean:
	rm -rf $(BUILD_DIR) $(TARGET)

.PHONY: all bundle-runtime run test clean
