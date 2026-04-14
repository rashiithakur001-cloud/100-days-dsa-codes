/*Problem: Perform DFS starting from a given source vertex using recursion.
*/#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int visited[MAX];

// Node structure for adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Add edge to graph (undirected)
void addEdge(struct Node* adj[], int u, int v) {
    struct Node* newNode = createNode(v);
    newNode->next = adj[u];
    adj[u] = newNode;

    newNode = createNode(u);
    newNode->next = adj[v];
    adj[v] = newNode;
}

// DFS function (recursive)
void dfs(struct Node* adj[], int node) {
    printf("%d ", node);
    visited[node] = 1;

    struct Node* temp = adj[node];
    while (temp != NULL) {
        if (!visited[temp->data]) {
            dfs(adj, temp->data);
        }
        temp = temp->next;
    }
}

int main() {
    int n, e, u, v, s;

    struct Node* adj[MAX];

    // Initialize adjacency list
    for (int i = 0; i < MAX; i++) {
        adj[i] = NULL;
        visited[i] = 0;
    }

    // Input number of vertices and edges
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &e);

    // Input edges
    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
    }

    // Input starting vertex
    printf("Enter starting vertex: ");
    scanf("%d", &s);

    // Perform DFS
    printf("DFS Traversal: ");
    dfs(adj, s);

    return 0;
}