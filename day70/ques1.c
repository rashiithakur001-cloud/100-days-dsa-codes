//Problem: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.
#include <stdio.h>
#include <limits.h>

struct Edge {
    int src, dest, weight;
};

void bellmanFord(struct Edge edges[], int V, int E, int source) {
    int dist[V];

    // Step 1: Initialize distances
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;
    dist[source] = 0;

    // Step 2: Relax edges V-1 times
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int w = edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    // Step 3: Check for negative weight cycles
    for (int j = 0; j < E; j++) {
        int u = edges[j].src;
        int v = edges[j].dest;
        int w = edges[j].weight;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("Graph contains a negative weight cycle\n");
            return;
        }
    }

    // Print shortest distances
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main() {
    int V = 5, E = 8;

    struct Edge edges[] = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3},
        {1, 3, 2}, {1, 4, 2}, {3, 2, 5},
        {3, 1, 1}, {4, 3, -3}
    };

    bellmanFord(edges, V, E, 0);
    return 0;
}