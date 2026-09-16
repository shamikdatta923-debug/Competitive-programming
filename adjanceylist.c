#include <stdio.h>

int main() {
    int n, e, u, v;
    int adj[10][10] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges:\n");

    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);

        adj[u][v] = 1;
        adj[v][u] = 1;   // for undirected graph
    }

    printf("\nAdjacency List:\n");

    for (int i = 0; i < n; i++) {
        printf("%d -> ", i);

        for (int j = 0; j < n; j++) {
            if (adj[i][j] == 1)
                printf("%d ", j);
        }

        printf("\n");
    }

    return 0;
}