#include<bits/stdc++.h>
using namespace std;

vector<int> nextPermutation(vector<int>& arr){
    int n = arr.size();
    int breakInd = -1;
    for (int i = n - 1; i > 0; i--)
    {
        if(arr[i-1] < arr[i]){
            breakInd = i-1;
            break;
        }
    }
    if(breakInd == -1){
        reverse(arr.begin() , arr.end());
        return arr;
    }
    for (int i = n - 1; i > breakInd; i--)
    {
        if(arr[i] > arr[breakInd]){
            swap(arr[i], arr[breakInd]);
            break;
        }
    }
    
    reverse(arr.begin() + breakInd+1, arr.end());
    return arr;
}



int main()
{
    // vector<int> arr = {1,3,2};
    vector<int> arr = {2,1,5,4,3,0,0};
    vector<int> ans = nextPermutation(arr);
    for(auto num : ans) cout<<num<<" ";

return 0;
}