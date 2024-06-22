#include <bits/stdc++.h>
using namespace std;

#include <vector>
#include <algorithm>
#include <climits>

int helper(int ind, int last, vector<int> &arr, int k, 
 vector<vector<vector<int>>> &dp) {
    if (ind == arr.size())  return 0;
    
    if (dp[ind][last + 1][k] != -1) return dp[ind][last + 1][k];

    int maxi = 0;

    if (last == -1 || arr[last] == arr[ind]) {
        maxi = max(maxi , 1 + helper(ind + 1, ind, arr, k, dp));
    } 
    else if (arr[last] != arr[ind]) {
        if(k > 0)
            maxi = max(maxi , 1 + helper(ind + 1, ind, arr, k - 1, dp));
    }
     
    maxi = max(maxi , 0 + helper(ind + 1, last, arr, k, dp));
    return dp[ind][last + 1][k] = maxi;
}

int maximumLength(vector<int> &nums, int k) {
    int n = nums.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n+2, vector<int>(min(n , 25) + 1, -1)));
    return helper(0, -1, nums, k, dp);
}

int main()
{
    // vector<int> nums = {1, 2, 1, 1, 3};
    // int k = 2;

    // vector<int> nums = {29,30,30};
    // int k = 0;
    vector<int> nums = {1,11,6,39};
    int k = 4;

    cout << maximumLength(nums, k) << endl;
    return 0;
}