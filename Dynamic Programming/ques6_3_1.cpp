// Counting the number of ways to reach a bottom right point from top left 
// suppose we have an n * m array
// using Sapce Optimization
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
    {0,0,0},
    {0,0,0},
};
int n = vec[0].size();
int m = vec.size();

// this one is taking a space of O(n)
 vector<int> dp(n , 0);

 vector<int> temp(n , 0);
 
 

for (int i = 0; i < m; i++)
{
    temp.resize(n, 0);
    
    for (int j = 0; j < n; j++)
    {
        int up = 0, left = 0;
        if(i == 0 && j == 0)
            temp[j] = 1;
      
        else{
            if(i > 0)
                up = dp[j];
            if(j > 0 )
                left = temp[j-1];
            
            temp[j] = up + left;
        }
        
    }
    dp = temp;
}

 // this will be giving you the no of paths
 cout<<dp[n-1];
return 0;
}
 