// calculating the combinatiosn that sum up to the required target using only one element at a time from the
// array

#include <bits/stdc++.h>
using namespace std;

bool isTargetInSqnc(vector<int> arr, int ind, int t)
{
    if(t == 0) return true;
    if(ind == 0) return (arr[0] == t);
    bool notPick = isTargetInSqnc(arr, ind - 1, t ); 
    bool pick = false;
    if(t >= arr[ind])
            pick = isTargetInSqnc(arr, ind - 1, t - arr[ind]);
   
    return (pick ||notPick);
  
}

int main()
{
    vector<int> arr = {10, 1, 2, 7, 6, 1, 5};
    int n = arr.size();
    int target = 8;
    cout<<isTargetInSqnc(arr,n-1, target);

    return 0;
}