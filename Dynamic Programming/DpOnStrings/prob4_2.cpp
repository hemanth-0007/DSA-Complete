//  ques is that the minimum number of insertions to make to make the given string a palindrome
//  the answer will be (total length of string - Longest palindromic subsequence)
 // Longest palindromic subsequence in a string 
#include<bits/stdc++.h>
using namespace std;

 string printLongSubSeq(int n,int m,string s1,string s2,vector<vector<int>> &dp)
{
    
    // we just backtrack from n, m to i<0 or j <0 to get the subsequence
    int length = dp[n][m];
    int index = length - 1;
    string ans = "";
    for (int i = 0; i < length; i++)
       ans += "$";
    
    int i = n , j = m;
    while (i > 0 && j >0)
    {
        if(s1[i-1] == s2[j-1]){
            ans[index] = s1[i-1];
            index--;
            i--; j--;
        }
        else{
            if(dp[i-1][j] > dp[i][j-1]){
                i--;
            }
            else{
                j--;
            }
        }
    }
    return ans;
}


int main()
{
    string s1 = "bbabcbcab";
    string s2(s1);
    reverse(s2.begin(), s2.end());
    int n = s1.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1, -1));
    
     
   
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int i = 0; i <= n; i++) dp[0][i] = 0;
   
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if(s1[i-1] == s2[j-1])
                dp[i][j] =  (1+dp[i-1][j-1]);
            else
                dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
        }
        
    }
    cout<<s1.size() - dp[n][n];
 
return 0;
}