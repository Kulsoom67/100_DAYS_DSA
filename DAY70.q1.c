QUES1: Compute shortest path from source and detect negative weight cycles using Bellman-Ford.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge edges[MAX];
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    return graph;
}

void bellmanFord(struct Graph* graph, int src) {
    int V = graph->V;
    int E = graph->E;
    int dist[MAX];

    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX;

    dist[src] = 0;

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = graph->edges[j].src;
            int v = graph->edges[j].dest;
            int w = graph->edges[j].weight;

            if (dist[u] != INT_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }

    for (int j = 0; j < E; j++) {
        int u = graph->edges[j].src;
        int v = graph->edges[j].dest;
        int w = graph->edges[j].weight;

        if (dist[u] != INT_MAX && dist[u] + w < dist[v]) {
            printf("Negative weight cycle detected\n");
            return;
        }
    }

    printf("Vertex\tDistance\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

int main() {
    int V = 5;
    int E = 8;

    struct Graph* graph = createGraph(V, E);

    graph->edges[0] = (struct Edge){0, 1, -1};
    graph->edges[1] = (struct Edge){0, 2, 4};
    graph->edges[2] = (struct Edge){1, 2, 3};
    graph->edges[3] = (struct Edge){1, 3, 2};
    graph->edges[4] = (struct Edge){1, 4, 2};
    graph->edges[5] = (struct Edge){3, 2, 5};
    graph->edges[6] = (struct Edge){3, 1, 1};
    graph->edges[7] = (struct Edge){4, 3, -3};

    bellmanFord(graph, 0);

    return 0;
}
