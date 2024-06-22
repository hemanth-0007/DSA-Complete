#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {1, 0, 0 - 1};
vector<int> dy = {0, 1, -1, 0};


int manDis(int i , int j, vector<pair<int,int>>& theives){
    int ans = 1e9;
    for (auto it : theives)
        ans = min(ans, abs(i - it.first) + abs(j - it.second));
    return ans;
}
 

int dfs(int i, int j, vector<vector<int>> &grid, vector<pair<int, int>> &theives,
        vector<vector<bool>> &visited)
{
    // base case
    if (i < 0 || i >= grid.size() || j < 0 || j >= grid.size() || visited[i][j])
        return 1e9;
    // base case 2
    if (grid[i][j] == 1)
        return 0;

    // base case 3
    if(i == grid.size()-1 && j == grid.size()-1){
        return manDis(i , j , theives );
    }

    // code
    visited[i][j] = true;
    int mini = 1e9;
    int dis = manDis(i , j , theives);
    // cout<<"\t"<<i<<" "<<j<<" "<<dis<<endl;
    for (int k = 0; k < 4; k++)
    {
        int newX = i + dx[k];
        int newY = j + dy[k];
        mini = min(mini, min(dis, dfs(newX, newY, grid, theives, visited)));
    }
    visited[i][j] = false;
    return mini;    
}

int maximumSafenessFactor(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<pair<int, int>> theives;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            if (grid[i][j] == 1)
                theives.push_back({i, j});
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] != 1 )
            {
                int temp = dfs(i, j, grid, theives, visited);
                // cout<<i<<" "<<j<<" "<<temp<<endl;
                ans = max(ans, temp);
            }
            else
                ans = 0;
        }
    }
    return ans;
}
int main()
{
   vector<vector<int>>  grid = {{0,0,1},{0,0,0},{0,0,0}};
    cout<<maximumSafenessFactor(grid);
    return 0;
}