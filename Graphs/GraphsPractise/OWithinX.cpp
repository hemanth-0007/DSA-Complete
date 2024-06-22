#include <bits/stdc++.h>
using namespace std;

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

void printMat(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

void dfs(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &vis)
{
    vis[x][y] = true;
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < 4; i++)
    {
        int newX = x + dx[i];
        int newY = y + dy[i];
        if (newX <= 0 && newX > n && newY <= 0 && newY > m && grid[newX][newY] == 'O')
        {
            dfs(newX, newY, grid, vis);
        }
    }
}

void OwithinX(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    for (int j = 0; j < m; j++)
    {
        if (grid[0][j] == 'O' && !vis[0][j])
        {
            dfs(0, j, grid, vis);
        }
        if (grid[n - 1][j] == 'O' && !vis[n - 1][j])
        {
            dfs(n - 1, j, grid, vis);
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (grid[j][0] == 'O' && !vis[j][0])
        {
            dfs(j, 0, grid, vis);
        }
        if (grid[j][m - 1] == 'O' && !vis[j][m - 1])
        {
            dfs(j, m - 1, grid, vis);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 'O')
                grid[i][j] = 'X';
        }
    }
}

int main()
{
    vector<vector<char>> grid = {
        {'X', 'X', 'X', 'X'},
        {'X', 'O', 'O', 'X'},
        {'X', 'X', 'O', 'X'},
        {'O', 'X', 'X', 'X'}};
    printMat(grid);
    OwithinX(grid);
    cout<<endl;
    printMat(grid);
    return 0;
}