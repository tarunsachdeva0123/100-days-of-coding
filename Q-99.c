#include <stdio.h>
#include <string.h>

int main() {
    char date[20];
    char day[3], month[3], year[5];

    
    scanf("%s", date);

    strncpy(day, date, 2);
    day[2] = '\0';

    strncpy(month, date + 3, 2);
    month[2] = '\0';

    strncpy(year, date + 6, 4);
    year[4] = '\0';

    if (strcmp(month, "04") == 0) {
        printf("%s-Apr-%s\n", day, year);
    } else {
      
        printf("Unsupported month: %s\n", month);
    }

    return 0;
}