#include<bits/stdc++.h>
using namespace std;

int helper(int i, int j, vector<vector<int>>& matrix,int n, int m, vector<vector<int>> &dp){
    // Base conditions
    if(j < 0 || j >= m) return 1e8;
    if(i == n - 1 && j >= 0 && j < m) {
        // cout<<i<<" "<<j<<endl;
        return dp[i][j] = matrix[i][j];
    }
    if(dp[i][j] != -1) return dp[i][j];
    int l = matrix[i][j] + helper(i+1, j, matrix, n, m, dp);
    int ld = matrix[i][j] + helper(i+1, j-1, matrix, n, m, dp);
    int rd = matrix[i][j] + helper(i+1, j+1, matrix, n, m, dp);
    return dp[i][j] = min(l , min(ld, rd));
}



int minFallingPathSum(vector<vector<int>>& matrix) {
     int n = matrix.size();
     int m = matrix[0].size();
     int mini = 1e9;
     vector<vector<int>> dp(n, vector<int>(m, -1));
     for(int j = 0 ; j < m ; j++){
        mini = min(mini, helper(0, j ,matrix, n, m, dp));
     }
     return mini;
}

int main()
{
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    cout<<minFallingPathSum(matrix);


return 0;
}