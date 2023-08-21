#include <stdio.h>
#include <stdlib.h>
#include <ctype.h> 
#include <time.h>
#include <conio.h>

char board[3][3]; 
// const char Player = 'X';
char Player = 'X'; 
const char Computer = 'O';

int i, j;

void resetBoard();
void printBoard();
int checkFreeSpaces();
void playerMove();
void computerMove();
char checkWinner();
void printWinner(char);

int main() {
    char winner = ' ';
    char response = ' ';

    do {
        winner = ' ';
        response = 'y';
        resetBoard(); 

        while (winner == ' ' && checkFreeSpaces() != 0) {
            printBoard(); 

            playerMove();
            winner = checkWinner(); 

            if(winner != ' ' || checkFreeSpaces() == 0)
                break;
            
            computerMove();
            winner = checkWinner();

            if(winner != ' ' || checkFreeSpaces() == 0)
                break;
        }

        printBoard();
        printWinner(winner); 
        getch();

        printf("Exit? (y/n) ");
        scanf("%c", response);

    } while (response != 'y');

    printf("Thnaks for playing!");

    return 0;
}

void resetBoard() {
    for (int i=0; i<3; i++) {
        for (int j=0; j<3; j++) {
            board[i][j] = ' ';
        }
    }
}


void printBoard() {
    printf(" %c  |  %c |  %c \n", board[0][0], board[0][1], board[0][2]);
    printf("    |    |     \n");
    printf("----|----|---- \n");
    printf("    |    |     \n");
    printf(" %c  |  %c |  %c \n", board[1][0], board[1][1], board[1][2]);
    printf("    |    |     \n");
    printf("----|----|---- \n");
    printf(" %c  |  %c |  %c \n", board[2][0], board[2][1], board[2][2]);
    printf("    |    |     \n");
}


int checkFreeSpaces() {
    int freeSpaces = 9;

    for (i=0; i<3; i++) {
        for (j=0; j<3; j++) {
            if (board[i][j] != ' ')
                freeSpaces--;
        }
    } 

    return freeSpaces;
}


void playerMove() {
    int x, y;

    do {
        printf("Enter row: ");
        scanf("%d", &x); 
        x--;    //If x=1, it refers to the first row (row 0). 

        printf(" Enter column: "); 
        scanf("%d", &y); 
        y--;

        if (board[x][y] != ' ') {
            printf("\033[1;31m Invalid move! \033[0m \n");
            printf("\033[1;31m"); 
            printf("Invalid move! "); 
            printf("\033[0m \n");
        }
        else {
            board[x][y] = Player; 
            break; 
        }
    } while (board[x][y] != ' ');
}


void computerMove() {
    srand(time(0));      // Creats a seed based on current time 
    int x, y; 

    if (checkFreeSpaces() > 0) {
        do {
            x = rand() % 3;      // Create a random from 0, 1, 2 
            x = rand() % 3; 
        
        } while (board[x][y] != ' '); 
 
        board[x][y] = Computer; 
    }
    else 
        printWinner(' '); 
}


char checkWinner() {
    for (i=0; i<3; i++) {             // Check rows 
        if (board[i][0] == board[i][1] && board[i][0] == board[i][2]) 
            return board[i][0]; 
    }

    for (i=0; i<3; i++) {             // Check columns
        if (board[0][i] == board[1][i] && board[0][i] == board[2][i]) 
            return board[0][i];   // Return the symbol in board[0][i] to determine winner  
    }

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) 
            return board[0][0];   // Return the symbol in board[0][0] 
    else if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) 
            return board[0][2];   // Return the symbol in board[0][2]  
    
    return ' ';        
}


void printWinner(char winner) {
    if (winner == Player) 
        printf("\033[1;32m You Win!!! \033[0m \n"); 
    
    else if (winner == Computer)
        printf("\033[1;34m You Lose!!! \033[0m \n"); 

    else 
        printf("\033[1;33m It's a Tie!!! \033[0m \n"); 
}