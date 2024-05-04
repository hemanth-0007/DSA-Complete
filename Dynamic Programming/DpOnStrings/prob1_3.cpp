// Longest subsequence in a string 
// Tabulation method
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
    string s1 = "groot";
    string s2 = "brute";
    int n = s1.size(), m = s2.size();
    // modifying by shifting one index right
    vector<vector<int>> dp(n+1,vector<int>(m+1, -1));
    
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int i = 0; i <= m; i++) dp[0][i] = 0;
   
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1])
             dp[i][j] =  (1+dp[i-1][j-1]);
            else
             dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
        }
        
    }
 

return 0;
}