// Give the minimum number of the required coins that are present infinitely in an array
#include<bits/stdc++.h>
using namespace std;

int minCoins(int ind , int target , vector<int> arr){
    
    if(ind == 0){
         if(target%arr[0] == 0 ) return (target/arr[0]);
         else return 1e9;
    }
    int notPick = minCoins(ind -1 ,target ,arr);
    int pick = 1e9;
    if(arr[ind] <= target) pick = 1 + minCoins(ind , target - arr[ind], arr);

    return min(pick , notPick);
}

int main()
{
    vector<int> arr = {1, 2, 3};
    int target = 8;
    int n = arr.size();
    cout<<minCoins(n-1,target, arr);
return 0;
}