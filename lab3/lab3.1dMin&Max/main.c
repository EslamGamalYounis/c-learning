#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[7];
    int i;
    int y =sizeof(arr)/sizeof(int);
    int min,max;

    printf("please enter the values in array \n");
    for(i=0;i<y;i++){
        scanf("%d",&arr[i]);
    }
    min=arr[0];
    max=arr[0];
    for(i=0;i<y;i++){
        if(arr[i]>max){
            max =arr[i];
        }

        if(arr[i]<min){
            min =arr[i];
        }
    }
    printf("the max is :%d\n" ,max);
    printf("the min is :%d",min);

    return 0;
}
