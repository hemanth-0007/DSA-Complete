#include <bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();

    int c = 1;
    for (int i = 0; i < n; i++)
    {
        if (grid[i][0] == 0)
        {
            c = 0;
            break;
        }
    }

    for (int j = 0; j < m; j++)
    {
        if (grid[0][j] == 0)
        {
            grid[0][0] = 0;
            break;
        }
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (grid[i][j] == 0)
            {
                grid[i][0] = 0;
                grid[0][j] = 0;
            }
        }
    }

    for (int i = 1; i < m; i++)
    {
        if (grid[0][i] == 0)
        {
            for (int j = 0; j < n; j++)
                grid[j][i] = 0;
        }
    }

    for (int i = 1; i < n; i++)
    {
        if (grid[i][0] == 0)
        {
            for (int j = 1; j < m; j++)
                grid[i][j] = 0;
        }
    }

    if (grid[0][0] == 0)
        for (int i = 0; i < m; i++)
            grid[0][i] = 0;

    if (c == 0)
        for (int i = 0; i < n; i++)
            grid[i][0] = 0;
}

void printGrid(vector<vector<int>> &grid)
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
    vector<vector<int>> grid = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
    printGrid(grid);
    setZeroes(grid);
    cout << endl;
    printGrid(grid);

    return 0;
}