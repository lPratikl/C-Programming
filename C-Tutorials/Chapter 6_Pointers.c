#include <stdio.h>
// Function to calculate Sum, Product & Average of 2 numbers using pointers.

// void math(int a, int b, int *sum, int *prod, int *avg);


// int main() {
//     int a =3, b=5;
//     int sum, prod, avg;
//     math(a, b, &sum, &prod, &avg); 
//     printf("Sum = %d, Product = %d, Average = %d \n", sum, prod, avg);

//     return 0;
// }

// void math(int a, int b, int *sum, int *prod, int *avg) {

//     *sum = a+b;
//     *prod = a*b;
//     *avg = (a+b)/2;
// }


//.......................................................................................
// Find maximum number between two numbers using a pointer 

// void findmax(int a, int b, int *max);

// int main() {
//     int a, b;
//     int max;
//     printf("Compare two numbers: ");
//     scanf("%d %d", &a, &b);
//     findmax(a, b, &max);
//     printf("Bigger number = %d", max);

//     return 0;
// }

// void findmax(int a, int b, int *max) {
//     *max = a>b ? a:b;
// }


//....................................................................................
// Print the element of an array in reverse order. 

// void printArr(int arr[], int n);
// void reverse(int arr[], int n);

// int main() {
//     int arr[] = {2, 9, 6, 0, 4};             // The list of 5 arrays. 
//     printArr(arr, 5);                        // Print the array in order. 
//     reverse(arr, 5);                         // Use a function to reverse the order
//     printArr(arr, 5);                        // Print the reverse order. 
//     return 0; 
// }

// void printArr(int arr[], int n) {
//     printf("Array: ");
//     for (int i=0; i<n; i++) {
//         printf("%d \t", arr[i]);
//     }
//     printf("\n");
// }

// void reverse(int arr[], int n) {
//     printf("Reverse ");
//     for (int i=0; i<n/2; i++) {
//         int firstval = arr[i];              // Store value in a[0] to firstval. 
//         int secondval = arr[n-i-1];         // Store value in a[5] to secondval. 
//         arr[i] = secondval;                 // Store old a[5] to new a[0]. Reverse order.
//         arr[n-i-1] = firstval;              // Store old a[0] to new a[5].
//     }
// }


//......................................................................................
// Print all English Alphabet letters using a pointer. 
int main() {

    char ch[27];
    int i; 
    char *ptr;
    ptr = ch;
    for (i=0; i<26; i++) {
        *ptr = i +'A';
        ptr++;
    }

    ptr = ch;

    for (int i=0; i<26; i++) {
        printf("%c  ", *ptr);
        ptr++;
    }

    return 0; 
}


