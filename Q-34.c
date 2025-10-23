#include <stdio.h>
int main()
{   int n,count=0;
    printf ("enter number = ");
    scanf("%d", &n);
    for (int i=1;i<=n;i++)
   { if (n%i==0)
    {
        count++;
    }
    else 
    continue;
    }
    if(count==2)
    printf ("%d is a prime number",n);
    else 
    printf("%d is not a prime number",n);
    return 0;
}