#include <bits/stdc++.h>
using namespace std;

int helper(int ind, int sum, vector<int> &arr, int n, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (sum < arr[0])
            return arr[0];
        else
            return 0;
    }
    if (dp[ind][sum] != -1)
        return dp[ind][sum];
    int inc = -1e9, notInc = -1e9;
    if (sum < arr[ind])
    {
        inc = arr[ind] + helper(ind - 1, sum + arr[ind], arr, n, dp);
    }
    notInc = 0 + helper(ind - 1, sum, arr, n, dp);
    return dp[ind][sum] = max(inc, notInc);
}

int maxTotalReward(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    for (auto num : arr)
        sum += num;
    vector<vector<int>> dp(n, vector<int>(sum + 1, -1));
    sort(arr.begin(), arr.end(), greater<int>());
    return helper(n - 1, 0, arr, n, dp);
}

int maxTotalRewardSpaceOpti(vector<int> &arr)
{
    int n = arr.size();
    sort(arr.begin(), arr.end(), greater<int>());
    int sum = 0;
    for(auto num : arr) sum += num;
    sum = min(sum , 4000);
    vector<int> prev(sum + 1, 0), cur(sum + 1, 0);
    for (int j = 0; j <= sum; j++)
        if (j < arr[0])
            prev[j] = arr[0];
    
    // for(auto num : prev) cout<<num<<" ";
    // cout<<endl; 
    // for(auto num : cur) cout<<num<<" "; 
    // cout<<endl; 
    // cout<<endl; 

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            int inc = -1e9, notInc = -1e9;
            if (j < arr[i])
                inc = arr[i] + prev[j + arr[i]];
            notInc = prev[j];
            cur[j] = max(notInc, inc);
        }
        for(auto num : prev) cout<<num<<" ";
        cout<<endl; 
        for(auto num : cur) cout<<num<<" "; 
        cout<<endl; 
        cout<<endl; 
        prev = cur;
    }
    return prev[0];
}

int main()
{
    vector<int> arr = {1, 6, 4, 3, 2};
    // 6 4 3 2 1 
    // vector<int> arr  = {73,45,55,9};
    cout << maxTotalReward(arr) << endl;
    cout << maxTotalRewardSpaceOpti(arr) << endl;
    return 0;
}