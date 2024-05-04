#include<bits/stdc++.h>
using namespace std;

 // implementing the merge sort using recursion 

// O( n*log(n) )
void merge(vector<int> &arr, int low, int mid , int high){
        int l = low;
        int r = mid+1;
        vector<int> temp;
        while(l <= mid && r <= high){
            if(arr[l] <= arr[r]){
                temp.push_back(arr[l]);
                l++;
            }
            else{
                temp.push_back(arr[r]);
                r++;

            }
        }

        while(l<= mid){
             temp.push_back(arr[l]);
                l++;
        }
        while(r<= high){
             temp.push_back(arr[r]);
                r++;
        }
        
        for (int i = low; i <= high; i++)
        {
            arr[i] = temp[i -low];
        }
        
        
}

 void mergeSort(vector<int> &arr, int low , int high){

    if(low >= high)
        return;
    int mid = (low+high)/2;
    mergeSort(arr,low, mid);
    mergeSort(arr,mid+1, high);
    merge(arr, low, mid , high);

 }

int main()
{
    vector<int> arr = {2,3,7,4,9};
    mergeSort(arr,0,4);
    for(auto num : arr){
        cout<<num<<" ";
    }
 
return 0;
}