#include <stdio.h>
#include <string.h>
int main() {
    char a[100], b[100];
    int result;

    printf("Enter first string: ");
    scanf("%s", a);

    printf("Enter second string: ");
    scanf("%s", b);

    result = strcmp(a, b);

    if (result == 0) {
        printf("Strings are equal\n");
    }
    else if (result < 0) {
        printf("%s comes before %s\n", a, b);
    }
    else {
        printf("%s comes after %s\n", a, b);
    }
    return 0;
}