// distinct subsequences 
#include<bits/stdc++.h>
using namespace std;

int noOfDistSubSeq(int i, int j, string s, string t, vector<vector<int>> &dp){
    
    if(j<0) return 1;
    if(i<0) return 0;
    if(s[i] == t[j])
        return dp[i][j] = (noOfDistSubSeq(i-1,j-1,s,t,dp) + noOfDistSubSeq(i-1,j,s,t,dp));
    else
        return dp[i][j] = noOfDistSubSeq(i-1,j,s,t,dp);
    
}


int main()
{
    string s = "babgbag", t = "bag";
    //ans = 5 
    int n = s.size(), m = t.size();
    vector<vector<int>> dp(n, vector<int>(m , -1));
    // tc - no of states O(m*n) and sc - O(m+n)
    cout<<noOfDistSubSeq(n-1,m-1,s,t,dp);
    return 0;
}