//Implementing the isCycle for a Directed Graph 
// Space complexity by using only O(N) that is visited array

#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int v;
    vector<int> visited;
    vector<bool> pathVis;
    vector<list<int>> adj;
    // My constructor to initialise above things
    Graph(int v);
    void addEdge(int u, int v);
    bool dfsCheck(int node);
    bool isCycle();
};

Graph::Graph(int v)
{
    this->v = v ;
    adj.resize(v); 
    visited.resize(v, 0);
    pathVis.resize(v,false);
}
 
void Graph:: addEdge(int u , int v){
     adj[u].push_back(v);
}
 
 
bool Graph:: dfsCheck(int s){
    visited[s] = 1;
    visited[s] = 2;
 

    for(auto adjNode : adj[s]){
        if(visited[adjNode] == 0){
            if(dfsCheck(adjNode) == true)
                return true;
        }
        else if(visited[adjNode] == 2){
            return true;
        }
    }
    visited[s] = 1;
    return false;
}

bool Graph :: isCycle(){
    
    for (int i = 0; i < v; i++)
        {if(dfsCheck(i) == true) return true;}
 
    return false;
}



int main(){
    Graph g(5);
 
    g.addEdge(0,1);
    g.addEdge(2,1);
    g.addEdge(3,2);
    g.addEdge(4,3);
    g.addEdge(2,4);
   
    cout<<g.isCycle()<<endl;

    return 0;
}