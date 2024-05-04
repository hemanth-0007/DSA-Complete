// distinct subsequences 
// Space optimization 
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
    vector<int> cur(m+1,0), prev(m+1,0);
    
    
  
    prev[0] = cur[0] = 1;

    for (int i = 1; i <=n; i++)
    {
        for (int j = 1; j <=m; j++)
        {
             if(s[i-1] == t[j-1])
                cur[j] = prev[j-1]+ prev[j];
             else
                cur[j] = prev[j];
        }
        prev = cur;
    }
    cout<<prev[m];
     
    return 0;
}