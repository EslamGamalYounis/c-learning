#include <stdio.h>
#include <stdlib.h>

char* binary_fun(int num){
int x=0;
char * ptr;
ptr=(char*)malloc(30);
for(int i=0;i<=sizeof(ptr)-1;i++){
    if(num>0){
        if(num%2==0){
            ptr[i]='0';
        }
        else{
            ptr[i]='1';
        }
        num=num/2;
    }
    x++;
}
ptr[x]='\0';
return ptr;
}

int main()
{
    char* pArr;
    int decimal;
    printf("enter the decimal to convert to binary\n");
    scanf("%d",&decimal);
    pArr = binary_fun(decimal);
    printf("%s",pArr);
    return 0;
}
