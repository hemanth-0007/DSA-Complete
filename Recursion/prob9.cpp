#include<bits/stdc++.h>
using namespace std;

 // implementing the quick Sort using recursion (time complexity of O(N*log(n)))

 int partition(vector<int> &arr ,int low , int high){

    int l = low;
    int r = high;
    int pivot = arr[low];
    while (l<r) 
    {
        while( arr[l] <= pivot && l <= high -1){
            l++;
        }
        while( arr[r] > pivot && r >= low + 1 ){
            r--;
        }
        while (l < r)
        {
            swap(arr[l], arr[r]);
        }
        
         
    }
    swap(arr[low], arr[r]);
    return r;
    
 }

 void quickSort(vector<int> &arr, int low , int high){

    if(low < high){
        int pIndex = partition(arr, low, high);
        quickSort(arr,low, pIndex-1);
        quickSort(arr,pIndex+1, high);
    }
   
 }

int main()
{
    vector<int> arr = {90,3,3,7,4,3,4,9};
    quickSort(arr,0,4);
    for(auto num : arr){
        cout<<num<<" ";
    }
 
return 0;
}