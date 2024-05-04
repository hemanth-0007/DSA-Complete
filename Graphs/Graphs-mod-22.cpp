// Marking the safe nodes out from a directed graph
//  using the BFS algorithm (prerequichites )--> topological sort using bfs

#include <bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int v;

    vector<list<int>> adj;
    vector<int> indegree;

    Graph(int v);
    void addEdge(int u, int v);

    vector<int> getSafeNodeBFS();
};

Graph::Graph(int v)
{
    this->v = v;
    indegree.resize(v,0);
    adj.resize(v);
}

void Graph::addEdge(int u, int v)
{
    adj[u].push_back(v);
}
 

vector<int> Graph ::getSafeNodeBFS()
{
    vector<list<int>> adjT(v);// inverted graph
    for (int i = 0; i < v; i++)
    {
        for(auto adjNode : adj[i]){
            adjT[adjNode].push_back(i);
        }
    }
    

    // get the indegree in that vector
    for (int i = 0; i < v; i++)
    {
        for (auto adjNode : adjT[i])
        {
            indegree[adjNode]++;
        }
    }

    vector<int> result;
    queue<int> q;
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }

    while (!q.empty())
    {
        int top = q.front();
        q.pop();
        result.push_back(top);

        for (auto adjNode : adjT[top])
        {
            indegree[adjNode]--;
            if (indegree[adjNode] == 0)
            {
                q.push(adjNode);
            }
        }
    }
    return result;
}

int main()
{
    int v = 12;
    Graph g(v);
   
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(3, 4);
    g.addEdge(4, 6);
    g.addEdge(5, 6);
    g.addEdge(6, 7);
    g.addEdge(9, 10);
    g.addEdge(8, 1);
    g.addEdge(10, 8);
    g.addEdge(8, 9);
    g.addEdge(9, 10);
    g.addEdge(11, 9);
     vector<int> vec = g.getSafeNodeBFS();
     for (auto it : vec)
     {
        cout<<it<<" ";
     }
     

    return 0;
}