#include <stdio.h>
#include <stdlib.h>

#define SIZE 5      // 5x5 grid
#define WIN_LEN 4   // need 4 in a row to win

// function prototypes
void setupBoard(char board[SIZE][SIZE]);
void printBoard(char board[SIZE][SIZE]);
int checkWin(char board[SIZE][SIZE], char player);
int isBoardFull(char board[SIZE][SIZE]);
void playerMove(char board[SIZE][SIZE], char player);

int main() {
    char board[SIZE][SIZE];
    char player = 'X';
    int won = 0, full = 0;

    setupBoard(board);

    while (!won && !full) {
        printBoard(board);
        playerMove(board, player);

        won = checkWin(board, player);
        if (won) {
            printBoard(board);
            printf("\n>>> Player %c wins! <<<\n\n", player);
            break;
        }

        full = isBoardFull(board);
        if (full) {
            printBoard(board);
            printf("\n>>> It's a draw! <<<\n\n");
            break;
        }

        // switch turns
        player = (player == 'X') ? 'O' : 'X';
    }

    return 0;
}

// fill board with '-'
void setupBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            board[i][j] = '-';
}

// show the board nicely
void printBoard(char board[SIZE][SIZE]) {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif

    printf("\n   === 5x5 TIC TAC TOE (4 in a row wins) ===\n\n");

    // print column headers
    printf("    ");
    for (int j = 0; j < SIZE; j++)
        printf("%d   ", j + 1);
    printf("\n   +---+---+---+---+---+\n");

    // print rows
    for (int i = 0; i < SIZE; i++) {
        printf(" %d |", i + 1);
        for (int j = 0; j < SIZE; j++)
            printf(" %c |", board[i][j]);
        printf("\n   +---+---+---+---+---+\n");
    }
    printf("\n");
}

// handle player's move and validate it
void playerMove(char board[SIZE][SIZE], char player) {
    int row, col;
    int moveOK = 0;

    while (!moveOK) {
        printf("Player %c, enter row and column (1-5): ", player);

        if (scanf("%d %d", &row, &col) != 2) {
            while (getchar() != '\n'); // clear bad input
            printf("Invalid input! Enter two numbers like 2 3.\n");
            continue;
        }

        row--; col--; // convert to 0-based index

        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE)
            printf("Out of range! Pick numbers between 1 and 5.\n");
        else if (board[row][col] != '-')
            printf("That spot’s taken! Try again.\n");
        else {
            board[row][col] = player;
            moveOK = 1;
        }
    }
}

// check if there are no empty spaces left
int isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == '-') return 0;
    return 1;
}

// check for 4-in-a-row in all directions
int checkWin(char board[SIZE][SIZE], char player) {
    int limit = SIZE - WIN_LEN;

    // horizontal
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j <= SIZE - WIN_LEN; j++) {
            int count = 0;
            for (int k = 0; k < WIN_LEN; k++)
                if (board[i][j + k] == player) count++;
            if (count == WIN_LEN) return 1;
        }

    // vertical
    for (int i = 0; i <= SIZE - WIN_LEN; i++)
        for (int j = 0; j < SIZE; j++) {
            int count = 0;
            for (int k = 0; k < WIN_LEN; k++)
                if (board[i + k][j] == player) count++;
            if (count == WIN_LEN) return 1;
        }

    // diagonal ↘
    for (int i = 0; i <= SIZE - WIN_LEN; i++)
        for (int j = 0; j <= SIZE - WIN_LEN; j++) {
            int count = 0;
            for (int k = 0; k < WIN_LEN; k++)
                if (board[i + k][j + k] == player) count++;
            if (count == WIN_LEN) return 1;
        }

    // diagonal ↗
    for (int i = WIN_LEN - 1; i < SIZE; i++)
        for (int j = 0; j <= SIZE - WIN_LEN; j++) {
            int count = 0;
            for (int k = 0; k < WIN_LEN; k++)
                if (board[i - k][j + k] == player) count++;
            if (count == WIN_LEN) return 1;
        }

    return 0;
}
