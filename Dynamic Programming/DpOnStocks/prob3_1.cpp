// Stock Problems 
// 3 rd model  similar to 2 nd model but of atmax 2 transactions
// we will be carrying a cap varaible to keep a track of no of transactions


#include<bits/stdc++.h>
using namespace std;

int getMaxProfit(int ind , int buy,int cap, vector<int> price, int n){

  if(cap == 0 || ind == n) return 0;
  
    int profit = 0;
    if(buy == 1)
        profit = max( -price[ind] + getMaxProfit(ind+1, 0,cap, price, n), 
                    getMaxProfit(ind+1,1,cap,price,n)); 
    else
        profit = max( price[ind] + getMaxProfit(ind+1,1,cap-1,price, n), 
                    getMaxProfit(ind+1,0,cap, price, n) );
    
    return profit;

}

int main()
{
 
vector<int> price = {1,2,4,8};
int n = price.size();
cout<<getMaxProfit(0 , 1 ,2 , price, n );

return 0;
}