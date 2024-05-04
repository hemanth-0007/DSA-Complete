// Stock Problems 
// 2 nd model that is buying and selling on different days untill the end of the array 
// for example we should buy and sell that particular stock before buying another 
// Space optimization

#include<bits/stdc++.h>
using namespace std;

int getMaxProfit(int ind , int buy, vector<int> price, int n,vector<vector<int>> &dp){

    //base condition
    if(ind == n) return 0;
    if(dp[ind][buy] != -1) return dp[ind][buy];
    int profit = 0;
    if(buy == 1)
        profit = max( -price[ind] + getMaxProfit(ind+1, 0, price, n, dp), 
                    getMaxProfit(ind+1,1,price,n, dp)); 
  
    else
        profit = max( price[ind] + getMaxProfit(ind+1,1,price, n, dp), 
                    getMaxProfit(ind+1,0,price, n, dp) );
    

    return dp[ind][buy] = profit;

}






int main()
{
 
vector<int> price = {7,1,5,3,6,4};
int n = price.size();
vector<vector<int>> dp(n+1, vector<int>(2,-1));
vector<int> prev(2, 0), cur(2,0);

prev[0] = 0;prev[1] = 0;

for (int ind = n-1; ind >= 0; ind--)
{
    for (int buy = 0; buy < 2; buy++)
    {
        int profit = 0;
        if(buy == 1)
             profit = max( -price[ind] + prev[0], prev[1]); 
  
        else
            profit = max( price[ind] + prev[1],prev[0]);
    

        cur[buy] = profit;
    }
    prev = cur;
}
cout<<prev[1];
 

return 0;
}