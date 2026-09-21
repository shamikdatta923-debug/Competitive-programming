#include <stdio.h>

int main() {
    int n, i;
    int dp[100];

    printf("Enter number of terms: ");
    scanf("%d", &n);

    dp[0] = 0;
    dp[1] = 1;

    for (i = 2; i < n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    printf("Fibonacci Series:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", dp[i]);
    }

    return 0;
}