#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LINE_BUF 1024

typedef enum { SUNDAY = 0, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY } Day;

void strip_newline(char *s) {
    size_t L = strlen(s);
    if (L > 0 && s[L-1] == '\n') s[L-1] = '\0';
}

void check_and_display_file() {
    char filename[256];
    printf("Enter filename to open and display: ");
    scanf("%255s", filename);
    getchar(); 

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Could not open file \"%s\"\n", filename);
        return;
    }

    char line[LINE_BUF];
    printf("----- Contents of %s -----\n", filename);
    while (fgets(line, sizeof(line), fp) != NULL) {
        fputs(line, stdout);
    }
    printf("----- End of file -----\n");
    fclose(fp);
}

void convert_input_to_output() {
    const char *inName  = "input.txt";
    const char *outName = "output.txt";

    FILE *in = fopen(inName, "r");
    if (!in) {
        printf("Error: Could not open %s for reading.\n", inName);
        return;
    }
    FILE *out = fopen(outName, "w");
    if (!out) {
        printf("Error: Could not open %s for writing.\n", outName);
        fclose(in);
        return;
    }

    int ch;
    while ((ch = fgetc(in)) != EOF) {
        if ('a' <= ch && ch <= 'z') ch = toupper(ch);
        fputc(ch, out);
    }

    fclose(in);
    fclose(out);
    printf("Converted lowercase to uppercase from %s --> %s\n", inName, outName);
}

void count_vowels_consonants() {
    char filename[256];
    printf("Enter filename to count vowels and consonants: ");
    scanf("%255s", filename);
    getchar();

    FILE *fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Could not open file \"%s\"\n", filename);
        return;
    }

    long long vowels = 0, consonants = 0;
    int ch;
    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha(ch)) {
            int c = tolower(ch);
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u') vowels++;
            else consonants++;
        }
    }
    fclose(fp);
    printf("Vowels: %lld, Consonants: %lld\n", vowels, consonants);
}

void numbers_sum_avg() {
    const char *fname = "numbers.txt";
    FILE *fp = fopen(fname, "r");
    if (!fp) {
        printf("Error: Could not open %s\n", fname);
        return;
    }

    long long sum = 0;
    long long count = 0;
    long long val;
    while (fscanf(fp, "%lld", &val) == 1) {
        sum += val;
        count++;
    }
    fclose(fp);

    if (count == 0) {
        printf("No integers found in %s\n", fname);
    } else {
        double avg = (double)sum / (double)count;
        printf("Read %lld integers from %s\n", count, fname);
        printf("Sum = %lld\nAverage = %.6f\n", sum, avg);
    }
}

void student_records() {
    const char *fname = "students.txt";
    int n;
    printf("How many student records to store? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid number.\n");
        getchar(); // flush
        return;
    }
    getchar(); 

    FILE *fp = fopen(fname, "w"); 
    if (!fp) {
        printf("Error: Could not open %s for writing.\n", fname);
        return;
    }

    for (int i = 0; i < n; ++i) {
        char name[200];
        int roll;
        double marks;

        printf("Enter name of student %d: ", i + 1);
        if (!fgets(name, sizeof(name), stdin)) name[0] = '\0';
        strip_newline(name);

        printf("Enter roll number: ");
        scanf("%d", &roll);
        printf("Enter marks (e.g., 78.5): ");
        scanf("%lf", &marks);
        getchar(); 

        fprintf(fp, "%s|%d|%.2f\n", name, roll, marks);
    }
    fclose(fp);
    printf("Records written to %s\n", fname);

    FILE *fr = fopen(fname, "r");
    if (!fr) {
        printf("Error: Could not open %s for reading.\n", fname);
        return;
    }

    printf("----- Student Records -----\n");
    char line[LINE_BUF];
    int idx = 0;
    while (fgets(line, sizeof(line), fr) != NULL) {
        char name[200];
        int roll;
        double marks;
        if (sscanf(line, "%199[^|]|%d|%lf", name, &roll, &marks) == 3) {
            printf("Student %d: Name = %s, Roll = %d, Marks = %.2f\n", ++idx, name, roll, marks);
        } else {
            printf("Warning: could not parse line: %s", line);
        }
    }
    printf("----- End of Records -----\n");
    fclose(fr);
}

void print_enum_days() {
    printf("Days enumeration (name : integer value):\n");
    printf("SUNDAY   : %d\n", SUNDAY);
    printf("MONDAY   : %d\n", MONDAY);
    printf("TUESDAY  : %d\n", TUESDAY);
    printf("WEDNESDAY: %d\n", WEDNESDAY);
    printf("THURSDAY : %d\n", THURSDAY);
    printf("FRIDAY   : %d\n", FRIDAY);
    printf("SATURDAY : %d\n", SATURDAY);
}

int main() {
    while (1) {
        printf("\n---- Multi-Task File & Small Utilities Program ----\n");
        printf("1. Ask for filename and display contents (check existence)\n");
        printf("2. Convert input.txt lowercase -> uppercase to output.txt\n");
        printf("3. Count vowels and consonants in a file\n");
        printf("4. Read numbers.txt and print sum & average\n");
        printf("5. Store and read student records (students.txt)\n");
        printf("6. Print enum for days (SUNDAY..SATURDAY)\n");
        printf("0. Exit\n");
        printf("Choose an option: ");

        int opt;
        if (scanf("%d", &opt) != 1) {
            printf("Invalid input. Exiting.\n");
            break;
        }
        getchar();

        switch (opt) {
            case 1: check_and_display_file(); break;
            case 2: convert_input_to_output(); break;
            case 3: count_vowels_consonants(); break;
            case 4: numbers_sum_avg(); break;
            case 5: student_records(); break;
            case 6: print_enum_days(); break;
            case 0: printf("Goodbye!\n"); exit(0);
            default: printf("Invalid option. Try again.\n");
        }
    }
    return 0;
}