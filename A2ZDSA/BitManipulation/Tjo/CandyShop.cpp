// Jack loves candles, and he goes to the market to buy some. There are K
//  different flavors of candles available in the market, and he wants to buy candles of all flavors.

// Also, there are N
//  types of candy combos available in the market. Each candy combo having some cost C
//  contains candles of one or more flavors. Help Jack to buy candy combos in such a way that he will have all the flavors at the end and will have to incur the minimum cost in doing so.

// You are given −
// 1.
//  An Integer array Cost[
//  ]
//  having the cost of all the candy combos available in the market.

// 2.
//  An integer K
//  denoting the number of different candy flavors available in the market.

// 3.
//  An integer N
//  denoting the different types of candy combos available in the market.

// 4.
//  An array of N
//  binary strings denoting the availability of various candy flavors in a candy combo. In each string, denoting a single combo, if the ith
//  character is 1
//  that means it contains the ith
//  flavor of candy otherwise not.

// Your task is to return the minimum cost required for buying combos such that Jack will have all the flavors of candies in the end.

// Note:
//  If you can't get all the K flavors at the end, you need to return −1
// .

#include<bits/stdc++.h>
using namespace std;

//  0<k<=31

int helper(int ind, vector<int>& mask, vector<int>& cost, vector<string>&combo , int k ){
    if(ind == cost.size()){
        bool isAllFlavoured = true;
        for (int i = 0; i < k; i++)
        {
            if(mask[i] == 0){
                isAllFlavoured = false;
                break;
            }
        }
        if(isAllFlavoured) return 0;
        else return 1e8;
    }

    // code 
    // modify mask
    for (int i = 0; i < k; i++)
        if(combo[ind][i] == '1') mask[i]++;
    
    int include = cost[ind] + helper(ind + 1, mask, cost, combo, k);
    
    for (int i = 0; i < k; i++)
        if(combo[ind][i] == '1') mask[i]--;

    int notInclude = 0 + helper(ind + 1, mask , cost, combo, k);
    return min(include , notInclude);
}




int candyShop(vector<int>& cost, vector<string>&combo , int k ){
    int n = cost.size();
    vector<int> mask(k , 0);
    return helper(0 , mask, cost, combo, k);
}


int main()
{
    // int k = 4;
    // vector<string> combo =  {"1010" ,"0100","0001","1111","1011"};
    // vector<int> cost =  {5 ,5 ,5 ,10 ,2};
    // cout<<candyShop(cost, combo, k);


    int n,k ;
    cin>>n>>k;
    vector<string> combo(n);
    for (int i = 0; i < n; i++)
    {
        cin>>combo[i];
    }
    vector<int> cost(n);
    for (int i = 0; i < n; i++)
    {
        cin>>cost[i];
    }
    
    cout<<candyShop(cost, combo, k);

return 0;
}