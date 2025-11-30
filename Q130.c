#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void checkFileExists() {
    char filename[100];
    FILE *fp;

    printf("Enter filename to check: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File does not exist!\n");
        return;
    }

    printf("\n--- File Content ---\n");
    char ch;
    while ((ch = fgetc(fp)) != EOF) {
        putchar(ch);
    }
    printf("\n--------------------\n");

    fclose(fp);
}

void convertLowerToUpper() {
    FILE *in = fopen("input.txt", "r");
    FILE *out = fopen("output.txt", "w");

    if (!in || !out) {
        printf("Error opening input/output file!\n");
        return;
    }

    char ch;
    while ((ch = fgetc(in)) != EOF) {
        if (islower(ch))
            ch = toupper(ch);
        fputc(ch, out);
    }

    fclose(in);
    fclose(out);
    printf("Converted text written to output.txt\n");
}

void countVowelsConsonants() {
    char filename[100];
    printf("Enter filename: ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: File not found!\n");
        return;
    }

    int vowels = 0, consonants = 0;
    char ch;

    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha(ch)) {
            char lower = tolower(ch);
            if (lower=='a'||lower=='e'||lower=='i'||lower=='o'||lower=='u')
                vowels++;
            else
                consonants++;
        }
    }

    fclose(fp);

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
}

void sumAndAverageNumbers() {
    FILE *fp = fopen("numbers.txt", "r");
    if (!fp) {
        printf("Error: numbers.txt not found!\n");
        return;
    }

    int num, count = 0;
    long long sum = 0;

    while (fscanf(fp, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    fclose(fp);

    if (count == 0) {
        printf("File has no integers.\n");
        return;
    }

    printf("Sum = %lld\n", sum);
    printf("Average = %.2f\n", (double)sum / count);
}

void studentRecords() {
    FILE *fp = fopen("students.txt", "w");
    int n;

    printf("How many students? ");
    scanf("%d", &n);

    char name[50];
    int roll;
    float marks;

    for (int i = 0; i < n; i++) {
        printf("\nEnter name: ");
        scanf("%s", name);

        printf("Enter roll number: ");
        scanf("%d", &roll);

        printf("Enter marks: ");
        scanf("%f", &marks);

        fprintf(fp, "%s %d %.2f\n", name, roll, marks);
    }

    fclose(fp);

    printf("\n--- Reading Records Back ---\n");

    fp = fopen("students.txt", "r");
    while (fscanf(fp, "%s %d %f", name, &roll, &marks) == 3) {
        printf("Name: %s  Roll: %d  Marks: %.2f\n", name, roll, marks);
    }

    fclose(fp);
}

int main() {
    int choice;

    while (1) {
        printf("\n===== FILE OPERATIONS MENU =====\n");
        printf("1. Check file existence and display content\n");
        printf("2. Convert input.txt lowercase → uppercase into output.txt\n");
        printf("3. Count vowels and consonants in a file\n");
        printf("4. Compute sum and average of integers in numbers.txt\n");
        printf("5. Store & read student records using fprintf/fscanf\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: checkFileExists(); break;
            case 2: convertLowerToUpper(); break;
            case 3: countVowelsConsonants(); break;
            case 4: sumAndAverageNumbers(); break;
            case 5: studentRecords(); break;
            case 6: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}