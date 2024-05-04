// Counting the number of ways to reach a bottom right point from top left 
// suppose we have an n * m array
// using memoization
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
int n = 3;
int m = 3;
vector<vector<int>> dp(n, vector<int>(m , -1));

cout<<noOfWays(n-1, m-1, dp);
return 0;
}
 