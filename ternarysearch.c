#include <stdio.h>

int ternarySearch(int a[], int low, int high, int key) {

    while (low <= high) {

        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        if (a[mid1] == key)
            return mid1;

        if (a[mid2] == key)
            return mid2;

        if (key < a[mid1]) {
            high = mid1 - 1;
        }
        else if (key > a[mid2]) {
            low = mid2 + 1;
        }
        else {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }

    return -1;
}

int main() {
    int a[100], n, key, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter sorted elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    result = ternarySearch(a, 0, n - 1, key);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}