#include<bits/stdc++.h>

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

vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();      
    int top = 0, bottom = n-1, left = 0, right = m-1;
    vector<int> ans;
    while (left <= right && top<= bottom)
    {
        for (int i = left; i <= right; i++)
            ans.push_back(matrix[top][i]);
        top++;
        if(top > bottom) break;
        for (int i = top; i <= bottom; i++)
            ans.push_back(matrix[i][right]);
        right--;
        if(left > right) break;
        for (int i = right; i >= left; i--)
            ans.push_back(matrix[bottom][i]);
        bottom--;
        if(top > bottom) break;
        for (int i =  bottom; i >= top; i--)
            ans.push_back(matrix[i][left]);
        left++;
        if(left > right) break;
    }
    return ans;
}



int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> ans = spiralOrder(matrix);
    for(auto num : ans) cout<<num<< " ";

return 0;
}