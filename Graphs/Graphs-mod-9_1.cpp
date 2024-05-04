//Implementing the isCycle for a Directed Graph 

#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int v;
    vector<bool> visited;
    vector<bool> pathVis;
    vector<list<int>> adj;
    Graph(int v);
    void addEdge(int u, int v);
    void initVis();
    void BFS(int s);
    bool isCycle(int s);
};

Graph::Graph(int v)
{
    this->v = v ;
    adj.resize(v);// This is resizing the adjacency list the v (i.e no of vertices)
}
void Graph:: initVis(){
    this->visited.resize(this->v, false);
    this->pathVis.resize(this->v,false);
}
void Graph:: addEdge(int u , int v){
     adj[u].push_back(v);
     // Since we are working with a directed graph 
}
 
void Graph:: BFS(int s){
    visited.resize(v,false);
    visited[s] = true;
    queue<int> q;
    q.push(s);

    while(!q.empty()){
        s = q.front();
        cout<<s<<" ";
        q.pop();
        for (auto adjNode : adj[s])
        { 
            if(!visited[adjNode]){
                visited[adjNode] = true;
                q.push(adjNode);
            }
        }
        
    }
}

 
bool Graph:: isCycle(int s){
    visited[s] = true;
    pathVis[s] = true;

    for(auto adjNode : adj[s]){
        if(!visited[adjNode]){
            if(isCycle(adjNode)){
                return true;
            }
        }
        else if(pathVis[adjNode])
            return true;
  
    }
    pathVis[s] = false;
    return false;
}








int main(){
    Graph g(5);
    g.initVis();
    g.addEdge(0,1);
    g.addEdge(2,1);
    g.addEdge(3,2);
    g.addEdge(4,3);
    g.addEdge(2,4);
    // g.BFS(2);
    // cout<<g.isCycle(0);
    bool result = false;
    for (int i = 0; i < 5; i++)
    {
        if(!g.visited[i]){
            result = g.isCycle(i);
            if(result) break;
        }
    }
    cout<<result;
    


    return 0;
}