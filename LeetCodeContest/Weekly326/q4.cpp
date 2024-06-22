#include<bits/stdc++.h>
using namespace std;

 
int helper(int ind , bool isIncluded, vector<int>& nums, vector<vector<int>> & dp){
    if(ind == nums.size()){
        return 0;
    }
    if(dp[ind][isIncluded]  != -1) return dp[ind][isIncluded];
    //code
    int include = -1e9;
    if(!isIncluded){
        include = nums[ind] + helper(ind + 1, !isIncluded, nums, dp);
    }
    int notInclude = 0 + helper(ind + 1, !isIncluded, nums, dp);
    return dp[ind][isIncluded] = max(notInclude, include);
}

 
int maximumSumSubsequence(vector<int>& nums, vector<vector<int>>& queries) {
    int n = nums.size();
    int ans = 0;
    for(auto q : queries){
        nums[q[0]] = q[1];
        // for(auto num : nums)cout<<num<<" ";
        // cout<<endl;
        vector<vector<int>> dp(n+1,vector<int>(2, -1));
        int res = helper(0, false, nums, dp);
        cout<<res<<endl;    
        ans +=  res;
    }
    return ans;
}


int main()
{
   vector<int> nums = {3,5,9};
   vector<vector<int>> queries = {{1,-2},{0,-3}};
   cout<<maximumSumSubsequence(nums , queries);

return 0;
}