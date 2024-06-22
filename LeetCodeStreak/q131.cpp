#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s)
{
    int n = s.size();
    for (int i = 0; i <= n / 2; i++)
        if (s[i] != s[n - i - 1])
            return false;

    return true;
}

void helper(int ind, string s, vector<vector<string>> &ans, vector<string> &ds)
{
    if (ind == s.size())
    {
        ans.push_back(ds);
        // ds.clear();
        return;
    }
    // code
    for (int i = 1; i <= s.size() - ind; i++)
    {
        string temp = s.substr(ind, i);
        // cout<<"temp str: "<<temp<<endl;
        if (isPalindrome(temp))
        {
            // cout<<temp<<" "<<ind<<" "<<i<<endl;
            ds.push_back(temp);
            helper(ind + i, s, ans, ds);
            ds.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    vector<vector<string>> ans;
    vector<string> ds;
    int n = s.size();

    vector<vector<bool>> dp(n, vector<bool>(n, false));

    // dp[i][j] --> s(i , j) is a palindrome
    // get the one letter as true
    for (int i = 0; i < n; i++)
        dp[i][i] = true;

    for (int length = 2; length <= n; ++length)
    {
        for (int i = 0; i < n - length; ++i)
        {
            int j = i + length - 1;
            if (s[i] == s[j] && (length == 2 || dp[i + 1][j - 1]))
            {
                dp[i][j] = true;
            }
        }
    }

    helper(0, s, ans, ds);
    return ans;
}

int main()
{
    // string s = "temp";
    // for (int i = 1; i <= s.size(); i++)
    // {
    //     cout<<s.substr(0, i)<<endl;
    // }
    string s = "aaab";
    // cout<<s.substr(0, 1);
    vector<vector<string>> ans = partition(s);
    for (auto v : ans)
    {
        for (auto st : v)
            cout << st << " ";
        cout << endl;
    }

    return 0;
}