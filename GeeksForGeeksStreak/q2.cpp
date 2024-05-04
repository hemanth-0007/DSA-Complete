#include<bits/stdc++.h>
using namespace std;


int maxStocks(vector<int>& price, int money){
    // we can buy atmost i +1 stocks on the i th day with price as price[i]
    // return maximum stocks one can buy with the given money
    int n = price.size(), count = 0;
    vector<pair<int,int>> sortedPrices;
    for(int i = 0 ; i < n ; i++) sortedPrices.push_back({price[i], i+1});
    sort(sortedPrices.begin(), sortedPrices.end());
    for(auto i : sortedPrices){
        int noOfStocksPerDay = min(money/i.first,i.second);
        count += noOfStocksPerDay;
        money -= noOfStocksPerDay*i.first;
    }
    return count;
}





int main()
{

return 0;
}