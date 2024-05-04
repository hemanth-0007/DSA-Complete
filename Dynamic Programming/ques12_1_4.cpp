
// Getting the number of subsets whose sum equals to k 
// Space Optimisation
// for the constraints 1<= arr[i]<<1000

#include<bits/stdc++.h>
using namespace std;

int countSubsets(int ind , int target , vector<int> arr, vector<vector<int>> dp){
    
    if(target == 0) return 1;
    if(ind == 0) return (arr[0] == target);
    if(dp[ind][target] != -1) return dp[ind][target];
    int notPick = countSubsets(ind-1, target, arr,dp);
    int  pick = 0;
    if(target >= arr[ind])
        pick = countSubsets(ind-1, target- arr[ind], arr, dp);
    
    
    return dp[ind][target] = (pick + notPick);


}

int main()
{
    vector<int> arr = {2,1,1,3};
    int n = arr.size();
    int k = 5 ;
    vector<vector<int>> dp(n,vector<int>(k + 1, 0));
    
    for (int i = 0; i < n; i++) dp[i][0] = 1;
    dp[0][arr[0]] = 1;

    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= k; target++)
        {
            int notPick = dp[ind-1][target] ;
            int  pick = 0;
            if(target >= arr[ind])
                pick = dp[ind-1][target- arr[ind]];
            
            
            dp[ind][target] = (pick + notPick);
        }
        
    }
    
    cout<<dp[n-1][k];
return 0;
}