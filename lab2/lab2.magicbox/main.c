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

int main()
{
  int num,col,row,size=3;
  row=1;
  col=size/2 +1;

  for(num =1 ; num<=9;num++){
    gotoxy(col*3,row*3);
    printf("%i",num);

    if(num%size !=0){
        row--;
        col--;
        if(row==0){
            row=size;
        }
        if(col==0){
            col=size;
        }
    }
    else{
        row++;
        if(row>size){
            row=1;
        }
    }
  }
    return 0;
}



