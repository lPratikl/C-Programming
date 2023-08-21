// Name: Tic Tac Toe Game 
// Difficulty: Intermediate -> Adavanced
// LOC: ~400 lines   

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>    
#include <ctype.h>
#include <time.h>          // srand(), rand()
#include <conio.h>         // getch()

#define TRUE 1
#define FALSE 0

void board(char x, char o, unsigned char *user, char *a);     // 2D Graphics on CLI
void board2(char x, char o, unsigned char *u1, unsigned char *u2, char *a);
void rules();                                                                    // Print rule page on CLI
int checkforwin(char *a);                                                        // Check wether a player has won 
bool decision(char *x, char *o, unsigned char *user);                            // Points player to mark X or O

void player1v1(char x, char o, unsigned char *u1, unsigned char *u2, char *a);    // Player vs Player 
void playermove(char x, char o, unsigned char *user);                             // Player vs Computer 
void computerMove(char x, char o, unsigned char *user, char *a);                  // Player vs Computer 


char a[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};                      // Initialize the elements of array in the boxes

FILE *ptr, *ptr2;


int main() { 
    char x, o, r;
    char user[50], u1[50], u2[50];
    int q, player_score, computer_score; 

    A:
    system("cls");                                            // cls: Clear console screem; windows 
    printf("\n[1] Player vs Player \n");                         // Displace options 
    printf("[2] Player vs Computer \n");
    printf("[3] LeaderBoards \n\n");
    printf("Enter choice: ");
    scanf("%d", &q);

    switch(q) {
        case 1:                                                 // Case 1: Two Player Game 
        printf("\nTwo Player Game \n");

        do {
            ptr = fopen("Score.txt", "a+");
            printf("Enter name of player 1: ");
            scanf("%s", u1);
            fprintf(ptr, "\n%s vs ", u1);                       // Store name of player 1 in 'Score.txt' file 
    
            printf("Enter name of player 2: ");
            scanf("%s", u2);
            fprintf(ptr, "%s", u2);                             // Store name of player 1 in 'Score.txt' file 
            fclose(ptr);
                                                                                           // Check if both player have differnet names;
            !strcmp(u1, u2) ? printf("Player names should be different! \n\n") : FALSE;    // strcmp() returns 0 if true 
        } while(!strcmp(u1, u2));                                                          // Run the do while loop until the player names are different. 
    
        decision(&x, &o, u1);                                 // Player 1 decides which symbol to play              
        
        do {
            board2(x, o, u1, u2, a);                          // Board for Two Player 
            player1v1(x, o , u1, u2, a);                      // Player vs Player 
            printf("Play Again? (y/n): ");                    
            scanf("%c", &r);
        } while(r == 'y');                                   // Play game until players input 'y' 
        break; 


        case 2:                                             // Case 2: Computer vs Player 
            ptr2 = fopen("Score.txt", "a+");
            printf("\nEnter player name: ");
            scanf("%s", user);
            fprintf(ptr2, "\nComputer vs %s ", user);      // Store player name in 'Score.txt' file 
            fclose(ptr2);
    
            decision(&x, &o, user);                        // Player decides which symbol to play 

            do {
                board(x, o, user, a);                     // Print the initial board 

                do {
                    playermove(x, o, user);              // Player makes the first move 
                    player_score = checkforwin(a);       // Check if player has won 
                    if (player_score == 1 || player_score == 0)  // Player_score == 1 --> Player wins 
                        break;                                   // Player_score == 0 --> Draw

                    computerMove(x, o, user, a);         // Computer's move 
                    computer_score = checkforwin(a);
                    if (computer_score == 1)             // Computer_score == 1 --> Computer wins 
                        break; 

                } while (player_score == -1 && computer_score == -1);   // player_score & computer_score == -1 --> No winner yet

                ptr2 = fopen("Score.txt", "a+");
            
                if (player_score == 1) {                                         // Exectue if Player wins 
                    printf("\n \t\t\t \033[1;32m You Win!!! \033[0m \n\n");      // [1;32m --> Green 
                    fprintf(ptr2, "\t\t WINNER -> %s", user);
                    getchar();
                } 
                else if (computer_score == 1) {                                  // Exectue if Computer wins 
                    printf("\n \t\t\t \033[1;33m You Lose!!! \033[0m \n\n");     // [1;33m --> Yello2 
                    fprintf(ptr2, "\t\t WINNER -> Computer");
                    getchar();
                } 
                else {
                    printf("\n \t\t Game Drawn! \n\n");                          // Exectue if Draw  
                    fprintf(ptr2, "\t\t %s", "DRAW");
                    getchar(); 
                }

                printf("Play again (y/n): ");                                   // Ask to play again
                scanf("%c", &r);

                a[0] = '1'; a[1] = '2'; a[2] = '3'; a[3] = '4'; a[4] = '5'; a[5] = '6'; a[6] = '7'; a[7] = '8'; a[8] ='9';

            } while (r == 'y');                             // Repat the loop as long as player inputs 'y
            break; 


        case 3:                                  // Case 3: Show leaderboard
            system("cls");
            printf("\n\n");
            printf("\t LEADERBOARD \n\n");
            char c;
            ptr = fopen("score.txt", "r");
                                                 
            while ((c=getc(ptr)) != EOF) {       // Case 3: Show leaderboard
                printf("%c", c);                 // EOF: End Of File 
            }                                    // get each character in 'Score.txt' file & print if one by one
            
            fclose(ptr);
            printf("\n\n"); 
            getchar();                           // Double getchar() <--> Only having one didn't work 
            getchar();
            goto A;                              // Go back to top (B --> Line 37) after viewing leaderboards 
            // break;

        default:                                 // Execute if user didn't input 1, 2 or 3, in the beginning.  
            printf("\n\n Hope to see you back soon! \n\n");
            getchar();
            break;             

    }         // End bracket of Swtich (q)

    return 0;
}


