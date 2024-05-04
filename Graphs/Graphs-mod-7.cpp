#include <bits/stdc++.h>
using namespace std;
 


void BFS(int n, vector<vector<int>>& grid, vector<int>& visited, int src)
{
    queue<int> q;
    visited[src] = true;
    q.push(src);
    while(!q.empty()){
        int node = q.front();
        q.pop();
        // traverse through the adjacent nodes
        for (int j = 0; j < n; j++)
        {   
            if(j != node && grid[node][j] == 1 && !visited[j]){
                visited[j] = true;
                q.push(j);
            }
        }
    }
}

int main()
{
    int n = 4;
    vector<vector<int>> grid(n, vector<int>(4, 0));
    vector<int> visited(n, false);
    grid[0][0] = 1;
    grid[1][0] = 1;
    grid[0][1] = 1;
    grid[1][1] = 1;

    grid[2][1] = 1;
    grid[1][2] = 1;

    grid[2][2] = 1;
    grid[3][3] = 1;
    grid[2][3] = 1;
    grid[3][2] = 1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i])
            {
                count++;
                BFS(n, grid, visited, i);
            }
        }
    }
    cout<<count<<endl;

    return 0;
}