// Implementing the topological sort using the BFS. think on the basis of the degrees
// only works on the (DAG)
// Directed acyclic graph
#include <bits/stdc++.h>
using namespace std;
class Graph
{

public:
    int v; // vertices
    Graph(int v);
    vector<bool> visited;
    vector<int> indegree;
    vector<list<int>> adj;
    void addEdge(int v, int w);
    vector<int> topoSort();
};
// constructor fucntion
Graph::Graph(int v)
{
    this->v = v;
    adj.resize(v);
    visited.resize(v, false);
    indegree.resize(v,0);
}

void Graph ::addEdge(int v, int w)
{
    // directed graph
    adj[v].push_back(w);
}

vector<int> Graph :: topoSort()
{

    // get the indegree in that vector
     for (int i = 0; i < v; i++)
     {
        for(auto adjNode : adj[i]){
            indegree[adjNode]++;
        }
     }
     
    
    
    vector<int> result;
    queue<int> q;
    // step 1: To push the 0 degree to the queue
    for (int i = 0; i < v; i++)
    {
        if(indegree[i] == 0)
            q.push(i);
    }
 

    while (!q.empty())
    {
       int top = q.front();
       q.pop();
       result.push_back(top);
       
        for (auto adjNode :  adj[top])
        {
            // This a  simple someWhat the modified version of the BFS
             indegree[adjNode]--;
             if(indegree[adjNode] == 0) q.push(adjNode);
        }
    }
    return result;
}

int main()
{
    int V = 6;
    Graph G(V);

    G.addEdge(5, 0);
    G.addEdge(5, 2);
    G.addEdge(4, 0);
    G.addEdge(4, 1);
    G.addEdge(2, 3);
    G.addEdge(3, 1);
 
    vector<int> v = G.topoSort();
    for (int i = 0; i < V; i++)
    {
        cout<<v[i]<<" ";
    }
    
     

    return 0;
}