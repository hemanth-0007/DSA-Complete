#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {1, 0, 0, -1};
vector<int> dy = {0, 1, -1, 0};

int helper(int i, int j, vector<vector<int>> &grid,
           vector<vector<bool>> &visited)
{
    // base case 1
    if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0)
        return 0;
    // base case 2
    if (visited[i][j] == true || grid[i][j] == 0)
        return 0;

    // recursive code
    visited[i][j] = true;
    int maxi = -1e9;
    for (int k = 0; k < 4; k++)
        maxi = max(maxi, grid[i][j] + helper(i + dx[k], j + dy[k], grid, visited));
    visited[i][j] = false;
    return maxi;
}

int getMaximumGold(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int maxi = -1e9;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != 0)
            {
                cout << i << " " << j << " " << grid[i][j] << endl;
                int temp = helper(i, j, grid, visited);
                cout << temp << endl;
                maxi = max(maxi, temp);
            }
        }
    }
    return maxi == -1e9 ? 0 : maxi;
}

int dfs(int i, int j, vector<vector<int>> &grid)
{
    // base case 1
    if (i >= grid.size() || i < 0 || j >= grid[0].size() || j < 0)
        return 0;
    // base case 2
    if (grid[i][j] == 0) return 0;

    // recursive code
     
    int maxi = -1e9;
    int curr = grid[i][j];
    grid[i][j] = 0;
    for (int k = 0; k < 4; k++)
        maxi = max(maxi, curr + dfs(i + dx[k], j + dy[k], grid));
    grid[i][j] = curr;
    return maxi;
}

// improved effieciency by modifing the grid values to 0
int getMaximumGoldOp(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int maxi = -1e9;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != 0)
            {
                cout << i << " " << j << " " << grid[i][j] << endl;
                int temp = dfs(i, j, grid);
                cout << temp << endl;
                maxi = max(maxi, temp);
            }
        }
    }
    return maxi == -1e9 ? 0 : maxi;
}

int main()
{
    vector<vector<int>> grid = {{0, 6, 0},
                                {5, 8, 7},
                                {0, 9, 0}};
    cout << getMaximumGold(grid);
    return 0;
}