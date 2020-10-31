#include <stdio.h>
#include <stdlib.h>

int main()
{
    char op;
    printf("a- good morning\n");
    printf("b- good afternoon\n");
    printf("c- good bye\n");

    do{
    printf("enter character a,b,c: \t");
    _flushall();
    scanf("%c",&op);
    switch(op)
            {
            case 'a':
              printf("good morning\n");
              break;
            case 'A':
              printf("good morning\n");
              break;
            case 'b':
              printf("good afternoon\n");
              break;
            case 'c':
              printf("good bye\n");
              break;

            default:
              printf("invalid char please try again\n");
              break;
            }
           }while(op!='c');
    return 0;
}
