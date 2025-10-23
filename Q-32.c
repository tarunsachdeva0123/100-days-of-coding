#include <stdio.h>
int main ()
{   int n,rev=0,m;
    printf ("enter no. ");
    scanf("%d",&n);
    m=n;
    while (m!=0)
    {
        rev=(m%10)+rev*10;
        m=m/10;
    }
    printf ("reverse no.%d \n",rev);
    if (n==rev)
    printf ("the no. is palindrome");
    else 
    printf("the no is not palindrome");
    return 0;

}