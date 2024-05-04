
// Getting the number of subsets whose sum equals to k 
// by memoization


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
    int target = 5 ;
    vector<vector<int>> dp(n,vector<int>(target + 1, -1));
    cout<<countSubsets(n-1, target, arr, dp);

return 0;
}