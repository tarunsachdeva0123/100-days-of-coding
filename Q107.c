#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    if (n <= 0) {
        printf("\n");
        return 0;
    }

    int *arr = malloc(n * sizeof(int));
    if (!arr) return 0;

    for (int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; ++i) {
        int prevGreater = -1;
        for (int j = i - 1; j >= 0; --j) {
            if (arr[j] > arr[i]) {
                prevGreater = arr[j];
                break;
            }
        }
        if (i > 0) printf(",");
        printf("%d", prevGreater);
    }

    printf("\n");
    free(arr);
    return 0;
}