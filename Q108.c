#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int *nums = malloc(n * sizeof(int));
    int *answer = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++)
        scanf("%d", &nums[i]);

    answer[0] = 1;
    for (int i = 1; i < n; i++) {
        answer[i] = answer[i - 1] * nums[i - 1];
    }

    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        answer[i] = answer[i] * suffix;
        suffix *= nums[i];
    }

    for (int i = 0; i < n; i++) {
        if (i > 0) printf(" ");
        printf("%d", answer[i]);
    }
    printf("\n");

    free(nums);
    free(answer);
    return 0;
}