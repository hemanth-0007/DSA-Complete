// C++ code to print BFS traversal from a given
// source vertex from a adjacency matrix

#include <bits/stdc++.h>
using namespace std;

 

void  BFS(int s,  vector<vector<int>> &grid , int V)
{
   vector<bool> visited(V,false);
   queue<int> q;
   visited[s] = true;
   q.push(s);

   while (!q.empty())
   {
     int node = q.front();
     cout<<node<<" ";
     q.pop();
        for(int adjNode = 0 ; adjNode < V; adjNode++){
            if(grid[node][adjNode] != 1) continue;
            if(!visited[adjNode]){
                visited[adjNode]= true;
                q.push(adjNode);
            }
        }
   }
    
}

// Driver code
int main()
{
    int V = 4, src;
   vector<vector<int>> grid = {
      {0,1,9999,1},
      {1,0,1,9999},
      {9999,1,0,9999},
      {1,9999,9999,0}
    };
 
    cout<<"Enter the vertex you wanna start: ";
    cin>>src;

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex "<<src<<") \n";
        BFS(src,grid,V);
 

    return 0;
}
