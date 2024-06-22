#include <bits/stdc++.h>
using namespace std;
void helper(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
    if (ind == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    ds.push_back(nums[ind]);
    helper(ind + 1, nums, ds, ans);
    ds.pop_back();
    helper(ind + 1, nums, ds, ans);
}
vector<vector<int>> subsets(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    helper(0, nums, ds, ans);
    return ans;
}



 vector<vector<int>> subsetsOp(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++) {
            vector<int> subset;
            // this loop will run for each bit of i from right to left to check if the bit is set or not'
            // here bits represent the index of the element in the array
            for (int j = 0; j < n; j++) {
                if ((i & (1 << j)) > 0) {
                    subset.push_back(nums[j]);
                }
            }
            result.push_back(subset);
        }
        return result;
}
int main()
{
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> res = subsets(nums);
    // for (auto it : res)
    // {
    //     for (auto el : it)
    //     {
    //         cout << el << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < 3; i++)
    {
        cout<<(1 << i) << endl;
    }
    

    return 0;
}