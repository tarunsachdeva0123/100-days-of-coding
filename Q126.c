#include <stdio.h>

int main() {
    char filename[100];
    FILE *fp;
    char line[200];

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File does not exist or cannot be opened!\n");
        return 1;
    }

    printf("\n--- File Content ---\n");
    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);
    return 0;
}