//Implementing the isCycle for a Directed Graph through diff question

#include<bits/stdc++.h>
using namespace std;
 

 
 
void BFS(int s, int v, vector<int> adj[] ){
    
    vector<bool> visited(v,false);
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

 
bool isCycle(int s, vector<bool> &visited,
vector<bool> &pathVis,vector<int> adj[]){
    visited[s] = true;
    pathVis[s] = true;

    for(auto adjNode : adj[s]){
        if(!visited[adjNode]){
            if(isCycle(adjNode,visited,pathVis,adj)){
                return true;
            }
        }
        else if(pathVis[adjNode])
            return true;
  
    }
    pathVis[s] = false;
    return false;
}

bool isCycleUtill(int V, vector<int> adj[] ){

        vector<bool> visited(V, false);
        vector<bool> pathVis(V, false);
         bool result = false;
                for (int i = 0; i < V; i++)
                {
                    if(!visited[i]){
                        result = isCycle(i,visited,pathVis,adj);
                        if(result) break;
                    }
                }
        return result;
}







int main(){
    // int V = 5;
    //  vector<vector<int>> vec;
    //     vec.push_back({0,1});
    //     vec.push_back({2,1});
    //     vec.push_back({3,2});
    //     vec.push_back({4,3});
    //     vec.push_back({4,2});
        int V = 2;
     vector<vector<int>> vec;
        vec.push_back({0,1});
        vec.push_back({1,0});
       
         
     

     vector<int> adj[V];
     for(auto v : vec){
        adj[v[0]].push_back(v[1]);
       cout<<v[0]<<"-->"<<v[1]<<endl;
     }




    cout<<isCycleUtill(V,adj)<<endl;

    // for (int i = 0; i < V; i++) cout<<i<<" ";
    // cout<<endl;
    // for(auto bl : visited) cout<<bl<<" ";
    // cout<<endl;
    // for(auto b : pathVis) cout<<b<<" ";

 
    


    return 0;
}