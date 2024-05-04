#include<bits/stdc++.h>
using namespace std;
string makeGood(string s) {
    int n = s.size();
    int prev_len, cur_len;
    do
    {
        // cout<<"Inside Do while"<<endl;
        prev_len = s.size();
        int i = 0;
        while(i < s.size()-1 && s.size() > 0){
            // cout<<"\tInside while "<<i<<endl;
            // cout<<s[i]<<" "<<s[i] - 32<<" "<<int(s[i+1])<<endl;
            // if(s.size() == 0) break;
            if(s[i] - 32 == s[i+1] || s[i] + 32 == s[i+1]){
                // cout<<"\t\tInside if"<<endl;
                s.erase(i , 2);
                // cout<<"\t\tThe size is : "<<s.size()<<endl;
                continue;
            }
            i++;
        }
        cur_len = s.size();
    } while (prev_len != cur_len && prev_len >= 0 && cur_len >= 0);
    return s;
}

string makeGoodOp(string s){
    stack<char> st;
    string res;
    for (int i = 0; i < s.size(); i++)
    {
        if(!st.empty()){
            char top = st.top();
            if(top + 32 == s[i] || top - 32 == s[i]){
                st.pop();
                continue;
            }
        }
        st.push(s[i]);      
    }
    while (!st.empty())
    {
        res += st.top();
        st.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}


string makeGoodOp2(string s){
    string res;
    for (int i = 0; i < s.size(); i++)
    {
        if(res.size() != 0){
            char top = res.back();
            if(top + 32 == s[i] || top - 32 == s[i]){
                res.pop_back();
                continue;
            }
        }
        res.push_back(s[i]);      
    }
    return res;
}

int main()
{
    // string s = "leEeetcode";
    // string s = "abBAcC";
    string s = "Pp"; 
    // string s = "s";
    // cout<<makeGood(s)<<endl;
    // cout<<makeGoodOp(s)<<endl;
    cout<<makeGoodOp2(s)<<endl;

     

return 0;
}