#include<bits/stdc++.h>
using namespace std;

void helper(int i ,int& cnt, vector<int>& arr, int n , vector<int>& ds){
    if(i == n){
        int sum = 0;
        for(auto num : ds) sum = sum^num; 
        cnt += sum;
        return;
    }
    
    ds.push_back(arr[i]);
    helper(i+1,cnt, arr, n, ds);
    ds.pop_back();
    helper(i+1,cnt,arr, n ,ds);
}



int subsetXORSum(vector<int> & nums){
    int n = nums.size();
    vector<int> ds;
    int cnt = 0;
    helper(0 ,cnt, nums, n, ds);
    return cnt;
}

int helperOp(int ind, int xorSum,vector<int>& nums){
    if(ind == nums.size()){
        return xorSum;
    }
    int include = helperOp(ind +1 , xorSum^nums[ind] , nums);
    int notInclude = helperOp(ind +1, xorSum, nums); 
    return include + notInclude;
}
 

int subsetXORSumOp(vector<int> & nums){
    int n = nums.size();
    return  helperOp(0, 0, nums);
}




int main()
{
    vector<int> nums = {5, 1, 6};
    cout<<subsetXORSumOp(nums);

return 0;
}