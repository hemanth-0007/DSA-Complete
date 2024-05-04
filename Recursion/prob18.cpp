//  coloring a undirected graph with atmost m colors 
// using recursion

#include<bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    public:
        vector<list<int>> adj;
        Graph(int v){
            this->V = v;
        }
        void addEdge(int u , int v){
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
};
int main()
{
    Graph g(5);

 

    return 0;
}