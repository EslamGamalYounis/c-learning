#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr1[3][2],arr2[2][1];
    int res[3][1];
    int i,j,x;

    printf("please enter the element of first array \n");
    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            scanf("%i",&arr1[i][j]);
        }
    }

    printf("please enter the element of second array \n");
    for(i=0;i<2;i++){
        for(j=0;j<1;j++){
            scanf("%i",&arr2[i][j]);
        }
    }

    for(i=0;i<3;i++){
        for(j=0;j<2;j++){
            for(x=0;x<1;x++){
                res[i][x] +=arr1[i][j]*arr2[j][x];
            }
        }
    }

    printf("the result array of mul this 2d arrays\n");

    for(j=0;j<3;j++){
            for(x=0;x<1;x++){
              printf("%i\t",res[j][x]);
            }
        }

    return 0;
}
