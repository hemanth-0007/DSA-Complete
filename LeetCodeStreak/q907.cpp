#include<bits/stdc++.h>
using namespace std;


using ll = long long;
const int MOD = 1e9 + 7;

 
int sumSubarrayMins(vector<int>& nums) {
        int length = nums.size();
        vector<int> left(length, -1);
        vector<int> right(length, length);
        stack<int> stk;

        for (int i = 0; i < length; ++i) {
            while (!stk.empty() && nums[stk.top()] >= nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }

        stk = stack<int>();

        for (int i = length - 1; i >= 0; --i) {
            while (!stk.empty() && nums[stk.top()] > nums[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        for(auto num : left) cout<<num<<" ";
        cout<<endl;
        for(auto num : right) cout<<num<<" ";
        cout<<endl;

        ll sum = 0;

        for (int i = 0; i < length; ++i) {
            cout<<i<<" "<<static_cast<ll>(i - left[i]) * (right[i] - i)<<endl;
            sum += static_cast<ll>(i - left[i]) * (right[i] - i) * nums[i] % MOD;
            sum %= MOD;
        }

        return sum;
}
 

int subarraysMinsSum(vector<int>& nums){
    int n = nums.size();
    vector<int> left(n, -1);
    vector<int> right(n, n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
        if(!st.empty()) left[i]= st.top();
        st.push(i);
    }
    st = stack<int>();
    for (int i = n-1; i >= 0; --i)
    {
        while(!st.empty() && nums[st.top()] > nums[i]) st.pop();
        if(!st.empty()) right[i]= st.top();
        st.push(i);
    }
    ll ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += static_cast<ll>(i -left[i])*(right[i]-i)*nums[i] %MOD;
        ans %= MOD;
    }
    
    return ans;

    
}

int main()
{
    // vector<int> v = {3,1,2,4};
    vector<int> v = {11,81,94,43,3};
    cout<<sumSubarrayMins(v)<<endl;
    cout<<subarraysMinsSum(v);
return 0;
}