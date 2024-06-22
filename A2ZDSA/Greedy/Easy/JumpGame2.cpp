#include <bits/stdc++.h>
using namespace std;

int helper(int ind, int n, vector<int> &nums, vector<int> &dp)
{
    if (ind == n - 1)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int res = 1e9;
    for (int i = ind + 1; i < n && i <= ind + nums[ind]; i++)
    {
        res = min(res, 1 + helper(i, n, nums, dp));
    }
    return dp[ind] = res;
}

int jump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    return helper(0, n, nums, dp);
}

int jumpOp(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 1; i < n; i++)
        nums[i] = max(nums[i - 1], nums[i] + i);

    int ind = 0, jumps = 0;
    while (ind < n - 1)
    {
        ind = nums[ind];
        jumps++;
    }
    return jumps;
}

int main()
{
    vector<int> nums = {2, 3, 1, 1, 4};
    cout << jump(nums) << endl;
    cout << jumpOp(nums) << endl;

    return 0;
}