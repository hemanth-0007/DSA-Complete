#include<bits/stdc++.h>
using namespace std;

int subarraysWithKDistinct(vector<int>& nums, int k) {
    int n = nums.size();
    int ans = 0;
    unordered_map<int,int> mp;
    for(int left = 0 , right = 0; right < n ; right++){
        mp[nums[right]]++;
        if(mp.size() == k){
            ans++;
        }
        else if(mp.size() > k){

        }
    }   
    return ans;    
}

int main()
{

return 0;
}