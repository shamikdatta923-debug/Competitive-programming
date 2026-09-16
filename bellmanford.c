#include <stdio.h>

#define INF 9999

struct Edge {
    int u, v, weight;
};

int main() {
    int V, E, source;
    struct Edge edge[20];
    int dist[10];

    printf("Enter number of vertices: ");
    scanf("%d", &V);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    printf("Enter edges (source destination weight):\n");

    for (int i = 0; i < E; i++) {
        scanf("%d %d %d",
              &edge[i].u,
              &edge[i].v,
              &edge[i].weight);
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    // Initialize distances
    for (int i = 0; i < V; i++)
        dist[i] = INF;

    dist[source] = 0;

    // Relax all edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {

            int u = edge[j].u;
            int v = edge[j].v;
            int w = edge[j].weight;

            if (dist[u] != INF &&
                dist[u] + w < dist[v]) {

                dist[v] = dist[u] + w;
            }
        }
    }

    // Check for negative cycle
    for (int i = 0; i < E; i++) {
        int u = edge[i].u;
        int v = edge[i].v;
        int w = edge[i].weight;

        if (dist[u] != INF &&
            dist[u] + w < dist[v]) {

            printf("Negative weight cycle exists!\n");
            return 0;
        }
    }

    printf("\nShortest distances from %d:\n", source);

    for (int i = 0; i < V; i++) {
        printf("%d -> %d = %d\n",
               source, i, dist[i]);
    }

    return 0;
}