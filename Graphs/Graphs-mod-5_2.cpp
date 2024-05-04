// C++ code to print BFS traversal from a given
// source vertex

#include <bits/stdc++.h>
using namespace std;

// This class represents a directed graph using
// adjacency list representation
class Graph
{

public:
    // No. of vertices
    int V;

    // Pointer to an array containing adjacency lists
    vector<list<int>> adj;

    vector<bool> visited;

    // Constructor
    Graph(int V);

    // Function to add an edge to graph
    void addEdge(int v, int w);

    // Prints BFS traversal from a given source s
    void BFS(int s);
   
};

Graph::Graph(int V)
{
    V = V;
    adj.resize(V);
    visited.resize(V,false);
}

void Graph::addEdge(int v, int w)
{
    // Add w to v’s list.
    adj[v].push_back(w);
    // adj[w].push_back(v);
}

void Graph::BFS(int s)
{
   visited[s] = true;
   list<int> ls;
   ls.push_back(s);

   while (!ls.empty())
   {
        s = ls.front();
        cout<<s<<" ";
        ls.pop_front();
        for(auto adjNode : adj[s]){
            if(!visited[adjNode]){
                visited[adjNode]= true;
                ls.push_back(adjNode);
                }
        }
   }
    
}

// Driver code
int main()
{
    // Create a graph given in the above diagram
    Graph g(4);
    int a ;
    cout<<"Enter the vertex you wanna start: ";
    cin>>a;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    // g.addEdge(3, 3);

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex "<<a<<") \n";
    g.BFS(a);

    return 0;
}
