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
#define left 75
#define right 77
#define back_space 8
#define delete 83



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
    char *name;
    int age;
    float salary;
    float commission;
    float deduction;
};

char* lineEditor(int size,int xPos,int yPos,int startC,int endC)
{
    char *ptr = malloc(size*sizeof(char));
    for(int i=0; i<size; i++)
    {
        gotoxy(xPos+i,yPos);
        textattr(23);
        _cprintf(" ");
    }

    int flag =10;

    //char *pAll;
    char *pfirst,*pcurrent,*plast;
    char ch;
    int currentPos,firstPos,lastPos;
    currentPos=lastPos=firstPos=xPos;
    pcurrent = pfirst =plast =ptr;

    do
    {
        gotoxy(currentPos,yPos);
        ch = getch();

        switch(ch)
        {
        case extended:
            ch=getch();
            switch(ch)
            {
            case home:
                currentPos=xPos;
                pcurrent=ptr;
                break;

            case end:
                currentPos =lastPos;
                pcurrent=plast;
                break;

            case left:
                if(pcurrent>pfirst)
                {
                    currentPos --;
                    pcurrent--;
                }
                break;

            case right:
                if(pcurrent<plast)
                {
                    currentPos ++;
                    pcurrent++;
                }
                break;
                case delete:
                if(pcurrent==plast){
                    break;
                }
                else if(pcurrent<plast&&pcurrent>pfirst)
                {
                    char *tempAdd = pcurrent;
                    for(tempAdd+1; tempAdd<plast; tempAdd++)
                    {
                        *tempAdd = *(tempAdd+1);
                    }
                    tempAdd=pcurrent;
                    plast--;
                    lastPos--;
                    int tempPos = currentPos+1;
                    for(tempPos; tempPos<lastPos; tempPos++)
                    {
                        gotoxy(tempPos,yPos);
                        printf("%c",*(tempAdd+1));
                        tempAdd++;
                    }
                    gotoxy(lastPos,yPos);
                    textattr(23);
                    _cprintf(" ");
                }
                break;
            }
            break;

        case enter:
            flag=-1;
            *plast='\0';
            break;

        case esc:
            flag=-1;
            *plast='\0';
            break;

        case back_space:
            if(pcurrent==plast&&pcurrent>pfirst)
            {
                pcurrent--;
                plast--;
                currentPos--;
                lastPos--;
                gotoxy(currentPos,yPos);
                textattr(23);
                _cprintf(" ");
            }
            else if(pcurrent<plast&&pcurrent>pfirst);
            {
                char *tempAdd = pcurrent;
                for(pcurrent; pcurrent<plast; pcurrent++)
                {
                    *pcurrent = *(pcurrent+1);
                }
                pcurrent=tempAdd;
                pcurrent--;
                currentPos--;
                plast--;
                lastPos--;
                int tempPos = currentPos+1;

                for(tempPos; tempPos<=lastPos; tempPos++)
                {
                    gotoxy(tempPos,yPos);
                    printf("%c",*tempAdd);
                    tempAdd++;
                }
                break;
            }
            break;

        default:
            if(isprint(ch)&&ch>startC&&ch<endC)
            {
                if(pcurrent<pfirst+size)
                {
                    if(pcurrent==plast)
                    {
                        *pcurrent =ch;
                        printf("%c",ch);
                        pcurrent++;
                        currentPos++;
                        plast++;
                        lastPos++;
                    }
                    else
                    {
                        *pcurrent =ch;
                        printf("%c",*pcurrent);
                        pcurrent++;
                        currentPos++;
                    }
                }
            }
            break;
        }
    }
    while(flag==10);

    for(int i=0; i<size; i++)
    {
        gotoxy(xPos+i,yPos);
        textattr(23);
        _cprintf(" ");
    }
    return  ptr;
}

int main()
{
    struct Employee employee[3];
    struct Employee *pEmployee;
    pEmployee =&employee;

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

    for(int i=0;i<3;i++){
    pEmployee[i].id=atoi(lineEditor(4,12,5,47,58));
    _flushall();
    pEmployee[i].name=lineEditor(20,33,5,96,123);
    _flushall();
    pEmployee[i].age=atoi(lineEditor(3,12,15,47,58));
    pEmployee[i].salary=atof(lineEditor(10,33,15,45,58));
    pEmployee[i].commission=atof(lineEditor(6,12,25,45,58));
    pEmployee[i].deduction=atof(lineEditor(6,33,25,45,58));
    //system("cls");

    }

    system("cls");

    for(int i=0;i<3;i++){
        printf("employee id :%d\n",employee[i].id);
        printf("employee name :%s\n",employee[i].name);
        printf("employee age :%d\n",employee[i].age);
        printf("employee salary :%f\n",employee[i].salary);
        printf("employee commission :%f\n",employee[i].commission);
        printf("employee deduction :%f\n",employee[i].deduction);
    }

    return 0;
}
