#include <stdio.h>
int main()
{
    int a, b, sum, multiply, subs;
    float Quotient;
    printf("type first number: \t");
    scanf("%d", &a);
    printf("\n type second number: \t");
    scanf("%d", &b);
    sum= a+b;
    subs= a-b;
    multiply= a*b;
    Quotient= (float)a / b;
    printf("sum=%d", sum);
    printf("\n diff=%d", subs);
    printf("\n product=%d", multiply);
    printf("\n Quotient=%f", Quotient);
    return 0;
}
