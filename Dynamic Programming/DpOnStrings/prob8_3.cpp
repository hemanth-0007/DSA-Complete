// Edit Distance Problem 
// convert string 1 to string 2 by 3 using methods minimum number of operations
// 1. add
// 2. delete 
// 3. replace ****
// Tabulation

#include<bits/stdc++.h>
using namespace std;

int editDistance(int i , int j , string s, string t, vector<vector<int>> &dp){
    // string 1 exhausts
    if(i == 0) return j;// j+1 insert operations
    if(j == 0) return i;// i+1 delete operations
    if(dp[i][j] != -1) return dp[i][j];
    if(s[i-1] == t[j-1]) return dp[i][j] = (editDistance(i-1,j-1,s,t, dp));// if equal no operations req.
    return dp[i][j] =  min( 1 + editDistance(i ,j-1 ,s ,t, dp), 
                        min(1 + editDistance(i-1, j , s, t, dp), 
                        1 + editDistance(i-1, j-1 , s, t, dp))); 

}


int main()
{
    string s = "bass" , t = "ass";
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n+1 ,vector<int>(m+1, -1));
     dp[0][0] = 0;
     for (int i = 1; i <=n; i++) dp[0][i] = i;
     for (int i = 1; i <=m; i++) dp[i][0] = i;

     for (int i = 1; i <=n; i++)
     {
        for (int j = 1; j <=m; j++)
        {
             if(s[i-1] == t[j-1]) 
                dp[i][j] = dp[i-1][j-1];
             else 
                dp[i][j] =  min( 1 + dp[i][j-1], min(1 + dp[i-1][j],1 + dp[i-1][j-1])); 
        }
        
        
     }
     
   cout<<dp[n][m];

    

return 0;
}