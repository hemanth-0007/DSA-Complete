#include<bits/stdc++.h>
using namespace std;
int largestRectangleArea(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n , -1), right(n, n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
        if(!st.empty()) left[i] = st.top();
        st.push(i);
    }
    for(auto num : left) cout<<num<<" ";
    cout<<endl;
    st = stack<int>();
    for (int i = n - 1; i >= 0; i--)
    {
        while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
        if(!st.empty()) right[i] = st.top();
        st.push(i);
    }
    for(auto num : right) cout<<num<<" ";
    cout<<endl;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int range = (i - left[i] - 1) + (right[i] - i - 1) + 1;
        ans = max(ans, nums[i]*range);
    }
    
    return ans;
}
int main()
{
    vector<int> nums = {2,1,5,6,2,3};
    for(auto num : nums) cout<<num<<" ";
    cout<<endl;
    cout<<largestRectangleArea(nums);
return 0;
}