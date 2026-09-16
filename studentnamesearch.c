#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n, i;
    char names[100][50];
    char search[50];
    int found = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter student names:\n");
    for (i = 0; i < n; i++) {
        scanf("%s", names[i]);
    }

    printf("Enter name to search: ");
    scanf("%s", search);

    /* Case-sensitive search */
    found = 0;

    for (i = 0; i < n; i++) {
        if (strcmp(names[i], search) == 0) {
            printf("Case-sensitive: Found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Case-sensitive: Not found\n");

    /* Case-insensitive search */
    found = 0;

    for (i = 0; i < n; i++) {
        int j = 0;
        int same = 1;

        while (names[i][j] != '\0' || search[j] != '\0') {
            if (tolower(names[i][j]) != tolower(search[j])) {
                same = 0;
                break;
            }
            j++;
        }

        if (same) {
            printf("Case-insensitive: Found at position %d\n", i + 1);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Case-insensitive: Not found\n");

    return 0;
}