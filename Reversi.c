// This program is a simulation for reversi game using the terminal and
// standard I/O.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// Some constants about any pieces.
#define front "  O  "  
#define reverse "  X  "
#define empty "     "
#define sol "  *  "
// solution is a structures for recording the solutions for certain point.
struct solution {
    // start_row, start_col is the location where the pieces can be put.
    int start_row;
    int start_col;
    // end_row, end_col is the location the destination of the same colour.
    // (the pieces are already in board)
    int end_row;
    int end_col;
    // pos_row and pos_col is the direction for the flipping.
    int pos_row;
    int pos_col;
};

// board_printer (board, n) is used to print the reversi board of dimension
// n * n on terminal.
// For printing format, I got inspired by rodolfoams work.
// https://github.com/rodolfoams/reversi-c
void board_printer(char board[][26], int n, struct solution sol_list[],
    int solution_number) {
    for (int i = 0; i < n; i++) {
        printf("     %c", 'a' + i);
    }
    printf("\n");
    printf("  ");
    for (int i = 0; i < n; i++) {
        printf(" _____");
    }
    printf("\n");
    // changing the pending pieces into (pending_solution)
    for (int i = 0; i < solution_number; i++) {
        board[sol_list[i].start_row][sol_list[i].start_col] = 'S';
    }
    for (int i = 0; i < n; i++) {
        printf("  |");
        for (int j = 0; j < n; j++) {
            printf("     |");
        }
        printf("\n");

        printf("%c |", 'a' + i);
        for (int j = 0; j < n; j++) {
            // the three cases: front, reverse, or empty.
            if (board[i][j] == 'F') {
                printf("%s", front);
            }
            if (board[i][j] == 'R') {
                printf("%s", reverse);
            }
            if (board[i][j] == 'U') {
                printf("%s", empty);
            }
            if (board[i][j] == 'S') {
                printf("%s", sol);
            }
            printf("|");
        }
        printf("\n  |");
        for (int i = 0; i < n; i++) {
            printf("_____|");
        }
        printf("\n");
    }
    // change back to normal.
        // changing the pending pieces into (pending_solution)
    for (int i = 0; i < solution_number; i++) {
        board[sol_list[i].start_row][sol_list[i].start_col] = 'U';
    }
}

// board_init(board, n) is used to create a board of dimension
// n * n with the center being filled.
void board_init(char board[26][26], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 'U';
        }
    }
    board[n / 2 - 1][n / 2 - 1] = 'F';
    board[n / 2][n / 2 - 1] = 'R';
    board[n / 2 - 1][n / 2] = 'R';
    board[n / 2][n / 2] = 'F';
}


// in_bound_check(n, row, col) returns true if the given point
// (row, col) is in the given bounds and false otherwise.
bool in_bound_check(int n, int row, int col) {
    return (row < n&& row >= 0) && (col < n&& col >= 0);
}


// find_solution_in_direction (board, n, row, col) returns true if 
// the given point (row, col) is a valid move on board, and
// if that's the case, record the destination point as a structrues
// in sol_num array.
bool find_solution_in_direction(char board[][26], int n, int row, int col,
    char colour, int deltaRow, int deltaCol, struct solution sol_list[676],
    int* sol_num) {
    bool condition = false;
    // if the current grid is not empty, terminates instantly.
    if (board[row][col] != 'U') {
        return false;
    }
    char reverse_colour = 0;
    // find the reverse colour.
    if (colour == 'F') {
        reverse_colour = 'R';
    } if (colour == 'R') {
        reverse_colour = 'F';
    }
    // find the adjcent colour of point (row, col)
    int x = row + deltaRow;
    int y = col + deltaCol;
    // the adjecent grid must be reverse colour and must in bound
    // otherwise, terminates instantly.
    if (!in_bound_check(n, x, y) || board[x][y] != reverse_colour) {
        return 0;
    }
    // search for rest part of the grid.
    x += deltaRow;
    y += deltaCol;
    for (int i = 0; i < n; i++) {
        // not in bound or empty, false.
        if (!in_bound_check(n, x, y) || board[x][y] == 'U') {
            return false;
        }
        // if find the same colour, record and save as solution.
        if (board[x][y] == colour) {
            sol_list[*sol_num].start_row = row;
            sol_list[*sol_num].start_col = col;
            sol_list[*sol_num].end_row = x;
            sol_list[*sol_num].end_col = y;
            sol_list[*sol_num].pos_row = deltaRow;
            sol_list[*sol_num].pos_col = deltaCol;
            (*sol_num)++;
            return true;
        }
        x += deltaRow;
        y += deltaCol;
    }
    return false;
}


int winning_decision(char board[][26], int n) {
    int r_count = 0;
    int f_count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 'R') {
                r_count++;
            }
            else if (board[i][j] == 'F') {
                f_count++;
            }
        }
    }
    if (f_count > r_count) {
        return 'F';
    }
    else if (f_count < r_count) {
        return 'R';
    }
    else {
        return 0;
    }
}


