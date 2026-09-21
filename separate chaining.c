#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
struct Node {
    int data;
    struct Node *next;
};
struct Node *hashTable[SIZE];
void initialize() {
    for (int i = 0; i < SIZE; i++)
        hashTable[i] = NULL;
}
void insert(int key) {
    int index = key % SIZE;

    struct Node *newNode =
        (struct Node *)malloc(sizeof(struct Node));

    newNode->data = key;
    newNode->next = hashTable[index];

    hashTable[index] = newNode;
}
void display() {
    printf("\nHash Table:\n");

    for (int i = 0; i < SIZE; i++) {
        printf("%d : ", i);

        struct Node *temp = hashTable[i];

        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }

        printf("NULL\n");
    }
}
int main() {
    int n, key;

    initialize();

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }
    display();
    return 0;
}