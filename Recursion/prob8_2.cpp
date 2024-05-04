#include<bits/stdc++.h>
using namespace std;

 // implementing the merge sort using recursion modified interview question
// O( n*log(n) )
void merge(vector<int> &arr, int low, int mid , int high, map<int,int>& merged_count){
        int l = low;
        int r = mid+1;
        vector<int> temp;
        int flag = 0;
        while(l <= mid && r <= high){
            if(arr[l] <= arr[r]){
                temp.push_back(arr[l]);
                l++;
                flag = 1;
            }
            else{
                temp.push_back(arr[r]);
                // signifies that we only increment the counter only if the element from right subarray is merged before atleast one element from the left subarray is merged 
                //that is the 
                if(flag == 0)  merged_count[arr[r]]++;
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

 void mergeSort(vector<int> &arr, int low , int high,map<int,int>& merged_count){

    if(low >= high)
        return;
    int mid = (low+high)/2;
    mergeSort(arr,low, mid,merged_count);
    mergeSort(arr,mid+1, high,merged_count);
    merge(arr, low, mid , high,merged_count);

 }

int main()
{
    vector<int> arr = {2,3,1};
    int n = arr.size();
    map<int,int> merged_count;
    for(auto num : arr){
        merged_count[num] = 0;
    }
    mergeSort(arr,0,n-1, merged_count);
    for(auto num : arr){
        cout<<num<<" ";
    }
    cout<<endl;
    for(auto it : merged_count){
        cout<<it.first<<"--"<<it.second<<endl;
    }
 
return 0;
}