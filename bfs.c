#include <stdio.h>

int main() {
    int n, adj[10][10];
    int visited[10] = {0};
    int queue[10];
    int front = 0, rear = 0;
    int start, i, v;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    // Put starting vertex in queue
    queue[rear++] = start;
    visited[start] = 1;

    printf("BFS: ");

    while (front < rear) {
        v = queue[front++];

        printf("%d ", v);

        // Check all adjacent vertices
        for (i = 0; i < n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                queue[rear++] = i;
                visited[i] = 1;
            }
        }
    }

    return 0;
}