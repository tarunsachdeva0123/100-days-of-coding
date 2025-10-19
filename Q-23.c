#include <stdio.h>
int main()
{
    int days;
    int fine = 0;

    printf("Enter number of late days: ");
    scanf("%d", &days);

    if (days <= 0)
    {
        printf("No fine.\n");
    }
    else if (days <= 5)
    {
        fine = days * 2;
        printf("Fine = rs%d\n", fine);
    }
    else if (days <= 10)
    {
        fine = 5 * 2 + (days - 5) * 4;
        printf("Fine = rs%d\n", fine);
    }
    else if (days <= 20)
    {
        fine = 5 * 2 + 5 * 4 + (days - 10) * 6;
        printf("Fine = rs%d\n", fine);
    }
    else
    {
        printf("Membership Cancelled.\n");
    }

    return 0;
}