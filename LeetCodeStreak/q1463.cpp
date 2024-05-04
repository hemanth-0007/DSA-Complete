#include<bits/stdc++.h>
using namespace std;

int helper(int i, int j1, int j2,vector<vector<int>>& grid,
 int m, int n, vector<vector<vector<int>>> &dp ){
   
   
    if(j1 < 0 || j1 >= m || j2 < 0 || j2 >= m) return -1e8;
    
    if( dp[i][j1][j2] != -1) return  dp[i][j1][j2] ;
   
    // base case
    if(i == n-1){
        if(j1 == j2) return grid[i][j1];
        else return (grid[i][j1] + grid[i][j2]);
    }

    // main code
    int maxi = 0;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            if(j1 == j2){
                maxi = max(maxi, grid[i][j1] + helper(i+1, j1 + dj1, j2 + dj2, grid, m ,n, dp));
            }
            else{
                maxi = max(maxi, grid[i][j1] + grid[i][j2] + helper(i+1, j1 + dj1, j2 + dj2, grid, m ,n, dp));
            }
        }
        
    }
    return dp[i][j1][j2] = maxi; 

}



int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(m , vector<int>(m, -1)));
    return helper(0, 0, m-1, grid, m, n, dp);
}

int main()
{
    vector<vector<int>> grid = {{3,1,1},{2,5,1},{1,5,5},{2,1,1}};
    cout<<cherryPickup(grid);

    // tabulation

return 0;
}