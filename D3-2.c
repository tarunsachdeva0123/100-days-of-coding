#include<stdio.h>
int main()
{
    int a,b,c;
    printf("input first number:");
    scanf("%d",&a);
    printf("input second number:");
    scanf("%d",&b);
    c=a;
    a=b;
    b=c;
    printf("after swap = %d %d",a,b);
    return 0;
}