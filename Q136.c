#include <stdio.h>

enum Menu {
    ADD = 1,
    SUBTRACT,
    MULTIPLY
};

int main() {
    int choice;
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Select operation:\n");
    printf("1. Add\n");
    printf("2. Subtract\n");
    printf("3. Multiply\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case ADD:
            printf("Result = %d\n", a + b);
            break;

        case SUBTRACT:
            printf("Result = %d\n", a - b);
            break;

        case MULTIPLY:
            printf("Result = %d\n", a * b);
            break;

        default:
            printf("Invalid choice.\n");
    }

    return 0;
}