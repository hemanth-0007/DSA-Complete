// calculating the combinatiosn that sum up to the required target using only one element at a time from the
// array
// Tabulation technique


#include <bits/stdc++.h>
using namespace std;

bool isTargetInSqnc(vector<int> arr, int ind, int target, vector<vector<int>> &dp)
{
    if(target == 0) return true;
    if(ind == 0) return (arr[0] == target);
    if(dp[ind][target] != -1) return dp[ind][target];
    bool notPick = isTargetInSqnc(arr, ind - 1, target, dp); 
    bool pick = false;
    if(target >= arr[ind])
            pick = isTargetInSqnc(arr, ind - 1, target - arr[ind], dp);
   
    return dp[ind][target] = (pick | notPick);
  
}

int main()
{
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    int n = arr.size();
    int target = 8;
    vector<vector<bool>> dp(n,vector<bool>(target+1, false)); 
    
    for (int i = 0; i < n; i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
    // tc - O(N*Target)
     for (int ind = 1; ind < n; ind++)
     {
        for (int tar = 1; tar < target+1; tar++)
        {
            
            bool notPick = dp[ind - 1][tar] ;
            bool pick = false;
            if(tar >= arr[ind])
                    pick = dp[ind - 1][ tar - arr[ind]];
        
            dp[ind][tar] = (pick | notPick);
        }
        
     }
     cout<<dp[n-1][target];
    

    return 0;
}