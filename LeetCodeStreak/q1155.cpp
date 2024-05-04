// Dynamic Programming Number of Dice Rolls With Target Sum
#include<bits/stdc++.h>
using namespace std;
const int mod = (int)pow(10, 9) + 7; // Modulo value for calculations

int helper(int ind ,int k , int target, vector<vector<int>>&dp){
    // base conditions
    // if(ind == 0){
    //     if(target == 0) return 1;
    //     else return 0;
    // }
    if (target == 0 && ind == 0) return 1;
    if (ind == 0 || target <= 0) return 0;
    
    if(dp[ind][target] != -1) return dp[ind][target]%mod;
    // main recursive code
    long long ans = 0;
    for (int i = 1; i <= k; i++){
        // if(target > 0 && target <= n*k)
            ans = (ans + helper(ind -1, k , target-i, dp))%mod;
    }
    
    dp[ind][target] = ans%mod;
    return dp[ind][target];
}




int numRollsToTarget(int n, int k, int target) {
    vector<vector<int>> dp(n + 1, vector<int>(target + 1 , -1));
    return helper(n, k , target, dp);
}


int main()
{
    cout<<numRollsToTarget(2, 6, 7)<<endl;
    cout<<numRollsToTarget(1, 6, 3)<<endl;
    cout<<numRollsToTarget(30, 30, 500)<<endl;

return 0;
}