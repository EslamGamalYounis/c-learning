#include <stdio.h>
#include <stdlib.h>

int main()
{

    char c = 'M';
    char result = tolower(c);


    printf("tolower(%c) = %c\n", c, result);


    char d;

    d = 'm';
    printf("%c -> %c\n", d, toupper(d));

   int val;
   char str[20];

   strcpy(str, "98993489");
   val = atoi(str);
   printf("String value = %s, Int value = %d\n", str, val);

   strcpy(str, "tutorialspoint.com");
   val = atoi(str);
   printf("String value = %s, Int value = %d\n", str, val);

   int val1;
   char str1[20];

   strcpy(str1, "2222.98993489");
   val1 = atof(str1);
   printf("String value = %s, Float value = %f\n", str1, val1);

   strcpy(str1, "tutorialspoint.com");
   val1 = atof(str1);
   printf("String value = %s, Float value = %f\n", str1, val1);

    return 0;
}
