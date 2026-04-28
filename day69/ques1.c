//Problem: Given weighted graph with non-negative edges, compute shortest path from source using priority queue
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 10005
#define INF INT_MAX

// Edge structure
typedef struct Edge {
    int v, w;
    struct Edge* next;
} Edge;

// Adjacency list
Edge* adj[MAX];

// Min Heap Node
typedef struct {
    int node, dist;
} HeapNode;

// Min Heap
typedef struct {
    HeapNode arr[MAX];
    int size;
} MinHeap;

// Swap
void swap(HeapNode* a, HeapNode* b) {
    HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify up
void heapifyUp(MinHeap* h, int i) {
    while(i > 0 && h->arr[(i-1)/2].dist > h->arr[i].dist) {
        swap(&h->arr[i], &h->arr[(i-1)/2]);
        i = (i-1)/2;
    }
}

// Heapify down
void heapifyDown(MinHeap* h, int i) {
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < h->size && h->arr[left].dist < h->arr[smallest].dist)
        smallest = left;
    if(right < h->size && h->arr[right].dist < h->arr[smallest].dist)
        smallest = right;

    if(smallest != i) {
        swap(&h->arr[i], &h->arr[smallest]);
        heapifyDown(h, smallest);
    }
}

// Push into heap
void push(MinHeap* h, int node, int dist) {
    h->arr[h->size].node = node;
    h->arr[h->size].dist = dist;
    heapifyUp(h, h->size);
    h->size++;
}

// Pop from heap
HeapNode pop(MinHeap* h) {
    HeapNode root = h->arr[0];
    h->arr[0] = h->arr[h->size - 1];
    h->size--;
    heapifyDown(h, 0);
    return root;
}

// Add edge
void addEdge(int u, int v, int w) {
    Edge* newEdge = (Edge*)malloc(sizeof(Edge));
    newEdge->v = v;
    newEdge->w = w;
    newEdge->next = adj[u];
    adj[u] = newEdge;
}

// Dijkstra with Priority Queue
void dijkstra(int n, int source) {
    int dist[MAX];
    
    for(int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[source] = 0;

    MinHeap heap;
    heap.size = 0;

    push(&heap, source, 0);

    while(heap.size > 0) {
        HeapNode top = pop(&heap);
        int u = top.node;
        int d = top.dist;

        if(d > dist[u]) continue;

        Edge* temp = adj[u];
        while(temp) {
            int v = temp->v;
            int w = temp->w;

            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    // Print result
    for(int i = 1; i <= n; i++) {
        if(dist[i] == INF)
            printf("Node %d: Unreachable\n", i);
        else
            printf("Node %d: %d\n", i, dist[i]);
    }
}