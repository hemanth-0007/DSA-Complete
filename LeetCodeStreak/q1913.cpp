#include<bits/stdc++.h>
using namespace std;

int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        int min = 1e9, secMin = 1e9, max = 0, secMax = 0;
        for (int i = 0; i < n; i++)
        {
            if(nums[i] < min){
                secMin = min;
                min = nums[i];
            }
            else if(nums[i] < secMin){
                secMin = nums[i];
            }

            if(nums[i] > max){
                secMax = max;
                max = nums[i];
            }
            else if(nums[i] > secMax){
                secMax = nums[i];
            }
        }
        // cout<<min<<" "<<secMin<<" "<<max<<" "<<secMax<<endl;
        return max*secMax - min*secMin;
        // return nums[n-1]*nums[n-2] - nums[0]*nums[1];
}



int main()
{
    vector<int> nums = {5,6,2,7,4};
    cout<<maxProductDifference(nums)<<endl;
    for(auto num : nums){
        cout<<num<<" ";
    }

return 0;
}