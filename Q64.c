#include <stdio.h>

int main() {
    long long num;
    int digit, i, maxDigit = 0, maxCount = 0;

    int freq[10] = {0};

    printf("Enter an integer number: ");
    scanf("%lld", &num);

    if (num < 0) {
        num = -num;
    }

    while (num > 0) {
        digit = num % 10;  
        freq[digit]++;     
        num /= 10;        

    for (i = 0; i < 10; i++) {
        if (freq[i] > maxCount) {
            maxCount = freq[i];
            maxDigit = i;
        }
    }

    printf("Digit that occurs the most times: %d\n", maxDigit);
    printf("It occurs %d times.\n", maxCount);

    return 0;
}