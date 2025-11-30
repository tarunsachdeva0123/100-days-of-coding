#include <stdio.h>

int main() {
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    int totalSum = n * (n + 1) / 2;
    int leftSum = 0;
    int pivot = -1;

    for (int x = 1; x <= n; x++) {
        leftSum += x;  
        int rightSum = totalSum - (x - 1) * x / 2; 

        if (leftSum == rightSum) {
            pivot = x;
            break;
        }
    }

    printf("%d\n", pivot);
    return 0;
}