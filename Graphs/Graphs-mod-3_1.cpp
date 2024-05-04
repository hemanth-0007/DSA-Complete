#include <bits/stdc++.h>
using namespace std;
/*
    Implementing the Graph using 
    oops concept
*/
class Graph{


    public:
    Graph(int v){
        visited.resize(v,false);
        adjList = new vector<int>[v];
    }
    
        int v;
        vector<int> *adjList ;// array of vectors to store the adjList
        vector<bool> visited;
        void addEdge(int v, int w);
        void DFS(int v);
        void BFS(int v);
        void initialize();
};

// after every bfs or dfs this is mandatory
void Graph :: initialize(){
    visited = vector<bool>(v, false);
}

 
void Graph :: addEdge(int v, int w)
{
    // undeirected graph
    adjList[v].push_back(w);
    adjList[w].push_back(v); 
}
 
void Graph :: DFS(int src){

    visited[src] = true;
    cout<<src<<" ";
    // base case is not needed as we are using the visited array
    // Base Case : when we have visited all the adjacent nodes of the src node
    for (auto adjNode : adjList[src])
        if(!visited[adjNode])
            DFS(adjNode);
    
}
 
void Graph :: BFS(int src){
    queue<int> q;
    visited[src] = true;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        cout<<node<<" ";
        q.pop();
        for(auto adjNode : adjList[node]){
            if(!visited[adjNode]){
                visited[adjNode] = true;
                q.push(adjNode);
            }
        }
    }
}

int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,2);
    g.addEdge(1,4);
    g.addEdge(4,2);
 
    g.DFS(0);
    g.initialize();
    cout<<endl;
    g.BFS(0);

return 0;
}



    //     This peice of the code is for the discnnected graph
    //     as we will be checking for the not visited vertex 
    //     and then appyling the DFS algo then
    //     for(auto itr = adjList.begin(); itr != adjList.end(); itr++){
    //           if(visited[itr->first] == false){
    //             DFS(itr->first);
    //           }
    //     }