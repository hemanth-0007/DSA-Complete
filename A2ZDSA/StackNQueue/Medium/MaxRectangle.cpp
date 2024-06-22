#include <bits/stdc++.h>
using namespace std;

void printMat(vector<vector<char>> &grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int maximalRectangle(vector<vector<char>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            grid[i][j] = ((grid[i][j - 1] - '0') + (grid[i][j] - '0')) + '0';
        }
    }
    // printMat(grid);
    vector<int> col(n, 0);
    int ans = 0;
    int maxCnt = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = i; j < m; j++)
        {
            int noOfCols = j - i + 1;
            if (i == 0)
            {
                for (int k = 0; k < n; k++)
                    col[k] = grid[k][j] - '0';
            }
            else
            {
                for (int k = 0; k < n; k++)
                    col[k] = ((grid[k][j] - '0') - (grid[k][i - 1] - '0'));
            }
            int k = 0;
            while (k < col.size())
            {
                int cnt = 0;
                while (k < col.size() && col[k] == noOfCols)
                {
                    k++;
                    cnt++;
                }
                maxCnt = max(maxCnt, cnt);
                ans = max(ans, noOfCols * maxCnt);
                k++;
            }
        }
    }

    return ans;
}
int main()
{
    // vector<vector<char>> grid = {
    //     {'1', '0', '1', '0', '0'},
    //     {'1', '0', '1', '1', '1'},
    //     {'1', '1', '1', '1', '1'},
    //     {'1', '0', '0', '1', '0'}
    // };
    //  vector<vector<char>> grid = {
    //     {'0'}
    // };
    vector<vector<char>> grid = {
        {'1'}};
    printMat(grid);
    cout << endl;
    cout << maximalRectangle(grid);
    return 0;
}