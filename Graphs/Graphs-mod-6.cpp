// Finding the number of provinces using bfs or dfs 
// Or the no of connected components in an undirected graph 

#include<bits/stdc++.h>
using namespace std;
class Graph{

    public:
        int v;//vertices
        Graph(int v );
        vector<bool> visited;
        vector<list<int>> adj;
        void addEdge(int v ,int w);
        void BFS(int s);
        void DFS(int f);
};
// constructor fucntion 
Graph:: Graph(int v){
    this->v = v ;
    adj.resize(v);
    visited.resize(v,false);
}


void Graph :: addEdge(int v, int w){
     // undirected graph
     adj[v].push_back(w);
     adj[w].push_back(v);
}


void Graph :: BFS(int s){

    list<int> q ;

    this->visited[s] = true;
    q.push_back(s);

    while (!q.empty())
    {
         s = q.front();
        //  cout<<s<<" ";
         q.pop_front();
         for(auto itr : this->adj[s]){
           if(!this->visited[itr]){
                this->visited[itr] = true;
                q.push_back(itr);
           }
         }
         

    }
    
}

void Graph :: DFS(int src){
    
    visited[src] = true;
    cout<<src<<" ";

    for(auto adjNode : adj[src]){
        if(!visited[adjNode]){
            DFS(adjNode);
        }
    }

}
int main()
{
    Graph G(6);
    int c = 0;
    G.addEdge(0,1);
    G.addEdge(0,2);
    G.addEdge(1,2);
    G.addEdge(3,4);
    // G.addEdge(3,5);
    
    // G.addEdge(0,2);
    // G.addEdge(1,2);
    // G.addEdge(1,3);
    // G.BFS(0);
    // no of provinces
    // G.visited.resize(4,false);
    // G.DFS(2);
    for (int i = 0; i < 6; i++)
    {
        if(!G.visited[i]){
            c++;
            cout<<c<<endl;
            G.DFS(i);
        }
    }//Here c will be counting the number of provinces and printing them 
    // In an undirected graph 
    // Any of the traversals can be used to findout the provinces in the graph 
    
    
return 0;
}