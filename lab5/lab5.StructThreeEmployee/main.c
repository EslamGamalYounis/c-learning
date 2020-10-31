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
    struct Employee employee[3];


    for(int i=0;i<3;i++){
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
    scanf("%d",&employee[i].id);

    _flushall();
    gotoxy(33,5);
    scanf("%s",&employee[i].name);

    _flushall();
    gotoxy(12,15);
    scanf("%d",&employee[i].age);


    gotoxy(33,15);
    scanf("%f",&employee[i].salary);


    gotoxy(12,25);
    scanf("%f",&employee[i].commission);


    gotoxy(33,25);
    scanf("%f",&employee[i].deduction);

    system("cls");
    }

    system("cls");

    for(int i=0;i<3;i++){
        printf("employee id :%d\n",employee[i].id);
        printf("employee name :%s\n",employee[i].name);
        printf("employee age :%d\n",employee[i].age);
        printf("employee sallry :%f\n",employee[i].salary);
        printf("employee commission :%f\n",employee[i].commission);
        printf("employee deduction :%f\n",employee[i].deduction);
    }

    return 0;
}
