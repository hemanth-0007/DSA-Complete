//Implementing the isCycle for a Directed Graph using bfs (toposort)
 

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
     
    bool isCycleTopoSort();
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
 
 
bool Graph:: isCycleTopoSort(){
     vector<int> indegree(v,0);
     queue<int> q;
     for(int i =0 ; i<v ;i++){
        for(auto adjNode : adj[i])  indegree[adjNode]++;
     }
    //  step 1 is to push indegree == 0
    for (int i = 0; i < v; i++)
        if(indegree[i] == 0) q.push(i);
    int cnt = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        cnt++;
        for(auto adjNode : adj[node]){
            indegree[adjNode]--;
            if(indegree[adjNode] == 0) q.push(adjNode);
        }

    }
    if(cnt == v) return false;
    else return true;
}

 

int main()
{
    Graph g(5);
 
    g.addEdge(0,1);
    g.addEdge(2,1);
    g.addEdge(3,2);
    g.addEdge(4,3);
    g.addEdge(2,4);
   
    cout<<g.isCycleTopoSort()<<endl;

    return 0;
}