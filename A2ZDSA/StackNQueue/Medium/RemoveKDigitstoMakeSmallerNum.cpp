#include<bits/stdc++.h>
using namespace std;
string removeKdigits(string num, int k) {
    stack<char> st;
    for(auto digit : num){
        while(!st.empty() && k > 0 && st.top() > digit){
            st.pop();
            k--;
        }
        st.push(digit);
    }
    while(k > 0 && !st.empty()){
        k--;
        st.pop();
    }
    string res = "";
    while(!st.empty()){
        res += st.top();
        st.pop();
    }
    // cout<<res<<endl;
    while(!res.empty() && res[res.size() -1] == '0') res.pop_back();
    reverse(res.begin(), res.end());
    if(res.empty()) return "0";
    return res;
}
int main()
{
    string num = "100200";
    int k = 4;
    cout<<removeKdigits(num ,k);

return 0;
}