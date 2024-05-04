#include<bits/stdc++.h>
using namespace std;



int minJumps(vector<int>& nums){
    int n = nums.size();
    // iterating over the array and updating the value at the index to the 
    // maximum of the previous value and the index + the value at the index
    // that is the maximum index we can reach from the current index its not relative
    for(int i = 1 ; i < n ; i++) nums[i] = max(nums[i - 1], nums[i] + i);
    // initialising the ind to 0 and jumps to 0
    int ind = 0 , jumps = 0;
    // iterating over the modified nums array
    while (ind < nums.size() - 1)
    {
        ind = nums[ind];
        jumps++;
    }
    return jumps;    
}


int main()
{
    // vector<int> nums = {2,3,1,1,4};
    vector<int> nums = {2,3,0,1,4};
    vector<int> nums = {5,9,3,2,1,0,2,3,3,1,0,0};


    cout<<minJumps(nums);

return 0;
}