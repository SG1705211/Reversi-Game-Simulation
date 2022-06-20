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
# Compilation.
To play the game, firstly clone the repository:
   ```bash
   git clone https://github.com/SG1705211/Reversi-Game-Simulation
   ```
Then, when in the root directory, compile the Reversi.c:
```bash
gcc Reversi.c -o Reverse_game
```
Simply run the output file, and enjoy the game
# Game Rule
You can skip this part if you are already familiar with the game.\
Reversi is a strategy board game\
On this game, you can either play `front-side` or `reverse-side`, denoted by `O` (front) and `X`(reverse), and the first player will play reverse-side.\
All the placement of the piece is controled by typing the coordinates.\
You can play in a position if, in any direction, you can trap more than one's opponent's piece with your existing pieces.\
All the valid move for specific colour is denoted by `*` character.\
To illustrate this using an exmaple:
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
Noted that since the front side piece on cd is between two reverse side, then it is flipped.
# End of the game:
If only one of player cannot make any move, the game will switch side instantly\
After the point where no move can be made for both player, the game terminates.\
The player with more pieces on the board win.\
Enjoy.

