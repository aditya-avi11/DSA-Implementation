#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int numVertices;
    int **adjMatrix;
}Graph;

Graph *createGraph(int vertices){
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    if(graph==NULL){
        printf("Memory not allocated to structure!\n");
        exit(0);
    }
    graph->numVertices = vertices;
    graph->adjMatrix = (int **)malloc(vertices*sizeof(int *));
    if(graph->adjMatrix==NULL){
        printf("Memory Allocation failed\n");
        exit(0);
    }

    for(int i=0; i<vertices; i++){
        graph->adjMatrix[i] = (int *)malloc(vertices*sizeof(int));

        if(graph->adjMatrix[i]==NULL){
            printf("Memory Allocation failed\n");
        exit(0);
        }
        for(int j=0; j<vertices; j++){
            graph->adjMatrix[i][j] = 0;
        }
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest){
    graph->adjMatrix[src][dest] = 1;
    graph->adjMatrix[dest][src] = 1;
}

void printGraph(Graph *graph){
    for (int i = 0; i < graph->numVertices; i++)
    {
        for (int j = 0; j < graph->numVertices; j++)
        {
            printf("%d\t",graph->adjMatrix[i][j]);
        }
        printf("\n");
    }
}

void freeGraph(Graph *graph){
    for (int i = 0; i < graph->numVertices; i++)
    {
        free(graph->adjMatrix[i]);
    }
    free(graph->adjMatrix);
    free(graph);
}

int main(){

    Graph *graph = createGraph(4);
   
    addEdge(graph, 1,2);
    addEdge(graph, 2,3);
    addEdge(graph, 3,1);
    addEdge(graph, 3,2);
    printGraph(graph);
    freeGraph(graph);

    return 0;
}

