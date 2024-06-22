#include<bits/stdc++.h>
using namespace std;
int singleNumber(vector<int>& nums) {
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
       int sum = 0;
    //    comsider the sum of the bits and if it is not a multiple of 3 
    // then it must be the one in the ans number
       for (int j = 0; j < n; j++)
            sum += ((nums[j] >> i)&1);
       if(sum%3 != 0) ans = ans | (1<<i); 
    }
    return ans;
}
int main()
{
    vector<int> nums = {0,1,0,1,0,1,99};
    cout<<singleNumber(nums);
return 0;
}