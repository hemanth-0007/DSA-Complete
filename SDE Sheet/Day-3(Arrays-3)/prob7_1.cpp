
//  Rain Water getting traped calculate how much
// brute force
#include<bits/stdc++.h>
using namespace std;
// approx --> O(N^2)
int rainWaterTrapped(vector<int> &nums , int n){
     
     int trapped = 0;
     for (int i = 0; i < n; i++)
     {
        if(i == 0 || i == n-1) continue;
        int temp = min( *max_element(nums.begin(), nums.begin() + i), 
                        *max_element(nums.begin() + (i+1), nums.end()));
        if(temp > nums[i]) trapped += temp - nums[i];
               
      
     }
     return trapped;
  
}

int main()
{
    vector<int> nums = {0,1,0,2,1,0,1,3,2,1,2,1};
    int n = nums.size();
    cout<<rainWaterTrapped(nums, n);
      
return 0;
}