#include <bits/stdc++.h>
using namespace std;

void printMatrix(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

}

void rotate(vector<vector<int>> &matrix)
{
    // nxn matrix
    int n = matrix.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (i != j){
                cout<<i<<" "<<j<<endl;
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n/2; j++)
        {
            swap(matrix[i][j], matrix[i][n-j-1]);   
        }
    }
    
    // printMatrix(matrix);
}


int main()
{
    vector<vector<int>>  matrix = {{1,2,3},{4,5,6},{7,8,9}};
    // printMatrix(matrix);
    rotate(matrix);
    return 0;
}