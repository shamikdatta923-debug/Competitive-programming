#include <stdio.h>
int main() {
    int a[3][4];
    int i = 2, j = 3;

    int address = (int)&a[0][0] +
                  ((i * 4) + j) * sizeof(int);

    printf("Effective Address = %d\n", address);

    return 0;
}