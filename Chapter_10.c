//File I/O
#include <stdio.h>
#include <stdlib.h>

// int main() {
//     FILE*fptr;
//     fptr = fopen("Ch10_Odd.txt", "r"); 

//     int a, b;
//     fscanf(fptr, "%d", &a);
//     fscanf(fptr, "%d", &b);
    
//     fclose(fptr); 

//     fptr = fopen("Ch10_Odd.txt", "w");
//     fprintf(fptr, "Hello = %d", a+b);
//     fclose(fptr);

//     return 0; 
// }


//..........................................................................................
// Read a string from a file & output to the user. 

// int main() {
//     FILE *fptr, *fptr2;
//     fptr = fopen("Ch10_Test.txt", "r");
//     fptr2 = fopen("Ch10_Test.txt", "r");

//     char str[50];
//     fscanf(fptr, "%[^\n]", &str);             // "%[^\n]": Scan text until newline encountered. 
//     printf("%s \n", str);                     // Only Read the first line. 
//     fclose(fptr);
 
   
//     char str2[100];
//     fscanf(fptr2, "%[^\0]", &str2);             // "%[^\0]": Scan unit the of text. 
//     printf("\n%s \n", str2);                      //  Read the whole string. 
//     fclose(fptr2);


//     return 0;
// } 

//......................................................................................
// int countvowels(char string[]);

// int main() {
//     FILE*fptr;
//     fptr = fopen("Ch10_Test.txt", "r"); 

//     int n;
//     char string[50];
//     fscanf(fptr, "%[^\0]", &string);
//     n = countvowels(string);
//     printf("Numer of vowels = %d", n);
//     fclose(fptr); 

//     fptr = fopen("Ch10_Test.txt", "w");
//     fprintf(fptr, "Numer of vowels = %d", n);
//     fclose(fptr);

//     return 0; 
// }

// int countvowels(char string[]) {
//     int count = 0;
//     for (int i=0; string[i] != '\0'; i++) {
//         if (string[i] == 'a' || string[i] == 'e' || string[i] == 'i' || string[i] == 'o' || string[i] == 'u' ||
//             string[i] == 'A' || string[i] == 'E' || string[i] == 'I' || string[i] == 'O' || string[i] == 'U')
//             count++;
//     }
//     return count++;
// }


//..........................................................................................
// Format info of 5 students in a table like strucutre in a file, 
// include (Name, Marks, CGPA, Course)

int main() {
    char name[50], subject[50];
    int n, marks;
    float cgpa;

    printf("Enter number of students: ");
    scanf("%d", &n); 

    FILE*fptr;
    fptr = fopen("Ch10_StoreInfo.txt", "w"); 

    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }

    for (int i=0; i<n; i++) {
        printf("Student %d, Name: ", i+1);
        scanf("%s", name);
        printf("Enter marks: ");
        scanf("%d", &marks);
        printf("Enter CGPA: ");
        scanf("%f", &cgpa);
        printf("Enter subject: ");
        scanf("%s", subject);
        printf("\n");
        fprintf(fptr, "Name = %s, Marks = %d, CGPA = %f, Subject = %s \n", name, marks, cgpa, subject);
    }

    fclose(fptr);
    return 0;
}