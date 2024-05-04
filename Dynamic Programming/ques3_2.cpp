//maximun sum of the non-adjacent elemnts from  a
// subsequence in an array 
// memoizing the solution
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
cout<<maxAdjSum(n-1 , a, dp);
return 0;
}