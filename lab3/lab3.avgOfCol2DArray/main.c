#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,d1,d2;

    printf("please enter the dime for array:\n");
    scanf("%i",&d1);
    scanf("%i",&d2);

    int arr[d1][d2];
    float avg[d2];//={0.0};
    printf("please enter the values for array:\n");
    for(i=0;i<d1;i++){
        for(j=0;j<d2;j++){
            scanf("%i",&arr[i][j]);
        }
    }

    printf("the two dimen array is:\n");
    for(i=0;i<d1;i++){
        for(j=0;j<d2;j++){
            printf("%i\t",arr[i][j]);
        }
        printf("\n");
    }

    for(j=0;j<d2;j++){
            avg[j]=0;
        for(i=0;i<d1;i++){
            avg[j] += arr[i][j]/3;
        }
    }

    printf("the avg for the 3 col is :");
        for(j=0;j<d2;j++){
            printf("%f\t",avg[j]);
        }

    return 0;
}
