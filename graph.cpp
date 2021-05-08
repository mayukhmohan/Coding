#include<bits/stdc++.h>
using namespace std;

#define vertex 5

void addEdge(vector<int> graph[], int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void DFSUtil(int u, vector<int> graph[], vector<bool> &visited){
    visited[u] = true;
    cout<<u<<" ";
    for(int i=0; i<graph[u].size(); i++){
        if(!visited[graph[u][i]]) DFSUtil(graph[u][i], graph, visited);
    }
}

void DFS(vector<int> graph[]){
    vector<bool> visited(vertex, false);
    for(int u=0; u<vertex; u++){
        if(!visited[u]) DFSUtil(u, graph, visited);
    }
}

int main(){
    vector<int> graph[vertex];

    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    DFS(graph);

    return 0;
}