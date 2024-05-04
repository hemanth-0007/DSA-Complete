//maximun sum of the non-adjacent elemnts from  a
// subsequence in an array 
// tabulating the solution 
#include<bits/stdc++.h>
using namespace std;
int maxAdjSum(int ind , vector<int> a,vector<int> &dp){
    //base cases 
    if(ind == 0){
        return dp[0] = a[0];
    }
    // for out off bound return 0
    if(ind < 0){
        return 0;
    }
    if(dp[ind] != -1){
        return dp[ind];
    }

    int pick = a[ind] + maxAdjSum(ind -2 , a, dp);
    int notPick = 0 + maxAdjSum(ind -1, a, dp);

    return dp[ind] = max(pick , notPick);

}



int main()
{
vector<int> a = {2,1,4, 9};
int n = a.size();
vector<int> dp(n, -1);

dp[0] = a[0];

// TC - O(N) and sc - O(n)
 for (int i = 1; i < n; i++)
 {
    int pick = a[i] ;
    // to exlude the edge case of negative index of the array dp
    if(i > 1)
        pick += dp[i-2];

    int notPick = dp[i-1];
    dp[i] = max(pick , notPick);
 }
 cout<<dp[n-1];
 
 
return 0;
}