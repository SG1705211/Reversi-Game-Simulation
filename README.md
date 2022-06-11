# Reversi-Game-Simulation.
This program is a simulation of Reversi game using C langauge
# Motivation.
Being obsessed with the idea of "who can design the best Reversi Solver Algorithm" and "Computer vs Computer", I decide to design my own Reversi game solver to compete with my friends in U of Toronto. \
Before implementing the solver algorithm, I implemented this game to allow user play Reversi in C environment.
# Techniques.
The techniques used in this programs are mostly  **dynamic memory** and **structures pointer**.\
The reason for using both techniques is to use less memory, and to be faster.\
Using structure pointers, the "board array" only needs to be iterated once when finding the potential solution of Reversi at any steps\
Using dynamic memory and doubling stratregy, the program asked for the minimum amount of memory from heap as possible.\
The usage of structure pointer also makes the code more readable, as it provides a neat way to display solution.
# How to play the game.
Compile the `Reversi.c` file using ```g++ Reversi.c -o Reversi.out``` and run the output file.
# Game Rule
Reversi is a strategy board game\
On this game, you can either play front side or reverse-side, denoted by `O` (front) and `X`(reverse)\
The game starts with reverse side piece, and the piece will be placed using command.\
For example, if you want to place a piece on `(c,c)`, you can simply type `CC` (All cap)\
All the valid move for specific colour is denoted by `*` character.
To illustrate what is the valid move, considering the board:
```
     a     b     c     d     e     f     g     h
   _____ _____ _____ _____ _____ _____ _____ _____
  |     |     |     |     |     |     |     |     |
a |     |     |     |     |     |     |     |     |
  |_____|_____|_____|_____|_____|_____|_____|_____|
  |     |     |     |     |     |     |     |     |
b |     |     |     |     |     |     |     |     |
  |_____|_____|_____|_____|_____|_____|_____|_____|
  |     |     |     |     |     |     |     |     |
c |     |     |     |  *  |     |     |     |     |
  |_____|_____|_____|_____|_____|_____|_____|_____|
  |     |     |     |     |     |     |     |     |
d |     |     |  *  |  O  |  X  |     |     |     |
  |_____|_____|_____|_____|_____|_____|_____|_____|
  |     |     |     |     |     |     |     |     |
e |     |     |     |  X  |  O  |  *  |     |     |
  |_____|_____|_____|_____|_____|_____|_____|_____|
  |     |     |     |     |     |     |     |     |
f |     |     |     |     |  *  |     |     |     |
  |_____|_____|_____|_____|_____|_____|_____|_____|
  |     |     |     |     |     |     |     |     |
g |     |     |     |     |     |     |     |     |
  |_____|_____|_____|_____|_____|_____|_____|_____|
  |     |     |     |     |     |     |     |     |
h |     |     |     |     |     |     |     |     |
  |_____|_____|_____|_____|_____|_____|_____|_____|
```
  For reverse side, the location "DC" is a valid move, because between DC and DE, there is at least one piece, in a row, are all reverse side\
  All the reverse side that's in between has to be consecutive reverse side.\
  For each move, after the piece is placed, all the opposite piece (for example, if it is front's move, then the opposite means reverse side) that's between the same    colour (in which case, front) will be flipped and change to opposite side.\
  If reverse side placed piece on dc, then the board will become
```
     a     b     c     d     e     f     g     h
   _____ _____ _____ _____ _____ _____ _____ _____
  |     |     |     |     |     |     |     |     |
a |     |     |     |     |     |     |     |     |
  |_____|_____|_____|_____|_____|_____|_____|_____|
  |     |     |     |     |     |     |     |     |
b |     |     |     |     |     |     |     |     |
  |_____|_____|_____|_____|_____|_____|_____|_____|
  |     |     |     |     |     |     |     |     |
c |     |     |  *  |     |  *  |     |     |     |
  |_____|_____|_____|_____|_____|_____|_____|_____|
  |     |     |     |     |     |     |     |     |
d |     |     |  X  |  X  |  X  |     |     |     |
  |_____|_____|_____|_____|_____|_____|_____|_____|
  |     |     |     |     |     |     |     |     |
e |     |     |  *  |  X  |  O  |     |     |     |
  |_____|_____|_____|_____|_____|_____|_____|_____|
  |     |     |     |     |     |     |     |     |
f |     |     |     |     |     |     |     |     |
  |_____|_____|_____|_____|_____|_____|_____|_____|
  |     |     |     |     |     |     |     |     |
g |     |     |     |     |     |     |     |     |
  |_____|_____|_____|_____|_____|_____|_____|_____|
  |     |     |     |     |     |     |     |     |
h |     |     |     |     |     |     |     |     |
  |_____|_____|_____|_____|_____|_____|_____|_____|
```
Noted that since the front side piece on cd is between two reverse side, then it is flipped.\
Noted that if only one of player cannot make any move, the game will switch side.
After the point where no move can be made for both player, the game terminates.\
The player with more pieces on the board win.\
Enjoy.

