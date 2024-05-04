// calculating the combinatiosn that sum up to the required target using only one element at a time from the
// array
// Tabulation technique --> Follow Up question
// we want that id it is possible to partition the array so the we can have the
// least absolute difference between them


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
int sumOf(vector<int> &arr){
    int cnt = 0;
    for (int i = 0; i < arr.size(); i++) cnt += arr[i];
    return cnt;
}


int main()
{
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    int n = arr.size();
    int target = sumOf(arr);
    int mini = 1e9;
    vector<vector<bool>> dp(n,vector<bool>(target+1, false)); 
    
    for (int i = 0; i < n; i++) dp[i][0] = true;
    dp[0][arr[0]] = true;
   
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
     
     for (int i = 0; i < (target + 1); i++)
     {
        if(dp[n-1][i] == true)
        mini = min(mini , abs(2*i - target));
     }
     cout<<mini;
    

    return 0;
}