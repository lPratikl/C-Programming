// Snakes & Ladder 
// Difficulty: Advanced


// Rules of Game
/* 
1. Press '1' for player 1 turn, '2' for player 2 turn , '0' to exit. 
2. First player to reach 100 wins. 
3. If a player rolls '6', they get one more turn. 
4. Snakes: 99->1,  65->40, 25->9;  If a player lands on 99, then go back to 1.  
5. Ladder: 70->93, 60->83, 13->42; If a player lands on 70, climb to 93. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include <conio.h>

int rd(); 
void displaychart(int curp1, int curp2, char player1[4], char player2[4]);

void main() {
    int i, dice, cur_pos1=0, cur_pos2=0;             
    int old_pos1, old_pos2;                          
    char ch;

    while(1) {
        printf("\n         *** SNAKE & LADDER GAME *** \n\n");                                   // First Page 
        printf("Snakes 🐍: \t 25-->9,\t 65-->40, \t 99-->1 \n");                                 // 🐍
        printf("Ladder %s: \t 70-->93, \t 60-->83, \t 13-->42 \n\n", "\U0001fa9c");              // \U0001fa9c: Ladder 
        printf("\033[1;32m[1] Player 1 plays \033[0m  \t");           
        printf("\033[1;33m[2] Player 2 plays \033[0m  \t");   
        printf("[0] Exit \n");
        scanf("%s", &ch);

        switch(ch) {

            case '1': 
                system("cls");
                dice =rd();                           // Player 1 rolls the dice 
                old_pos1 = cur_pos1;                  // old_pos1: store old position of player 1
                cur_pos1 += dice;                     // cur_pos1 = dice + cur_pos1, new postion after dice rolled 

                if(cur_pos1<101) {                     // For snakes & ladders 
                    if(cur_pos1==99)  {
                        displaychart(1, cur_pos2, "$P1$", "^P2^");          // Snake: 99->1
                        printf("\033[1;31m Snaked: 99 --> 1 \033[0m \n");   // Display msg to show change 
                        cur_pos1 = 1;                                       // Update new postions of after change                
                    } 
                    else if(cur_pos1==65) {
                        displaychart(40, cur_pos2, "$P1$", "^P2^");         // Snake: 65->40
                        printf("\033[1;31m Snaked: 65 --> 40 \033[0m \n");
                        cur_pos1 = 40; 
                    }
                    else if(cur_pos1==25) {
                        displaychart(9, cur_pos2, "$P1$", "^P2^");          // Snake: 25->9
                        printf("\033[1;31m Snaked: 25 --> 9 \033[0m \n");
                        cur_pos1 = 9; 
                    }
                    else if (cur_pos1==70) {
                        displaychart(93, cur_pos2, "$P1$", "^P2^");         // Ladder: 70->93
                        printf("\033[1;36m Climb Up: 70 --> 93 \033[0m \n");
                        cur_pos1 = 93; 
                    }
                    else if (cur_pos1==60) {
                        displaychart(83, cur_pos2, "$P1$", "^P2^");         // Ladder: 60->83
                        printf("\033[1;36m Climb Up: 60 --> 83 \033[0m \n");
                        cur_pos1 = 83; 
                    }
                    else if (cur_pos1==13) {
                        displaychart(42, cur_pos2, "$P1$", "^P2^");         // Ladder: 13->42
                        printf("\033[1;36m Climb Up: 13 --> 42 \033[0m \n");
                        cur_pos1 = 42; 
                    }
                    else {
                        displaychart(cur_pos1, cur_pos2, "$P1$", "^P2^");    // Update board normally if no snakes or ladders 
                    }
                    
                }
                else {
                    cur_pos1-=dice;                               // cur_pos1= cur_pos1-dice
                    printf("Range exceeded of Player 1. \n");     // Move back if final position is >100. 
                     displaychart(cur_pos1, cur_pos2, "$P1$", "^P2^");   
                }

                printf("\033[1;32m Player 1 Dice = %d \033[0m \t", dice);    // Show value of dice rolled 

                if(dice==6) {                                                // One more turn if rolled '6'
                    printf("Player 1: %d --> %d \t", old_pos1, cur_pos1); 
                    printf("\033[1;32m Player 1 Roll Again!!! \033[0m \n");
                }
                else {
                    printf("Player 1: %d --> %d \t", old_pos1, cur_pos1);     // Show old & new postion of player 
                    printf("\033[1;33m Player 2 Turn:  %d --> \033[0m \n", cur_pos2);    
                }    

                break;

            case '2': dice=rd(); 
                system("cls");
                
                old_pos2 = cur_pos2;                 // old_pos2: store previous position of player 2 
                cur_pos2 += dice;                    // cur_pos2 = dice + cur_pos2, new position after dice rolled 

                if(cur_pos2<101){
                    if(cur_pos2==99) {
                        displaychart(cur_pos1, 1, "$P1$", "^P2^");          // Snake: 99->1
                        printf("\033[1;31m Snaked: 99 --> 1 \033[0m \n");
                        cur_pos2 = 1;                                       // Update new position 
                    }
                    else if(cur_pos2==65) {
                        displaychart(cur_pos1, 40, "$P1$", "^P2^");         // Snake: 65->40
                        printf("\033[1;31m Snaked: 65 --> 49 \033[0m \n");
                        cur_pos2 = 40;
                    }
                    else if(cur_pos2==25) {
                        displaychart(cur_pos1, 9, "$P1$", "^P2^");          // Snake: 25->9
                        printf("\033[1;31m Snaked: 99 --> 1 \033[0m \n");
                        cur_pos2 = 9;
                    }
                    else if (cur_pos2==70) {
                        displaychart(cur_pos1, 93, "$P1$", "^P2^");          // Ladder: 70->93
                        printf("\033[1;36m Climb Up: 70 --> 93 \033[0m \n");
                        cur_pos2 = 93;
                    }
                    else if (cur_pos2==60) {
                        displaychart(cur_pos1, 83, "$P1$", "^P2^");          // Ladder: 60->83
                        printf("\033[1;36m Climb Up: 60 --> 83 \033[0m \n");
                        cur_pos2 = 83;
                    }
                    else if (cur_pos2==13) {
                        displaychart(cur_pos1, 42, "$P1$", "^P2^");         // Ladder: 13->42
                        printf("\033[1;36m Climb Up: 13 --> 42 \033[0m \n");
                        cur_pos2 = 42;
                    }
                    else {
                         displaychart(cur_pos1, cur_pos2, "$P1$", "^P2^");   // Show current position of player     
                    }
                    
                }
                else {
                    cur_pos2-=dice;                             // cur_pos2 = cur_pos2 - dice
                    printf("Range exceeded of Player 2. \n");   // Move back if final position is >100. 
                     displaychart(cur_pos1, cur_pos2, "$P1$", "^P2^");    
                }

                printf("\033[1;33m Player 2 Dice = %d \033[0m \t", dice); 

                if(dice==6) {
                    printf("Player 2: %d --> %d \t", old_pos1, cur_pos1); 
                    printf("\033[1;33m Player 2 Roll Again!!! \033[0m \n");
                }           
                else {                    
                    printf("Player 2: %d --> %d \t", old_pos2, cur_pos2); 
                    printf("\033[1;32m Player 1 Turn: %d --> \033[0m \n", cur_pos1);      
                }

                break;
            
            case '0': exit(0);                        // Exit game if '0' pressed 
                break; 

            default: printf("\033[1;31m Incorrect choice. Try Again  \033[0m");   // Execute when input is invalid 
                     getch(); 

        }
    }
}


// Create a random number for dice 
int rd() {
    int rem;
    srand(time(0));             // Increases randomness of rand()
    rem = rand()%6 + 1;         // Min=0, Max=5 -> %6 
    return rem;
}


// Display the game board with current poisitons of each player 
void displaychart(int curp1, int curp2, char player1[4], char player2[4]) {
    int i, j, t, c, sft=0;           // curp: current poisition on the board, diceres: dice result 
    int diceres, pos1, pos2;

    system("cls");
    if (curp1==100 || curp2 == 100) {        // If any player reaches 100, game ends 
        printf("*****Congratulations******\n\n\n Player %s Wins!!!\n", curp1==100 ? player1 : player2);
        scanf("%*s");
        exit(0);
    }

// Print the board 
    for (i=10; i>0; i--) {                            // Start from top to bottom, Row: 100, 80, 60, 40, 20, 10
        t=i-1;                                        // for i = 10, 8, 6, 4, 2
        if ((sft%2)==0) {                             // ite=1, stf=0; i=10, j=10, t=9, c=0,  --> diceres=100         ite=3, stf=2; i=8, j=10, t=7, c=0, --> diceres=80
            c=0;                                      //               i=10, t=9, t=9,  c=1 --> diceres=99                          i=8, j=9, t=7, c=1 --> diceres=79 
            for (j=10; j>=1; j--) {                                                                                   //            i=8, j=8, t=7, c=2 --> diceres=78
                diceres = (i*j)+(t*c++);             // c++: First, use the value of c. Then increment of c                                 .
                                                     // i=10, j=10, t=9, c=0 --> diceres=100 --> c=1                                        .
                if(curp1==diceres)                                                                                    //            i=8, j=1, t=7, c=9 --> diceres=71
                    printf("\033[1;32m %s \033[0m\t", player1);        // 32m --> Green --> Player 1
                else if(curp2==diceres)                                                                               // ite=5, stf=4; diceres = 60->51             
                    printf("\033[1;33m %s \033[0m\t", player2);        // 33m --> Yellow --> Player 2                 // ite=7, stf=6; diceres = 40->31    
                else 
                    printf(" %d \t", diceres);                 // Print remaining number for rows 100, 80, 60, 40, 20, 10   
            }
            sft++;                                             // sft=0 -> sft=1
        } 
        else {                                                 // for i = 9, 7, 5, 3, 1
            c=9;                                               // Row: 81, 61, 41, 21, 1
                                                               
            for (j=1; j<=10; j++) {                            // ite=2, sft=1; i=9, j=1, t=8, c=9, --> diceres = 81    ite=4, stf=3; i=7, j=1, t=6, c=9, --> diceres=61
                diceres = (i*j)+(t*c--);                       //               i=9, j=2, t=8, c=8, --> diceres = 82                  i=7, j=2, t=6, c=8 --> diceres=62                         
                                                                                                                             //       i=7, j=3, t=6, c=7 --> diceres=62
                if (curp1==diceres)                                 // If player 1 = box no.,                                                      .
                    printf("\033[1;32m %s \033[0m\t", player1);     // Replace current number with player 1 ($P1$)                                 .
                else if(curp2==diceres)                                                                                      //       i=7, j=10, t=6, c=0 --> diceres=70
                    printf("\033[1;33m %s \033[0m\t", player2);     // Replace current number with player 2 (^P2^)
                else                                                                                                          //   ite=5, stf=4; diceres = 41->50 
                    printf(" %d \t", diceres);                      // Print remaining number for rows 81, 61, 41, 21, 1           ite=7, stf=6; diceres = 21->30 
            }
            sft++;                                                  // stf=1 -> stf=2
        }
        printf("\n\n");
    }
    printf("----------------------------------------------------------------------------------------\n\n");
}
