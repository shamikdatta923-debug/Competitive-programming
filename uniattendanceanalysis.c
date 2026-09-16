#include <stdio.h>

int main() {
    int n, i, threshold;
    float attendance[100], sum = 0;
    int below = 0, lowestPos = 0;

    printf("Enter number of students: ");
    scanf("%d", &n);

    printf("Enter attendance percentages:\n");
    for (i = 0; i < n; i++) {
        scanf("%f", &attendance[i]);
        sum += attendance[i];
    }

    printf("Enter threshold: ");
    scanf("%d", &threshold);

    for (i = 0; i < n; i++) {
        if (attendance[i] < threshold)
            below++;

        if (attendance[i] < attendance[lowestPos])
            lowestPos = i;
    }

    printf("Students below threshold = %d\n", below);
    printf("Lowest attendance = %.2f\n", attendance[lowestPos]);
    printf("Position = %d\n", lowestPos + 1);
    printf("Average attendance = %.2f\n", sum / n);

    return 0;
}