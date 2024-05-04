// KnapSack Problem maximizing the value of the stolen things
// by recursion

#include<bits/stdc++.h>
using namespace std;

int knapSack(int ind , int W , vector<int> value, vector<int> weight){
    
    if(ind == 0){
        if(weight[0] <= W) return value[0];
        else return 0;
    }
    int notPick = knapSack(ind -1 , W , value , weight);
    int pick = -1e9;
    if(weight[ind] <= W)
     pick = value[ind] + knapSack(ind -1 , W - weight[ind], value , weight);

    return max(pick , notPick);
}

int main()
{
    vector<int> weight = {3,2,5};
    vector<int> value = {60,40,60};
    int W = 6;// total weight that can be placed the theifs bag
    int n = weight.size();
    cout<<knapSack(n-1 , W, value , weight);
    
    // wanna do memoization then we can do in the same format in the prev count problem
    
return 0;
}