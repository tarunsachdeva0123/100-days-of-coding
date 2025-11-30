#include <stdio.h>
#include <ctype.h>

int main() {
    FILE *fp;
    char ch;
    int chars = 0, words = 0, lines = 0;
    int inWord = 0;

    fp = fopen("info.txt", "r");   
    if (fp == NULL) {
        printf("Error: Could not open file!\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        chars++;

        if (ch == '\n')
            lines++;

        if (!isspace((unsigned char)ch)) {
            if (!inWord) {     
                words++;
                inWord = 1;
            }
        } else {
            inWord = 0;        
        }
    }

    fclose(fp);

    if (chars > 0 && ch != '\n')
        lines++;

    printf("Total Characters: %d\n", chars);
    printf("Total Words: %d\n", words);
    printf("Total Lines: %d\n", lines);

    return 0;
}