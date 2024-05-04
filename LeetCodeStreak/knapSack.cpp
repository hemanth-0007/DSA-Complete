#include<bits/stdc++.h>
using namespace std;

int helper(int ind, int W, vector<int>& wt, 
vector<int>& profit, vector<vector<int>> &dp){
    // base
    if(ind == 0){
        if(wt[0] <= W) return profit[0];
        return 0;
    }
    if(dp[ind][W] != -1) return dp[ind][W];
    int take = INT_MIN;
    int notTake = 0 + helper(ind-1, W, wt, profit, dp);
    if(wt[ind] <= W){
        take = profit[ind] + helper(ind -1, W - wt[ind], wt, profit, dp);
    }
    return dp[ind][W] = max(take, notTake);
}

int knapSackMem( vector<int>& wt, vector<int>& profit, int W){
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(W+1, -1));
    return helper(n-1, W, wt, profit, dp);
}

int knapSackTabulation( vector<int>& wt, vector<int>& profit, int W){
    int n = wt.size();
    vector<vector<int>> dp(n, vector<int>(W+1, 0));
    for (int i = wt[0]; i <= W; i++)
        dp[0][i] = profit[0];
    
    for (int ind = 1; ind < n; ind++)
    {
        for (int w = 0; w <= W; w++)
        {
            int take = INT_MIN;
            int notTake = dp[ind-1][w];
            if(wt[ind] <= w) take = profit[ind] + dp[ind -1][w - wt[ind]];
            dp[ind][w] = max(take, notTake);
        }
    }
    return dp[n-1][W];
}


int main()
{
    vector<int> wt = {3,4,5};
    vector<int> profit = {30,50,60};
    int W = 8;
    cout<<knapSackMem(wt, profit, W)<<endl;
    cout<<knapSackTabulation(wt, profit, W);

return 0;
}