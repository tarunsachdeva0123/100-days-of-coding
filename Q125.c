#include <stdio.h>

int main() {
    FILE *fp;
    char filename[100];
    char text[500];

    printf("Enter filename: ");
    scanf("%s", filename);
    getchar(); 

    fp = fopen(filename, "a");
    if (fp == NULL) {
        printf("Error: Could not open file!\n");
        return 1;
    }

    printf("Enter text to append: ");
    fgets(text, sizeof(text), stdin);

    fputs(text, fp);

    fclose(fp);

    printf("Text appended successfully!\n");
    return 0;
}