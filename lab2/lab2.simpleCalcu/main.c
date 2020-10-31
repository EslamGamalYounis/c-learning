#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1 , num2 , result;
    char operator , option ='y';

    do{
    printf("enter number one:\n");
    scanf("%d",&num1);

    printf("enter number two: \n");
    scanf("%d",&num2);

    _flushall();
    printf("enter operator :\n");
    scanf("%c",&operator);

    switch(operator)
    {
    case '+':
      result = num1 +num2;
      break;
    case '-':
      result = num1 -num2;
      break;
    case '*':
      result = num1 *num2;
      break;
    case '/':
      if(num2!=0){
      result = num1 /num2;
      }
      else{
        printf("You can not div by zero\n");
        break;
      }
      break;
    default:
        printf("it is not valid opeator");
        break;
    }

    printf("result is =%d",result);

    printf("\n do you want to continue y/n \n");
    _flushall();
    scanf("%c",&option);
    }
    while(option=='y');
    return 0;
}
