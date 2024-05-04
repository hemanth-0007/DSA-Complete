#include <bits/stdc++.h>
using namespace std;

// optimal solution can we do it in O(1) sc
void rowColZero(vector<vector<int>> &vec)
{
    // row[..][0]
    // col[0][..]
    int col0 = 1;
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            if (vec[i][j] == 0)
            {
                vec[0][j] = 0;
                if (j != 0)
                    vec[i][0] = 0;
                else
                    col0 = 0;
            }
        }
    }

    for (int i = 1; i < vec.size(); i++)
    {
        for (int j = 1; j < vec[i].size(); j++)
        {
            if (vec[i][0] == 0 || vec[0][j] == 0)
            {
                vec[i][j] = 0;
            }
        }
    }

    if (vec[0][0] == 0)
        for (int i = 1; i < vec[0].size(); i++)
            vec[0][i] = 0;

    if (col0 == 0)
        for (int i = 1; i < vec.size(); i++)
            vec[i][0] = 0;
}

int main()
{
    vector<vector<int>> vec = {{0, 12, 3},
                               {1, 2, 4},
                               {9, 76, 3},
                               {6, 56, 1}};

    rowColZero(vec);

    for (auto itr : vec)
    {
        for (auto it : itr)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}