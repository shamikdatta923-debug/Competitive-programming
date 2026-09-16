#include <stdio.h>

#define INF 999

int main() {
    int n, graph[10][10];
    int dist[10], visited[10] = {0};
    int source;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);

            if (graph[i][j] == 0)
                graph[i][j] = INF;
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Initialize distances
    for (int i = 0; i < n; i++)
        dist[i] = graph[source][i];

    dist[source] = 0;
    visited[source] = 1;

    // Find shortest paths
    for (int count = 1; count < n; count++) {

        int min = INF;
        int u = -1;

        // Find nearest unvisited vertex
        for (int i = 0; i < n; i++) {
            if (!visited[i] && dist[i] < min) {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        // Update distances
        for (int v = 0; v < n; v++) {
            if (!visited[v] &&
                dist[u] + graph[u][v] < dist[v]) {

                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\nShortest distances from %d:\n", source);

    for (int i = 0; i < n; i++)
        printf("%d -> %d = %d\n", source, i, dist[i]);

    return 0;
}