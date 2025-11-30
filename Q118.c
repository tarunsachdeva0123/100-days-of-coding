#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    long long total = (long long)n * (n + 1) / 2;   

    long long missing = total - sum;

    printf("%lld\n", missing);

    return 0;
}