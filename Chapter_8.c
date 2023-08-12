#include<stdio.h>
#include<string.h>

// void printString(char arr[]);
// int countLength(char arr[]);

// int main() {
//     char str[100];
//     char ch;
//     int i =0;

//     printf("Enter a String: ");
//     while(ch != '\n') {
//         scanf("%c", &ch);
//         str[i] = ch;
//         i++;
//     }
//     str[i] = '\0';
//     printf("You entered: ");
//     puts(str);
// }


// int countLength(char arr[]) {
//     int count =0;
//     for (int i=0; arr[i] != '\0'; i++) {
//         count++;
//     }
//     return count-1;
// }
// void printString(char arr[]) {
//     for(int i=0; arr[i] != '\0'; i++) {
//         printf("%c", arr[i]);
//     }
//     printf("\t");
// }


//......................................................................................
// void salting(char password[]);                     // Salting: Add a string at the end 
// void slice(char str[], int n, int m);              // Slice: Extract a portion of string.  
// int countVowels(char word[]);                      // Count number of vowels in a word. 
// void checkChar(char str2[], char ch);               // Check if a letter is presetn. 

// int main() {
    // char password[100];                     // Use salting to create a new password. 
    // printf("Enter Old password: ");
    // gets(password);                         // 'gets' is a function to input a string.  
    // salting(password); 

    // char word[50];
    // printf("How many vowels the word: ");
    // gets(word);
    // printf("Number of vowels present = %d \n", countVowels(word));

    // int n, m;
    // char str[100];
    // printf("Enter string: ");
    // gets(str);
    // printf("Enter start & end point: ");
    // scanf("%d %d", &n, &m);
    // slice(str, n, m);
    
//     char str2[50];
//     char ch;
//     printf("Enter string to check: ");
//     gets(str2);
//     printf("Enter letter to check: ");
//     scanf("%c", &ch);
//     checkChar(str2, ch); 

//     return 0;
// }  

// void checkChar(char str2[], char ch) {
//     for (int i=0; str2[i] != 0; i++) {
//         if (str2[i] == ch) {
//             printf("Character is present!");
//             return;
//         }
//     }
//     printf("Character is NOT present!");
// }

// int countVowels(char word[]) {
//     int count =0;

//     for (int i=0; word[i] !='\0'; i++) {
//         if(word[i] == 'a'|| word[i] == 'e' || word[i] == 'i' || 
//         word[i] == 'o' || word[i] =='u') {
//             count++;
//         }
//     }
//     return count;
// }
// void slice(char str[], int n, int m)  {
//     char newStr[100];
//     int j=0;
//     for (int i=n; i<=m; i++, j++) {
//         newStr[j] = str[i];
//     }
//     newStr[j] = '\0';
//     puts(newStr);
// }

// void salting(char password[]) {
//     char salt[] = "123";
//     char newPass[200];

//     strcpy(newPass, password);
//     strcat(newPass, salt);
//     printf("New passord: ");
//     puts(newPass);  
//     printf("\n");
// }


//.......................................................................................
// Convert all lowercase vowels to uppercase in a string. 

// Method #1 (26 Lines)
// void changevowels(char str[]); 

// int main() {

//     char str[50];
//     printf("Enter string: ");
//     gets(str); 
//     changevowels(str);
//     return 0;
// }
 
// void changevowels(char str[]) {
//     for (int i=0; str[i] !='\0'; i++) {
//         if(str[i] == 'a') 
//             str[i] = 'A';
//         else if (str[i] == 'e')
//             str [i] ='E'; 
//         else if (str[i] == 'i')
//             str [i] ='I';
//         else if (str[i] == 'o')
//             str [i] ='O';
//         else if (str[i] == 'u')
//             str [i] ='U';       
//     }
//     puts(str);
// }

// Method 2 (14 Lines)............................................ 
// int  main() {
//     char string [100];
//     int i = 0;
//     printf("Enter string: ");
//     gets(string);

//     while (string[i] != '\0') {
//         if (string[i] == 'A' || string[i] == 'e' || string[i] == 'i'|| 
//             string[i] == 'o' || string[i] == 'u') {
//                 string[i] = string[i]-32;           // ASCI: 'A' = 65, 'a' = 97; diff = 32
//             }
//         i++;
//     }   
//     puts(string);
// }


//.......................................................................................
// Print the highest frequnecy character in a string. 
// int main() {
//     char str[100], result;
//     int i, len;
//     int max =0;
//     int freq[256] ={0};
//     printf("Enter string: ");
//     fgets(str, 100, stdin);
//     len =  strlen(str);
//     printf("Length of stirng  = %d \n", len);

//     for (i=0; i<len; i++) {
//         freq[str[i]]++;                    // Store the no. of time element [i] appers. 
//     }

//     for (i=0; i<len; i++) {
//         if (max <= freq[str[i]]) {
//             max = freq[str[i]];
//             result = str[i];
//         }
//     }

//     printf("Letter '%c' occus %d times", result, max);

//     return 0; 
// }


//.......................................................................................
// Remove blank spaces in a string. 

// int main() {
//     char str[100];
//     printf("Enter string: ");
//     fgets(str, 100, stdin);

//     for (int i=0; str[i] != '\0'; i++) {
//         if (str[i] == ' ') {
//             int j=i;
//              while(str[j]!='\0') {
//                 str[j] = str[j+1];        // Shift elements to the left. 
//                 j++;
//          }
//         }
//     } 
//     puts(str);
// }


//.......................................................................................
// Replace lowercase with uppercase & vice versa in a string. 

// int  main() {
//     char string [100];
//     int i = 0;
//     printf("Enter string: ");
//     gets(string);

//     while (string[i] != '\0') {
//         if (string[i] >= 'A' && string[i] <= 'Z') {
//             string[i] = string[i] + 32;
//         } 
//         else if (string[i] >= 'a'&& string[i] <= 'z') {
//             string[i] = string[i] - 32;
//         }
//         i++;  
//     }
//     puts(string);
// }

// Method 2 (using ctype.h library)
// https://www.programiz.com/c-programming/library-function/ctype.h
#include <ctype.h>

void main() {
    char str2[100];
    int ctr, ch, i = 0;
    printf("Enter string: ");
    fgets(str2, sizeof str2, stdin);


    while(str2[i] != '\0') {
        ch = islower(str2[i]) ? toupper(str2[i]) : tolower(str2[i]);
        putchar(ch); 
        i++;
    }

}
    
