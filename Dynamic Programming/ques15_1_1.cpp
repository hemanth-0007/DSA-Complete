// assign signs to get the sum as the target 
// similar to the target sum problem where u just asign the signs to the elements 
// (+, -)
#include<bits/stdc++.h>
using namespace std;

int countSubsets(int ind , int target , vector<int> arr){
    
    if(target == 0) return 1;
    if(ind == 0) return (arr[0] == target);


    int negSign = 0, posSign = 0;
    if(target >= arr[ind])
    int posSign = countSubsets(ind-1, target - arr[ind] , arr);
        negSign = countSubsets(ind-1, target- arr[ind], arr);
    
    
    return posSign + negSign;


}

int main()
{
    vector<int> arr = {2,1,1,3};
    int n = arr.size();
    int target = 5 ;
    cout<<countSubsets(n-1, target,arr);

return 0;
}