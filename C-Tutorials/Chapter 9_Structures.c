// Structures 
#include <stdio.h>
#include <string.h>

// typedef struct student {
//     int roll;
//     float cgpa;
//     char name[100];
// } stu;

// typedef struct computerengineeringstudent {
//     int roll;
//     float cgpa;
//     char name[100];
// } coe;

// void printInfo(struct student s3);

// int main() {
//     coe s1;
//     s1.roll = 1664;
//     s1.cgpa = 4.03;
//     strcpy(s1.name, "Pratik");

//     printf("Student name = %s \n", s1.name);
//     printf("Roll no = %d \n", s1.roll);
//     printf("CGPA = %f \n", s1.cgpa);
//     printf("\n");

//     struct student s2 = {1660, 3.93, "Limbu"};
//     printf("Student name = %s \n", s2.name);
    
//     struct student *ptr = &s2;
//     printf("Name -> %s \n", ptr->name);
//     printf("Roll no = %d \n", (*ptr).roll);
//     printf("CGPA -> %f \n", ptr->cgpa);
//     printf("\n");


//     struct student s3 = {1780, 3.9, "LP"};
//     printInfo(s3);

//     s3.roll =1990;
//     printf("Student roll = %d \n", s3.roll);

//     return 0;
// }

// void printInfo(struct student s3) {
//     printf("Student Information: \n");
//     printf("Studnet.roll = %d \n", s3.roll);
//     printf("Student.name = %s \n", s3.name);
//     printf("Studnet.cgpa = %f \n", s3.cgpa);

//     s3.roll = 1900;
// }

//........................................................................................
//Enter address (House No., Block, City, State) of 5 people.
// struct address {
//     int houseNo;
//     int block;
//     char city[100];
//     char state[100];
// };

// void printAdd(struct address add) {
//     printf("Address is: %d, %d, %s, %s \n", add.houseNo, add.block, add.city, add.state);
// }

// int main() {
//     struct address adds[5];

//     printf("Enter Info for person 1: ");
//     scanf("%d", &adds[0].houseNo);
//     scanf("%d", &adds[0].block);
//     scanf("%s", adds[0].city);
//     scanf("%s", adds[0].state);

//     printf("Enter Info for person 2: ");
//     scanf("%d", &adds[1].houseNo);
//     scanf("%d", &adds[1].block);
//     scanf("%s", adds[1].city);
//     scanf("%s", adds[1].state);

//     // printf("Enter Info for person 3: ");
//     // scanf("%d", &adds[2].houseNo);
//     // scanf("%d", &adds[2].block);
//     // scanf("%s", adds[2].city);
//     // scanf("%s", adds[2].state);

//     // printf("Enter Info for person 4: ");
//     // scanf("%d", &adds[3].houseNo);
//     // scanf("%d", &adds[3].block);
//     // scanf("%s", adds[3].city);
//     // scanf("%s", adds[3].state);

//     // printf("Enter Info for person 5: ");
//     // scanf("%d", &adds[4].houseNo);
//     // scanf("%d", &adds[4].block);
//     // scanf("%s", adds[4].city);
//     // scanf("%s", adds[4].state);

//     printAdd(adds[0]);
//     printAdd(adds[1]);

//     return 0;
// }

//.......................................................................................
//Create a vector. 

// struct vector {
//     int x;
//     int y;
// }; 

// void calSum(struct vector v1, struct vector v2, struct vector sum);

// int main() {
//     struct vector v1 = {5, 10};
//     struct vector v2 = {3, 7};
//     struct vector sum ={0}; 
//     calSum(v1,v2, sum);
//     return 0;
// }

// void calSum(struct vector v1, struct vector v2, struct vector sum) {
//     sum.x = v1.x + v2.x;
//     sum.y = v1.y + v2.y;

//     printf("Sum of x = %d \n", sum.x);
//     printf("Sum of y = %d \n", sum.y);
// }

//.....................................................................................
// Create a structure to store complex numbers (use arrow operator).
// struct complex {
//     int real;
//     int img;
// };

// int main() {
//     struct complex number1 = {5, 8};
//     struct complex *ptr = &number1;
//     printf("Real part = %d \n", ptr->real);
//     printf("Img part = %d \n", ptr->img);

//     return 0;
// }

//...................................................................
// Create a Bank Account 
// typedef struct BankAccount {
//     int accountNo;
//     char name[100];
// } acc;

// int main() {
//     acc acc1 = {123, "POLP"};
//     acc acc2 = {124, "OLO"};
//     acc acc3 = {990, "LOBNM"};

//     printf("Account number = %d \n", acc1.accountNo);
//     printf("Name = %s", acc1.name); 
    
//     return 0;
// }


//.........................................................................................


