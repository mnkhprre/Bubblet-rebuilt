# Makefile for Bubblet! Rebuilt (Linux/Debian SDL2 Port)

CC = gcc
CFLAGS = -Wall -O2 $(shell pkg-config --cflags sdl2 SDL2_mixer SDL2_ttf) -I.
LDFLAGS = $(shell pkg-config --libs sdl2 SDL2_mixer SDL2_ttf) -lm

# Output name
TARGET = bubblet_linux

# Sources
SRCS = bubblet_main_linux.c \
       bubblet_globals.c \
       bubblet_sdl_linux.c \
       bubblet_init.c \
       bubblet_input.c \
       bubblet_logic.c \
       bubblet_sound.c \
       bubblet_ui.c

# Objects
OBJS = $(SRCS:.c=.o)

# Default rule
all: $(TARGET)

# Link
$(TARGET): $(OBJS)
	$(CC) -o $@ $(OBJS) $(LDFLAGS)

# Compile C files with header dependencies
%.o: %.c bubblet_types.h bubblet_globals.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJS) $(TARGET)

# Install (copies binary + assets to ~/.local/share/bubblet)
install: $(TARGET)
	mkdir -p $(HOME)/.local/share/bubblet
	cp $(TARGET) $(HOME)/.local/share/bubblet/
	cp -r bubblet_bmps $(HOME)/.local/share/bubblet/
	cp *.wav $(HOME)/.local/share/bubblet/ 2>/dev/null || true
	cp cursor.bmp $(HOME)/.local/share/bubblet/ 2>/dev/null || true
	cp bubblet.cfg $(HOME)/.local/share/bubblet/ 2>/dev/null || true
	@echo "Installed to $(HOME)/.local/share/bubblet/"
	@echo "Run with: cd $(HOME)/.local/share/bubblet && ./bubblet_linux"

.PHONY: all clean install
