#include <stdio.h>
#include <stdlib.h>

int main()
{
    int presentDate =19,presentMonth=10,presentYear=2020;
    int birthDate,birthMonth,birthYear;
    int yourDays,yourMonths,yourYears;
    int month[]={31,28,31,30,31,30,31,31,30,31,30,31};
    printf("enter your birth year\n");
    scanf("%d",&birthYear);
    _flushall();
    printf("enter your birth month\n");
    scanf("%d",&birthMonth);
    _flushall();
    printf("enter your birth date\n");
    scanf("%d",&birthDate);

    if(birthDate>presentDate){
        presentDate = presentDate+month[birthMonth-1];
        presentMonth = presentMonth-1;
    }

    if(birthMonth>presentMonth){
        presentYear =presentYear -1;
        presentMonth =presentMonth +12;
    }

    yourDays = presentDate - birthDate;
    yourMonths = presentMonth - birthMonth;
    yourYears = presentYear - birthYear;

    printf("Age is years: %d months: %d days: %d" ,yourYears,yourMonths,yourDays);


    return 0;
}
