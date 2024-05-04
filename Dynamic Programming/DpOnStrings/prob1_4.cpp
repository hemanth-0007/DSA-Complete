// Longest subsequence in a string 
// Space Optimisation method
#include<bits/stdc++.h>
using namespace std;

int longSubSeq(int ind1 , int ind2 , string s1, string s2, 
vector<vector<int>> &dp){

    if(ind1 == 0 || ind2 == 0) return 0;

    if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
    if(s1[ind1-1] == s2[ind2-1])
        return dp[ind1][ind2] =  (1+longSubSeq(ind1-1, ind2-1, s1, s2, dp));

    return dp[ind1][ind2] = max(longSubSeq(ind1-1, ind2, s1, s2, dp), longSubSeq(ind1, ind2-1, s1, s2, dp));

}


int main()
{
    string s1 = "abcdef";
    string s2 = "abxdyf";
    int n = s1.size(), m = s2.size();
    // sc - O(2*m)
    vector<int> cur(m+1,0), prev(m+1,0);
    
    for (int i = 0; i <= n; i++) prev[0] = 0;
   
   
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1])
             cur[j] =  (1+prev[j-1]);
            else
             cur[j] = max(prev[j],cur[j-1]);
        }
        prev = cur;
    }
    cout<<prev[m];

return 0;
}