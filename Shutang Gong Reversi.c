// This program is a simulation for reversi game using the terminal and
// standard I/O.
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// solution is a structures for recording the solutions for certain point.
struct solution {
    int start_row;
    int start_col;
    int end_row;
    int end_col;
    int pos_row;
    int pos_col;
};

// printBoard (board, n) is used to print the reversi board of dimension
// n * n on terminal.
void printBoard(char board[][26], int n) {
    printf("  ");
    for (int i = 0; i < n; i++) {
        printf("%c", 'a' + i);
    }
    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%c ", 'a' + i);
        for (int j = 0; j < n; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

// createBoard(board, n) is used to create a board of dimension
// n * n with the center being filled.
void createBoard(char board[26][26], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            board[i][j] = 'U';
        }
    }
    board[n / 2 - 1][n / 2 - 1] = 'W';
    board[n / 2][n / 2 - 1] = 'B';
    board[n / 2 - 1][n / 2] = 'B';
    board[n / 2][n / 2] = 'W';
}

// positionInBounds(n, row, col) returns true if the given point
// (row, col) is in the given bounds and false otherwise.
bool positionInBounds(int n, int row, int col) {
    return (row < n&& row >= 0) && (col < n&& col >= 0);
}

// recordLegalInDirection (board, n, row, col) returns true if 
// the given point (row, col) is a valid move on board, and
// if that's the case, record the destination point as a structrues
// in sol_num array.
bool recordLegalInDirection(char board[][26], int n, int row, int col,
    char colour, int deltaRow, int deltaCol, struct solution sol_list[676],
    int* sol_num) {
    bool condition = false;
    // if the current grid is not empty, terminates instantly.
    if (board[row][col] != 'U') {
        return false;
    }
    char reverse_colour = 0;
    // find the reverse colour.
    if (colour == 'W') {
        reverse_colour = 'B';
    }
    if (colour == 'B') {
        reverse_colour = 'W';
    }
    // find the adjcent colour of point (row, col)
    int x = row + deltaRow;
    int y = col + deltaCol;
    // the adjecent grid must be reverse colour and must in bound
    // otherwise, terminates instantly.
    if (!positionInBounds(n, x, y) || board[x][y] != reverse_colour) {
        return 0;
    }
    // search for rest part of the grid.
    x += deltaRow;
    y += deltaCol;
    for (int i = 0; i < n; i++) {
        // not in bound or empty, false.
        if (!positionInBounds(n, x, y) || board[x][y] == 'U') {
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

int main() {
    // board initilization.
    char board[26][26];
    int n = 0;
    printf("Enter the board dimension:  ");
    scanf("%d", &n);
    createBoard(board, n);
    printBoard(board, n);
    printf("Enter board configuration:\n");
    char character = 0;
    char row = 0;
    char column = 0;
    while (character != '!') {
        if (scanf(" %c", &character) != 1) break;
        if (scanf(" %c", &row) != 1) break;
        if (scanf(" %c", &column) != 1) break;
        board[row - 'a'][column - 'a'] = character;
    }
    printBoard(board, n);
    // finding available moves while record in sol_list.
    struct solution sol_list_w[676] = { 0 };
    struct solution sol_list_b[676] = { 0 };
    int sol_num_w = 0;
    int sol_num_b = 0;
    // record for both colour, each direction.
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            // -1, 0, 1 are all just directions of the searching process.
            for (int row_dir = -1; row_dir < 2; row_dir++) {
                for (int col_dir = -1; col_dir < 2; col_dir++) {
                    if (row_dir == 0 && col_dir == 0) {
                        continue;
                    }
                    recordLegalInDirection(board, n, row, col,
                        'W', row_dir, col_dir, sol_list_w, &sol_num_w);
                    recordLegalInDirection(board, n, row, col,
                        'B', row_dir, col_dir, sol_list_b, &sol_num_b);
                }
            }
        }
    }
    // basic parameter
    char basis = 'B';
    int pos_row = row - 'a';
    int pos_col = column - 'a';
    // for the actual playing process of the game.
    bool valid = false;
    while (1) {
        basis = 'B';
        if (scanf(" %c", &character) != 1) break;
        if (scanf(" %c", &row) != 1) break;
        if (scanf(" %c", &column) !=1) break;
        pos_row = row - 'a';
        pos_col = column - 'a';
        valid = false;
        if (character == 'W') {
            for (int i = 0; i < sol_num_w; i++) {
                if (sol_list_w[i].start_row == pos_row && sol_list_w[i].start_col == pos_col &&
                    basis == 'W') {
                    valid = true;
                    basis = 'B';
                    // flip the current direction.
                    while (pos_row != sol_list_w[i].end_row || pos_col != sol_list_w[i].end_col) {
                        board[pos_row][pos_col] = character;
                        pos_row += sol_list_w[i].pos_row;
                        pos_col += sol_list_w[i].pos_col;
                    }
                }
            }
            if (valid) {
                printBoard(board, n);
            }
        }
        if (character == 'B') {
            for (int i = 0; i < sol_num_w; i++) {
                if (sol_list_b[i].start_row == pos_row && sol_list_b[i].start_col == pos_col && 
                    basis == 'B') {
                    valid = true;
                    basis = 'W';
                    // flip the current direction.
                    while (pos_row != sol_list_b[i].end_row || pos_col != sol_list_b[i].end_col) {
                        board[pos_row][pos_col] = character;
                        pos_row += sol_list_b[i].pos_row;
                        pos_col += sol_list_b[i].pos_col;
                    }
                }
            }
            if (valid) {
                printBoard(board, n);
            }
        }
        if (!valid) {
            printf("Invalid move.\n");
            printBoard(board, n);
            return 0;
        }
    }
}