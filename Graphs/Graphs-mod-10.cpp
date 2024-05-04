//Checking if there is path between the two verrices u, v in a Directed Graph 

#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int v;
    vector<bool> visited;
 
    vector<list<int>> adj;

    Graph(int v);
    void addEdge(int u, int v);
    void initVis();
    void BFS(int s);
    bool isPath(int u , int v);
};

Graph::Graph(int v)
{
    this->v = v ;
    adj.resize(v);// This is resizing the adjacency list the v (i.e no of vertices)
}
void Graph:: initVis(){
    this->visited.resize(this->v, false);
    
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

 
bool Graph :: isPath(int u , int v){
     visited[u] = true;
     queue<int> q ;
     q.push(u);
     int s ;
     while(!q.empty()){
        s = q.front();
        q.pop();
        for(auto adjNode : adj[u]){
            if(!visited[adjNode]){
                visited[adjNode] = true;
                q.push(adjNode);
            }
        }
     }
     if(visited[v])
        return true;
     else
        return false;

}






int main(){
    Graph g(5);
    g.initVis();
    g.addEdge(0,1);
    g.addEdge(2,1);
    g.addEdge(2,3);
    g.addEdge(3,4);
    g.addEdge(2,4);
    cout<<g.isPath(2,4);
    


    return 0;
}