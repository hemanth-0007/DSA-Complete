#include <bits/stdc++.h>
using namespace std;

int orangesRotting(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    queue<pair<int, pair<int,int>>> q;
    vector<vector<bool>> vis(n , vector<bool>(m , false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++){
            if(grid[i][j]==2) {
                q.push({0, {i ,j}});
                vis[i][j] = true;
            }
        }
    }
    vector<int> dx = {-1,1,0,0};
    vector<int> dy = {0,0,1,-1};
    int ans = 0;
    while (!q.empty())
    {
        int time = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        q.pop();
        ans = max(ans, time);
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i], newY = y + dy[i];
            if(newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1 && !vis[newX][newY]){
                vis[newX][newY] = true;
                grid[newX][newY] = 2;
                q.push({time + 1, {newX, newY}});
            }
        }
    }
     for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if(grid[i][j]==1)  return -1;

    return ans;
}
int main()
{

    return 0;
}