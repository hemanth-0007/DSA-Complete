// KnapSack Problem maximizing the value of the stolen things
// Space Optimization using only one array 

#include<bits/stdc++.h>
using namespace std;

int knapSack(int ind , int W , vector<int> value, vector<int> weight){
    
    if(ind == 0){
        if(weight[0] <= W) return value[0];
        else return 0;
    }
    int notPick = knapSack(ind -1 , W , value , weight);
    int pick = -1e9;
    if(weight[ind] <= W) pick = value[ind] + knapSack(ind -1 , W - weight[ind], value , weight);

    return max(pick , notPick);
}

int main()
{
    vector<int> weight = {1, 2, 3};
    vector<int> value = {60,40,60};
    int n = weight.size();
    // total weight that can be placed the theifs bag
    int maxWeight = 6;
    vector<int> prev(maxWeight+1, 0);

    vector<vector<int>> dp(n , vector<int>(maxWeight + 1 , 0));

    for (int i = 0; i <= maxWeight; i++) if(weight[0] <= maxWeight) prev[i] = value[0];

    for (int ind = 1; ind < n; ind++)
    {
        for (int wt = maxWeight; wt >= 0; wt--)
        {   
            int notPick = prev[wt];
            int pick = -1e9;
            if(weight[ind] <= wt) pick = value[ind] + prev[ wt- weight[ind]];

           prev[wt] = max(pick , notPick);
        }
        
        
    }
    cout<<prev[maxWeight];

    
return 0;
}