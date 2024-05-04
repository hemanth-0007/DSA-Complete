// Stock Problems 
// 2 nd model that is buying and selling on different days untill the end of the array 
// for example we should buy and sell that particular stock before buying another 


#include<bits/stdc++.h>
using namespace std;

int getMaxProfit(int ind , int buy, vector<int> price, int n){

    //base condition
    if(ind == n) return 0;
    int profit = 0;
    if(buy == 1)
        profit = max( -price[ind] + getMaxProfit(ind+1, 0, price, n), 
                    getMaxProfit(ind+1,1,price,n)); 
  
    else
        profit = max( price[ind] + getMaxProfit(ind+1,1,price, n), 
                    getMaxProfit(ind+1,0,price, n) );
    

    return profit;

}






int main()
{
 
vector<int> price = {7,1,5,3,6,4};
int n = price.size();
cout<<getMaxProfit(0 , 1, price, n );

return 0;
}