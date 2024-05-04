// Implementing the topological sort using the "DFS" only works on the (DAG)
// Directed acyclic graph 
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
        void DFS(int f, stack<int> &st);
};
// constructor fucntion 
Graph:: Graph(int v){
    this->v = v ;
    adj.resize(v);
    visited.resize(v,false);
}


void Graph :: addEdge(int v, int w){
     // directed graph
     adj[v].push_back(w);
     
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

void Graph :: DFS(int src, stack<int> &st){
    
    visited[src] = true;
    for(auto adjNode : adj[src]){
        if(!visited[adjNode]){
            DFS(adjNode,st);
        }
    }
    st.push(src);

}

void print_stack(stack<int> st){
    int n = st.size();
    for (int i = 0; i < n; i++)
    {
        cout<<st.top()<<" ";
        st.pop();
    }
    
}
int main()
{   
    int V = 6;
    Graph G(V);
    int c = 0;
    G.addEdge(5,0);
    G.addEdge(5,2);
    G.addEdge(4,0);
    G.addEdge(4,1);
    G.addEdge(2,3);
    G.addEdge(3,1);
     // declare a stack
     stack<int> st;
    for (int i = 0; i < V; i++)
       { if(!G.visited[i]) G.DFS(i,st);}
    
    print_stack(st);
    
    
return 0;
}