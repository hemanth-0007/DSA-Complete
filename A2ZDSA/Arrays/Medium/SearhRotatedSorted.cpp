#include <bits/stdc++.h>
using namespace std;

int search(vector<int> &arr, int target)
{
    int n = arr.size();
    int left = 0, right = n-1;
    // cout<<left<<" "<<right<<endl;
    while (left <= right)
    {
        int mid = (left + right)/2;
        // cout<<left<<" "<<mid<<" "<<right<<endl;
        if(arr[mid] == target) {
            return mid;
        }
        else if(arr[left] <= arr[mid]){ // we check if the left half is sorted 
            if(arr[left] <= target && target < arr[mid] ){
                right = mid -1;
            }
            else {
                left = mid + 1;
            }
        }
        else{
            if(arr[mid] < target && target <= arr[right]){
                left = mid +1;
            }
            else {
                right = mid -1;
            }
        }
    }
    return -1;
    
}


int binarySearch(vector<int> & arr, int target){
    int n = arr.size();
    int low = 0 , high= n-1;
    while (low<= high)
    {
        // int mid = (low + high)/2;
        int mid = low + (high - low)/2;
        if(arr[mid] == target) {
            return mid;
        }
        else if(arr[low] <= arr[mid]){
            if(arr[low] <= target && target < arr[mid]){
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }
        else{
            if(arr[mid] < target &&target <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid -1;
            }
        }   
        }
    return -1;
}


int main()
{
    vector<int> nums = {4,5,6,7,0,1,2}; 
    int target = 0;
    // vector<int> nums = {4,5,6,7,0,1,2};
    // int target = 3;
    cout<<search(nums, target)<<endl;
    cout<<binarySearch(nums, target);
    return 0;
}