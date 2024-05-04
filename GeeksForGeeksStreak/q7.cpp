#include<bits/stdc++.h>
using namespace std;

bool helper(int ind , int sum, vector<int>&coins,vector<vector<int>>& dp){
    // base condi
    // cout<<ind<<" "<<sum<<endl;
    if(dp[ind][sum] != -1) return dp[ind][sum];
    if(ind == 0){
        if(sum != 0 && (sum == 2024 || sum%20 == 0 || sum%24 == 0)) return true;
        sum += coins[ind];
        if(sum != 0 && (sum == 2024 || sum%20 == 0 || sum%24 == 0)) return true;
        else return false;
    }
    // main code
    if(helper(ind-1, sum + coins[ind], coins, dp) == true) return true;
    if(helper(ind-1, sum, coins, dp) == true) return true;
    dp[ind][sum] = false;
    return dp[ind][sum];
}




bool isPossible(vector<int>& coins){
    // base condi
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(2025,-1));
    return helper(n-1, 0, coins, dp);
}



int main()
{
    // vector<int> coins = {5, 8, 9, 10, 14, 2, 3, 5};
    // vector<int> coins = {1,2, 3, 4, 5};
    // vector<int> coins = {10,5,5};
    // vector<int> coins = {18, 1, 16, 17};
    vector<int> coins = {9 ,24, 5};
    cout<<isPossible(coins)<<endl;

return 0;
}