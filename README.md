# So Long
## This is an exercise in using MiniLibX(X11) to create low level graphic
### This is a basic 2D game in which a ball has to collect all the dots before it can escape through a hole

This program takes a bitmap file with a .ber extension. 

Example Bitmap:
1 = Wall
0 = Empty Space
P = Player
C = Collectable
E = Exit

```1111111111111
1E0001000CCC1
1111000111111
1000011000001
1CCC1111CCCC1
10000000000P1
1111111111111

```The program can take any configuration of a bitmap, validate it, initialize it, render the graphics, and manage input controls from the player for gameplay.
