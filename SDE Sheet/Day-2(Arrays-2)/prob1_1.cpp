// Rotating the given array by 90 degrees clockwise

#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &grid)
{
    int n = grid.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
            swap(grid[i][j], grid[j][i]);
    }

    for (int i = 0; i < n; i++)
        reverse(grid[i].begin(), grid[i].end());
}

int main()
{

    vector<vector<int>> grid = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}};
    rotate(grid);
    int n = grid.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}