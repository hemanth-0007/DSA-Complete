// Getting the Number of inversions in an array 
//Optimal Version that is O(N*logN) merge sort
#include<bits/stdc++.h>
using namespace std;
 
int merge(vector<int> &nums, int low, int mid, int high){

    int cnt = 0;
    vector<int> temp;
    int left = low, right = mid + 1;

    while (left <= mid && right <= high)
    {
        if(nums[left] <= nums[right]){
            temp.push_back(nums[left]);
            left++;
        }
        else{
            cnt += (mid - low + 1);
            temp.push_back(nums[right]);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(nums[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(nums[right]);
        right++;
    }
    

    for (int i = low; i <= high; i++)
        nums[i] = temp[i - low];
  
    
        return cnt;

}

int mergeSort(vector<int> &nums, int low , int high){
    int cnt = 0;
    if(low >= high ) return cnt;
    int mid = (low + high)/2;
    cnt += mergeSort(nums, low, mid );
    cnt += mergeSort(nums, mid + 1, high );
    cnt += merge(nums ,low, mid, high);
    return cnt;
}

int noOfInversions(vector<int> &nums){
 int n = nums.size();
 return mergeSort(nums, 0 , n-1);
}


int main()
{
    vector<int> nums= {5,8,3,2,1};
    cout<<noOfInversions(nums);

return 0;
}