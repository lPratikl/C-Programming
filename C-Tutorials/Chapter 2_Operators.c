// 2. Instructions & Operators 

#include<stdio.h>
#include<math.h>

int main() {
//Program to print the average of 3 numbers 
    // int a,b,c; 
    // printf("Enter 3 numbers: ");
    // scanf("%d", &a);
    // scanf("%d", &b);
    // scanf("%d", &c);
    // printf("Average = %d", (a+b+c)/3 );

    
//....................................................................................
//Program to check if the charcter is digit or not 
//     char ch;
//     printf("Enter a character: ");
//     scanf("%c", &ch);
//     if (ch>='0' && ch<='9') { 
//         printf("%c is digit", ch);
//    }
//     else {
//         printf("%c is not digit", ch);
//     }

    
//......................................................................................
// Program to print the smallest number 
   int num1, num2;
   printf("Enter number 1: ");
   scanf("%d", &num1);
   printf("Enter number 2: ");
   scanf("%d", &num2);
   printf("Smaller number = %d", num2>num1 ? num1:num2);
// "Condition ? True : False;" If num2>num1 is true, output num1, else ouput num2. 

    return 0;
}
