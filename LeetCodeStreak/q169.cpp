#include<bits/stdc++.h>
using namespace std;

int majorityElement(vector<int>& nums) {
        int majorNum = nums[0], count = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == majorNum) count++;
            else{
                if(count == 1) majorNum = nums[i];
                else count--;
            }
        }
        return majorNum;
}


int main()
{
    // vector<int> nums = {2,2,1,1,1,2,2};
    vector<int> nums = {2,2,1,1,1,3};
    cout<<majorityElement(nums)<<endl;

return 0;
}