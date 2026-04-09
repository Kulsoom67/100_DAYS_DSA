QUES1: Print topological ordering of a Directed Acyclic Graph (DAG) using DFS.
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int vertex;
    struct Node* next;
};

struct Graph{
    int numVertices;
    struct Node** adjLists;
    int* visited;
};

struct Node* createNode(int v){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int vertices){
    struct Graph* graph = malloc(sizeof(struct Graph));
    graph->numVertices = vertices;

    graph->adjLists = malloc(vertices * sizeof(struct Node*));
    graph->visited = malloc(vertices * sizeof(int));

    for(int i=0;i<vertices;i++){
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph,int src,int dest){
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

void DFS(struct Graph* graph,int vertex,int stack[],int* top){

    graph->visited[vertex] = 1;

    struct Node* temp = graph->adjLists[vertex];

    while(temp){
        int adjVertex = temp->vertex;

        if(!graph->visited[adjVertex])
            DFS(graph,adjVertex,stack,top);

        temp = temp->next;
    }

    stack[++(*top)] = vertex;
}

void topologicalSort(struct Graph* graph){

    int stack[100];
    int top = -1;

    for(int i=0;i<graph->numVertices;i++){
        if(!graph->visited[i])
            DFS(graph,i,stack,&top);
    }

    printf("Topological Order:\n");

    while(top!=-1){
        printf("%d ",stack[top--]);
    }
}

int main(){

    struct Graph* graph = createGraph(6);

    addEdge(graph,5,2);
    addEdge(graph,5,0);
    addEdge(graph,4,0);
    addEdge(graph,4,1);
    addEdge(graph,2,3);
    addEdge(graph,3,1);

    topologicalSort(graph);

    return 0;
}
