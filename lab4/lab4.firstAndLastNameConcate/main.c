#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char firstName[10]={""};
    char lastName[10]={""};
    char fullName[21]={""};

    printf("please enter the first name: \n");
    gets(firstName);

    printf("please enter the last name: \n");
    gets(lastName);

    strcpy(fullName,firstName);
    strcat(fullName," ");

    strcat(fullName,lastName);

    printf("the full name is :\t ");
    puts(fullName);

    return 0;
}
