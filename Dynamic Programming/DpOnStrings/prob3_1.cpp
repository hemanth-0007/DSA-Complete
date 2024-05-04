 // Longest common substring in a string 
 
#include<bits/stdc++.h>
using namespace std;

 


int main()
{
    string s1 = "abcdef";
    string s2 = "xyabcd";
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1,vector<int>(m+1, -1));
    int ans = 0 ;
    pair<int,int> pr;
   
    for (int i = 0; i <= n; i++) dp[i][0] = 0;
    for (int i = 0; i <= m; i++) dp[0][i] = 0;
   
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(s1[i-1] == s2[j-1]){
                dp[i][j] =  (1+dp[i-1][j-1]);
                 
                if(dp[i][j] > ans){
                    ans = dp[i][j];
                    pr.first = i; pr.second = j;
                }
            }
            
            else
             dp[i][j] = 0;
        }
        
    }

    int len = ans;
    int ind = ans-1;
    string res ="";
    for (int i = 0; i < len; i++) res += "$";
    int x = pr.first, y = pr.second;
    
    while(dp[x][y] > 0){
        res[ind] = s1[x-1];
        ind--;x--;y--;
    }
    cout<<res;



return 0;
}