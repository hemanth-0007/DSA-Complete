#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    stack<int> st;
    vector<int> nge(n, -1);

    for (int i = 2*n - 1; i >= 0; i--)
    {
        while(!st.empty() && arr[i%n] >= st.top()) st.pop();
        if(i < n){
            if(!st.empty()) nge[i] = st.top();
        }
        st.push(arr[i]);
    }
    for(auto num : nge ) cout<<num<<" ";
    return nge;   
}

int main()
{

return 0;
}