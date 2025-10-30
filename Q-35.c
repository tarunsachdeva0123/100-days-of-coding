#include <stdio.h>
int main ()
{   int n,fact;
    printf ("type the first no.");
    scanf ("%d",&n);
    for (int i=1;i<=n;i++)
    {
        fact=n%i;
        if (fact==0)
        {
            printf (" %d factor\n" ,i);
        }
        else 
        continue;

    }
    return 0 ;
}