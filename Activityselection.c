#include <stdio.h>

int main() {
    int n, i, j;
    int start[100], finish[100];
    int temp;
    printf("Enter number of activities: ");
    scanf("%d", &n);
    printf("Enter start times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &start[i]);
    }
    printf("Enter finish times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &finish[i]);
    }
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (finish[i] > finish[j]) {

                temp = finish[i];
                finish[i] = finish[j];
                finish[j] = temp;

                temp = start[i];
                start[i] = start[j];
                start[j] = temp;
            }
        }
    }
    printf("\nSelected activities:\n");
    printf("Activity 1: %d - %d\n", start[0], finish[0]);
    int lastFinish = finish[0];
    for (i = 1; i < n; i++) {
        if (start[i] >= lastFinish) {
            printf("Activity %d: %d - %d\n",
                   i + 1, start[i], finish[i]);

            lastFinish = finish[i];
        }
    }

    return 0;
}