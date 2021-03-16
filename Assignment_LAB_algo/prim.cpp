#include<iostream>
#include<stdlib.h>
using namespace std;
struct AdjListNode
{
    int dest;
    int weight;
    struct AdjListNode *next;
};
struct AdjList
{
    struct AdjListNode *head;
};
struct Graph
{
    int V;
    struct AdjList *arr;
};
struct heapNode
{
    int v,key;
};
struct MinHeap
{
    int size;
    int capacity;
    int *pos;
    struct heapNode **arr;
};
MinHeap* createMinHeap(int);
heapNode* HeapNode(int,int);
struct Graph* createGraph(int);
void PrimMST(Graph*);
void minHeapify(MinHeap*,int);
void addEdge(Graph*,int,int,int);
heapNode* extractMin(MinHeap*);
void decreaseKey(MinHeap*,int,int);
void swap_me(heapNode**,heapNode**);
bool isInMinHeap(MinHeap*,int);
void printArr(int*,int,int*);
int main()
{
    int V = 9;
    struct Graph *graph = createGraph(V);

    /*     g    h
        f/1--2----3\a
        / | j| \  | \
        0M|  8 i\ |N 4
        \ |k/|L  \| /b
       e \7--6----5/
            d   c

    a = 9,b = 10,c = 2,d = 1,e = 8,f = 4,g = 8,h = 7,i = 4,j = 2,k = 7,L = 6,M = 11,N = 14
	*/

    addEdge(graph, 0, 1, 4);
    addEdge(graph, 0, 7, 8);
    addEdge(graph, 1, 2, 8);
    addEdge(graph, 1, 7, 11);
    addEdge(graph, 2, 3, 7);
    addEdge(graph, 2, 8, 2);
    addEdge(graph, 2, 5, 4);
    addEdge(graph, 3, 4, 9);
    addEdge(graph, 3, 5, 14);
    addEdge(graph, 4, 5, 10);
    addEdge(graph, 5, 6, 2);
    addEdge(graph, 6, 7, 1);
    addEdge(graph, 6, 8, 6);
    addEdge(graph, 7, 8, 7);

    PrimMST(graph);

    return 0;
}
struct Graph* createGraph(int V)
{
    Graph *graph = new Graph();
    graph->V = V;
    graph->arr = new AdjList[V];
    for (int i = 0; i < V; ++i)
        graph->arr[i].head = NULL;
    return graph;
}
void PrimMST(Graph *g)
{
    int v = g->V;
    int key[v];
    int parent[v];

    MinHeap* minHeap = createMinHeap(v);

    for(int i=1;i<v;i++)
    {
        parent[i] = -1;
        key[i] = 9999999;
        minHeap->arr[i] = HeapNode(i,key[i]);
        minHeap->pos[i] = i;
    }

    key[0] = 0;
    minHeap->arr[0] = HeapNode(0,key[0]);
    minHeap->pos[0] = 0;
    minHeap->size = v;

    while(minHeap->size != 0)
    {
        heapNode* n = extractMin(minHeap);
        int u = n->v;
        AdjListNode* ptr = g->arr[u].head;
        while(ptr!=NULL)
        {
            if(isInMinHeap(minHeap,ptr->dest) && ptr->weight < key[ptr->dest])
            {
                key[ptr->dest] = ptr->weight;
                parent[ptr->dest] = u;
                decreaseKey(minHeap,ptr->dest,key[ptr->dest]);
            }
            ptr=ptr->next;
        }
    }
    printArr(parent,v,key);
}
void decreaseKey(MinHeap* minHeap, int v, int key)
{
    int i = minHeap->pos[v];
    minHeap->arr[i]->key = key;
    while (i && minHeap->arr[i]->key < minHeap->arr[(i - 1) / 2]->key)
    {
        minHeap->pos[minHeap->arr[i]->v] = (i-1)/2;
        minHeap->pos[minHeap->arr[(i-1)/2]->v] = i;
        swap_me(&minHeap->arr[i],  &minHeap->arr[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
bool isInMinHeap(struct MinHeap *minHeap, int v)
{
   if (minHeap->pos[v] < minHeap->size)
     return true;
   return false;
}
void printArr(int arr[], int n, int key[])
{
    for (int i = 1; i < n; i++)
        cout<<endl<<arr[i]<<"-----"<<i<<"==>>"<<key[i]<<endl;
}
void minHeapify(MinHeap* minheap,int index)
{
	int l,r,smallest=index;
	l=2*index+1;
	r=2*index+2;
	if((l<minheap->size) && (minheap->arr[l]->key < minheap->arr[smallest]->key))
	{
		smallest=l;
	}
	if((r<minheap->size) && (minheap->arr[r]->key < minheap->arr[smallest]->key))
	{
		smallest=r;
	}
	if(smallest!=index)
	{
	    heapNode *small = minheap->arr[smallest];
	    heapNode *indexNd = minheap->arr[index];

		minheap->pos[small->v] = index;
		minheap->pos[indexNd->v] = smallest;

		swap_me(&minheap->arr[smallest],&minheap->arr[index]);

		minHeapify(minheap,smallest);
	}
}
void swap_me(heapNode** a,heapNode** b)
{
    heapNode* t = *a;
    *a = *b;
    *b = t;
}
void addEdge(struct Graph* graph, int src, int dest, int weight)
{
    AdjListNode* Node = new AdjListNode();
    Node->dest = dest;
    Node->weight = weight;
    Node->next = graph->arr[src].head;
    graph->arr[src].head = Node;

    Node = new AdjListNode();
    Node->dest = src;
    Node->weight = weight;
    Node->next = graph->arr[dest].head;
    graph->arr[dest].head = Node;
}
struct MinHeap* createMinHeap(int capacity)
{
    struct MinHeap* minHeap = new MinHeap();
    minHeap->pos = new int[capacity];
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->arr = (struct heapNode **)malloc(capacity*sizeof(heapNode*));
    return minHeap;
}
heapNode* HeapNode(int v, int key)
{
    heapNode* minHeapNode = new heapNode();
    minHeapNode->v = v;
    minHeapNode->key = key;
    return minHeapNode;
}
struct heapNode* extractMin(struct MinHeap* minHeap)
{
    if (minHeap->size==0)
        return NULL;
    heapNode* root = minHeap->arr[0];
    heapNode* lastNode = minHeap->arr[minHeap->size - 1];
    minHeap->arr[0] = lastNode;
    minHeap->pos[root->v] = minHeap->size-1;
    minHeap->pos[lastNode->v] = 0;
    --minHeap->size;
    minHeapify(minHeap, 0);
    return root;
}
