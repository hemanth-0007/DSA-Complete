// Getting the longest distance possible using the toposort simply update d[adjNode] < d[node] + weight => d[adjNode] = d[node] = weight
// fails if have posiitive edge cycles 
// only works for DAG
#include <bits/stdc++.h>
using namespace std;
#define NINF INT_MIN
class Graph
{

public:
    int v; // vertices
    Graph(int v);
    vector<bool> visited;
    list<pair<int, int>> *adj;

    void addEdge(int u, int v, int w);

    void topoSort(int f, stack<int> &st);
    vector<int> longPath(int s, stack<int> &st);
};
// constructor fucntion
Graph::Graph(int v)
{
    this->v = v;
    adj = new list<pair<int, int>>[v];
    visited.resize(v, false);
}

void Graph ::addEdge(int u, int v, int w)
{

    adj[u].push_back({v, w});
}

void Graph ::topoSort(int src, stack<int> &st)
{

    visited[src] = true;

    for (auto itr : adj[src])
    {
        int adjNode = itr.first;

        if (!visited[adjNode])
        {
            topoSort(adjNode, st);
        }
    }
    st.push(src);
}
vector<int> Graph ::longPath(int src, stack<int> &st)
{

    vector<int> dis;
    dis.resize(v, NINF);
    dis[src] = 0;
    while (!st.empty())
    {
        int node = st.top();

        st.pop();
        for (auto itr : adj[node])
        {
            int adjNode = itr.first;
            int edgeWgt = itr.second;

            if (dis[adjNode] < dis[node] + edgeWgt)
                dis[adjNode] = dis[node] + edgeWgt;
        }
    }

    return dis;
}

int main()
{
    int V = 6;
    Graph g(V);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);

    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!g.visited[i])
        {

            g.topoSort(i, st);
        }
    }
    vector<int> d = g.longPath(1, st);
    for (int i = 0; i < V; i++)
    {
        if (d[i] == NINF)
        {
            cout << i << " -- "
                 << "INF" << endl;
        }
        else
        {
            cout << i << " -- " << d[i] << endl;
        }
    }
    return 0;
}