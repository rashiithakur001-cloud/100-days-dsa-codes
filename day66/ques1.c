//Problem: Detect cycle in directed graph using DFS and recursion stack.
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// DFS function
bool dfs(int node, int** adj, int* adjSize, bool* visited, bool* recStack) {
    
    visited[node] = true;
    recStack[node] = true;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        // If not visited, recurse
        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, adjSize, visited, recStack))
                return true;
        }
        // If neighbor is in recursion stack → cycle
        else if (recStack[neighbor]) {
            return true;
        }
    }

    // Remove from recursion stack
    recStack[node] = false;
    return false;
}

// Main function to detect cycle
bool isCycle(int V, int** adj, int* adjSize) {
    
    bool* visited = (bool*)calloc(V, sizeof(bool));
    bool* recStack = (bool*)calloc(V, sizeof(bool));

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, adjSize, visited, recStack))
                return true;
        }
    }

    return false;
}