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

char* lineEditor(int size,int xPos,int yPos,int startC,int endC){
    char *ptr = malloc(size*sizeof(char));
    for(int i=0; i<size; i++)
        {
            gotoxy(xPos+i,yPos);
            textattr(27);
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
                if(pcurrent<plast)
                {
                    char *tempAdd = pcurrent;
                    for(pcurrent+1; pcurrent<plast; pcurrent++)
                    {
                        *pcurrent = *(pcurrent+1);
                    }
                    pcurrent=tempAdd;
                    plast--;
                    lastPos--;
                    int tempPos = currentPos+1;
                    for(tempPos; tempPos<lastPos; tempPos++)
                    {
                        gotoxy(tempPos,yPos);
                        printf("%c",*tempAdd+1);
                        tempAdd++;
                    }
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
            //*pcurrent="";
            if(pcurrent==plast&&pcurrent>pfirst)
            {
                pcurrent--;
                plast--;
                currentPos--;
                lastPos--;
                gotoxy(currentPos,yPos);
                textattr(27);
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

    return  ptr;

}

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

    //gotoxy(12,5);
    emp1.id=atoi(lineEditor(4,12,5,0,128));
    //scanf("%d",&emp1.id);

    _flushall();
    //gotoxy(33,5);
    //scanf("%c",&emp1.name);
    emp1.name=lineEditor(20,33,5,0,128);

    _flushall();
    //gotoxy(12,15);
    //scanf("%d",&emp1.age);
    emp1.age=atoi(lineEditor(3,12,15,0,128));

    /*gotoxy(33,15);
    scanf("%f",&emp1.salary);*/
    emp1.salary=atof(lineEditor(10,33,15,0,128));


    /*gotoxy(12,25);
    scanf("%f",&emp1.commission);*/
    emp1.commission=atof(lineEditor(6,12,25,0,128));


    /*gotoxy(33,25);
    scanf("%f",&emp1.deduction);*/
    emp1.deduction=atof(lineEditor(6,33,25,0,128));

    system("cls");

    printf("emp1 id :%d\n",emp1.id);
    printf("emp1 name :%s\n",emp1.name);
    printf("emp1 age :%d\n",emp1.age);
    printf("emp1 sallry :%f\n",emp1.salary);
    printf("emp1 commission :%f\n",emp1.commission);
    printf("emp1 deduction :%f\n",emp1.deduction);





    return 0;
}

