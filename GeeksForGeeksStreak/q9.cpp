#include<bits/stdc++.h>
using namespace std;

int helper(int ind, int total, vector<int>&cost, int n, vector<vector<int>>& dp){
    // base condi
    if(ind >= n) return 0;
    if(dp[ind][total] != -1) return dp[ind][total];
    // main recursion
    int ans = -1e9;
    if(total >= cost[ind]){
        int buy = 1 + helper(ind +1, total - (0.1)*cost[ind], cost, n, dp);
        ans = max(ans, buy);
    } 
    int notBuy = 0 + helper(ind + 1, total, cost, n, dp);
    ans = max(ans, notBuy);
    return dp[ind][total] = ans;
}





int max_courses(int n, int total, vector<int> &cost)
{
        vector<vector<int>> dp(n, vector<int>(total+1,-1));
        return helper(0, total,cost,n, dp);
}

int main()
{
    vector<int> cost = {18, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int n = cost.size();
    int total = 18;
    cout<<max_courses(n , total, cost);

return 0;
}