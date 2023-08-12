#include<stdio.h>

int main() {
// Find the sum of the first n Nautral number & print in reverse. 
    // int i, j;
    // int sum;
    // int num;
    // printf("Enter a number: ");
    // scanf("%d", &num);
    // for(i=1, j=num; i<=num && j>=1; i++, j--) {
    //     sum += i;
    //     printf("%d \t", j); 
    // }
    // printf("\n");
    // printf("Sum = %d", sum);


//..............................................................................
//Print the table of a number in reverse. 
    // int i, num;
    // printf("Enter a number: ");
    // scanf("%d", &num);

    // for(i=10; i>=1; i--) {;
    //     printf("%d \t", num*i);
    // }


//...................................................................................    
// Keep taking input until user enter a multiple of 7.
// int num; 

// do {
//     printf("Enter a number: ");
//     scanf("%d", &num);
    
//     if(num%7 == 0) {
//         break; 
//     }
// } while(1); 

// printf("%d is a multiple of 7. \n", num);


//............................................................................
// Print the factorial of a number.
    // int num, num2;
    // printf("Enter a number: ");
    // scanf("%d", &num);
    // num2 = num;

    // for(int i=num-1; i>=1; i--) {
    //    num*=i;
    // }

    // printf("Factorial of %d =  %d \n", num2, num);


//...............................................................................
// Find the sum of all numbers between 5 and 50.
    // int sum=0;

    // for(int i=5; i<=50; i++) {
    //     sum += i;
    // }
    // printf("Sum = %d", sum);

//...................................................................................
// // Print a nxn pattern using 'nested loop'.
//     int n;
//     printf("Enter a number: ");
//     scanf("%d", &n);

// // Pattern 1 (nxn *)
//     for ( int i=1; i<=n; i++) {
//         for (int j=1; j<=n; j++) {
//             printf("*");
//         }
//         printf("\n");
//     }

//  // Pattern 2 
//     for  (int i=1; i<=n; i++) {
//         for (int j=n; j>=i; j--) {
//             printf("%d", j);
//         }
//         printf("\n");
//     }  


//.......................................................................................
// Check if a number is prime or not. 
    // int n;
    // int count = 0;
    // printf("Enter a prime number: ");
    // scanf("%d", &n);

    // for (int i=1; i<=n; i++) {                  // Find the number of factors.  
    //     if (n % i == 0) {
    //         count++;                  
    //     }
    // }

    // if (count == 2) {                         // If only 2 factor -> Prime number. 
    //     printf("%d is a prime number.", n);   
        
    // } else {
    //     printf("Not a prime number.");  
    // }


//.......................................................................................
// Print prime nubmer in a range. 
    int i, prime, n1, n2, j;
    int count = 0;
    printf("Enter first number: ");
    scanf("%d", &n1);
    printf("Enter second number: ");
    scanf("%d", &n2);

    if (n1 >= 2) {
        printf ("Prime numbers are: ");
        
        for (j = n1+1; j < n2; j++) {
            prime = 1;
            for (i = 2; i < j/2; i++) {
                if (j % i == 0) {
                    prime = 0;
                    break;
                }
            }

            if (prime) {
                printf("%d \t", j);
            }
        }
        } else {
        printf("Enter a number greater than 1");
    }


    return 0;
}