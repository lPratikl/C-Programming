// Movie Ticket Booking System 
// Dificulty: Advanced

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>              // For getch();

char ch[10][130] = {"OMG 2", "Gadar 2", "Titanic", "Barbie", "Oppenheimer"};
char name[32][100] ={'\0'};     // store up to 32 names with 100 character
char number[32][3] = {'\0'};    // Strore up ot 32 seats with 2 numbers
int num1[32]={0}; 
int trno;                        //trno: seat number 

void movie_list();              // List of buses 
int read_number(int trno);      // Read the numbers from file 
void read_name(int trno);       // Read names from file 
void booking();                 // Booking tickets 
void status();                  // Print ticket status 
void status_1(int trno);        // Print status wile booking tickets 
void name_number(int booking, char numstr[100]);
void cancle();                  // Cancle ticket booking 
void login();                   // User login 

int main() {
    login();                    // Call the login fucntion 
    int num, i=0, trno=2;
    do {                        // Display Page after login
        system("cls"); 
        printf("\n\n\n");
        printf("===============================  Welcome To Ticket Booking System  ===================================== \n\n\n");
        printf("\t\t\t\t\t [1]  =>  View Movie List \n\n");
        printf("\t\t\t\t\t [2]  =>  Ticket Status \n\n");
        printf("\t\t\t\t\t [3]  =>  Book Tickets \n\n");
        printf("\t\t\t\t\t [4]  =>  Cancle Booking \n\n");
        printf("\t\t\t\t\t [0]  =>  Exit \n\n");
        printf("=========================================================================================================\n\n");
        printf("\t\t\t Enter Your Choice: ");
        scanf("%d", &num);


        if (num == 0 || num == 1 || num == 2 || num == 3 || num == 4 || num ==5) {

            switch(num) {
                case 1:
                    movie_list();       // View List of Moview available  
                    break;

                case 2:
                    status();           // View Available Tickets 
                    break;

                case 3:
                    booking();          // Book Tickets 
                    break;

                case 4:   
                    cancle();           // Cancle Bookings
                    break; 
                
                case 5:
                    read_number(trno); 
                    break;
            }
            printf("\n\t\t\t\t Press any key to continue... "); 
            getch();
        }

        else if (num == 6 || num == 7 || num == 8 || num == 9) {
            printf("\n \033[1;31m Invalid Input. Try Again \033[0m "); 
            getch(); 
            i++;                      // i=0 -> i=1, If wrong input more than 2 time => break.  
                
                if (i>=2) 
                    break; 
        }
      
        else                     // If input in non-number => break immediately.     
            break;
    
    } while(num != 0);

    system("cls");
    printf("\t-----------------------------------------------------------------------------------------------\n\n");
    printf("\t\t\t\t\t Thank You For Using This System \t\t\t\t\t \n\n");
    getch();     
    return 0;
}

void movie_list() {                                 // Display the available movies 
    system("cls");
    printf("\n\n\n"); 
    printf("======================================= Movie Ticket List  ============================================== \n\n\n");
    printf("\t\t\t\t\t [1]  =>  %s \n\n", ch[0]);            // char ch[10][130]; declared at the top
    printf("\t\t\t\t\t [2]  =>  %s \n\n", ch[1]);
    printf("\t\t\t\t\t [3]  =>  %s \n\n", ch[2]);
    printf("\t\t\t\t\t [4]  =>  %s \n\n", ch[3]);
    printf("\t\t\t\t\t [5]  =>  %s \n\n", ch[4]);
}

