#include <stdio.h>
#include <stdlib.h>
#include <windows.h>


void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}


struct Employee
{
    int id;
    char name[10];
    int age;
    float salary;
    float commission;
    float deduction;
};

int main()
{
    struct Employee emp1;
    gotoxy(5,5);
    printf("id:");
    gotoxy(25,5);
    printf("name:");
    gotoxy(5,15);
    printf("age:");
    gotoxy(25,15);
    printf("salary:");
    gotoxy(5,25);
    printf("comm:");
    gotoxy(25,25);
    printf("deduc:");

    gotoxy(12,5);
    scanf("%d",&emp1.id);

    _flushall();
    gotoxy(33,5);
    scanf("%c",&emp1.name);

    _flushall();
    gotoxy(12,15);
    scanf("%d",&emp1.age);


    gotoxy(33,15);
    scanf("%f",&emp1.salary);


    gotoxy(12,25);
    scanf("%f",&emp1.commission);


    gotoxy(33,25);
    scanf("%f",&emp1.deduction);

    system("sls");

    printf("emp1 id :%d\n",emp1.id);
    printf("emp1 name :%s\n",emp1.name);
    printf("emp1 age :%d\n",emp1.age);
    printf("emp1 sallry :%f\n",emp1.salary);
    printf("emp1 commission :%f\n",emp1.commission);
    printf("emp1 deduction :%f\n",emp1.deduction);





    return 0;
}
