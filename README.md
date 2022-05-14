# Reversi-Game-Simulation
This program is a simulation of reversi using C langauge\
To play the game, simply compile the file, then the board will be printed on the terminal.\
Noted: The dimension can only between 3 and 26. Any other numbers will be treated as invalid.
# Game Rule
Reversi is a strategy board game. On this game, you can either play white or black.\
"U" denoted the blank space while B denoted the space that's occupied by black and vice versa\
For each move, all the opposite color piece (for example, if it is white's move, then the opposite means black) that's between the same colour (in which case, white) will be flipped and change to opposite color.\
For each move, at least one piece have to be flipped, otherwise it is an invalid move\
The game terminated as long as one invalid move is entered.\
After the pointer where no move can be made, the game terminates.

