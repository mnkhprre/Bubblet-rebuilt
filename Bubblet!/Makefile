# Makefile for Bubblet! Rebuilt
# Designed for MinGW (x86_64-w64-mingw32-gcc)

# Compiler and tools
CC = x86_64-w64-mingw32-gcc
WINDRES = x86_64-w64-mingw32-windres
CFLAGS = -Wall -O2 -I. -D_WIN32_WINNT=0x0501
LDFLAGS = -mwindows -lgdi32 -luser32 -lwinmm -lddraw -lole32

# Output name
TARGET = bubblet.exe

# Sources
SRCS = bubblet_main.c \
       bubblet_globals.c \
       bubblet_graphics.c \
       bubblet_init.c \
       bubblet_input.c \
       bubblet_logic.c \
       bubblet_sound.c \
       bubblet_ui.c

# Objects
OBJS = $(SRCS:.c=.o)
RES_OBJ = bubblet_res.o

# Default rule
all: $(TARGET)

# Link
$(TARGET): $(OBJS) $(RES_OBJ)
	$(CC) -o $@ $(OBJS) $(RES_OBJ) $(LDFLAGS)

# Compile C files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Compile Resources
$(RES_OBJ): bubblet.rc
	$(WINDRES) $< -o $@

# Clean
clean:
	rm -f $(OBJS) $(RES_OBJ) $(TARGET)

.PHONY: all clean
