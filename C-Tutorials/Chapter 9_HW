// Make a system that can store information of all students, teachers, & staff in form of... 
// structures (include cpga, attendacne)

#include <stdio.h>
#include <string.h>

void studentinfo();                                   // Store & Display student info 
void teacherinfo();                                   // Store & Display teacher info
void staffinfo();                                     // Store & Display staff info 


struct student {                                     // Create a strutrue for student info
    char name[50];                                   // Name, Roll no. GPA, Attendacen 
    int roll;
    float cgpa;
    int attend;
} stu[5];

typedef struct teacher {
    char name[50];
    char subject[50];
    int id;
} teach;

typedef struct staff {
    char name[50];
    int id;
    char depart[50];
} staff;


int main() {
    int i, j = 0, roll; 
    char ch;
    printf("S: Student, T: Teacher, s: staff ;  " );
    scanf("%c", &ch);

    if (ch == 'S')
        studentinfo();
    else if (ch == 'T')
        teacherinfo();
    else if (ch == 's');
        staffinfo();    

    return 0;
}

void studentinfo() {
    int i, j=0;
    for (i=0; i<2; i++) {
    stu[i].roll = i+1;
    printf("Roll number = %d\n", stu[i].roll);
    printf("Enter Student name: ");
    scanf("%s", stu[i].name);
    printf("Enter cgpa: ");
    scanf("%f", &stu[i].cgpa);                      // Remeber to put '&' for int, floats. 
    printf("Enter attendance: ");
    scanf("%d", &stu[i].attend); 
    }

    do {
        printf("Roll number = %d  ", j+1);
        printf("Name =  %s  ", stu[j].name);
        // puts(stu[j].name);
        printf("Cgpa = %f  ", stu[j].cgpa);
        printf("Attendance = %d \n", stu[j].attend);
        j++;
    } while(j < 5); 
}

void teacherinfo() {
    int i, j=0;
    teach t[i];
    for(i=0; i<2; i++) {       
        t[i].id = 101+i;
        printf("Teacher ID = %d\n", t[i].id);
        printf("Enter Teacher name: ");
        scanf("%s", t[i].name);
        printf("Enter subject: ");
        scanf("%s", t[i].subject);
        printf("\n");
    }
    
    while (j<3) {
        printf("Teacher ID = %d  ", t[j].id);
        printf("Teacher name = %s  ", t[j].name);
        printf("Teacher Subject = %s \n",t[j].subject);         
        j++;
    }           
}

void staffinfo() {
    int i, j=0;
    staff s[i];
    for(i=0; i<2; i++) {       
        s[i].id = 501+i;
        printf("Staff ID = %d\n", s[i].id);
        printf("Enter Staff name: ");
        scanf("%s", s[i].name);
        printf("Enter Department: ");
        scanf("%s", s[i].depart);
        printf("\n");
    }

    for (j=0; j<3; j++) {
        printf("Staff ID = %d  ", s[j].id);
        printf("Staff name = %s  ", s[j].name);
        printf("Department = %s \n",s[j].depart);         
    }  
}
