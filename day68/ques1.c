//Problem: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>
#define MAX 100
int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = 0, rear = 0;

void topologicalSort(int V) {
    int i, j;

    // Step 1: Calculate indegree
    for (i = 0; i < V; i++) {
        indegree[i] = 0;
        for (j = 0; j < V; j++) {
            if (adj[j][i] == 1) {
                indegree[i]++;
            }
        }
    }

    // Step 2: Push nodes with indegree 0
    for (i = 0; i < V; i++) {
        if (indegree[i] == 0) {
            queue[rear++] = i;
        }
    }

    int count = 0;

    printf("Topological Order: ");

    // Step 3: Process queue
    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (i = 0; i < V; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    queue[rear++] = i;
                }
            }
        }

        count++;
    }

    // Step 4: Cycle detection
    if (count != V) {
        printf("\nCycle detected! No Topological Ordering.\n");
    }
}

int main() {
    int V = 6;
    // Initialize adjacency matrix
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            adj[i][j] = 0;

    // Example graph
    adj[5][2] = 1;
    adj[5][0] = 1;
    adj[4][0] = 1;
    adj[4][1] = 1;
    adj[2][3] = 1;
    adj[3][1] = 1;

    topologicalSort(V);

    return 0;
}