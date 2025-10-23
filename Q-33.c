#include <stdio.h>
#include <math.h>

int main ()
{   int m,n,sum=0,num=0;
    printf ("type the required number :");
    scanf ("%d",&n);
    m = n;
    while(m!=0)
    {
        m/=10;
        num++;
    }
    m=n;
    while (m!=0)
    {
        sum= pow((m%10),num)+sum;
        m=m/10;
    }
    if(n==sum)
        printf ("  %d is an armstrong number",n);
    else 
        printf("%d is not an armstrong number",n);
    return 0;
    
}