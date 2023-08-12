//Dynamic Memory Allocation 

// calloc(); allocate requested memory and return a pointer to it 
// malloc(); dynamically allocate a large block of memory with the sepcified size. 
// free(); de-allocate the memory to reduce wastage of memory by freeing it
// realloc(); re-allocate new memory if previously was not enough 
// malloc does not set memory to zero; calloc sets allocated memory to zero. So malloc is a bit faster.
#include <stdio.h>
#include <stdlib.h>

// int main() {
//     int *ptr;
//     ptr = (int*) calloc(5, sizeof(int));
//     ptr[0] = 1;
//     ptr[1] = 3;
//     ptr[2] = 5;
//     ptr[3] = 7;
//     ptr[4] = 9;
 
//     for (int i=0; i<5; i++) {
//         printf("%d \t", ptr[i]);
//     }


//     ptr = realloc(ptr, 6);
//     ptr[0] = 2;
//     ptr[1] = 4;
//     ptr[2] = 6;
//     ptr[3] = 8;
//     ptr[4] = 10;
//     ptr[5] = 12;
 
//     for (int i=0; i<6; i++) {
//         printf("Number %d is %d\n", i, ptr[i]);
//     }


//     return 0;
// }

//.......................................................................................
// int main() {
//     int *ptr, *ptr1 ;
//     ptr = (int*) calloc(5, sizeof(int));
//     for (int i=0; i<5; i++) {
//         printf("Enter number: ");
//         scanf("%d", &ptr[i]);
//     }

//     ptr1 = (int*)malloc(5*sizeof(int));
//     for (int i=0; i<5; i++) {
//         ptr1[i] = ptr[i];
//     }

    
//     for (int i=0; i<5; i++) {
//         printf("Calloc:" );
//         printf("%d \t", ptr[i]);
//         printf("Malloc: ");
//         printf("%d \n", ptr1[i]);
//     }
    
//     printf("\n");
//     free(ptr);
//     printf ("Calloc Memory freed.");
//     for (int i=0; i<5; i++) {
//         printf("%d \t", ptr[i]);
//     }

//     printf("\n");
//     ptr = realloc(ptr, 6);
//     ptr[0] = 2;
//     ptr[1] = 4;
//     ptr[2] = 6;
//     ptr[3] = 8;
//     ptr[4] = 10;
//     ptr[5] = 12;
 
//     for (int i=0; i<6; i++) {
//         printf("Number %d is %d\n", i, ptr[i]);
//     }


//     return 0;
// }


// //.......................................................................................
// // Allocate memory for 500 integers using calloc & then store first 500 natural number... 
// // in that space

int main() {
    int *ptr;

    ptr = (int*)calloc(500,sizeof (int));
    for (int i=0; i<500; i++) {
        ptr[i] = i+1;
    } 

    for (int i=0; i<500; i++) {
        printf("%d ", ptr[i]);
    }

    printf("\n %d", ptr[490]);

    return 0;
}