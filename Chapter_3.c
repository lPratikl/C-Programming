// 3. Conditional Statements

#include<stdio.h>
#include<math.h>

int main() {
//....................................................................................
// Program to check if a student passed or failed
//    int marks;
//    printf("Enter your marks: ");
//    scanf("%d", &marks);

//    if(marks >=0 && marks <= 30) {
//     printf("FAIL \n");
//    } else if (marks > 30 && marks <= 100) {
//     printf("PASS \n");
//    }
//    else {
//     printf ("Out of Range \n");
//    }

// marks >30 && marks <=100 ? printf("PASS \n") : printf("FAIL \n");

    
//.......................................................................................
// Program to give grades to a student 
    // int marks;
    // printf("Enter your marks: ");
    // scanf("%d", &marks);

    // if (marks >=0 && marks < 30) {
    //     printf("Grade = C \n");
    // }
    // else if(marks >=30 && marks <70) {
    //     printf("Grade = B \n");
    // }
    // else if (marks >= 70 && marks <90) {
    //     printf("Grade = A \n");
    // }
    // else if (marks >=90 && marks <= 100) {
    //     printf("Grade = A+ \n");
    // }    
    // else {
    //     printf("Out of Range \n");
    // }

    
//......................................................................................
// Program to find if a character is upper case or not
    // char ch;
    // printf("Enter charcater: ");
    // scanf("%c", &ch);

    // if(ch >= 'A' && ch <='Z') {
    //     printf("Upper case \n");
    // }
    // else if(ch >= 'a' && ch <= 'z') {
    //     printf("Lower case \n");
    // }
    // else {
    //     printf("Invalid \n");
    // }

    
//.....................................................................................
// Program to check if a number is Armstrong number.
// Link: https://www.programiz.com/c-programming/examples/check-armstrong-number
// For 3-digit number 
    // int num, originalNum, remainder, result = 0;
    // printf("Enter a 3-digit integer: ");
    // scanf("%d", &num);
    // originalNum = num;

    // while(originalNum != 0) {  // Seperate the 3 digit numbers (xyz) 
    //     remainder = originalNum % 10;
    //     result += remainder * remainder* remainder;  // x^3+y^3+z^3
    //     printf("remainder = %d \n", remainder);
    //     originalNum /= 10;
    //     printf("originalNum = %d \n", originalNum);
    // }
    
    // if (result == num) {
    //     printf("%d is an Armstrong number. \n", num);        
    // } else {
    //     printf("%d is not an Armstrong number. \n", num);
    // }

// Check Armstrong number of n digits 
    // int num, originalNum, remainder, n = 0;
    // float result = 0;

    // printf("Enter an integer: ");
    // scanf("%d", &num);

    // originalNum = num; 

    // // Store the number of digits in n 
    // for (originalNum = num; originalNum != 0; ++n) {
    //     originalNum /= 10;
    // }

    // for (originalNum = num; originalNum != 0; originalNum /= 10) {
    //     remainder = originalNum % 10;
    //     result += pow(remainder, n);  //Sum the power of individual digits in result 
    // }
    // printf("Result = %f \n", result);

    // if ((int)result == num) {
    //     printf("%d is an Armstrong number. \n", num);
    // } else {
    //     printf("%d is not an Armstrong number. \n", num);
    // }


//...................................................................................
// Check if a number is a nutural number. 
    int number;
    printf("Enter an integer: ");
    scanf("%d", &number);

    if (number >= 1 ) {
        printf("Natural number \n");
    } 
    else {
        printf("Not a nuatural number \n");
    }
      
    return 0;
}
