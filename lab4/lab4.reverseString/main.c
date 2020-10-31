#include <stdio.h>
#include <stdlib.h>
#define enter 13

int main()
{
    char arr[50]={""};
    char ch;
    int x=0;
    int start=0,end=0;
    char endOfString="";
    char temp="";

    printf("enter message to reverse it \n");
    while((ch=getche())!= enter)
    {
     arr[x]=ch;
     x++;
    }
    arr[x]='\0';

    printf("the message is :\n");
    int y=0;
    while(arr[y]!='\0'){
        printf("%c",arr[y]);
        y++;
    }
     printf("\n");

    for(int i=0;i<sizeof(arr);i++){
        if(arr[i]=='\0')
        {
           //endOfString =arr[i-1];
           end=i-1;
        }
    }
    while (start < end)
            {
            temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
            }

    printf("the reversed message is :\n");
    _flushall();
    for(int i =0;i<sizeof(arr);i++)
    {   if(arr[i]!='\0'){
        printf("%c",arr[i]);
    }
    }
    return 0;
}
