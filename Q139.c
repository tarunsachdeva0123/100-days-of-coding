#include <stdio.h>

enum Status {
    SUCCESS = 5,
    FAILURE = 10,
    TIMEOUT = 20
};

int main() {
    printf("SUCCESS = %d\n", SUCCESS);
    printf("FAILURE  = %d\n", FAILURE);
    printf("TIMEOUT  = %d\n", TIMEOUT);

    return 0;
}