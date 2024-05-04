// Stock Problems 
// with some cool down of the stock 
//once you have sold u cannot buy

#include<bits/stdc++.h>
using namespace std;

int getMaxProfit(int ind , int buy, vector<int> price, int n){

//base condition
    if(ind >= n) return 0;
    int profit = 0;
    if(buy == 1)
        profit = max( -price[ind] + getMaxProfit(ind+1, 0, price, n), 
                    getMaxProfit(ind+1,1,price,n)); 
  
    else
        profit = max( price[ind] + getMaxProfit(ind+2,1,price, n), 
                    getMaxProfit(ind+1,0,price, n) );
    

    return profit;

}

int main()
{
 
vector<int> price = {4,9,0,4,10};
int n = price.size();
cout<<getMaxProfit(0 , 1, price, n );

return 0;
}