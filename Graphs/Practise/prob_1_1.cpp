#include<bits/stdc++.h>
using namespace std;

int shortDis( vector<int> adj[], int n,
int src, int des){

    queue<int> q;
    int dis[n];
    for (int i = 0; i < n; i++) dis[i] = 1e9;
  
    q.push(src);
    dis[src] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for(auto adjNode : adj[node]){
            if(dis[node] + 1 < dis[adjNode]){
                dis[adjNode] = dis[node] + 1;
                q.push(adjNode);
            }
        }
         
        
    }
    for (int i = 0; i < n; i++)
    {
        cout<<dis[i]<<" ";
    }
    cout<<endl;
    
    if(dis[des] != 1e9)
        return dis[des] - dis[src];
     else 
        return 9999;
}





void printMinTime( vector<vector<int>>& grid , 
vector<int>& start  , vector<int>& end){
   int n = grid.size();
   vector<int> adj[n];
   // my adjacency list
   for(int i = 0 ; i<n ; i++){
    for (int j = 0; j < n; j++)
    {
        if(grid[i][j] == 1 && grid[j][i] == 1){
            adj[i].push_back(j);
            adj[j].push_back(i);
        }
    }
   }

    

    for (int i = 0; i < start.size(); i++)       
            cout<<shortDis(adj,n,start[i],end[i])<<endl;
   

}

int main()
{
    vector<vector<int>> grid = {
      {0,1,9999,9999},
      {1,0,1,9999},
      {9999,1,0,9999},
      {0,9999,9999,0}
    };
    vector<int> start = {0,0,0};
    vector<int> end = {1,2,3};
    printMinTime(grid, start , end);
return 0;
}