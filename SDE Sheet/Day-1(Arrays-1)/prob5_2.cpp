//sorting the array with the 0's , 1's , 2's
// Better Approach

#include<bits/stdc++.h>
using namespace std;

int countNum(vector<int> &nums, int k){
     int n = nums.size(), count = 0;
     for (int i = 0; i < n; i++)
     {
        if(nums[i] == k) count += 1;
     }
     return count;
     
}
int sortArray(vector<int> &nums, int countZero, int countOne){

    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        if(i < countZero) nums[i] = 0;
        else if(i >= countZero && i < (countOne + countZero)) nums[i] = 1;
        else nums[i] = 2;
    }
    
}



int main()
{
    vector<int> nums = {2,0,2,1,1,0,0,0};
    int countZero = countNum(nums, 0);
    int countOne = countNum(nums, 1);
     sortArray(nums, countZero, countOne);
     for(auto n : nums) cout<<n<<" ";


return 0;
}