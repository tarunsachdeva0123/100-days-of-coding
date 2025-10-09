#include <stdio.h>
int main ()
{
    int a,b;
    printf("type lenth of rectangle:");
    scanf ("%d", &a);
    printf("\n type breadth of rectangle:");
    scanf("%d", &b);
    printf("\n area of rectangle= %d", a*b);
    printf("\n perimeter of rectangle = %d", 2*(a+b));
    return 0;
}