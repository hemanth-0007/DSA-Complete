#include <bits/stdc++.h>
using namespace std;
string removeOuterParentheses(string s)
{
    stack<char> st;//O(n)
    string temp = "", ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            temp += s[i];
            st.push(s[i]);
        }
        if (s[i] == ')' && st.top() == '(')
        {
            temp += s[i];
            st.pop();
        }
        if (st.empty() && temp != "")
        {
            ans += temp.substr(1, temp.size() - 2);
            temp.clear();
        }
    }
    return ans;
}

string removeOuterParenthesesOp(string s)
{
    int cnt = 0;
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            if(cnt > 0) ans += s[i];
            cnt++;
        }
        if (s[i] == ')')
        {
            ans += s[i];
            cnt--;
        }
        if (cnt == 0 && ans != "")
        {
            ans.pop_back();
        }
    }
    return ans;
}
int main()
{
    string s = "(()())(())(()(()))";
    // string s = "(()(()))";
    cout << removeOuterParentheses(s)<<endl;
    cout << removeOuterParenthesesOp(s)<<endl;
    return 0;
}