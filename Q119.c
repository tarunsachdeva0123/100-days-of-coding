#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    int maxVal = 0;

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > maxVal)
            maxVal = arr[i];
    }

    int *visited = calloc(maxVal + 1, sizeof(int));
    
    for (int i = 0; i < n; i++) {
        if (visited[arr[i]] == 1) {
            printf("%d\n", arr[i]);  
            free(visited);
            return 0;
        }
        visited[arr[i]] = 1;
    }

    printf("-1\n");

    free(visited);
    return 0;
}