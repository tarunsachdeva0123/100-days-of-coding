#include <stdio.h>
int main ()
{   int rev=0,m;
    printf ("enter no. ");
    scanf("%d",&m);
    while (m!=0)
    {
        rev=(m%10)+rev*10;
        m=m/10;
    }
    printf ("reverse no.%d \n",rev);
    return 0;
}