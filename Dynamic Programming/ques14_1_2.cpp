// Give the minimum number of the required coins that are present infinitely in an array
// tabulation method
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
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));

    for (int i = 0; i <= target; i++){
              if(i%arr[0] == 0 )
                dp[0][i] = (i/arr[0]);
              else dp[0][i] = 1e9;
    }
       

  
    for (int ind = 1; ind < n; ind++)
    {
        for (int tr = 0; tr < target + 1; tr++)
        {
                int notPick = dp[ind -1][tr];
                int pick = 1e9;
                if(arr[ind] <= tr ) pick = 1 + dp[ind][tr- arr[ind]];

                dp[ind][tr] = min(pick , notPick);
        }
        
        
    }
    cout<<dp[n-1][target];
    
    


return 0;
}