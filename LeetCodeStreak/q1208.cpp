#include <bits/stdc++.h>
using namespace std;
int equalSubstring(string s, string t, int maxCost)
{
    int n = s.size();
    int maxLen = 0, cost = 0;
    int j = 0 , i = 0;
    while(j < n && i < n){
        int curCost = abs(s[j] - t[j]);
        cost += curCost;
        while(i < n && i < j && cost > maxCost){
            cost -= abs(s[i] - t[i]);
            i++;
        }
        if(cost <= maxCost) maxLen = max(maxLen, j - i +1);
        j++;
    }
    return maxLen;
}
int main()
{
    string s = "abcd";
    string t = "bcdf";
    int maxCost = 3;
    cout << equalSubstring(s, t, maxCost);

    return 0;
}