// Baord for Player vs Computer 
void board(char x, char o, unsigned char *user, char *a) {   
    system("cls"); 
    printf("\t\t\t Tic-Tac-Toe ---> Player vs Computer \n\n");
    printf("\t\t %s -> (%c) \t\t Computer -> (%c)\n\n", user, x, o);

    printf("\t\t\t  %c  |  %c |  %c \n", a[0], a[1], a[2]);
    printf("\t\t\t     |    |     \n");
    printf("\t\t\t ----|----|---- \n");
    printf("\t\t\t     |    |     \n");
    printf("\t\t\t  %c  |  %c |  %c \n", a[3], a[4], a[5]);
    printf("\t\t\t     |    |     \n");
    printf("\t\t\t ----|----|---- \n");
    printf("\t\t\t  %c  |  %c |  %c \n", a[6], a[7], a[8]);
    printf("\t\t\t     |    |     \n\n");
}


// Board for Player vs Player 
void board2(char x, char o, unsigned char *u1, unsigned char *u2, char *a) {   
    system("cls"); 
    printf("\t\t\t Tic-Tac Toe ----> Two Player \n\n");
    printf("\t\t %s -> (%c) \t\t %s -> (%c)\n\n", u1, x, u2, o);

    printf("\t\t\t ");
    for (int i=0; i<=2; i++) {                          // Row #1
        if (a[i] != 49+i) {
            if (a[i] == x)  
                printf("\033[1;32m %c \033[0m |", x);       // Green color if input is 'X'; 32m --> Green
            else if (a[i] == o) 
                printf("\033[1;33m %c \033[0m |", o);       // Yellow color if input is 'O'; 33m --> Yellow
        }
        else 
            printf("  %c |", a[i]);                     // Just print the number in a[i] otherwise 
        
    }

    printf("\b ");     // Backslash to remove in the ' |' after a[2] in box 3  
    printf("\n");
    printf("\t\t\t     |    |     \n");
    printf("\t\t\t ----|----|---- \n");
    printf("\t\t\t     |    |     \n");
    
    printf("\t\t\t ");
        for (int i=3; i<=5; i++) {                    // Row #2
        if (a[i] != 49+i) {
            if (a[i] == x)  
                printf("\033[1;32m %c \033[0m |", x);
            else if (a[i] == o) 
                printf("\033[1;33m %c \033[0m |", o);
        }
        else 
            printf("  %c |", a[i]);      
    }
    printf("\b \n");         // Backslash to remove in the ' |' after a[5] in box 6 
    printf("\t\t\t     |    |     \n");
    printf("\t\t\t ----|----|---- \n");
    printf("\t\t\t     |    |     \n");

    printf("\t\t\t ");
    for (int i=6; i<=8; i++) {            // Row #3
        if (a[i] != 49+i) {
            if (a[i] == x)  
                printf("\033[1;32m %c \033[0m |", x);
            else if (a[i] == o) 
                printf("\033[1;33m %c \033[0m |", o);
        }
        else 
            printf("  %c |", a[i]);
    }

    printf("\b \n");       // Backslash to remove in the ' |' after a[8] in box 9 
    printf("\t\t\t     |    |     \n\n");

}


