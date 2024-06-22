#include<bits/stdc++.h>
using namespace std;
int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    vector<int> left(n, -1), right(n, n);
    stack<int> st;
    // next left smaller element
    for (int i = 0; i < n; i++)
    {
        while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
        if(!st.empty()) left[i] = st.top();
        st.push(i);
    }

    st = stack<int>();
    // next right smaller element
    for (int i = n - 1; i >= 0; i--)
    { 
        while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
        if(!st.empty()) right[i] = st.top();
        st.push(i);
    }
    
    long long ans = 0;
    for (int i = 0; i < n; i++)
        ans += static_cast<long long>((i - left[i])*(right[i] - i)*arr[i]);
    // for(auto num : left) cout<<num<<" ";
    // cout<<endl;
    // for(auto num : right) cout<<num<<" ";
    // cout<<endl;
    // cout<<endl;
    return ans;
}

int main()
{
    vector<int>  arr = {3,1,2,4};
    cout<<sumSubarrayMins(arr);

return 0;
}