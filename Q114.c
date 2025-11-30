#include <stdio.h>
#include <string.h>

int main() {
    char s[1000005];
    if (!fgets(s, sizeof(s), stdin)) return 0;

    size_t len = strlen(s);
    if (len > 0 && s[len - 1] == '\n') {
        s[len - 1] = '\0';
        --len;
    }

    int last[256];
    for (int i = 0; i < 256; ++i) last[i] = -1;

    int maxLen = 0;
    int start = 0; 

    for (int i = 0; s[i] != '\0'; ++i) {
        unsigned char c = (unsigned char)s[i];
        if (last[c] >= start) {
            start = last[c] + 1;
        }

        last[c] = i;
        int curLen = i - start + 1;
        if (curLen > maxLen) maxLen = curLen;
    }

    printf("%d\n", maxLen);
    return 0;
}