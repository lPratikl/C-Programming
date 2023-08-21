// 1.Variables, Data types + Input/Output

# include<stdio.h>

int main() {
 //....................................................................................
// // Simple math of 2 inputs 
//     int a, b;
//     printf("enter a ");
//     scanf("%d", &a);

//     printf("enter b ");
//     scanf("%d", &b);

//     printf("sum is: %d \n", a + b);      // Sum of the two values 
//     printf("diff is: %d \n", a - b);     // Difference of the two values 
//     printf("prod is: %d \n", a*b);       // Product of the two values 
//     printf("div is: %d \n", a/b);        // Division of the two values 

 
//....................................................................................
// Calculate area of a square 
    // int side;
    // printf("enter lenght of a side: ");
    // scanf("%d", &side);
    // printf("Area of square = %d \n", side*side);

    // float side2;
    // printf("enter float lenght of a side: ");
    // scanf("%f", &side2);
    // printf("Area of square = %f \n", side2*side2);

 
//.......................................................................................
// Calculate area of a circle 
    // float radius;
    // printf("Enter the radius: ");
    // scanf("%f", &radius);
    // printf("Area of circle = %f", 3.14*radius* radius);

 
//........................................................................................
// Homework 1: 
// 1-Calculate perimeter of a rectangle
// 2-Find the cube of n. 
    int a, b, n;
    printf("Enter sides a: "); 
    scanf("%d", &a);
    printf("Enter sides b: "); 
    scanf("%d", &b);
    printf("Perimeter of rectangle = %d \n", 2*(a+b));     // Calculate perimeter of a rectangle. 

    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Cube of %d = %d", n, n*n*n);                    // Find the cube of n
 
    return 0;
}
