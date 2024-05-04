#include<bits/stdc++.h>
using namespace std;

int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    int max_len = 1;
    for(int i = 0 ; i < n-1 ;i++){
        int len = 1, prev = nums[i];
        cout<<i<<endl;
        for(int j = i; j < n-1 ;j++){
            if(nums[j+1] > prev){
                len++;
                prev = nums[j+1];
                cout<<"\t"<<j<<" "<<nums[j]<<' '<<nums[j+1]<<" "<<len<<" "<<prev<<endl;
            } 
        }
        max_len = max(max_len, len);
    }
    return max_len;
}

int helper(int ind, int prev, vector<int>&nums, int n){
    // base conditions


    // main code
    // pick
    if(nums[ind] > prev) helper(ind + 1,nums[ind] ,nums, n);
    helper(ind +1, prev, nums, n);
    //not pick
}



int lengthOfLIS_rec(vector<int>& nums) {
    int n = nums.size();
    int len = 0;
    return helper(0,-1,nums, n);
}



int main()
{
    // vector<int> v = {4,10,4,3,8,9};
    vector<int> v = {0,1,0,3,2,3};
    cout<<lengthOfLIS(v)<<endl;

return 0;
}