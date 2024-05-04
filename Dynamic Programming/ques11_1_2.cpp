// calculating the combinatiosn that sum up to the required target using only one element at a time from the
// array
//memoizing technique


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
    vector<vector<int>> dp(n,vector<int>(target+1, -1) ); 
    cout<<isTargetInSqnc(arr,n-1, target, dp);

    return 0;
}