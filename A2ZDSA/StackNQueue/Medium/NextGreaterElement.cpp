#include<bits/stdc++.h>
using namespace std;
vector<int> nextGreaterElement(vector<int>& arrS, vector<int>& arr) {
    // nums1 is subset of nums2
    int n = arrS.size();
    vector<int> ans(n);
    int m = arr.size();
    vector<int> nge(m, -1);
    stack<int> st;

    for (int i = m - 1; i >= 0; i--)
    {
        while(!st.empty() && arr[i] >= st.top()) st.pop();
        if(st.empty()){
            st.push(arr[i]);
        }
        else{
            nge[i] = st.top();
            st.push(arr[i]);
        }
    }

    unordered_map<int,int> mp;
    for (int i = 0; i < m; i++) mp[arr[i]] = i;
    for (int i = 0; i < n; i++)
        ans[i] = nge[mp[arrS[i]]];
    
    // for(auto num : nge ) cout<<num<<" ";
    return ans;   
}


int main()
{
    vector<int> arr = {73,74,75,71,69,72,76,73};
    vector<int> arrS = {313, 4321};
    vector<int> res = nextGreaterElement(arrS,arr);

return 0;
}