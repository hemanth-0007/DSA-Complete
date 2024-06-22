#include<bits/stdc++.h>
using namespace std;

vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    int n = nums.size();
    deque<int> dq;
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if(dq.front() == i - k) dq.pop_front();
        while(!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
        dq.push_back(i);
        if(i >= k-1) ans.push_back(nums[dq.front()]);
    }
    
    return ans;
}

int main()
{
    vector<int> nums = {1,3,-1,-3,5,3,6,7};
    int k = 3;
    vector<int>  ans = maxSlidingWindow(nums, k);
    for(auto num : ans) cout<<num<<" ";
    return 0;
}