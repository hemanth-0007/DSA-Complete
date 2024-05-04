// calculating the combination that sum up to the required target using only one element at a time from the

// follow up question can we divide the array into two equal sums 
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
    vector<int> arr = {10,20, 20 , 10, 11};
    int cnt = 0, n = arr.size();
    for (int i = 0; i < n; i++)
    {
        cnt += arr[i];
    }
     
    if((cnt%2) != 0){
        cout<<0;
        return 0;
    } 
    else cout<<isTargetInSqnc(arr,n-1, (cnt/2));
    
   

    return 0;
}