#include <stdio.h>
int main()
{
    int n, sum = 0, odd = 1;
    printf("Enter the value of n: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        sum += odd;
        odd += 2;
    }

    printf("Sum of the first %d odd numbers is: %d\n", n, sum);
    return 0;
}