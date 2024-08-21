#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = 'X';
const char COMPUTER = 'O';

void resetBoard();
void printBoard();
int checkFreeSpace();
void playerMove();
void ComputerMove();
char checkWinner();
void printWinner(char);

int main(void) {
    char winner = ' ';
    char response;

    do {
        winner = ' ';
        response = ' ';
        resetBoard();
        while(winner == ' ' && checkFreeSpace() != 0) {
            printBoard();
            playerMove();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpace() == 0) {
                break;
            }
            ComputerMove();
            winner = checkWinner();
            if(winner != ' ' || checkFreeSpace() == 0) {
                break;
            }
        }
        printBoard();
        printWinner(winner);

        printf("\nWould you like to play again? (Y/N): ");
        scanf("%c");
        scanf("%c", &response);
        response = toupper(response);
    } while(response == 'Y');

    printf("Thank you to play my game");

    return 0;
}

void resetBoard(){
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}
void printBoard(){
    printf(" %c | %c | %c", board[0][0], board[0][1], board[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c", board[1][0], board[1][1], board[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c", board[2][0], board[2][1], board[2][2]);
    printf("\n");

}
int checkFreeSpace(){
    int freeSpace = 9;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] != ' ') {
                freeSpace--;
            }
        }
    }
    return freeSpace;
}
void playerMove(){
    int x, y;
    do {
        printf("Enter row# (1-3): ");
        scanf("%d", &x);
        x--;
        printf("Enter column# (1-3): ");
        scanf("%d", &y);
        y--;

        if(board[x][y] != ' ') {
            printf("Invalid move! \n");
        }
        else {
            board[x][y] = PLAYER;
            break;
        }
    } while (board[x][y] != ' ');
}
void ComputerMove(){
    srand(time(0));
    int x, y;
    if(checkFreeSpace() > 0) {
        do {
            x = rand() % 3;
            y = rand() % 3;
        } while (board[x][y] != ' ');
        board[x][y] = COMPUTER;
    } else {
        printWinner(' ');
    }
}
char checkWinner(){
    for(int i = 0; i < 3; i++) {
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]) {
            return board[i][0];
        }
        if(board[0][0] == board[1][1] && board[0][0] == board[2][i]) {
        return board[0][0];
        }
    }
    return ' ';
}
void printWinner(char winner){
    if(winner == PLAYER) {
        printf("YOU WIN!");
    } else if(winner == COMPUTER) {
        printf("YOU LOSE");
    } else {
        printf("DRAW");
    }
}
