#include<bits/stdc++.h>
using namespace std;

#define vertex 5

void addEdge(vector<int> graph[], int u, int v){
    graph[u].push_back(v);
    graph[v].push_back(u);
}

void addEdgeWt(vector<pair<int, int>> graph[], int u, int v, int w){
    graph[u].push_back(make_pair(v, w));
    graph[v].push_back(make_pair(u, w));
}

void DFSUtil(int u, vector<int> graph[], vector<bool> &visited){
    visited[u] = true;
    cout<<u<<" ";
    for(int i=0; i<graph[u].size(); i++){
        if(!visited[graph[u][i]]) DFSUtil(graph[u][i], graph, visited);
    }
}

void DFSUtilWt(int u, vector<pair<int, int>> graph[], vector<bool> &visited){
    visited[u] = true;
    cout<<u<<" ";
    for(int i=0; i<graph[u].size(); i++){
        if(!visited[graph[u][i].first]) DFSUtilWt(graph[u][i].first, graph, visited);
    }
}

void DFS(vector<int> graph[]){
    vector<bool> visited(vertex, false);
    for(int u=0; u<vertex; u++){
        if(!visited[u]) DFSUtil(u, graph, visited);
    }
}

void DFSWt(vector<pair<int, int>> graph[]){
    vector<bool> visited(vertex, false);
    for(int u=0; u<vertex; u++){
        if(!visited[u]) DFSUtilWt(u, graph, visited);
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

    vector<pair<int, int>> graphWt[vertex];

    addEdgeWt(graphWt, 0, 1, 10);
    addEdgeWt(graphWt, 0, 4, 20);
    addEdgeWt(graphWt, 1, 2, 30);
    addEdgeWt(graphWt, 1, 3, 40);
    addEdgeWt(graphWt, 1, 4, 50);
    addEdgeWt(graphWt, 2, 3, 60);
    addEdgeWt(graphWt, 3, 4, 70);

    DFSWt(graphWt);

    return 0;
}