# So Long
## This project is a very small 2D game. 
### This is an exercise in textures, sprites, and some other very basic gameplay element.

This project is coded in C on a GNU/Linux system. The project involves window management, event handling, colors, and textures. The graphical library used is MiniLibX which is an API designed by Olivier Crouzet to simplify use of the X11 library developed by MIT. 

So Long can take any configuration of a bitmap, validate it, initialize it, render the graphics, and manage input controls from the player for gameplay. If there is an issue with the bitmap it will print an error message in the terminal. 

This program takes a bitmap file with a .ber extension. 

Example Bitmap:
- 1 = Wall
- 0 = Empty Space
- P = Player
- C = Collectable
- E = Exit

```
1111111111111
1E0001000CCC1
1111000111111
1000011000001
1CCC1111CCCC1
10000000000P1
1111111111111
```
**Instructions**
1. ```make```
2. ```./so_long map/<mapX.ber>```