// Make bookings 
void booking() {
    int i=0;
    char numstr[100];
    
    system("cls");
    printf("======================================= {3} Book Movie Tickets  ============================================== \n\n\n");
    movie_list();                             // List of Options 
    printf("Enter Movie no. ---> ");
    scanf("%d", &trno);                        // trno = Ticket No. 
    // system("cls"); 
    // printf("=================================  Bus Reservation System  ============================================== \n\n\n");
    // printf("Your Bus Number is %d ******** %s", trno, ch[trno-1]);
    
    status_1(trno);
    FILE *f1, *fopen();                      // Reading the seats from the user. 
    char str1[80]="32";    // str1 = no of available seats. Initialy, 'str1' = 32 (string) 
    // char str2[4], str3[4]; int seat2,
    int seat1, booking=0;

    if(trno == 1) {                           // If ticket no. = 1 --> trno=1
        f1=fopen("tr1.txt", "r+");            // 'tr1.txt': Stores the no. of remaining seats for Ticekt #1   
        fgets(str1, 80, f1);                  // Get the value in the file as a string and replace it in 'str1'
        fclose(f1);                           
    } 
    else if (trno == 2) {
        f1 = fopen("tr2.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    } 
    else if (trno == 3) {
        f1 = fopen("tr3.txt", "r+");
        fgets(str1, 80, f1);
        fclose(f1);
    } 
    else if (trno == 4) {
        f1 = fopen("tr4.txt", "r+");
        fgets(str1, 80, f1); 
        fclose(f1); 
    } 
    else if (trno == 5) {                           // If ticket no. = 5 --> trno=5      
        f1 = fopen("tr5.txt", "r+");                // 'tr5.txt': Stores the no. of remaining seats for Ticekt #5 
        fgets(str1, 80, f1);                        // Get the value in the file as a string and replace it in 'str1'
        fclose(f1);
    }
                                                   // atoi(): Convert a string into an integer 
    seat1 = atoi(str1);                            // 'str1' (string) --> 'seat1' (integer)                  
                                                   // str1 & seat1 = no. of remaining seats                                        
    if(seat1 <= 0) 
        printf("Sorry, All seats are booked.  ");
    else {
        printf("\n\n \t\t\t\t\t \033[1;34m Available Seats \033[0m----> %d \n", seat1); 
        printf("\t\t\t\t\t \033[1;35m Booked Seats \033[0m----> %d \n", 32-seat1); 
        printf("\n \t\t\t\t\t  Book ? Tickets ----> "); 
        scanf("%d", &booking);                     // booking: no of seats being booked 
        printf("\n");                              // trno: Ticket # (int), numstr: Ticket # (string) 

        seat1 = seat1 - booking;                   // Update no. available seat after seats are booked               If 4 seats are booked for ticke #1
        itoa(trno, numstr, 10);                    // Covert 'trno' into a string and store in 'numstr'              trno = 1, numstr = '1', booking =4
        name_number(booking, numstr);              // 'booking': no. of seats booked, 'numstr': Bus No.             
        printf("\n\n\t\t\t\t \033[1;31m Total Booking Amount = $%d \033[0m \n", 200*booking);      
                                                   
        itoa(seat1, str1, 10);                     // seat 1 (int) & str1 (string) <=> no. of remaining seat for 'trno'                 
                                                   // 'str1' now stores no. of remaining seats after recent booking 
        if (trno == 1) {                           // itoa: convert integer into string 
            f1 = fopen("tr1.txt", "w");             
            fputs(str1, f1);                       // Update no. of remianing seats in the respective file
            fclose(f1);
        }  
        else if (trno == 2) {
            f1 = fopen("tr2.txt", "w");
            fputs(str1, f1);
            fclose(f1);
        } 
        else if (trno == 3) {
            f1 = fopen("tr3.txt", "w");
            fputs(str1, f1);
            fclose(f1);
        } 
        else if (trno == 4) {
            f1 = fopen("tr4.txt", "w");
            fputs(str1, f1);
            fclose(f1);
        }
        else if (trno == 5) {
            f1 = fopen("tr5.txt", "w");
            fputs(str1, f1);
            fclose(f1);
        }
    }
}


void name_number(int booking, char numstr[100]) {
    char tempstr[100], tempstr1[20]="Name-", tempstr2[12] ="Seat#";
    int number; 

    FILE *a, *b;
    int i=0;

    strcat(numstr, ".txt");                 // 'numstr': Ticket # (string) 
    strcat(tempstr1, numstr);               // File to store booking names of booking --> 'Name-X.txt' 
    strcat(tempstr2, numstr);               // File to store seat number booked --> 'Seat#X.txt'  

    a = fopen(tempstr1, "a");               // a: append, add onto an existing file 
    b = fopen(tempstr2, "a"); 

    for (i=0; i<booking; i++) {      
        printf("\t\t ===================  Enter Details for Ticket No. '%d' ====================== \n\n", i+1);
        printf("\t\t\t\t Choose Seat No. -----> ");
        scanf("%d", &number);               // 'number': Seat no. selected 
        printf("\t\t\t\t Enter Name of Person: -----> ");
        scanf("%s", name[number-1]);        // If number=1, then store the booking name in name[0].   
        printf("\n----------------------------------------------------------------------------------------------------------------------- \n\n");
        // printf("\n========================================================================================================================\n\n");
       
                                            // number (int) & tempstr (string) <=> seat no. selected 
        itoa(number, tempstr, 10);          // itoa: Convert seat numbers selected into string and store in 'tempstr'
        fprintf(a, "%s ", name[number-1]);  // Print the booking name to 'Name-X.txt' file 

        fprintf(b, "%s ", tempstr);         // Print the seats selected to 'Seat#X' file
    }
    fclose(a);
    fclose(b); 
    printf("\t\t\t\t Press any key to continue.... ");
    getch();                                 // Wait for any input to continue 
}


int read_number(int trno) {                 // Read the Seat number value in the array 
    char tempstr[100], tempstr2[12] = "Seat#"; 
    FILE *a, *b;
    char numstr[100];                        // itoa(): Convert an integer into a character string
                                             // strcat(): Append and save into first string
    int i=0, j=0, k, m;
    itoa(trno, numstr, 10);                  // If trno = 1 (int)-> numstr = '1' (string)                      If trno=2 (int), numstr = '2' (string)                
    strcat(numstr, ".txt");                  // numstr = '1.txt' --> tempstr2 = 'Seat#1.txt'                    numstr= '2.txt' --> tempstr2 = 'Seat#2.txt'      
    strcat(tempstr2, numstr);                 
    a = fopen(tempstr2, "a+");               // a+: read & wirte the name in the file 

    while(!feof(a)) {                        // Check until the file pointer to a stream is pointing to the end of the file or not.
        number[i][j] = fgetc(a);             // fgetc(): Reads a single unsigned character from the input stream at the current position 
        
        if(number[i][j] == ' ') {            // number[32][2]; initialized at the top. When ' ' occurs in file, shift to next row. 
            number[i][j] == '\0';          // End line after ' '
            j=0;                             // ite=1; '1' i=0, j=0 --> number[0][0] = '1' 
            i++;                             // ite=2; ' ' i=0, j=1 --> number[0][1] = ' '
        }                                    // ite=3; '2' i=1, j=0 --> number[1][0] = '2'
        else {                               // ite=4; ' ' i=1, j=1 --> number[1][1] = ' '
            j++;                             // ite=5; '23' i=2, j=0 --> number[2][0] = '2'
        }    
        // printf("number[%d][%d] = %c \n", i, j, number[i][j]);     
        // getch();                           // ite=6; '23' i=2, j=1 --> number[2][1] = '3'
    }                                      // ite-7; ' ' i=2, j=2 --> number[2][0] = ' '
    printf("\n\n"); 

    k=i;                                    // k = no. of seats booked, if 3 seats are booked in 'SeatNumber_X' file, k=3.  
    for (i=0; i<k; i++) {
        num1[i] = atoi(number[i]);          // Convert seat no. booked into integers and store in 'num[i]' 

    }                                       // iter1; i=0 --> num[0] = 1
    fclose(a);                              // iter2; i=1 --> num[1] = 2
    return k;                               // iter3; i=2 --> num[2] = 23
}


void read_name(int trno) {                 // Read names storeed 'Name-X' file; X -> Ticket no. 
    char tempstr1[12]="Name-";
    FILE *b;
    char numstr[100]; 
    int i=0, j=0, k=0;

    itoa(trno, numstr, 10);               // trno: Ticket Number (int), numstr: Ticket Number (string) 
    strcat(numstr, ".txt");               // If trno = 3 (int) --> numstr = 3 (str) --> numstr = '3.txt'
    strcat(tempstr1, numstr);             // tempstr1 = 'Name-3.txt'

    b = fopen(tempstr1, "a+");            // Open 'Name-X' file and append 

    while(!feof(b)) {                     // char name[32][100]
        name[i][j] = fgetc(b);            // ite=1; 'A' i=0, j=0 --> name[0][0] = 'A' 
                                          // ite=2; 'B' i=0, j=1 --> hame[0][1] = 'B'
        if(name[i][j] == ' ') {           // ite=3; 'C' i=0, j=2 --> name[0][2] = 'C'
            number[i][j] == '\0';
            j=0;                          // ite=4: 'D' i=0, j=3 --> name[0][3] = 'D'
            i++;                          // ite=5: ' ' i=1, j=0 --> name[1][0] = ' '
        }                                 // ite=5: 'E' i=1, j=1 --> name[1][1] = 'E'
        else {                            // ite=5: 'F' i=1, j=2 --> name[1][2] = 'F' 
            j++;                          // ite=5: ' ' i=2, j=0 --> name[2][0] = ' '
        }                                 // ite=5: 'G' i=2, j=1 --> name[2][1] = 'G'
    }
    name[i][j] = '\0';                    // Set the last array to be a null character 
    k=i;                                  // k = no. of names in 'Name-X' file, if 10 names are stored, k=10. 
    fclose(b);
}


void status() {                           // Show stauts of avaiable tickets 
    int i, trno, index=0, j;
    system("cls");
    printf("======================================= {2} Movie Ticket List  ============================================== \n\n\n");
    movie_list(); 
    
    printf("Select Ticket No:----> ");    
    scanf("%d", &trno);                                              // trno: Ticket no., ch[trno-1]: Ticket Customer Name
                                                                     // If trno = 1 --> read_number(trno) returns k = no. of booked seats for Ticket 1
    j=read_number(trno);                                             // j = k = no. of booked seats for Ticket 1 
    read_name(trno);                                                 // Execute read_number(), read_name()
    
    system("cls");
    printf("--------------------------------------------------------------------------------------------------------------\n");
    printf("\t\t\t\t\t    {2}  Ticket No: %d ----> \033[1;36m%s \033[0m       \n", trno, ch[trno-1]);
    printf("______________________________________________________________________________________________________________\n\n\n");
    
    char tempname[33][10] = {"Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty",          // All 33 seats are empty 
                             "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty",
                             "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty"};
    
    for (i=0; i<j; i++) {                            // Assign seat number & name 
        strcpy(tempname[num1[i]], name[i]);          // Assume 4 bookings (Seat Number <=> Name) --> j=4  
    }                                                //  i=0; 1 <=> Apple--> tempname[1] = Apple                i=1; 10 <=> Banana --> tempname[10] = Banana  
                                                                                                             // i=2;  5 <=> Cary   --> tempname[5]  = Cary                                                                                                 
    for (i=0; i<8; i++) {                            // 8x4 Matrix to show the booking staus                    i=3; 23 <=> Darian --> tempname[23] = Darian 
        printf("\t\t\t\t");                          // index=0
        
        for (j=0; j<4; j++) {          
            if (strcmp(tempname[index+1], "Empty") != 0) {                          // Use 'strcmp()' to compare between two strings; returns 0 if true
                printf("%d.\033[1;31m%s \t\033[0m", index+1, tempname[index+1]);    // If seat is booked, print info in red color '31m'
            }                                                                       // index=0 -> index+1 becasue first seats is 1 --> tempname[1] = Apple 
            else {
                printf("%d.\033[1;32m%s \t\033[0m", index+1, tempname[index+1]);    // If seat is not booked -> "Empty" -> print in green '32m'
            }
            index++;                                                                // index=0 --> index=1, --> tempname[2] = Banana 
        }
        printf("\n"); 
    }
}


void status_1(int trno) {                        // Show seat status while making booking 
    system("cls");
    printf("\n\n");
    printf("==========================================  Book Movie Tickets  ============================================== \n\n");
    printf("\t\t\t\t\t \033[1;36m Movie [%d] ******** %s \033[0m \n", trno, ch[trno-1]);             // trno: Ticket no., ch[trno-1]: Ticket name 
                                                                                                          // Show movie no. & name
    int i, index=0, j;
    j=read_number(trno);                               // read_number() & read_name() gets the seats & names booked for ticket no. (trno)
    read_name(trno);

    char tempname[33][10] = {"Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", 
                             "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty",
                             "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty", "Empty"};
    
    for (i=0; i<j; i++) {                            // Copy booking name 'name[i]' to corrsponding seat no. 'num1[i]' --> tempname[i] = name[i] 
        strcpy(tempname[num1[i]], name[i]);          // For seats that are already booked
    } 

    for (i=0; i<8; i++) {                                       
        printf("\t\t\t\t");                                                                                          

        for (j=0; j<4; j++) {
            if (strcmp(tempname[index+1], "Empty") !=0) {                             // index = 0
                printf("%d.\033[1;31m%s \t\033[0m", index+1, tempname[index+1]);      // Show seats that are already booked in red color 
            }
            else {
            printf("%d.\033[1;32m%s \t\033[0m", index+1, tempname[index+1]);          // Show seats that are empty in green color 
            }
            index++;                                                                  // index=0 -> index=1
        }
        printf("\n");
    }
}


void cancle() {                                            // Cancle a booking 
    int seat_no, choice, seat1,  i, j;
    char numstr[100], tempstr1[15]="Name-", tempstr2[15]="Seat#", tr[10]="tr", str1[80];

    movie_list();     
    printf("Enter Ticket # -----> ");
    scanf("%d", &trno); 
    itoa(trno, numstr, 10);                // trno (int) & numstr(string) <=> Ticket # 
    strcat(numstr, ".txt");
    strcat(tempstr1, numstr);
    strcat(tempstr2, numstr);
    strcat(tr, numstr);
    // printf("tr = %s \t", tr);
    // getch();
    
    read_number(trno);                     // Get seat numbers that are booked for Ticcket #(trno)
    read_name(trno);                       // Get booking names for Ticket #(trno)
    status_1(trno);                        // Show the current status for Ticket #(trno)

    A: printf("Cancle Seat No. ----> ");       // Selet the booking to cancle 
    scanf("%d", &seat_no);

    FILE *a, *b, *f1;
    a = fopen(tempstr1, "w+");
    b = fopen(tempstr2, "w+");
    
    // printf("temp1 = %s \t", tempstr1);
    // printf("tr = %s \t", tr);
    // getch(); 

    for (i=0; i<32; i++) {                // For 32 seats 
        if (num1[i] == seat_no) {         
            for (j=0; j<32; j++) {
                if (num1[j] != seat_no && num1[j] != 0) {         // For seats that are not selected to cancle & but are booked 
                    fprintf(b, "%d ", num1[j]);                   // Rewrite the seat numbers in 'Seat#X.txt' file  
                    fprintf(a, "%s", name[j]);                    // Rewrite the booking names in 'Name-X.txt' file
                }
                else if (num1[j] == seat_no && num1[j] != 0) {    // For seat that is selected to cancle & booked  
                    strcpy(name[j], "Empty ");                    // Assignment 'Empty' to that seat 

                    f1 = fopen(tr, "r+");  
                    fgets(str1, 80, f1);                        // Update the available no. of seats after a booking cancllation 
                    fclose(f1);                                 // The number is obtained as a string from the respective file 
                    seat1 = atoi(str1)+1;                       // Covert the value into int --> Add 1 for each cancellation 
                    itoa(seat1, str1, 10);                      // Convert the new value back to string & write in respective file  
                    f1 = fopen(tr, "w+");   
                    fputs(str1, f1);                            // Update no. of remianing seats in the respective file
                    fclose(f1);

                }
            }
        }
    }

    fclose(a);
    fclose(b);
    
    status_1(trno); 
    printf("\n\n");
    printf("\t ================================================================================== \n");
    printf("\t\t\t\t\t \033[1;33m $200 has been refunded. \033[0m \n");
    printf("\t ================================================================================== \n\n");
    printf("\t\t\t\t Press any exit.... ");
    getch(); 
    exit(0); 
}


void login() {                       // For login function
    int a=0, i=0;
    char username[10], c=' ';            
    char password[10], code[10];
    char user[10] = "user";        // Username = user
    char pass[10] = "pass";        // Password = pass

    do {
        system("cls");
        // printf("\n ===================== LOGIN ========================== \n\n"); 
        printf("==========================================  PLEASE LOGIN  ============================================== \n\n");
        printf("                   Enter Username:  ");
        scanf("%s", &username);
        printf("                   Enter Password:  ");
        
        while (i<10) {
            password[i] = getch();       // Store each charater in the array of password     
            c = password[i]; 

            if (c==13)                  // ASCII char(13): Carriage Return; Enter 
                break;
            else printf("*");           // Hide the input character while entering password
                i++;
        }

        password[i] = '\0';
        
        i=0;

        if (strcmp(username, "user") == 0 && strcmp(password, "pass") == 0) {    // strcmp(): Compares two strings. Returns 0 when true 
            printf(" \n\n\n \033[1;32m    LOGIN Sucessful. Welcome to our System!!!! \033[0m");
            printf("\n\n\n \t\t\t\t Press any key to continue.... ");
            getch();                                                             // Hold the screen until any input
            break;  
        }
        else {
            printf("\n\n \t\t \033[1;31m     Try Again. \033[0m");
            a++;
            getch();
        }
    
    } while (a <= 2);        // 3 Tries for LOGIN

    if (a>2) {                // Exectue this if 3 failed attempts. 
        printf("\n\n \033[1;31m You have entered wrong username or password more than 3 times!!! \033[0m");
        getch();
        exit(0);             
    } 
    
    system("cls"); 

}


/*
Glossary 

trno: Bus Number in integer            numstr: Bus Number in string 
seat1: avaiable seats in integer       str1: available seats in string

booking: total no of seats booked (int)    number: seat selected (int)       tempstr1: Seat_Name
tempstr: Seat selected (str)               name: booking name                tempstr2: Seat_Number

tr1.txt: Stores no. of remaining seats in a file 
Name-X.txt: Stores booking names for Ticket #X 
Seat#X.txt: Stores booked seats for Ticket #X 

// atoi(): Convert a string into an integer
// itoa(): Convert an integer into a character string
// strcat(): Append and save into first string
// strcpy(): Copy string from one variable to another
// feof(): Check if the file pointer to a stream is pointing to the end of the file or not.
// fgetc(): Reads a single unsigned character from the input stream at the current position 

# Print text in Color 
    printf("\033[1;31m <Text> \033[0m\n");

'\033' -> Escape character, '[1;<color code>m' -> Set text color, "\033[1;0m" -> Reset color back to normal.

Black: 30     Yellow: 33    Cyan: 36
Red: 31       Blue: 34      White: 37
Green: 32     Magenta: 35   Reset: 0
*/
