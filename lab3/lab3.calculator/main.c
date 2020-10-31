#include <stdio.h>
#include <stdlib.h>

    int add(int x,int y){
        int z = x+y;
        return z;
    }

    int sub(int x,int y){
        int z = x-y;
        return z;
    }

    int mul(int x,int y){
        int z = x*y;
        return z;
    }

    int dive(int x,int y){
        int z =0;
        if(y!=0){
        z = x/y;
        }
        else{
         printf("you can not divide by zero try again");
        }
        return z;
    }

int main()
{
    int res=0;
    res = add(5,5);
    printf("the sum is :%d\n",res);

    res = sub(5,5);
    printf("the sub is :%d\n",res);

    res = mul(5,5);
    printf("the mul is :%d\n",res);

    res = dive(5,5);
    printf("the div is :%d\n",res);

    return 0;
}
