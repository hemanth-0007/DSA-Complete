#include<bits/stdc++.h>
using namespace std;

int shortDis( vector<vector<int>>& grid , int n,
int src, int des){

    queue<int> q;
    vector<int> dis(n,1e9);
  
    q.push(src);
    dis[src] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        
        for (int adjNode = 0; adjNode < n; adjNode++)
        {
            if(grid[node][adjNode] != 1) continue;
            
            if(dis[node] + 1 < dis[adjNode]){
                dis[adjNode] = dis[node] + 1;
                q.push(adjNode);
            }
        }
        
    }
    
 
    
    if(dis[des] != 1e9)
        return dis[des] - dis[src];
     else 
        return 9999;
}





void printMinTime( vector<vector<int>>& grid , 
vector<int>& start  , vector<int>& end){
   int n = grid.size();
    //O(q) * 
    for (int i = 0; i < start.size(); i++)       
            cout<<shortDis(grid,n,start[i],end[i])<<endl;
   

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