
// Getting the number of subsets whose sum equals to k 
// Space Optimisation
// for the test case if 0 is included in the array

#include<bits/stdc++.h>
using namespace std;

int countSubsets(int ind , int target , vector<int> arr){
    
   
    if(ind == 0){
        if(target == 0 && arr[ind] == 0) return 2;
        if(target == 0 || arr[ind] == target) return 1;
        return 0;
    }  
    int notPick = countSubsets(ind-1, target, arr);
    int  pick = 0;
    if(target >= arr[ind])
        pick = countSubsets(ind-1, target- arr[ind], arr);
    
    
    return (pick + notPick);


}

int main()
{
    vector<int> arr = {0,0,1};
    int n = arr.size();
    int k = 1 ;
    cout<<countSubsets(n-1,k,arr);
    
    
return 0;
}