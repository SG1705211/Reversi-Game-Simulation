# Reversi-Game-Simulation
This program is a simulation of reversi using C langauge\
To play the game, simply compile the file, then the board will be printed on the terminal.\
Noted: The dimension can only between 3 and 26. Any other numbers will be treated as invalid.\
Although allowed, it is recommended that using the dimension 8 as it is the most way to enjoy this game.\
# Game Rule
Reversi is a strategy board game. \
On this game, you can either play front side or reverse-side, denoted by O (front) and X(reverse)\
All the valid move for specific colour is denoted by star character.\
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
After the point where no move can be made for both player, the game terminates.\
The player with more pieces on the board win.\
Enjoy.

