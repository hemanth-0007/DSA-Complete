#include<bits/stdc++.h>
using namespace std;
// memoization techniquee for Dynamic programming
int f(int n , vector<int>& dp){
if(n == 0 ) return dp[0] = 1;
if(n < 0) return 0;

if(dp[n] != -1) return dp[n];

return dp[n] = f(n-1, dp) + f(n-2,dp);
}

int climbStairs(int n) {

    vector<int> dp(n+1, -1);
    return f(n ,dp);

}

int main()
{
int n = 6;

cout<<climbStairs(6);
 
return 0;
}