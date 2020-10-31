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
        }
    }
    while(flag==10);

    return  ptr;

}

int main()
{
    char *pArray;
    int size,xPos,yPos,startC,endC;

    printf("please enter size: ");
    scanf("%d",&size);

    printf("please enter XStartPosition: ");
    scanf("%d",&xPos);

    printf("please enter yStartPosition: ");
    scanf("%d",&yPos);

    printf("please enter StartCharAscii: ");
    scanf("%d",&startC);

    printf("please enter EndCharAscii: ");
    scanf("%d",&endC);

    pArray = lineEditor(size,xPos,yPos,startC,endC);


    system("cls");
    for(int i=0;i<size;i++){
        printf("%c",pArray[i]);
    }
    return 0;
}
