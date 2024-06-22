#include<bits/stdc++.h>
using namespace std;


void helper(int i , vector<int>& arr, int n ){
    if(i == 0) return;
    if(arr[i-1] > arr[i]){
        int j = i;
        // cout<<i <<" "<<arr[i]<<" "<<j<<" "<<arr[j]<<endl;
        while(j <= n-1 && arr[j-1] > arr[j]){
            swap(arr[j-1], arr[j]);
            j++;
        }
    }
    helper(i-1, arr, n);
}



void insertionSortRec(vector<int>& arr){
    int n = arr.size();
    helper(n-1, arr, n);
}


int main()
{
    vector<int> arr = {1,-4,3,5,2};
    insertionSortRec(arr);
    for(auto num : arr) cout<<num<<" ";

return 0;
}