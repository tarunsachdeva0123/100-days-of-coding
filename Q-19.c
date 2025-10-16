#include <stdio.h>

int main()
{
    int a, b, c;
    printf("Enter the lengths of the three sides of the triangle: ");
    scanf("%d %d %d", &a, &b, &c);
    if (a + b > c && a + c > b && b + c > a)
    {
        if (a == b && b == c)
        {
            printf("Equilateral triangle\n");
        }
        else if (a == b || b == c || a == c)
        {
            printf("Isosceles triangle\n");
        }
        else
        {
            printf("Scalene triangle\n");
        }
    }
    else
    {
        printf("The given sides do not form a valid triangle.\n");
    }

    return 0;
}