#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> prevSmaller(vector<int>& nums);
};


vector<int> Solution::prevSmaller(vector<int> &arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> pse(n,-1);
    for (int i = 0; i < n; i++)
    {
        while(!st.empty() && st.top() >= arr[i]) st.pop();
        if(!st.empty()) pse[i] = st.top();
        st.push(arr[i]);
    }
    return pse;
}



int main()
{

return 0;
}