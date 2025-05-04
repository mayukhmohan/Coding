#include<stdio.h>

#define VERTEX 6

int graph[VERTEX][VERTEX] = {
   {0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0},
   {0, 0, 0, 1, 0, 0},
   {0, 1, 0, 0, 0, 0},
   {1, 1, 0, 0, 0, 0},
   {1, 0, 1, 0, 0, 0}
};

int lastIndexofStack = 0;

void topoSort(int index, int visited[], int stack[]) {
   visited[index] = 1;    

   for(int v = 0; v < VERTEX; v++) {
      if(graph[index][v] && !visited[v]) {
            topoSort(v, visited, stack);
      }
   }
   stack[lastIndexofStack++] = index;  
}

void topologicalSort(int answer[VERTEX]) {
    int stack[VERTEX];
    int visited[VERTEX];

    for(int i = 0; i < VERTEX; i++)
        visited[i] = 0;     

    for(int i = 0; i < VERTEX; i++) {
        if(!visited[i]) {
            topoSort(i, visited, stack);
        }
    }

    for(int i = 0; i < VERTEX; i++) {
        answer[i] = stack[VERTEX - i - 1];
    }
}

int main() {
    int arr[VERTEX]; 
    topologicalSort(arr);
    for(int i = 0; i < VERTEX; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}