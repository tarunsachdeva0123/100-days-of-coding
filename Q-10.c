#include <stdio.h>
int main()

{ int a;
int sec,hour,min;
printf ("type seconds= ");
scanf("%d",&a);
sec= a%60;
hour=a/3600;
min= (a%3600)/60;
printf("%d:%d:%d", hour, min,sec);
return 0;

}