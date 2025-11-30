#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    if (n <= 0) {
        printf("-1\n"); 
        return 0;
    }

    long long *arr = malloc((size_t)n * sizeof(long long));
    if (!arr) return 0;

    for (int i = 0; i < n; ++i) {
        if (scanf("%lld", &arr[i]) != 1) {
            free(arr);
            return 0;
        }
    }

    int k;
    if (scanf("%d", &k) != 1) {
        free(arr);
        return 0;
    }

    if (k <= 0 || k > n) {
        printf("-1\n"); 
        free(arr);
        return 0;
    }

    long long windowSum = 0;
    for (int i = 0; i < k; ++i) windowSum += arr[i];

    long long maxSum = windowSum;

    for (int i = k; i < n; ++i) {
        windowSum += arr[i];         
        windowSum -= arr[i - k];     
        if (windowSum > maxSum) maxSum = windowSum;
    }

    printf("%lld\n", maxSum);

    free(arr);
    return 0;
}