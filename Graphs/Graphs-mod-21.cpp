//Marking the safe nodes out from a directed graph 
// using the dfs algorithm

#include<bits/stdc++.h>
using namespace std;

class Graph
{
public:
    int v;
    vector<bool> visited;
    vector<bool> pathVis;
    vector<int> checked;
    vector<list<int>> adj;


    Graph(int v);
    void addEdge(int u, int v);
    void initVis();
    vector<int> getSafeNodes();
    bool dfsCheck(int s);
};

Graph::Graph(int v)
{
    this->v = v ;
    checked.resize(v,0);
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
 


 
bool Graph:: dfsCheck(int s){
    visited[s] = true;
    pathVis[s] = true;
    checked[s] = 0;

    for(auto adjNode : adj[s]){
        if(!visited[adjNode]){
            if(dfsCheck(adjNode)){
                checked[s] = 0;
                return true;
                
            }
        }
        else if(pathVis[adjNode])
            return true;
  
    }
    checked[s] = 1;
    pathVis[s] = false;
    return false;
}




vector<int> Graph:: getSafeNodes(){
    
    for (int i = 0; i < this->v; i++)
    {
        if(!visited[i]){
            dfsCheck(i);
        }
    }
    
}



int main(){
    int v = 12;
    Graph g(v);
    g.initVis();
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,5);
    g.addEdge(3,4);
    g.addEdge(4,6);
    g.addEdge(5,6);
    g.addEdge(6,7);
    g.addEdge(9,10);
    g.addEdge(8,1);
    g.addEdge(10,8);
    g.addEdge(8,9);
    g.addEdge(9,10);
    g.addEdge(11,9);
    g.getSafeNodes();


  
    for (int i = 0; i < v; i++)
    {
        if(g.checked[i] == 1){
            cout<<i<<" ";
        }
        // cout<<g.checked[i]<<" ";
    }
    
     
    


    return 0;
}