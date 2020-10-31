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
int main()
{

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
                printf("New Page");
                getch();
                break;

                case 1:
                system("cls");
                printf("Display Page");
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
