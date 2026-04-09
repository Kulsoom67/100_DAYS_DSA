QUES1: Build a graph with n vertices and m edges using adjacency matrix representation.
The graph may be directed or undirected.
#include <stdio.h>

int main() {
    int n, m;
    int graph[100][100];
    int i, j, u, v;
    int directed;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    printf("Enter 1 for Directed Graph, 0 for Undirected Graph: ");
    scanf("%d", &directed);

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    printf("Enter edges (u v):\n");

    for(i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;

        if(!directed)
            graph[v][u] = 1;
    }

    printf("\nAdjacency Matrix:\n");

    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    return 0;
}
