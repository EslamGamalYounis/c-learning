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

    struct Employee employee[10]={0};;
    struct Employee emptyEmployee={0,"",0,0.0,0.0,0.0};;
    char menu[6][15]={"New","DisplayAll","DisplayById","DeleteAll","DeleteById","Exit"};
    int cursor=0;
    char ch;
    int flag=1;

    do{
       system("cls");
        for(int i=0;i<6;i++){
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
                        cursor=5;
                    }
                 break;

                case down:
                    cursor++;
                    if(cursor>5){
                    cursor=0;
                    }
                break;

                case home:
                    cursor=0;
                break;

                case end:
                    cursor=5;
                break;
            }
            break;
        case enter:
            switch(cursor)
            {
                case 0:
                system("cls");
                int index=0;
                printf("where are you need to add employee from 1 to 10\n");
                scanf("%d",&index);

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
                        scanf("%d",&employee[index-1].id);

                        _flushall();
                        gotoxy(33,5);
                        scanf("%s",&employee[index-1].name);

                        _flushall();
                        gotoxy(12,15);
                        scanf("%d",&employee[index-1].age);


                        gotoxy(33,15);
                        scanf("%f",&employee[index-1].salary);


                        gotoxy(12,25);
                        scanf("%f",&employee[index-1].commission);


                        gotoxy(33,25);
                        scanf("%f",&employee[index-1].deduction);

                getch();
                break;

                case 1:
                system("cls");
                for(int i=0;i<3;i++){
                    if(employee[i].id!=0){
                    printf("employee id :%d\n",employee[i].id);
                    printf("employee name :%s\n",employee[i].name);
                    printf("employee age :%d\n",employee[i].age);
                    printf("employee sallry :%f\n",employee[i].salary);
                    printf("employee commission :%f\n",employee[i].commission);
                    printf("employee deduction :%f\n",employee[i].deduction);
                    }
                    else{
                     printf("no any employee data here please add some");
                    }
                }
                getch();
                break;

                case 2:
                    system("cls");
                    int id;
                    printf("enter the id to display user from 1 to 10:\n");
                    scanf("%d",&id);
                    for(int i=0;i<10;i++){
                       if(employee[i].id==id){
                        printf("employee id :%d\n",employee[i].id);
                        printf("employee name :%s\n",employee[i].name);
                        printf("employee age :%d\n",employee[i].age);
                        printf("employee sallry :%f\n",employee[i].salary);
                        printf("employee commission :%f\n",employee[i].commission);
                        printf("employee deduction :%f\n",employee[i].deduction);
                        }

                }
                getch();
                break;

                case 3:
                system("cls");
                    for(int i=0;i<10;i++){
                        employee[i]=emptyEmployee;
                    }
                    printf("all employee deleted successfully");
                getch();
                break;

                case 4:
                    system("cls");
                    int _id;
                    int _index;
                    printf("enter the id to delete user from 1 to 10:\n");
                    scanf("%d",&_id);
                    for(int i=0;i<10;i++){
                        if(employee[i].id==_id){
                          _index=i;
                          break;
                        }
                    }
                    struct Employee temp;
                    for(int i=_index;i<10;i++){
                        temp = employee[i];
                        employee[i]= employee[i+1];
                        employee[i+1]=temp;
                    }
                    printf("employee deleted successfully");
                break;


                case 5:
                flag=-1;
                break;
            }
            break;
        case esc:
            flag=-1;
        break;

        case tab:
            cursor++;
            if(cursor>5){
                cursor =0;
            }
        break;
       }

    }while(flag==1);

    return 0;
}