// Check if the game has been won or not 
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


// Choose which sysmbol to play
bool decision(char *x, char *o, unsigned char *user) {
    char dec;
    printf("\n\n");
    do {
        printf("Player 1 -> %s -> Choose 'X' or 'O': ", user);
        dec=getchar();               // getchar(): Only takes a single input character from standard input.
        scanf("%c", &dec);
    } while(dec != 'X' && dec !='x' && dec != 'O' && dec !='o'); 

    if (dec == 'X' || dec == 'x') {    // If player 1 inputs 'x' or 'X', player 2 is 'O'.  
        *x = 'X';
        *o = 'O';
    } else {
        *x = 'O';
        *o = 'X';
    }

    return 1;

}

// Two Player Game
void player1v1(char x, char o, unsigned char *u1, unsigned char *u2, char *a) { 
    int player=1, choice, score;      // First move player 1. choice: Choose the box. score: check status of game 
    char symbol;                      // symbol: what symbol to put in each box after player input 

    do {
        player = ((player%2) ? 1 : 2);     // i=1: player=1 -> player%2 = 1 -> TRUE -> 1 -> player=1 
        if (player == 1) {                 // i=2: player=2 -> player%2 = 0 -> FALSE -> 2 -> player=2
            printf("\033[1;32m Type any digit from 1-9 to fill your response. -> %s (%c) -> \033[0m", u1, x);
        } else {
            printf("\033[1;33m Type any digit from 1-9 to fill your response. -> %s (%c) -> \033[0m", u2, o);
        }
        scanf("%d", &choice);              // Save player's response in 'choice' 
        symbol=((player==1) ? x : o);      // i=1: player=1 -> TRUE -> x -> symbol=x
                                           // i=2: player=2 -> FALSE -> 0 -> symbol=o 
        if (choice==1 && a[0] == '1')
            a[0] = symbol;
        else if (choice==2 && a[1]=='2')   // If 'choice' points to this box and it doesn't contain 'X' or 'O',  
            a[1] = symbol;                 //  then store response in the box.
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
            printf("\033[1;31m Wrong selection. Press any key to continue. \033[0m");   // Execute if 'choice' was a box, that was not empty. 
            getch(); 
            player--;                
        }
        
        score = checkforwin(a);        // check status of game, score = -1 -> still some box empty 
        player++;                      // i=1: player=1 -> player = 2; i=2: player=2 -> player=3
        board2(x, o, u1, u2, a);       // update the game board 
    
    } while (score == -1);            // Do while until game ends; score != -1. 
                                      // Reset the values of each box 
    a[0] = '1'; a[1] = '2'; a[2] = '3'; a[3] = '4'; a[4] = '5'; a[5] = '6'; a[6] = '7'; a[7] = '8'; a[8] ='9';

    ptr = fopen("Score.txt", "a+");
    
    if (score == 1) {                                     // score == 1 -> someone has won the game 
        if(player == 2) {                                 // After i=1, player=2 -> player 1 wins 
            printf("\n \t\t \033[1;32m Player 1 -> %s (%c) Wins!!! \033[0m \n\n", u1, x);
            fprintf(ptr, "\t\t WINNER -> %s", u1);        // Store the name of winner in 'Score.txt'  
            getchar(); 
        } else {                                          // If player != 2 -> player 2 wins 
            printf("\n \t\t \033[1;33m Player 2 -> %s (%c) Wins!!! \033[0m \n\n", u2, o);
            fprintf(ptr, "\t\t WINNER -> %s", u2);
            getchar();
        } 
        fclose(ptr);
    } else {                            // If score != 1, but game ends -> score=0 -> Draw. 
        printf("\n \t\t Game Drawn! \n\n"); 
        fprintf(ptr, "\t\t DRAW \n");
        getchar(); 
    }
}



