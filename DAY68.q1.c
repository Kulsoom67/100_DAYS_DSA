QUES1: Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).
#include <stdio.h>
#include <stdlib.h>

struct Node{
    int vertex;
    struct Node* next;
};

struct Graph{
    int numVertices;
    struct Node** adjLists;
    int* inDegree;
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
    graph->inDegree = malloc(vertices * sizeof(int));

    for(int i=0;i<vertices;i++){
        graph->adjLists[i] = NULL;
        graph->inDegree[i] = 0;
    }

    return graph;
}

void addEdge(struct Graph* graph,int src,int dest){

    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjLists[src];
    graph->adjLists[src] = newNode;

    graph->inDegree[dest]++;
}

void topologicalSort(struct Graph* graph){

    int queue[100];
    int front=0,rear=0;

    for(int i=0;i<graph->numVertices;i++){
        if(graph->inDegree[i]==0)
            queue[rear++]=i;
    }

    printf("Topological Order:\n");

    while(front<rear){

        int current = queue[front++];
        printf("%d ",current);

        struct Node* temp = graph->adjLists[current];

        while(temp){
            int adjVertex = temp->vertex;
            graph->inDegree[adjVertex]--;

            if(graph->inDegree[adjVertex]==0)
                queue[rear++]=adjVertex;

            temp=temp->next;
        }
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
