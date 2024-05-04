#include<bits/stdc++.h>
using namespace std;
// return ind
int binary_search(int left , int right, 
vector<int> &nums,int key){

        if(left > right) return right;
      int mid = left + (right - left)/2;
      if(key == nums[mid]) return mid;
      if(key > nums[mid]) return binary_search(mid+1,right, nums, key);
      if(key < nums[mid]) return binary_search(left,mid-1, nums, key);
}
  



int main()
{
    vector<int> nums = {2,4,5,6,7,10};
    int n = nums.size();
    cout<<binary_search(0,n-1,nums,8);
    return 0;
}