// Player vs Computer
void playermove(char x, char o, unsigned char *user) { 
    int choice; 
    
     do {
        B: 
        printf("Type any digit from 1-9 to fill your respnse ->");
        printf("\033[1;32m %s (%c) -> \033[0m", user, x); 
        scanf("%d", &choice);                    // Save player's response in 'choice' 
        
        if (a[choice-1] == choice + 48) {        // ASCII 49 = 1, choice starts from 1. --> a[0] == '1' 
            a[choice-1] = x;                     // If 'choice' = 1 -> a[choice-1] = a[0] -> box #1 
        }                                        // Asign symbol in x to a[choice-1]
        else {
            printf("\033[1;31m Wrong selection. Press any key to continue. \033[0m");
            getch();                             // If (a[choice-1] != choice + 48) --> box is already filled. 
            printf("\n");
            goto B;                              // Jump back (A --> Line 354) to get another response 
        } 

    } while (a[choice-1] == choice + 48);        // Exit the loop after updating the box. 
    
    board(x, o, user, a);                        // Update the game board.   
}

void computerMove(char x, char o, unsigned char *user, char *a) {
    int i;                           
    srand(time(0));                  // srand(time(0)) --> initialize a different seed of random every time 
                                     // the code runs to get a different random result      
    do {                             // rand() usually return the smae results in each run -> Use srand() 
        i = rand()%9;                // Min= 0, Max = 8 -> %9, ASCII 49 = 1. a[0] = '1' 
    } while (a[i] != i+49);          // Do not exit when a non-empty box is selected. 

    a[i] = o;                        // Store symbol of 'o' in the randomly selected empty box.  

    board(x, o, user, a);            // Update the game board 
}


// Rules of the game 
// void rules() {
//     char link;
//     printf("\n\n\n\t Tic-Tac-Toe --- Welcome to this fun game \n\n");              // Display a welcome page and info on how to play. 
//     printf("Rules: \n");
//     printf("1. Each player enters respective 'X' or 'O' in the desire position. \n");
//     printf("2. Player who makes a full verical, horizontal or diagonal line wins. \n\n");
//     printf("Press 'Y' for more clarification. Type any other character to play: ");
//     scanf("%c", &link);

//     if (link == 'y' || link == 'Y') {
//         if (OS == "nt")                              // If user needs more clarification, open the link on how to play Tic-Tac-Toe. 
//             system("start http://www.wikihow.com/Play-Tic-Tac-Toe");
//         if (OS == "posix")
//             system("firefox http://www.wikihow.com/Play-Tic-Tac-Toe");
//     }
// }


// Difficult
// void computer(char x, char o, char *a) {
//     int player = 1;
//     char user[50];
//     int choice, score = -1;
//     char symbol, re;
//     char start, dec;
//     int s; 

//     do {
//         printf("Type any digit from 1-9 to select the box.  ");
//         scanf("%d", &choice);
//         // symbol = ((player==1) ? x : o);

//         // if (choice==5 && a[4]=='5') {
//         //     a[4] = x; 
//         //     a[2] = o;
//         //     printf("Type any digit from 1-9 to select the box.  ");
//         //     scanf("%d", &choice);
//         // }

//         // if (choice==2 && a[1]=='2') {
//         //         a[1] = x;
//         //         a[7] = o;
//         // }

//         switch(choice) {
//             case 5:
//                 if (a[4]=='5') {
//                     a[4] = x; 
//                     a[2] = o;
//                     break;
//                 }
//             case 2: 
//                 if (a[1]=='2' && a[4] == x) {
//                     a[1] = x; a[7] = o; break; }
//                 if (a[1]=='2' && a[4] == '5') { 
//                      a[1] = x; a[4] = o; break; }

//             case 4: 
//                 if (a[3] == '4' && a[4] !='5') {
//                     a[3] = x;
//                     a[5] = o;  
//                     break;    
//                 }
//             case 1: 
//                 if (a[0] == '1' && a[3] != '3') {
//                     a[0] = x; a[6] = o;
//                     break; 
//                 }
//             default: 
//                 printf("Type from 1-9");
//                 break;
//         }

//         score = checkforwin(a);
//         board(x, o, user, a); 
//     } while(score == -1);
// }


/*
Glossary 


# Print text in Color 
    printf("\033[1;31m <Text> \033[0m\n");

'\033' -> Escape character, '[1;<color code>m' -> Set text color, "\033[1;0m" -> Reset color back to normal.

Black: 30     Yellow: 33    Cyan: 36
Red: 31       Blue: 34      White: 37
Green: 32     Magenta: 35   Reset: 0

*/
