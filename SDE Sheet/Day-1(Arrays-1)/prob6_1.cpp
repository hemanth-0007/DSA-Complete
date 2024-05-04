// Buying and Selling the stock problem 
// Brute Force Method

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &nums){

     int n = nums.size();
     int maxPro = 0 ;
     //O(n^2)
     for (int i = 0; i < n; i++)
     {
         
        for (int j = i+1; j < n; j++)
        {
            int profit = (nums[j] - nums[i]);
            if(maxPro < profit) maxPro = profit;
        }
        
     }
     return maxPro;
     
     
}
 
int main()
{
    vector<int> nums = {7,1,5,3,6,4};
    cout<<maxProfit(nums);
        return 0;

}