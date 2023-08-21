//Functions & Recursions 
#include<stdio.h>
#include<math.h>
//..................................................................
// // Functions
// float squareArea(float side);
// float circleArea(float rad);
// float rectangleArea(float a, float b);

// int main() {
//     float a = 5.0;
//     float b = 10.0;

//     printf("Area = %f", rectangleArea(a, b));
//     return 0;
// }

// float squareArea(float side) {
//     return side * side;
// }

// float circleArea(float rad) {
//     return 3.14 * rad * rad;
// }

// float rectangleArea(float a, float b) {
//     return a * b;
// }

//...........................................................................
//Recursive Function  

// int calcPer(int science, int math, int english);

// int main() {
//     int sc = 98;
//     int math = 95;
//     int en = 99;

//     printf("Percentage = %d", calcPer(sc, math, en));
//     return 0; 
// }


// int calcPer(int science, int math, int english) {
//     return (science + math + english)/3;
// }

//......................................................................
// Print n terms of fibonacci sequence 
// int fib(int n);

// int main() {
//     printf("%d",fib(6)); 
//     return 0;
// }

// int fib(int n ) {
//         if (n==0) {
//             return 0;
//         }
//         if (n==1) {
//             return 1;
//         }

//     int fibNm1 = fib(n-1);
//     int fibNm2 = fib(n-2);
//     int fibN = fibNm1+ fibNm2;
//     // printf("Fib of %d = %d \n", n, fibN);
//     return fibN;
// }


//.......................................................................................
// Function to find sum, root, power, and temp. 
int sum(int a, int b);
double root(double n);
void temp(int t);
double power(double x, double y);

int main() {
    int a, b, t;
    double n, x, y; 
    printf("Find the sum of two values: "); 
    scanf("%d  %d", &a, &b);
    printf("Answer = %d \n", sum(a, b)); 

    printf("Find the root of a number: ");
    scanf("%lf", &n);
    printf("Root of %.2lf = %.2lf \n", n, root(n));

    printf("Enter Temperature: ");
    scanf("%d", &t);
    temp(t);

    printf("Enter a number and power: ");
    scanf("%lf %lf", &x, &y);
    printf("%lf ^ %lf = %.2lf", x, y, pow(x, y));

    return 0;
}

int sum(int a, int b) {
    int sum = a + b;
    return sum; 
}

double root(double n) {
    double root = sqrt(n);
    return root;
}

void temp(int t) {
    if (t >= 30) {
        printf("HOT HOT HOT \n");
    } else {
        printf("Cold Cold Cold \n");
    }
}

double power(double x, double y) {
    double power = pow(x, y);
    return power; 
}


//.....................................................................................


