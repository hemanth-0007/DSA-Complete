// distinct subsequences 
// tabulation technique
#include<bits/stdc++.h>
using namespace std;

int noOfDistSubSeq(int i, int j, string s, string t, vector<vector<int>> &dp){
    
    if(j==0) return 1;
    if(i==0) return 0;
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i-1] == t[j-1])
        return dp[i][j] = (noOfDistSubSeq(i-1,j-1,s,t,dp) + noOfDistSubSeq(i-1,j,s,t,dp));
    else
        return dp[i][j] = noOfDistSubSeq(i-1,j,s,t,dp);
    
}


int main()
{
    string s = "babgbag", t = "bag";
    //ans = 5 
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1 , -1));
    
    // Base Cases
    for(int i=1; i<=m ; i++) dp[0][i] = 0;
    for(int i=0; i<=n ; i++) dp[i][0] = 1;

    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=m; j++)
        {
             if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1]+ dp[i-1][j];
             else
                dp[i][j] = dp[i-1][j];
        }
        
    }
    cout<<dp[n][m];
     
    return 0;
}