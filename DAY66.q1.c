QUES1: Detect cycle in directed graph using DFS and recursion stack.
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
    int* recStack;
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
    graph->recStack = malloc(vertices * sizeof(int));

    for(int i=0;i<vertices;i++){
        graph->adjLists[i] = NULL;
        graph->visited[i] = 0;
        graph->recStack[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph,int src,int dest){
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;
}

int DFS(struct Graph* graph,int vertex){

    graph->visited[vertex] = 1;
    graph->recStack[vertex] = 1;

    struct Node* temp = graph->adjLists[vertex];

    while(temp){
        int adjVertex = temp->vertex;

        if(!graph->visited[adjVertex] && DFS(graph,adjVertex))
            return 1;

        else if(graph->recStack[adjVertex])
            return 1;

        temp = temp->next;
    }

    graph->recStack[vertex] = 0;

    return 0;
}

int hasCycle(struct Graph* graph){

    for(int i=0;i<graph->numVertices;i++){
        if(!graph->visited[i]){
            if(DFS(graph,i))
                return 1;
        }
    }

    return 0;
}

int main(){

    struct Graph* graph = createGraph(4);

    addEdge(graph,0,1);
    addEdge(graph,1,2);
    addEdge(graph,2,3);
    addEdge(graph,3,1);

    if(hasCycle(graph))
        printf("Graph contains cycle\n");
    else
        printf("Graph does not contain cycle\n");

    return 0;
}
