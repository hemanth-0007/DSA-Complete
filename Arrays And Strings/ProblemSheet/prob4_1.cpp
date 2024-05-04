#include<bits/stdc++.h>
using namespace std;


int searchInsert(vector<int> & nums , int target){
    int l = 0;
    int r = nums.size() - 1;
    int mid = (l+r)/2;
    if(l < r){
        if(target == nums[mid])
            return mid;
        if((target > nums[mid])){
            
        }
    }
}


int main()
{
    vector<int> nums = {1,3,5,6};
    int target = 5;
    cout<<searchInsert(nums, target);


return 0;
}