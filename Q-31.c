#include <stdio.h>
int main()
{
    int n,bin=0,fin=0;
    printf ("enter no. for binary representation");
    scanf("%d",&n);
    while (n!=0)
    {
      bin=(n%2)+bin*10;
      n=n/2;
    }
    while (bin!=0)
    {
        fin=(bin%10)+fin*10;
        bin=bin/10;
    }
    printf("binary= %d",fin);
    return 0;
}