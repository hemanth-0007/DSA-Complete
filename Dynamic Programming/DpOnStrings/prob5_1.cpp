// minimum number of insertions or deletions that can be made to 
// convert a string s1 to s2

#include<bits/stdc++.h>
using namespace std;

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
    string s1 = "abcde", s2 = "anc";
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1 , vector<int>(m+1, -1));
    int lenCommon = longSubSeq(n, m, s1, s2, dp);
    int deletions = n - lenCommon;
    int insertions = m - lenCommon;
    cout<<deletions + insertions;
    

return 0;
}