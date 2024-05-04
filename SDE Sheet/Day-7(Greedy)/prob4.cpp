// To find coin denominations
#include<bits/stdc++.h>
using namespace std;

vector<int> minNoCoins(vector<int> &coins, int V){
    int n = coins.size();
    int cnt = 0;
    vector<int> ans;
    for (int i = n-1; i >=0 ; i--)
    {
        while (V >= coins[i])
        {
            V -= coins[i];
            ans.push_back(coins[i]);
        }
    }
    return ans;
    
}


int main()
{
    vector<int> coins = {1,2,5,10,20,50,100,500,1000};
    int V = 9121, cnt = 0;
    vector<int> ans = minNoCoins(coins,V);
    for(auto num : ans){
        cnt++;
        cout<<num<<" ";
    }
    cout<<"\n"<<cnt;
return 0;
}