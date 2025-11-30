#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char s[1000];

    if (!fgets(s, sizeof(s), stdin))
        return 0;

    int n = strlen(s);

    for (int i = 0; i < n; i++)
        s[i] = tolower((unsigned char)s[i]);

    for (int i = 0; i < n; i++) {
        if (isalpha((unsigned char)s[i])) {
            s[i] = toupper((unsigned char)s[i]);
            break;
        }
    }

    printf("%s", s);
    return 0;
}