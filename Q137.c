#include <stdio.h>

enum Role {
    ADMIN = 1,
    USER,
    GUEST
};

int main() {
    enum Role r = USER;  

    switch (r) {
        case ADMIN:
            printf("Welcome, Admin! You have full access.\n");
            break;

        case USER:
            printf("Hello, User! You have limited access.\n");
            break;

        case GUEST:
            printf("Welcome, Guest! Please login for more features.\n");
            break;

        default:
            printf("Invalid role.\n");
    }

    return 0;
}