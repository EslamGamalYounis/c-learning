#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

#define up 72
#define down 80
#define enter 13
#define esc 27
#define extended -32
#define home 71
#define end 79
#define tab 9

void gotoxy( int column, int line )
{
    COORD coord;
    coord.X = column;
    coord.Y = line;
    SetConsoleCursorPosition(GetStdHandle( STD_OUTPUT_HANDLE ),coord);
}
void textattr(int i)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), i);

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
    char menu[3][10]={"New","Display","Exit"};
    int cursor=0;
    char ch;
    int flag=1;

    do{
       system("cls");
        for(int i=0;i<3;i++){
            if(i==cursor){
                textattr(2);
            }
            else{
                textattr(15);
            }
            gotoxy(20,20+i*2);
            _cprintf("%s",menu[i]);
        }
    _flushall();
    ch =getche();
       switch(ch)
       {
        case extended:
            ch=getch();
            switch(ch){
                case up:
                    cursor--;
                    if(cursor<0){
                        cursor=2;
                    }
                 break;

                case down:
                    cursor++;
                    if(cursor>2){
                    cursor=0;
                    }
                break;

                case home:
                    cursor=0;
                break;

                case end:
                    cursor=2;
                break;
            }
            break;
        case enter:
            switch(cursor)
            {
                case 0:
                system("cls");
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
                getch();
                break;

                case 1:
                system("cls");
                for(int i=0;i<3;i++){
                    printf("employee id :%d\n",employee[i].id);
                    printf("employee name :%s\n",employee[i].name);
                    printf("employee age :%d\n",employee[i].age);
                    printf("employee sallry :%f\n",employee[i].salary);
                    printf("employee commission :%f\n",employee[i].commission);
                    printf("employee deduction :%f\n",employee[i].deduction);
                }
                getch();
                break;

                case 2:
                flag=-1;
                break;
            }
            break;
        case esc:
            flag=-1;
        break;

        case tab:
            cursor++;
            if(cursor>2){
                cursor =0;
            }
        break;
       }

    }while(flag==1);

    return 0;
}
