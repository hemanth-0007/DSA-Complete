// Stock Problems 
//

#include<bits/stdc++.h>
using namespace std;
int main()
{
int minPrice = 1e9;
int maxProfit  = -1e9;
vector<int> price = {7,1,5,3,6,4};
// {5,4,3,2,1}
int n = price.size();
for (int i = 0; i < n; i++)
{
    minPrice = min(minPrice, price[i]);
    maxProfit = max(maxProfit, price[i]);
}
cout<<maxProfit<<endl;

return 0;
}