# Makefile for Bubblet! Rebuilt (macOS/SDL2 Port)

CC = clang
SDL2_CONFIG = /usr/local/bin/sdl2-config
CFLAGS = -Wall -O2 `$(SDL2_CONFIG) --cflags` -I. -I/usr/local/include
LDFLAGS = `$(SDL2_CONFIG) --libs` -L/usr/local/lib -lSDL2_mixer -lSDL2_ttf

# Output name
TARGET = bubblet_mac

# Sources
SRCS = bubblet_main_mac.c \
       bubblet_globals.c \
       bubblet_sdl.c \
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
	rm -rf Bubblet.app

app: $(TARGET)
	mkdir -p Bubblet.app/Contents/MacOS
	mkdir -p Bubblet.app/Contents/Resources
	cp $(TARGET) Bubblet.app/Contents/MacOS/
	cp -r bubblet_bmps Bubblet.app/Contents/Resources/
	cp *.wav Bubblet.app/Contents/Resources/ 2>/dev/null || true
	cp cursor.bmp Bubblet.app/Contents/Resources/ 2>/dev/null || true
	cp bubblet.cfg Bubblet.app/Contents/Resources/ 2>/dev/null || true
	cp bubblet.icns Bubblet.app/Contents/Resources/ 2>/dev/null || true
	@echo '<?xml version="1.0" encoding="UTF-8"?>' > Bubblet.app/Contents/Info.plist
	@echo '<!DOCTYPE plist PUBLIC "-//Apple//DTD PLIST 1.0//EN" "http://www.apple.com/DTDs/PropertyList-1.0.dtd">' >> Bubblet.app/Contents/Info.plist
	@echo '<plist version="1.0">' >> Bubblet.app/Contents/Info.plist
	@echo '<dict>' >> Bubblet.app/Contents/Info.plist
	@echo '  <key>CFBundleExecutable</key>' >> Bubblet.app/Contents/Info.plist
	@echo '  <key>launcher.sh</key>' >> Bubblet.app/Contents/Info.plist
	@echo '  <key>CFBundleIconFile</key>' >> Bubblet.app/Contents/Info.plist
	@echo '  <key>bubblet</key>' >> Bubblet.app/Contents/Info.plist
	@echo '  <key>CFBundleName</key>' >> Bubblet.app/Contents/Info.plist
	@echo '  <key>Bubblet</key>' >> Bubblet.app/Contents/Info.plist
	@echo '  <key>CFBundleIdentifier</key>' >> Bubblet.app/Contents/Info.plist
	@echo '  <key>com.houseofbytes.bubblet</key>' >> Bubblet.app/Contents/Info.plist
	@echo '  <key>CFBundlePackageType</key>' >> Bubblet.app/Contents/Info.plist
	@echo '  <key>APPL</key>' >> Bubblet.app/Contents/Info.plist
	@echo '</dict>' >> Bubblet.app/Contents/Info.plist
	@echo '</plist>' >> Bubblet.app/Contents/Info.plist
	@echo '#!/bin/bash' > Bubblet.app/Contents/MacOS/launcher.sh
	@echo 'DIR="$$( cd "$$( dirname "$${BASH_SOURCE[0]}" )" && pwd )"' >> Bubblet.app/Contents/MacOS/launcher.sh
	@echo 'cd "$$DIR/../Resources"' >> Bubblet.app/Contents/MacOS/launcher.sh
	@echo 'exec "$$DIR/$(TARGET)"' >> Bubblet.app/Contents/MacOS/launcher.sh
	chmod +x Bubblet.app/Contents/MacOS/launcher.sh

.PHONY: all clean app
