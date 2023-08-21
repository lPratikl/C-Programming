// Project name: Tic-Tac-Toe 
// Difficulty: Intermediate 
// Credit: mishal23, https://www.interviewbit.com/blog/c-projects/
// Source: https://github.com/mishal23/Tic-Tac-Toe


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#ifdef _WIN32                                   // #ifdef is a directive that allows conditional compilation 
    #define OS "nt"                             // USeful for checking whether a defintion exits 
#elif __unix__
    #define OS "posix"
#endif 

#define TRUE 1
#define FALSE 0 

void board(char x, char o, unsigned char *u1, unsigned char *u2, char *a);     // 2D Graphics on CLI
void rules();                                                                  // Print rule page on CLI
int checkforwin(char *a);                                                      // Check wether a player has won 
bool decision(char *x, char *o, unsigned char *u1);                            // Points player to mark X or O

int main() {
    FILE *ptr;
    char x, o;
    ptr = fopen("score.txt", "a+");                                 // "a+": open file in both read & write mode 
    fclose(ptr);
    
    char a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    char u1[50], u2[50];                                          // u1: Player 1, u2: Player 2 
    int player = 1;
    int choice, score = -1;
    char symbol, re;
    char start, dec;
    int y;

    if (OS == "nt")
        system ("color 04");
        rules();
        printf("\n\n Type '1' to start start the game. \n Type '2' to view leader board. \n Enter: ");
        scanf("%d", &y);

        switch(y) {
            case 1: 
                do {
                    ptr=fopen("score.txt", "a+");
                    printf("\nEnter name of player 1:  ");
                    scanf("%s", u1);
                    fprintf(ptr, "\n%s", u1); 
                    printf("Enter name of player 2: ");
                    scanf("%s", u2);
                    fprintf(ptr, "\t %s", u2);
                    fclose(ptr);
                    !strcmp(u1, u2) ? printf("Player names should be different! \n\n") : FALSE;
                } while(!strcmp(u1, u2));        // Run the do while loop until the player names are different. 

                decision(&x, &o, u1);
                if (OS == "nt")
                    system("color A7");           //"Color XY": X is for Background, Y is for Text. 
                
                board(x, o, u1, u2, a);

                do {
                    player = ((player%2) ? 1 : 2);
                    if (player == 1) {
                        system("color A4");
                        printf("Type any digit from 1-9 to fill your respnse -> %s  ", u1);
                    } else {
                        system("color A5");
                        printf("Type any digift from 1-9 to fill you response. -> %s", u2);
                    }
                    scanf("%d", &choice); 

                    symbol=((player==1) ? x : o);
                    if (choice==1 && a[0] == '1')
                        a[0] = symbol;
                    else if (choice==2 && a[1]=='2')
                        a[1] = symbol;
                    else if (choice==3 && a[2]=='3')
                        a[2] = symbol;
                    else if (choice==4 && a[3]=='4')
                        a[3] = symbol;
                    else if (choice==5 && a[4]=='5')
                        a[4] = symbol;
                    else if (choice==6 && a[5]=='6')
                        a[5] = symbol;
                    else if (choice==7 && a[6]=='7')
                        a[6] = symbol;
                    else if (choice==8 && a[7]=='8')
                        a[7] = symbol;
                    else if (choice==9 && a[8]=='9')
                        a[8] = symbol;
                    else {
                        printf("Wrong selection \n");
                        player--;
                    }
                    score = checkforwin(a);
                    player++;
                    board(x, o, u1, u2, a);
                } while (score == -1);                       // Do while until game ends; score != -1. 

                ptr = fopen("score.txt", "a+");
                if (score == 1) {
                    if(player==2) {
                        printf("\n\n Player 1 -> %s Wins!!! \n", u1);
                        fprintf(ptr, "\t\t Winner -> %s", u1);
                        getchar();
                    } else {
                        printf("\n\n Player 2 -> Wins!!! \n", u2);
                        fprintf(ptr, "\t\t Winner -> %s", u2);
                        getchar();
                    } 
                    fclose(ptr);
                } else {
                    printf("\n\n Game Drawn! \n\n"); 
                    fprintf(ptr, "\t\t %s", "DRAW");
                    getchar(); 
                }
                break;

            case 2:
                if (OS == "nt")
                    system("cls");
                if (OS == "posix")
                    system("clear");
                printf("\n\n");
                printf("\t LEADERBOARD \n\n");
                char c;
                ptr=fopen("score.txt", "r");
                while ((c=getc(ptr)) != EOF) {
                    printf("%c", c);
                }                   
                fclose(ptr);
                getchar();
                break;

            default:
                printf("\n\n Type 1 to play the game!\n Hope to see you back soon! \n\n");
                getchar();
                break;         
        }           

    return 0;
}