int main() {
    // board initilization.
    char board[26][26];
    int n = 0;
    printf("Enter the board dimension:  ");
    scanf("%d", &n);
    char character = 0;
    char row = 0;
    char column = 0;
    board_init(board, n);
    struct solution sol_list[676] = { 0 };
    int sol_num = 0;
    // record for both colour, each direction.
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // -1, 0, 1 are all just directions of the searching process.
            for (int row_dir = -1; row_dir < 2; row_dir++) {
                for (int col_dir = -1; col_dir < 2; col_dir++) {
                    if (row_dir == 0 && col_dir == 0) {
                        continue;
                    }
                    find_solution_in_direction(board, n, row, col,
                        'R', row_dir, col_dir, sol_list, &sol_num);
                }
            }
        }
    }
    // basic parameter, for this part, pos_row and pos_col should be minus
    // 'a' because it can converts character into the index for the board
    // dimension array. For exmaple, if row == a, then row - a equals 0.
    char basis = 'R';
    int pos_row = row - 'a';
    int pos_col = column - 'a';
    // if accmulating equals to 2, then the game should terminates because
    // that implies no move can be made.
    int accmulating = 0;
    // for the actual playing process of the game.
    bool valid = false;
    while (1) {
        // terminating condition: no moves can be made for both player.
        // in other words, accmulating == 2
        if (accmulating == 2) {
            break;
        }

        // if sol_num == 0; switch side instantly.
        if (sol_num == 0) {
            accmulating++;
            printf("switch side ***********************************************\n");
            if (basis == 'R') {
                basis = 'F';
            }
            else {
                basis = 'R';
            }
            // After this, recalculating the possible moves.
            // reset the solution list and solution number.
            sol_num = 0;
            for (int row = 0; row < n; row++) {
                for (int col = 0; col < n; col++) {
                    // -1, 0, 1 are all just directions of the searching process.
                    for (int row_dir = -1; row_dir < 2; row_dir++) {
                        for (int col_dir = -1; col_dir < 2; col_dir++) {
                            if (row_dir == 0 && col_dir == 0) {
                                continue;
                            }
                            find_solution_in_direction(board, n, row, col,
                                basis, row_dir, col_dir, sol_list, &sol_num);
                        }
                    }
                }
            }
            continue;
        }

        // the condition that breaks is when there are two CONSECUTIVE rounds
        // where no move can be made. If there's only one round, then reset
        // the accmulator.
        if (accmulating == 1) {
            accmulating = 0;
        }
        // print the board
        board_printer(board, n, sol_list, sol_num);
        if (basis == 'R') {
            printf("reverse side's move\n");
        }
        if (basis == 'F') {
            printf("front side's move:\n");
        }
        // Read two consecutive character, and break if input is invalid.
        if (scanf(" %c", &row) != 1) break;
        if (scanf(" %c", &column) != 1) break;
        // minus a is to convert a into 0, b into 1 etc.
        pos_row = row - 'a';
        pos_col = column - 'a';
        // before the testing, set valid parameter to false.
        valid = false;
        for (int i = 0; i < sol_num; i++) {
            if (sol_list[i].start_row == pos_row && sol_list[i].start_col == pos_col) {
                valid = true;
                // flip the current direction.
                while (pos_row != sol_list[i].end_row || pos_col != sol_list[i].end_col) {
                    board[pos_row][pos_col] = basis;
                    pos_row += sol_list[i].pos_row;
                    pos_col += sol_list[i].pos_col;
                }
                // flipping the basis (change the round)
                if (basis == 'R') {
                    basis = 'F';
                }
                else {
                    basis = 'R';
                }
                // Recalculating the possible moves.
                // reset the solution list and solution number.
                sol_num = 0;
                for (int row = 0; row < n; row++) {
                    for (int col = 0; col < n; col++) {
                        // -1, 0, 1 are all just directions of the searching process.
                        for (int row_dir = -1; row_dir < 2; row_dir++) {
                            for (int col_dir = -1; col_dir < 2; col_dir++) {
                                if (row_dir == 0 && col_dir == 0) {
                                    continue;
                                }
                                find_solution_in_direction(board, n, row, col,
                                    basis, row_dir, col_dir, sol_list, &sol_num);
                            }
                        }
                    }
                }
                // terminates, go to the next round.
                break;
            }
        }
        // otherwise, the user inputs an invalid move.
        if (!valid) {
            printf("Invalid move, please enter an valid move. \n");
        }
    }
    // to find who wins the game, simply count the current piece for each side.
    char winner = winning_decision(board, n);
    if (winner) {
        if (winner == 'F') {
            printf("Game over, Front side wins the game.\n");
        }
        else {
            printf("Game over, Reverse side wins the game.\n");
        }
        return 0;
    }
    printf("The game ends in tie.");
}
