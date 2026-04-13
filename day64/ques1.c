/* Problem: Perform BFS from a given source using queue.

Input:
- n
- adjacency list
- source s

Output:
- BFS traversal order */
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Queue structure
int queue[MAX];
int front = -1, rear = -1;

// Enqueue
void enqueue(int x) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) front = 0;
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    if (front == -1 || front > rear) {
        return -1;
    }
    return queue[front++];
}

// Check if queue is empty
int isEmpty() {
    return (front == -1 || front > rear);
}

// BFS function
void BFS(int n, int adj[MAX][MAX], int s) {
    int visited[MAX] = {0};
    int c[MAX];   // to store BFS traversal
    int k = 0;

    enqueue(s);
    visited[s] = 1;

    while (!isEmpty()) {
        int u = dequeue();
        c[k++] = u;

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && visited[v] == 0) {
                enqueue(v);
                visited[v] = 1;
            }
        }
    }

    // Print BFS traversal
    printf("BFS Traversal: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", c[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n, s;
    int adj[MAX][MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }
    printf("Enter source node: ");
    scanf("%d", &s);
  BFS(n, adj, s);
  return 0;
}