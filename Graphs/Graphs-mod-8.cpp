// Implementing the iscycle fucntion using the bfs for a undirected graph

#include <bits/stdc++.h>
using namespace std;

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
    bool isCycle(int s);// Checking the isCycle function for a fully connected graph
    bool isCycleComp(int s); // Checking the isCycle function for components
    void initVis();// For intializing the visited array
};

Graph::Graph(int V)
{
    this->V = V;
    adj.resize(V);
}

void Graph::addEdge(int v, int w)
{
    //  For a directed graph
    adj[v].push_back(w);
    adj[w].push_back(v);
}

void Graph::BFS(int s)
{
    visited.resize(V, false);
    list<int> q;

    visited[s] = true;
    q.push_back(s);

    while (!q.empty())
    {
        s = q.front();
        cout << s << ' ';
        q.pop_front();

        for (auto adjItr : adj[s])
        {
            if (!visited[adjItr])
            {
                visited[adjItr] = true;
                q.push_back(adjItr);
            }
        }
    }
}

bool Graph ::isCycle(int s)
{

    queue<pair<int, int>> q;
    // storing the
    // current_node --> first
    // parent node  --> second

    visited[s] = true;
    q.push({s, -1});

    while (!q.empty())
    {
        int node = q.front().first;
        int parentNode = q.front().second;
        // cout << s << ' ';
        q.pop();

        for (auto adjNode : adj[node])
        {
            if (!visited[adjNode])
            {
                visited[adjNode] = true;
                q.push({adjNode, node});
            }
            else if (adjNode != parentNode)
                return true;
            
        }
    }
    return false;
}

void Graph ::initVis()
{
    this->visited.resize(this->V, false);
}

bool Graph::isCycleComp(int s)
{
    bool result = false;
    for (int i = 0; i < this->V; i++)
    {
        if (!this->visited[i])
        {
           result = this->isCycle(i);
        }
    }
    return result;
}

int main()
{
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(2, 3);
    g.addEdge(4, 5);
    g.addEdge(5, 6);
    // g.addEdge(4, 6);
     
    g.initVis();
    cout<<g.isCycleComp(0);
    // cout << g.isCycle(0);

    return 0;
}