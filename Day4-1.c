#include <stdio.h>
int main ()
{
    int a,b;
    printf ("enter 1st number: ");
    scanf("%d",&a);
    printf("enter 2nd number: ");
    scanf("%d",&b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("required swap= %d %d", a,b);
    return 0;
}