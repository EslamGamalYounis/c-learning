#include <stdio.h>
#include <stdlib.h>

int power(int ba,int po){
    if(po==0){
        return 1;
    }
    else{
        return ba*power(ba,po-1);
    }
}

int fact(int num){
    if(num==1){
        return 1;
    }
    else{
        return num*fact(num-1);
    }
}

int fib(int num){
    if(num==0){
        return 0;
    }
    else if(num==1){
        return 1;
    }
    else{
        return (fib(num-1)+fib(num-2));
    }

}


int binary_fun(int num)
{
    if (num==0)
        return 0;
    else
        return ((num%2)+10*binary_fun(num/2));
}

int main()
{
    int x = 0,y=0, z=0;
    int binaryRes;
    int decimal;
    x =power(5,3);
    printf("power is:%d\n",x);

    y=fact(4);
    printf("factorial is:%d\n",y);

    z=fib(8);
    printf("fib is:%d\n",z);

    printf("enter the decimal to convert to binary\n");
    scanf("%d",&decimal);
    binaryRes = binary_fun(decimal);
    printf("%d",binaryRes);
    return 0;
}
