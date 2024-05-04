// Counting the number of ways to reach a bottom right point from top left 
// suppose we have an n * m array
// using Tabulation
#include<bits/stdc++.h>
using namespace std;
int noOfWays(int i , int j ,vector<vector<int>>& dp){
    if( i < 0 || j < 0) return 0;
    if(i ==0 && j ==0 ) return dp[0][0] = 1 ;

    if( dp[i][j] != -1) return dp[i][j];

    int upStep = noOfWays(i  , j-1 , dp);
    int leftStep = noOfWays(i-1 , j , dp);

    return dp[i][j] = (upStep + leftStep);
}




int main()
{
 
vector<vector<int>> vec = {
    {0,0,0},
    {0,-1,0},
    {0,0,0},
};
int n = vec[0].size();
int m = vec.size();
vector<vector<int>> dp(m, vector<int>(n,-1));
 
 

for (int i = 0; i < m; i++)
{
    for (int j = 0; j < n; j++)
    {
        if(i == 0 && j == 0)
            dp[i][j] = 1;
      
        else{
            int upStep = 0, leftStep = 0 ;
            if(j >0)
                upStep = dp[i][j-1];
            if(i >0)
                leftStep = dp[i-1][j];
            dp[i][j] = leftStep + upStep;
        }
        
    }
    
}

 // this will be giving you the no of paths
 cout<<dp[m-1][n-1];
return 0;
}
 