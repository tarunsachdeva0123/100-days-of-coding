#include <stdio.h>

int main() {
    int m, n;
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &m, &n);

    int a[m][n], rowSum[m];

    printf("Enter elements of the matrix:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        rowSum[i] = 0;
        for (int j = 0; j < n; j++) {
            rowSum[i] += a[i][j];
        }
    }

    printf("Sum of each row:\n");
    for (int i = 0; i < m; i++) {
        printf("Row %d = %d\n", i + 1, rowSum[i]);
    }

    return 0;
}