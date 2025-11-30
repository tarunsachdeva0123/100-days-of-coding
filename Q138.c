#include <stdio.h>

enum Role {
    ADMIN = 1,
    USER,
    GUEST
};

int main() {
    const char *roleNames[] = { "ADMIN", "USER", "GUEST" };
    int roleValues[] = { ADMIN, USER, GUEST };

    int totalRoles = 3;

    for (int i = 0; i < totalRoles; i++) {
        printf("%s = %d\n", roleNames[i], roleValues[i]);
    }

    return 0;
}