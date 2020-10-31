#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1 =0,dicimalNum = 0,remainder;
    int i, j = 0;
    char hexaDicimalNum[100];

    printf("please enter the decimal number\n");
    scanf("%d",&dicimalNum);

    num1=dicimalNum;

    while(num1 != 0){
       remainder = num1%16;
       if(remainder <10){
          hexaDicimalNum[j++]=48+remainder;
       }
       else{
          hexaDicimalNum[j++]=55+remainder;
          num1 = num1/16;
       }
    }

// display integer into character
    printf("the hexadecimal numer is : ");
    for (i = j; i >= 0; i--)
    printf("%c", hexaDicimalNum[i]);

    return 0;
}
