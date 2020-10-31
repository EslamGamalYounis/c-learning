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
#define Delete 127

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

int main()
{
    int flag =10;
    char line[30];
    char *pfirst,*pcurrent,*plast;
    char ch;
    int currentPos,firstPos,lastPos;
    currentPos=lastPos=firstPos=10;

    for(int i=0; i<31; i++)
    {

        gotoxy(10+i,10);
        textattr(27);
        _cprintf(" ");
    }

    pcurrent = pfirst =plast =line;
    do
    {
        gotoxy(currentPos,10);
        ch = getch();

        switch(ch)
        {
        case extended:
            ch=getch();
            switch(ch)
            {
            case home:
                currentPos=10;
                pcurrent=line;
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
                        gotoxy(tempPos,10);
                        printf("%c",*(tempAdd+1));
                        tempAdd++;
                    }
                    gotoxy(lastPos,10);
                    textattr(27);
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

        default:
            if(isprint(ch))
            {
                if(pcurrent<pfirst+30)
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
        case back_space:
            if(pcurrent==plast&&pcurrent>pfirst)
            {
                pcurrent--;
                plast--;
                currentPos--;
                lastPos--;
                gotoxy(currentPos,10);
                textattr(27);
                _cprintf(" ");
            }
            else if(pcurrent<plast)
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
                    gotoxy(tempPos,10);
                    printf("%c",*tempAdd);
                    tempAdd++;
                }
            }
            break;
            }

        }
    while(flag==10);

    system("cls");
    printf("%s",line);
    return 0;
}


