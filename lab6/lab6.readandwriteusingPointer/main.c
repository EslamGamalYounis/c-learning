#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[10];
    int *ptr;

    ptr =arr;
    printf("please enter the number in array :\n");
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        scanf("%d",ptr);
        ptr++;
    }

    system("cls");
    ptr=arr;
    printf("\nthe number that you entered is:\t ");
    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        printf("%d ",*ptr);
        ptr++;
    }


    return 0;
}
