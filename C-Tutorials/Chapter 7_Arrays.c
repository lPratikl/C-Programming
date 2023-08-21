// Arrays 
#include <stdio.h>

//...................................................................................
// int countOdd(int arr[], int n);
// void reverse(int arr[], int n);
// void printArr(int arr[], int n);

// int main() {
//     int arr[] = {1, 2, 3, 4, 5};
//     reverse(arr, 5);
//     printArr(arr, 5);
//     return 0; 
// }

// void printArr(int arr[], int n) {
//     for (int i=0; i<n; i++) {
//         printf("%d \t", arr[i]);
//     }
//     printf("\n");
// }

// void reverse(int arr[], int n) {
//     for (int i=0; i<n/2; i++) {
//         int firstval = arr[i];
//         int secondval = arr[n-i-1];
//         arr[i] = secondval;
//         arr[n-i-1] = firstval;
//     }
// }

// int countOdd(int arr[], int n) {
//     int count = 0;
//     for (int i=0; i<n; i++) {
//         if(arr[i] %2 != 0) {
//             count++;
//         }
//     }

//     return count; 
// }

//........................................................................................
//Fibonaci 
// int main() {
//     int n;
//     printf("Enter a number: ");
//     scanf("%d", &n);

//     int fib[n];
//     fib[0] = 0 ;
//     fib[1] = 1;

//     printf("%d \t %d \t", fib[0], fib[1]);
    
//     for(int i=2; i<n; i++) {
//         fib[i] = fib[i-1] + fib[i-2]; 
//         printf("%d \t", fib[i]);
//     }
//     return 0;
// }

//.........................................................................................
// 2-D Arry to store the tables of 2 & 3.

// void storeTable(int arr[][10], int n, int m, int number);

// int main() {
//     int tables[2][10];
//     storeTable(tables, 0, 10, 4);
//     storeTable(tables, 1, 10, 9);
    
//     for (int i=0; i<10; i++) {
//         printf("%d \t", tables[0][i]);
//     }
//     printf("\n");

//     for (int i=0; i<10; i++) {
//         printf("%d \t", tables[1][i]);
//     }


//     return 0; 
// }

// void storeTable(int arr[][10], int n, int m, int number) {
//     for (int i=0; i<m; i++) {
//         arr[n][i] = number*(i+1);
//     }
// }

//....................................................................................
// 1. Find how many times number 'x' occurs in an array of numbers. 
// 2. Print largest number in an array. 
// 3. Insert new element at the end of an array. 

void printArray(int arr[], int size);           // List the elements in an array. 
int countx(int arr[], int n, int size);         // 1. How many times 'x' ocuurs. 
void findlargest(int arr[], int size);          // 2. Print the largest number. 
void addNumbers(int arr[], int size);           // 3. Inser new elements. 
 

int main() {
    int i, n, N, size;

    int arr[] = {20, 8, 3, 16, 10, 14, 12, 6, 6}; 
    size = sizeof(arr)/sizeof(arr[0]);               // Find no. of element in the array.
    printf("Number of elements = %d \n", size);
    printArray(arr, size);
    printf(" \nEnter a number ");
    scanf("%d", &n);
    printf("'%d' occurs %d times \n", n, countx(arr, n, size));
    findlargest(arr, size);
    addNumbers(arr, size);

    return 0;
}

int countx(int arr[], int n, int size) {
    int count = 0; 
    for (int i=0; i<size; i++) {
        if(arr[i] == n) {             // Count + if elemnt in arr[i] = n
            count++;
        }
    }
    return count;
}

void printArray(int arr[], int size) {
    printf("List of Array: ");
    for (int i=0; i <size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void findlargest(int arr[], int size) {
    for (int i=1; i<size; i++) {
        if (arr[0] < arr[i]) {             // Compare arr[0] with every elemnt. 
            arr[0] = arr[i];               // If arr[i]>arr[0], save it in arr[0] & 
        }                                  // compare with remianing elements. 
    }
    printf("Largest number in array = %d \n", arr[0]);
}

void addNumbers(int arr[], int size) {
    int i, N;
    printf("\nHow many new elements: ");
    scanf("%d", &N);
    printf("Enter %d integer numbers: \n", N);   
    for(i = size; i < size+N; i++) {              // Start from the last poistion in the... 
        scanf("%d", &arr[i]);                     // array and add N new elements. 
    }
    for(i = 0; i < size+N; i++) {
        printf("%d \t", arr[i]); 
   }
}

