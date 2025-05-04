#include<stdio.h>
#include<stdlib.h>
#include "queue.h"

// typedef enum {false, true} bool;

typedef struct _node
{
    int data;
    int weight;
    struct _node *next;
}node;


typedef struct _Graph
{
    int V;
    bool *visited;
    
    node** adjList;
}Graph;

void DFS(Graph* graph);
void BFS(Graph* graph);
Graph* createGraph(int V);
void printGraph(Graph* graph);
void DFSUtil(int index, Graph* graph);
void addEdge(Graph *graph, int u, int v, int w);

int main() {
    int v = 5;

    Graph *graph = createGraph(v);

    addEdge(graph, 0, 1, 0);
    addEdge(graph, 0, 4, 0);
    addEdge(graph, 1, 2, 0);
    addEdge(graph, 1, 3, 0);
    addEdge(graph, 1, 4, 0);
    addEdge(graph, 2, 3, 0);
    addEdge(graph, 3, 4, 0);
    
    //printf("\nDFS:----\n");
    //DFS(graph);

    printf("\nBFS:----\n");
    BFS(graph);

    printGraph(graph);
    return 0;
}

Graph* createGraph(int V) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;
    graph->visited = (bool *)malloc(V * sizeof(bool));
    graph->adjList = (node **)malloc(V * sizeof(node *));

    for(int i = 0; i < V; i++){
        graph->adjList[i] = NULL;
        graph->visited[i] = false;
    }
    return graph;
}

void addEdge(Graph *graph, int u, int v, int w) {
    if(u >= graph->V){
        printf("\nCheck the certex number again !!cannont insert!!\n");
        return;
    }
    if(graph->adjList[u] == NULL){
        graph->adjList[u] = (node *)malloc(sizeof(node));
        graph->adjList[u]->data = v;
        graph->adjList[u]->weight = w;
        graph->adjList[u]->next = NULL;
    }
    else {
        node* head = graph->adjList[u];
        while(head->next != NULL){
            head = head->next;
        }
        head->next = (node *)malloc(sizeof(node));
        head = head->next;
        head->data = v;
        head->weight = w;
        head->next = NULL;
    }
}

void BFS(Graph* graph) {
    queue *q = createQueue(sizeof(int));
    int start = 0;
    enqueue(q, &start);
    graph->visited[start] = true;
    while(!isEmpty(q)){
        int index;
        peek(q, &index);
        printf("%d", index);
        dequeue(q);
        node *head = graph->adjList[index];
        while(head != NULL) {
            if(!graph->visited[head->data]){
                graph->visited[head->data] = true;
                enqueue(q, &head->data);
            }
            head = head->next;
        }
    }
}

void DFS(Graph* graph){
    for(int i = 0; i < graph->V; i++){
        if(!graph->visited[i]) DFSUtil(i, graph);
    }
}

void DFSUtil(int index, Graph* graph){
    printf("%d", index);
    graph->visited[index] = true;
    node *head = graph->adjList[index];
    while(head != NULL){
        if(!graph->visited[head->data]) {
            DFSUtil(head->data, graph);
        }
        head = head->next;
    }
}

void printGraph(Graph* graph) {
  int v;
  for (v = 0; v < graph->V; v++) {
    node* temp = graph->adjList[v];
    printf("\n Adjacency list of vertex %d\n ", v);
    while (temp) {
      printf("%d -> ", temp->data);
      temp = temp->next;
    }
    printf("\n");
  }
}