#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;

    if (n <= 0) {
        printf("-1\n");
        return 0;
    }

    int *arr = malloc(n * sizeof(int));
    if (!arr) return 0;
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
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

    int *dq = malloc(n * sizeof(int)); 
    int front = 0, back = -1;          

    int firstOutput = 1; 

    for (int i = 0; i < n; ++i) {
        while (front <= back && arr[dq[back]] <= arr[i]) {
            --back;
        }

        dq[++back] = i;

        while (front <= back && dq[front] <= i - k) {
            ++front;
        }

        if (i >= k - 1) {
            if (!firstOutput) printf(" ");
            printf("%d", arr[dq[front]]);
            firstOutput = 0;
        }
    }

    printf("\n");

    free(arr);
    free(dq);
    return 0;
}