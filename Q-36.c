#include <stdio.h>
int main()
{
    int a,b,hcf=0;
    printf ("enter two number = ");
    scanf ("%d %d", &a,&b);
    int final=(a<b)?a:b;
    for (int i=1;i<=final;i++)
    {
        if (a%i==0 && b%i==0)
        hcf=i;
        else
    continue;
    }
    printf("hcf=%d",hcf);
    return 0; 
}