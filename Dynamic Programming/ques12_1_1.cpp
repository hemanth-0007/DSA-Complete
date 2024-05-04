
// Getting the number of subsets whose sum equals to k 
// by resursion


#include<bits/stdc++.h>
using namespace std;

int countSubsets(int ind , int target , vector<int> arr){
    
    if(target == 0) return 1;
    if(ind == 0) return (arr[0] == target);

    int notPick = countSubsets(ind-1, target, arr);
    int  pick = 0;
    if(target >= arr[ind])
        pick = countSubsets(ind-1, target- arr[ind], arr);
    
    
    return pick + notPick;


}

int main()
{
    vector<int> arr = {2,1,1,3};
    int n = arr.size();
    int target = 5 ;
    cout<<countSubsets(n-1, target,arr);

return 0;
}