#include<bits/stdc++.h>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int,int> mp;
    int prefixMod = 0;    
   
    int cnt = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        prefixMod = sum%k;
        if(prefixMod < 0) prefixMod += k;
        cout<<prefixMod<<" ";
        if(prefixMod == 0) cnt++;
        cnt += mp[prefixMod];
        mp[prefixMod]++;
    }
    cout<<endl;
    return cnt;
}


int main()
{
//    vector<int> nums = {4,5,0,-2,-3,1};
   vector<int> nums = {-1,2,9};
   int k = 2;
   cout<<subarraysDivByK(nums , k)<<endl;

return 0;
}