#include <bits/stdc++.h>
using namespace std;

void nearestZero(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    // node , distance
    queue<pair<int, pair<int, int>>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 0)
                q.push({0, {i, j}});
            else grid[i][j] = 1e9;
        }
    }
    vector<int> dx = {0, 0, 1, -1};
    vector<int> dy = {1, -1, 0, 0};

    while (!q.empty())
    {
        int x = q.front().second.first;
        int y = q.front().second.second;
        int dis = q.front().first;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] != 0 && grid[newX][newY] > dis + 1)
            {
                grid[newX][newY] = 1 + dis;
                q.push({grid[newX][newY], {newX, newY}});
            }
        }
    }
}

void printMat(vector<vector<int>> &grid)
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

int main()
{
    vector<vector<int>> grid = {{1,0,1}, {1,1,1}, {1,1,0}};
    printMat(grid);
    nearestZero(grid);
    printMat(grid);

    return 0;
}