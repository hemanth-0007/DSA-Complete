#include<bits/stdc++.h>
using namespace std;

int helper(int ind, int N,vector<int>& price,
vector<vector<int>>& dp ){
    if(ind == 0){
        return N*price[0];
    }
    if(dp[ind][N] != -1) return dp[ind][N];
    int notTake = 0 + helper(ind-1, N, price, dp);
    int take = INT_MIN;
    int rodLength = ind + 1;
    if(N >= rodLength){
        take = price[ind] + helper(ind, N-rodLength, price, dp);
    }
    return dp[ind][N] = max(take, notTake);
}


int cutRodMem(vector<int>& price, int n){
    vector<vector<int>> dp(n , vector<int>(n+1, -1));
    return helper(n-1, n, price, dp);
}


int cutRodTabulation(vector<int>& price, int n){
    vector<vector<int>> dp(n , vector<int>(n+1, 0));
    
    for (int i = 0; i <= n; i++)
        dp[0][i] = i*price[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int N = 0; N <= n; N++)
        {
            int notTake = dp[ind-1][N];
            int take = INT_MIN;
            int rodLength = ind + 1;
            if(N >= rodLength){
                take = price[ind] + dp[ind][N-rodLength];
            }
            dp[ind][N] = max(take, notTake);
        }
    }
    
    return dp[n-1][n];
}


int main()
{
    vector<int> price = {2,5,7,8,10};
    int n = price.size();
    cout<<cutRodMem(price, n)<<endl;
    cout<<cutRodTabulation(price, n)<<endl;

return 0;
}