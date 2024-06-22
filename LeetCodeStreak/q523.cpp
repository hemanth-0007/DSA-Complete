#include<bits/stdc++.h>
using namespace std;
bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int,int> mp; 
    int prefixMod = 0;    
    
    for (int i = 0; i < n; i++)
    {
        prefixMod = (prefixMod + nums[i])%k;
        if(prefixMod == 0 && i >= 1) return true;
        if(mp.find(prefixMod) != mp.end()){
            if(i - mp[prefixMod] >= 2) return true;
        }
        else mp[prefixMod] = i;
    }
    return false;
}
int main()
{

return 0;
}