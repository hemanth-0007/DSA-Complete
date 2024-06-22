#include <bits/stdc++.h>
using namespace std;

string longestCommonPrefix(vector<string> &strs)
{
    int n = strs.size();
    sort(strs.begin(), strs.end(), greater<string>());
    string first = strs[0], last = strs[n - 1];
    string ans = "";
    for (int i = 0; i < n; i++)
    {
        if (first[i] != last[i])
            return ans;
        ans += first[i];
    }
    return ans;
}

int main()
{
    vector<string> strs = {"flower", "flow", "flight"};
    // for (auto st : strs)
    //     cout << st << " ";
    // cout << endl;
    // sort(strs.begin(), strs.end());
    // for (auto st : strs)
    //     cout << st << " ";
    // cout << endl;
    cout<<longestCommonPrefix(strs);
    return 0;
}