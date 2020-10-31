#include <stdio.h>
#include <stdlib.h>

#define null -32
#define esc 27
int main()
{
    char ch;
    do{
    ch=getche();
    printf("\n");
    if(ch!=null)
    {
        printf("key is Normal =>%d \n",ch);
    }
    else
    {
        ch=getch();
        printf("key is Extended =>%d \n",ch);
    }
    }while(ch!=27 );

    return 0;
}
