#include <bits/stdc++.h>
using namespace std;

bool isBeautiful(vector<int> &ds, int k)
{
    int n = ds.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n; j++)
        {
            if (abs(ds[i] - ds[j]) == k)
                return false;
        }
    }
    return true;
}

int helper(int ind, vector<int> &nums, int k, unordered_map<int,int>& mp)
{
    if (ind == nums.size()) return 1;

    // code
    int include = 0;
    // catch in this problem is this the abs diff is k then there must be someone with +k or -k
    if(!mp[nums[ind] - k] && !mp[nums[ind] + k]){
        mp[nums[ind]]++;
        include = helper(ind +1, nums, k ,mp);
        mp[nums[ind]]--;
    }
    int notInclude =  helper(ind + 1, nums, k, mp);
    return include + notInclude;
}

int beautifulSubsets(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_map<int,int> mp;
    return helper(0, nums, k, mp) -1;
}

int main()
{
    vector<int> nums = {2,4, 6};
    int k = 2;
    // vector<int> nums = {1};
    // int k = 1;

    cout<<beautifulSubsets(nums, k);

    return 0;
}