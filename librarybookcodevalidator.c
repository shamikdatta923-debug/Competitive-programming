#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main() {
    char code[20];
    int valid = 1;
    int i;

    printf("Enter book code: ");
    scanf("%s", code);

    /* Check exact length */
    if (strlen(code) != 12) {
        valid = 0;
    }

    /* Check first 3 uppercase letters */
    for (i = 0; i < 3 && valid; i++) {
        if (!(code[i] >= 'A' && code[i] <= 'Z'))
            valid = 0;
    }

    /* Check first hyphen */
    if (valid && code[3] != '-')
        valid = 0;

    /* Check 4 digits */
    for (i = 4; i < 8 && valid; i++) {
        if (!isdigit(code[i]))
            valid = 0;
    }

    /* Check second hyphen */
    if (valid && code[8] != '-')
        valid = 0;

    /* Check last 3 digits */
    for (i = 9; i < 12 && valid; i++) {
        if (!isdigit(code[i]))
            valid = 0;
    }

    if (valid)
        printf("Valid book code\n");
    else
        printf("Invalid book code\n");

    return 0;
}