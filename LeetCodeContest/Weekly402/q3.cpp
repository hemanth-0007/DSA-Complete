#include <bits/stdc++.h>
using namespace std;
#define ll long long 

long long helper(int ind , vector<int> &uniqueNum,map<int,int>& mp, 
vector<ll> dp){
    if(ind == uniqueNum.size()) return 0;
    if(dp[ind] != -1) return dp[ind];
    ll notTake = 0 + helper(ind +1 , uniqueNum, mp, dp);
    int nextInd = ind + 1;
    ll take = 0;
    while(nextInd < uniqueNum.size() && uniqueNum[nextInd] - uniqueNum[ind] <= 2)
        nextInd++;
    take = ((1ll)*(uniqueNum[ind])*(mp[uniqueNum[ind]])) + helper(nextInd, uniqueNum, mp, dp);
    return dp[ind] = max(notTake, take);
}




long long maximumTotalDamage(vector<int> &arr)
{
    int n = arr.size();
    map<int,int> mp;
    vector<ll> dp(n+1, -1);
    vector<int> uniqueNum;
    for(auto num : arr) mp[num]++;
    for(auto it : mp){
        // cout<<it.first<<" "<<it.second<<endl;
        uniqueNum.push_back(it.first);
    }
    return helper(0, uniqueNum, mp, dp);
    
}

int main()
{
    vector<int> arr = {1, 1, 3, 4};
    cout << maximumTotalDamage(arr);

    return 0;
}