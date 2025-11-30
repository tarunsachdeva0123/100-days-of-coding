#include <stdio.h>
#include <limits.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int maxEndingHere = 0;
    int maxSoFar = INT_MIN;   

    for (int i = 0; i < n; i++) {
        maxEndingHere += arr[i];

        if (maxEndingHere > maxSoFar)
            maxSoFar = maxEndingHere;

        if (maxEndingHere < 0)
            maxEndingHere = 0;
    }

    printf("%d\n", maxSoFar);

    return 0;
}