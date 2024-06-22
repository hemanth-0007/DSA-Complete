#include <bits/stdc++.h>
using namespace std;

int maxDepth(string s)
{
    int n = s.size();
    int cnt = 0, maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
            cnt++;
        else if (s[i] == ')')
            cnt--;
        maxi = max(maxi, cnt);
    }
    return maxi;
}

int main()
{
    string s = "(((2)))";
    string t = "((3))(((7)))";

    return 0;
}