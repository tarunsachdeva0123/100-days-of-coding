#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int k;
    scanf("%d", &k);

    if (k <= 0 || k > n) {
        printf("-1\n");
        return 0;
    }

    qsort(arr, n, sizeof(int), compare);

    printf("%d\n", arr[k - 1]);

    return 0;
}