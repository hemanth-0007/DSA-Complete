#include<bits/stdc++.h>
using namespace std;
// memoization techniquee for Dynamic programming
int fab(int n, vector<int> dp){
    if( n<= 1){
        return dp[n] = n;
    }
    if(dp[n] != -1){
        return dp[n];
    }
    return dp[n] =  fab(n-1,dp ) + fab(n-2, dp);
}


int main()
{
int n = 9;
vector<int> dp(n+1, -1);
cout<<fab(n,dp);

// tabular method for dp
int prev2 = 0;
int prev = 1;
// sc - O(1)
//tc - O(n)
for (int i = 2; i <= n; i++)
{
    int res = prev + prev2;
    prev2 = prev;
    prev = res;
}
// cout<<prev;



return 0;
}