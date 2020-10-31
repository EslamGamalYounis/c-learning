#include <stdio.h>
#include <stdlib.h>

 /*int* sortArrayF(int[]arr){
    int i=0,j=0,temp;
    int min =arr[0];
    for(i;i<sizeof(arr)/sizeof(int);i++){
        for(j;j<sizeof(arr)/sizeof(int);j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] =arr[j];
                arr[j] =temp ;
            }
        }
    }
    return arr ;
 }*/

int main()
{
    int size,y,i,j,temp;
    printf("please enter the size of array: \n");
    scanf("%d",&size);
    int arr[size];
    y = sizeof(arr)/sizeof(int);
    //int sorted_array[y];

    printf("please enter the values in array: \n");
    for(i=0;i<y;i++){
        scanf("%d",&arr[i]);
    }

    for(i=0;i<sizeof(arr)/sizeof(int);i++){
        for(j=0;j<sizeof(arr)/sizeof(int);j++){
            if(arr[i]>arr[j]){
                temp = arr[i];
                arr[i] =arr[j];
                arr[j] =temp ;
            }
        }
    }

    printf("the sorted array is :\n");
    for(i=0;i<y;i++){
        printf("%d\t",arr[i]);
    }
    return 0;
}
