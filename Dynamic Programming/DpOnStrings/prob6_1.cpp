// shortest common super sequence that can be formed from two strings 
// eg "groot" and "brute" ==> "bgrooute"
#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

string printSmallestSuperSeq(int n,int m,string s1,string s2,vector<vector<int>> &dp)
{
    
    // we just backtrack from n, m to i<0 or j <0 to get the subsequence
    int length = n + m - dp[n][m];
    
    string ans = "";
     
    
    int i = n , j = m;
    while (i > 0 && j >0)
    {
        if(s1[i-1] == s2[j-1]){
            ans += s1[i-1];
           
            i--; j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                ans += s1[i-1];
                i--;
            }
            else{
                ans += s2[j-1];
                j--;
            }
        }
    }
    while (i>0)
    {
        ans+=s1[i-1];
        i--;
    }
    while (j>0)
    {
        ans+=s2[j-1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    
    
    return ans;
}

int main()
{
    string s1 = "brute", s2 = "groot";
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1 , vector<int>(m+1, -1));
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
    cout<<printSmallestSuperSeq(n,m,s1,s2,dp);

return 0;
}