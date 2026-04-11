QUES1: Given weighted graph with non-negative edges, compute shortest path from source using priority queue.
  #include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct Node {
    int vertex;
    int weight;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node* adj[MAX];
};

struct HeapNode {
    int vertex;
    int dist;
};

struct MinHeap {
    int size;
    struct HeapNode heap[MAX];
};

struct Node* createNode(int v, int w) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->weight = w;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    for (int i = 0; i < V; i++)
        graph->adj[i] = NULL;
    return graph;
}

void addEdge(struct Graph* graph, int u, int v, int w) {
    struct Node* newNode = createNode(v, w);
    newNode->next = graph->adj[u];
    graph->adj[u] = newNode;
}

void swap(struct HeapNode* a, struct HeapNode* b) {
    struct HeapNode temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(struct MinHeap* heap, int idx) {
    while (idx && heap->heap[(idx - 1) / 2].dist > heap->heap[idx].dist) {
        swap(&heap->heap[idx], &heap->heap[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

void heapifyDown(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < heap->size && heap->heap[left].dist < heap->heap[smallest].dist)
        smallest = left;

    if (right < heap->size && heap->heap[right].dist < heap->heap[smallest].dist)
        smallest = right;

    if (smallest != idx) {
        swap(&heap->heap[idx], &heap->heap[smallest]);
        heapifyDown(heap, smallest);
    }
}

void push(struct MinHeap* heap, int v, int dist) {
    heap->heap[heap->size].vertex = v;
    heap->heap[heap->size].dist = dist;
    heapifyUp(heap, heap->size);
    heap->size++;
}

struct HeapNode pop(struct MinHeap* heap) {
    struct HeapNode root = heap->heap[0];
    heap->heap[0] = heap->heap[--heap->size];
    heapifyDown(heap, 0);
    return root;
}

void dijkstra(struct Graph* graph, int src) {
    int V = graph->V;
    int dist[MAX];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    struct MinHeap heap;
    heap.size = 0;

    dist[src] = 0;
    push(&heap, src, 0);

    while (heap.size > 0) {
        struct HeapNode minNode = pop(&heap);
        int u = minNode.vertex;

        struct Node* temp = graph->adj[u];
        while (temp) {
            int v = temp->vertex;
            int weight = temp->weight;

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                push(&heap, v, dist[v]);
            }
            temp = temp->next;
        }
    }

    printf("Vertex\tDistance\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main() {
    int V = 5;
    struct Graph* graph = createGraph(V);

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 4, 5);
    addEdge(graph, 1, 2, 1);
    addEdge(graph, 4, 1, 3);
    addEdge(graph, 4, 2, 9);
    addEdge(graph, 2, 3, 4);
    addEdge(graph, 3, 0, 7);

    dijkstra(graph, 0);

    return 0;
}
