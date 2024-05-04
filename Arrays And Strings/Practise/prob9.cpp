#include<bits/stdc++.h>
using namespace std;


bool isThere(vector<int>& nums, int n){
    int left = 0, right = n-1;
    while (left <= right)
    {
        int mid = left + (right - left)/2;
        if(nums[mid] < 0) left = mid + 1;
        else if(nums[mid] == mid) return true;
        else if(nums[mid] < mid){
            left = mid + 1;
        }
        else if(nums[mid] > mid){
            right = mid - 1;
        }
    }
    return false;
}



int main()
{

return 0;
}