Bubblet Readme (A more detailed version comming soon!!)
--------------

Contents:
1.) How to play Bubblet...
2.) Different Game-Styles
3.) Register Bubblet!
4.) Original Game
5.) Contact the Author!
6.) Visit our Homepage!
7.) Legal Stuff

---------------------------------------------------------------------------

1.) How to play Bubblet...
--------------------------
Playing Bubblet is very easy! The only thing you have to do is to click at
-at least- two Bubbles of the same color, which are connected to each other.
The more Bubbles aligned together the more Bubble-Points you get! If you click
Bubbles that are connected, they get highlighted. If you click them
again they get bursted. All Bubbles above the bursted ones will fall down.

2.) Different Game-Styles
-------------------------
Bubblet has four Game-Styles! Just try them out by changing 'em in
the Setup-Screen!

3.) Register Bubblet!
---------------------
I'd be very happy if some people would register Bubblet, so that i can go on
making updates and other cool games! ;-) Please support the concept of Shareware!

4.) Original Game
-----------------
The original Bubblet-Game has been created by Frank Fejes (frank@oopdreams.com) for the
PalmPilot. Take a look at it: www.oopdreams.com.

5.) Contact the Author!
-----------------------
I'd like it very much to get some feedback! Please send me your comments and
suggestions via E-Mail to d.klein@hobsoft.de.

6.) Visit our Homepage!
-----------------------
For updates and other cool stuff visit our homepage: www.hobsoft.de

7.) Legal Stuff
--------------
Bubblet is Shareware. The Shareware-Version may be distributed freely! Anyway,
if you're planning on releasing it within a Shareware-Compilation or on a Coverdisc
 please drop me a line (d.klein@hobsoft.de). I just want to know. Thanks.

8.) Building on Windows 11
--------------------------
The Windows build uses SDL2 and the MSYS2 UCRT64 toolchain. Install MSYS2 from
https://www.msys2.org/, open the UCRT64 terminal, and install the dependencies:

  pacman -S --needed make \
    mingw-w64-ucrt-x86_64-gcc mingw-w64-ucrt-x86_64-pkgconf \
    mingw-w64-ucrt-x86_64-SDL2 mingw-w64-ucrt-x86_64-SDL2_mixer \
    mingw-w64-ucrt-x86_64-SDL2_ttf mingw-w64-ucrt-x86_64-curl

From the UCRT64 terminal, change to this directory and build/run the game:

  make
  make run

Run the game-logic regression tests with:

  make test

This creates bubblet.exe and copies its required MSYS2 runtime DLLs alongside
it. The original ICO in bubblet_bmps is embedded as the Windows executable and
window icon. Keep the executable and DLLs alongside the bubblet_bmps folder,
cursor.bmp, the WAV files, and bubblet.cfg. The game uses the executable's
directory for these files and for its configuration. After building,
bubblet.exe can be run from File Explorer without an MSYS2 terminal.
