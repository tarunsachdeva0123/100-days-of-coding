 #include <stdio.h>

int main() {
    int i, j;
    int n[] = {1, 2, 3, 5, 3, 2, 1}; 
    int size = 7; 

    for (i = 0; i < size; i++) {
        for (j = 0; j < n[i]; j++) {
            printf("*\n");
        }
        printf("\n");  
    }

    return 0;
}