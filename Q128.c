#include <stdio.h>
#include <ctype.h>

int main() {
    char filename[256];
    FILE *fp;
    int ch;
    long vowels = 0, consonants = 0;

    printf("Enter filename to open and display: ");
    if (scanf("%255s", filename) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    getchar();

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open '%s' for reading.\n", filename);
    } else {
        printf("----- Contents of %s -----\n", filename);
        vowels = consonants = 0;
        while ((ch = fgetc(fp)) != EOF) {
            putchar(ch); 

            if (isalpha((unsigned char)ch)) {
                char lc = (char)tolower((unsigned char)ch);
                if (lc == 'a' || lc == 'e' || lc == 'i' || lc == 'o' || lc == 'u')
                    vowels++;
                else
                    consonants++;
            }
        }
        printf("\n----- End of %s -----\n", filename);
        printf("Vowels: %ld\n", vowels);
        printf("Consonants: %ld\n", consonants);

        fclose(fp);
    }

    FILE *in = fopen("input.txt", "r");
    if (in == NULL) {
        printf("Notice: 'input.txt' not found. Skipping conversion to 'output.txt'.\n");
    } else {
        FILE *out = fopen("output.txt", "w");
        if (out == NULL) {
            printf("Error: Could not open 'output.txt' for writing.\n");
            fclose(in);
            return 1;
        }

        while ((ch = fgetc(in)) != EOF) {
            if (islower((unsigned char)ch))
                ch = toupper((unsigned char)ch);
            fputc(ch, out);
        }

        fclose(in);
        fclose(out);
        printf("Conversion complete: lowercase letters from 'input.txt' were converted to uppercase and written to 'output.txt'.\n");
    }

    return 0;
}