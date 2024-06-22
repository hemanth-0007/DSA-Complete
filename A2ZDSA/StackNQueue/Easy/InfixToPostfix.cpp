#include <bits/stdc++.h>
using namespace std;

int getPre(char ch)
{

    if (isalpha(ch) || isdigit(ch))
        return 0;

    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

// true is left to right
// false is right to left
bool getAssociativity(char s, char t)
{
    if (s == '*' && t == '/' || s == '/' && t == '*')
        return true;
    if (s == '+' && t == '-' || s == '-' && t == '+')
        return true;
    if (s == '^' && t == '^')
        return false;
    else
        false;
}

bool isOperator(char s)
{
    return (!isdigit(s) && !isalpha(s));
}

string infixToPostfix(string s)
{
    int n = s.size();
    stack<char> st;

    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (isalpha(s[i]) || isdigit(s[i]))
            ans += s[i];

        if (s[i] == '(')
            st.push(s[i]);
        else if (s[i] == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }
            if (!st.empty())  st.pop();
        }
        else if (isOperator(s[i]))
        {
            if (!st.empty() && getPre(s[i]) < getPre(st.top()))
            {
                int curPre = getPre(s[i]);
                while (!st.empty() && curPre < getPre(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
            }
            if (!st.empty() && getPre(s[i]) == getPre(st.top()))
            {
                bool asso = getAssociativity(s[i], st.top());
                if (asso == true)
                {
                    ans += st.top();
                    st.pop();
                    st.push(s[i]);
                }
                else
                    st.push(s[i]);
            }
            else if (!st.empty() && getPre(s[i]) > getPre(st.top()))
            {
                st.push(s[i]);
            }
        }
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main()
{
    string str = "a+b*(c^d-e)^(f+g*h)-i";
    cout<<infixToPostfix(str);

    return 0;
}