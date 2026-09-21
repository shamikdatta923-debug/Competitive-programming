#include <stdio.h>

int main() {
    int n, i, j, temp;
    int price[100];

    printf("Enter number of products: ");
    scanf("%d", &n);

    printf("Enter product prices:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &price[i]);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (price[j] > price[j + 1]) {
                temp = price[j];
                price[j] = price[j + 1];
                price[j + 1] = temp;
            }
        }
    }
    printf("Product prices in ascending order:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", price[i]);
    }

    return 0;
}