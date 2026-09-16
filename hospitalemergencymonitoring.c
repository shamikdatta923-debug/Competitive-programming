#include <stdio.h>

int main() {
    int n, i;
    int patients[100];
    int max, min, maxHour;
    float sum = 0, avg;
    int above = 0;

    printf("Enter number of hours: ");
    scanf("%d", &n);

    printf("Enter patient count for each hour:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &patients[i]);
        sum += patients[i];
    }

    max = min = patients[0];
    maxHour = 1;

    for (i = 1; i < n; i++) {

        if (patients[i] > max) {
            max = patients[i];
            maxHour = i + 1;
        }

        if (patients[i] < min)
            min = patients[i];
    }

    avg = sum / n;

    for (i = 0; i < n; i++) {
        if (patients[i] > avg)
            above++;
    }

    printf("Maximum patients = %d\n", max);
    printf("Peak hour = %d\n", maxHour);
    printf("Minimum patients = %d\n", min);
    printf("Average = %.2f\n", avg);
    printf("Hours above average = %d\n", above);

    return 0;
}