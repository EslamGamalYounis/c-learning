#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr1[3][3],arr2[3][2];
    int res[3][2]={0};
    int i,j,x;

    printf("please enter the element of first array \n");
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            scanf("%i",&arr1[i][j]);
        }
    }

    printf("please enter the element of second array \n");
    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            scanf("%i",&arr2[i][j]);
        }
    }

for(x=0;x<2;x++){
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            res[i][x] +=arr1[i][j]*arr2[j][x];
        }
    }
}

    printf("the result array of mul this 2d arrays\n");

    for(j=0;j<3;j++){
            for(x=0;x<2;x++){
              printf("%i\t",res[j][x]);
            }
            printf("\n");
        }

    return 0;
}
