#include <stdio.h>

int main() {
    int arr[100], n, pos, value, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("\n1. Insert\n2. Delete\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        // Insertion
        printf("Enter position: ");
        scanf("%d", &pos);

        printf("Enter element: ");
        scanf("%d", &value);

        for (int i = n; i >= pos; i--)
            arr[i] = arr[i - 1];

        arr[pos - 1] = value;
        n++;
    }
    else if (choice == 2) {
        // Deletion
        printf("Enter position: ");
        scanf("%d", &pos);

        for (int i = pos - 1; i < n - 1; i++)
            arr[i] = arr[i + 1];

        n--;
    }
    else {
        printf("Invalid choice");
        return 0;
    }

    printf("Array after operation:\n");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}