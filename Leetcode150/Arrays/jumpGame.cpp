#include<bits/stdc++.h>
using namespace std;

 
bool canJump(vector<int> &nums ) {
    int n = nums.size();
    // initialising the maxInd to 0
    int maxInd = 0;
    // iterating over the array
    for(int i = 0 ; i < n ;i++){
        if(maxInd >= n-1) return true;
        // if the maxInd is less than the current index and the value at the current index is 0
        // that means we cannot move forward
        if(nums[i] == 0 && maxInd <= i) return false;
        // updating the maxInd to the maximum of the current maxInd and the index + the value at the index(ind + nums[ind])
        for(int j = i; j <=min(i + nums[i], n-1); j++){
            maxInd = max(maxInd, j + nums[j]);
            // if the maxInd is greater than or equal to the last index of the array
            // that means we can reach the end of the array so return true
            if(maxInd >= n-1) return true;
        }
    }
    // return false if the iteration is complete
        return false;
   
        
        // Time Complexity: O(n^2)
        // Space Complexity: O(1)
}
 



int main()
{
    vector<int> nums = {1,0,1,0};
    // vector<int> nums = {2,3,1,1,4};
    // vector<int> nums = {3,2,1,0,4};

    cout<<canJump(nums);

return 0;
}