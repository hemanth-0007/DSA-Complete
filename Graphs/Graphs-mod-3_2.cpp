#include <bits/stdc++.h>
using namespace std;
/*
    Implementing the DFS traversal of the graph
    using iteravtive approach
*/
class Graph{


    public:
    Graph(int v){
        visited.resize(v,false);
        adjList = new vector<int>[v];
    }
    
        int v;
        vector<int> *adjList ;
        vector<bool> visited;
        void addEdge(int v, int w);
        void DFS(int v);
};

 
void Graph :: addEdge(int v, int w)
{
    adjList[v].push_back(w);
    adjList[w].push_back(v); 
}
 
void Graph :: DFS(int src){

    stack<int> st;
    st.push(src);

    while (!st.empty()) {
        int current_node = st.top();
        st.pop();

        if (!visited[current_node]) {
            cout << current_node << " "; // Process the current node (in this case, just printing)
            visited[current_node]= true;

            for (auto neighbor : adjList[current_node])  
                if (!visited[neighbor])  
                    st.push(neighbor);
        }
    }
}
 
int main()
{
    Graph g(5);
    g.addEdge(0,1);
    g.addEdge(0,3);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(3,2);
    g.addEdge(4,2);
 
    g.DFS(0);

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