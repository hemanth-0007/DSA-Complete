#include <iostream>
#include <stdlib.h>
using namespace std;

/* 
  Creating a Graph and printing the adjacency list
   using a function 
   structs required are ;
   AdjListNode 
   AdjList 
   Graph --> vetices , AdjList array

   example :
   
   1--2
   \  /
     3
   1 : 2, 3
   2 : 1, 3
   3 : 1, 2
   This is the adjacency list representation 
   of an Undirected Graph

*/



struct AdjListNode
{
    int dest;
    struct AdjListNode *next;
};

struct AdjList
{
    struct AdjListNode *head;
};

struct Graph
{
    int v;// no of vertices
    struct AdjList *array;
};

struct AdjListNode *newAdjListNode(int k)
{
    struct AdjListNode *temp = (struct AdjListNode *)malloc(sizeof(struct AdjListNode));
    temp->dest = k;
    temp->next = NULL;
    return temp;
}

struct Graph *createGraph(int v)
{

    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->v = v;
    graph->array = (struct AdjList *)malloc(v * sizeof(struct AdjList));

    for (int i = 0; i < v; i++)
    {
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(struct Graph *graph, int src, int dest)
{

    struct AdjListNode *checked = NULL;
    struct AdjListNode *newnode = newAdjListNode(dest);
   // src and dest to be linked 
   // check the head is NULL or not and 
   // if NULL assign then newnode to NULL
   // else insert the newnode to the end of the AdjList 
    if (graph->array[src].head == NULL)
    {
        newnode->next = graph->array[src].head;
        graph->array[src].head = newnode;
    }
    else
    {
    // interate to end and insert
        checked = graph->array[src].head;
        while (checked->next != NULL)
        {
            checked = checked->next;
        }

        checked->next = newnode;
    }
    // Since the given graph is a undirected graph 
    // dest and src should also be mapped 
    newnode = newAdjListNode(src);

    if (graph->array[dest].head == NULL)
    {
        newnode->next = NULL;
        graph->array[dest].head = newnode;
    }
    else
    {
        checked = graph->array[dest].head;
        while (checked->next != NULL)
        {
            checked = checked->next;
        }
        checked->next = newnode;
    }
}

void print_graph(struct Graph *G)
{

    int v = G->v;
    struct AdjListNode *temp = NULL;
    for (int i = 0; i < v; i++)
    {
        cout << "For the vertex :" << i << "  : ";
        if (G->array[i].head == NULL)
        {
            cout << " Nil " << endl;
        }
        else
        {
            temp = G->array[i].head;
            while (temp != NULL)
            {
                cout << temp->dest << " - ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }
}

int main()
{

    int v = 5 ;
    struct Graph * graph = createGraph(v);
    addEdge(graph,0,1);
    addEdge(graph,0,4);
    addEdge(graph,1,4);
    addEdge(graph,1,3);
    addEdge(graph,4,3);
    addEdge(graph,1,2);
    addEdge(graph,2,3);


   print_graph(graph);

    return 0;
}