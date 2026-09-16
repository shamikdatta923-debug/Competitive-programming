#include <stdio.h>

#define INF 999

int main() {
    int n;
    int cost[10][10];
    int visited[10] = {0};
    int edges = 0, total = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);

            if (cost[i][j] == 0)
                cost[i][j] = INF;
        }
    }

    visited[0] = 1;   // Start from vertex 0

    printf("Edges in MST:\n");

    while (edges < n - 1) {
        int min = INF;
        int u = -1, v = -1;

        // Find minimum edge
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }

        printf("%d - %d = %d\n", u, v, min);

        visited[v] = 1;
        total += min;
        edges++;
    }

    printf("Minimum cost = %d\n", total);

    return 0;
}