int checkforwin(char *a) {
    if (a[0] == a[1] && a[1]==a[2])       // Row #1
        return 1;
    else if (a[3]==a[4] && a[4]==a[5])    // Row #2
        return 1;
    else if (a[6]==a[7] && a[7]==a[8])    // Row #3
        return 1;
    else if (a[0]==a[3] && a[3]==a[6])    // Column #1
        return 1;
    else if (a[1]==a[4] && a[4]==a[7])    // Column #2
        return 1;
    else if (a[2]==a[5] && a[5]==a[8])    // Column #3
        return 1;
    else if (a[0]==a[4] && a[4]==a[8])    // Diagonal L->R
        return 1;
    else if (a[2]==a[4] && a[4]==a[6])    // Diagonal R->L
        return 1;
    else if (a[0] != '1' && a[1] != '2' && a[2] != '3' && a[3] != '4' && a[4] != '5' && a[5] !='6'&& 
             a[6] != '7' && a[7] != '8' && a[8] != '9')      // If all boxes occupied, but no winner, return 0. 
        return 0;
    else 
        return -1;

}

bool decision(char *x, char *o, unsigned char *u1) {
    char dec;
    printf("\n\n");
    do {
        printf("Player 1 -> %s. Choose 'X' or 'O' :", u1);
        dec=getchar();               // getchar(): Only takes a single input character from standard input.
        scanf("%c", &dec);
    } while(dec != 'X' && dec !='x' && dec != 'O' && dec !='o'); 

    if (dec == 'X' || dec == 'x') {
        *x = 'X';
        *o = 'O';
    } else {
        *x = 'O';
        *o = 'X';
    }

    return 1;

}



void board(char x, char o, unsigned char *u1, unsigned char *u2, char *a) {
    int i;
    if (OS == "nt")
        system("cls");                    // 'int system(const char *command)' passes the 'command' name to the host environment & the command processor excutes it.
    if (OS == "posix")                     // cls: clear screen command for CLI
        system("clear");
    
    printf("\t Tic-Tac-Toe \n\n");
    printf("%s -> (%c) \t\t %s -> (%c)\n\n\n", u1, x, u2, o);

    printf(" %c  |  %c |  %c \n", a[0], a[1], a[2]);
    printf("    |    |     \n");
    printf("----|----|---- \n");
    printf("    |    |     \n");
    printf(" %c  |  %c |  %c \n", a[3], a[4], a[5]);
    printf("    |    |     \n");
    printf("----|----|---- \n");
    printf(" %c  |  %c |  %c \n", a[6], a[7], a[8]);
    printf("    |    |     \n");
}

void rules() {
    char link;
    printf("\n\n\n\t Tic-Tac-Toe --- Welcome to this fun game \n\n");              // Display a welcome page and info on how to play. 
    printf("Rules: \n");
    printf("1. Each player enters respective 'X' or 'O' in the desire position. \n");
    printf("2. Player who makes a full verical, horizontal or diagonal line wins. \n\n");
    printf("Press 'Y' for more clarification. Type any other character to play: ");
    scanf("%c", &link);

    if (link == 'y' || link == 'Y') {
        if (OS == "nt")                              // If user needs more clarification, open the link on how to play Tic-Tac-Toe. 
            system("start http://www.wikihow.com/Play-Tic-Tac-Toe");
        if (OS == "posix")
            system("firefox http://www.wikihow.com/Play-Tic-Tac-Toe");
    }
}



/* Glossary
CLI: Command Line Interface  

Colour code
0 = Black    4 = Red       8 = Gray           C = Light Red
1 = Blue     5 = Purple    9 = Light Blue     D = Light Purple
2 = Green    6 = Yellow    A = Light Green    E = Light Yellow
3 = Aqua     7 = White     B = Light Aqua     F = Bright White
   
     
   
    
*/
