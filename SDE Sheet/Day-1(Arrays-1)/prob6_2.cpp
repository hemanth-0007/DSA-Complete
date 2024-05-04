// Buying and Selling the stock problem 
// Optimal Solution O(n)

#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int> &nums){

     int n = nums.size();
     int maxPro = 0 ;
     int minPrice = 1e9;
     //O(n)
     for (int i = 0; i < n; i++)
     {
         minPrice = min(minPrice, nums[i]);
         maxPro = max(maxPro, nums[i] - minPrice);
        
     }
     return maxPro;
}
 
int main()
{
    vector<int> nums = {7,5,3,2,1};
    cout<<maxProfit(nums);
        return 0;

}