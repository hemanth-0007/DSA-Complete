// Implementing krushkals MST (minimum spanning tree)
// this implementation is for undirected graph 
#include <bits/stdc++.h>
using namespace std;

class DSU
{

    int *parent;
    int *rank;

public:
    DSU(int v)
    {
        parent = new int[v];
        rank = new int[v];
        for (int i = 0; i < v; i++)
        {
            parent[i] = -1;
            rank[i] = 1;
        }
    }

    int find(int i)
    {
        //Base Case
        if (parent[i] == -1)
            return i;
       
        else
        {
            parent[i] = find(parent[i]);
            return parent[i];
        }
    }

    void unite(int x, int y)
    {
        int s1 = find(x);
        int s2 = find(y);
        if (rank[s1] > rank[s2])
            parent[s2] = s1;
        else if (rank[s1] < rank[s2])
            parent[s1] = s2;
        else
            parent[s2] = s1;
        rank[s1]++;
    }

    bool isCycle(int x, int y) {return find(x) == find(y);}

};

class Graph
{
    vector<vector<int>> edge;
    int v;

public:
    Graph(int v)
    {
        this->v = v;
    }
    void addEdge(int x, int y, int w)
    {
        edge.push_back({w, x, y});
        edge.push_back({w, y, x});
        //undirected graph
    }
    void KrushkalMST()
    {
        int minWeight = 0;
        sort(edge.begin(), edge.end());
        DSU s(v);

        for (auto ed : edge)
        {
            int w = ed[0];
            int x = ed[1];
            int y = ed[2];

            if (s.isCycle(x, y) == false)
            {
                s.unite(x,y);
                minWeight += w;
                cout<< "The edge included is : " << x << " " << y <<" -- "<<w<< endl;
            }
        }
        cout << "the minimum cost is " << minWeight << endl;
    }
};

int main()
{
    Graph g(4);
    
    g.addEdge(0, 1, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);
    g.addEdge(2, 0, 6);
    g.addEdge(0, 3, 5);
    g.KrushkalMST();

    return 0;
}