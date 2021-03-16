#include<iostream>
#include<algorithm>
using namespace std;
struct Edge
{
    int src,dest,weight;
};
struct subset
{
    int parent,rank;
};
struct Graph
{
    int v,e;
    struct Edge *edge;
};
Graph* createGraph(int,int);
void kruskal(Graph* g);
bool myComp(Edge,Edge);
int Find(subset*,int);
int Union(subset*,int,int);
void link(subset*,int,int);
int main()
{
    int v,e;
	//cout<<"\nEnter number of vertices:";
	//cin>>v;
	//cout<<"\nEnter number of Edges:";
	//cin>>e;
	v=9;
	e=14;
	struct Graph *graph = createGraph(v,e);
    /*     g    h
        f/1--2----3\a
        / | j| \  | \
        0M|  8 i\ |N 4
        \ |k/|L  \| /b
       e \7--6----5/
            d   c

    a = 9,b = 10,c = 2,d = 1,e = 8,f = 4,g = 8,h = 7,i = 4,j = 2,k = 7,L = 6,M = 11,N = 14
	*/

	graph->edge[0].src = 1;
	graph->edge[0].dest = 2;
	graph->edge[0].weight = 8;

	graph->edge[1].src = 2;
	graph->edge[1].dest = 3;
	graph->edge[1].weight = 7;

	graph->edge[2].src = 3;
	graph->edge[2].dest = 4;
	graph->edge[2].weight = 9;

	graph->edge[3].src = 4;
	graph->edge[3].dest = 5;
	graph->edge[3].weight = 10;

	graph->edge[4].src = 5;
	graph->edge[4].dest = 6;
	graph->edge[4].weight = 2;

	graph->edge[5].src = 6;
	graph->edge[5].dest = 7;
	graph->edge[5].weight = 1;

	graph->edge[6].src = 7;
	graph->edge[6].dest = 0;
	graph->edge[6].weight = 8;

	graph->edge[7].src = 0;
	graph->edge[7].dest = 1;
	graph->edge[7].weight = 4;

    graph->edge[8].src = 1;
	graph->edge[8].dest = 7;
	graph->edge[8].weight = 11;

	graph->edge[9].src = 7;
	graph->edge[9].dest = 8;
	graph->edge[9].weight = 7;

	graph->edge[10].src = 2;
	graph->edge[10].dest = 8;
	graph->edge[10].weight = 2;

	graph->edge[11].src = 8;
	graph->edge[11].dest = 6;
	graph->edge[11].weight = 6;

	graph->edge[12].src = 2;
	graph->edge[12].dest = 5;
	graph->edge[12].weight = 4;

	graph->edge[13].src = 3;
	graph->edge[13].dest = 5;
	graph->edge[13].weight = 14;

	kruskal(graph);
	return 0;
}
Graph* createGraph(int v,int e)
{
    Graph *g = new Graph();
    g->v = v;
    g->e = e;
    g->edge = new Edge[e];
    return g;
}
void kruskal(Graph* g)
{
    int v = g->v;
    struct Edge result[v];
    int e = 0;
    int i = 0;
    sort(g->edge, g->edge+g->e, myComp);
    subset s[v];
    for(i=0;i<v;i++)
    {
        s[i].parent = i;
        s[i].rank = 0;
    }
    i=0;
    while(e < v-1)
    {
        Edge edge = g->edge[i++];
        if(Find(s,edge.src)!= Find(s,edge.dest))
        {
            result[e++] = edge;
            Union(s,edge.src,edge.dest);
        }
    }
    cout<<"\nHere is your MST:\n";
    for(i=0;i<e;i++)
    {
        cout<<endl<<result[i].src<<"-----"<<result[i].dest<<"==>>"<<result[i].weight<<endl;
    }
}
bool myComp(Edge a,Edge b)
{
    return a.weight < b.weight;
}
int Find(subset *s,int v)
{
    if (s[v].parent != v)
        s[v].parent = Find(s,s[v].parent);
    return s[v].parent;
}
int Union(subset *s,int u,int v)
{
    link(s,Find(s,u),Find(s,v));
}
void link(subset *s,int x,int y)
{
    if(s[x].rank > s[y].rank)
    {
        s[y].parent = x;
    }
    else
    {
        s[x].parent = y;
        if(s[x].rank == s[y].rank)
        {
            s[y].rank = s[y].rank + 1;
        }
    }
}
