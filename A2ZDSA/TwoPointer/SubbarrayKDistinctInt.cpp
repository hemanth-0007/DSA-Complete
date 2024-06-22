#include<bits/stdc++.h>
using namespace std;

// subbarays with atmost k different integers
int subarraysWithKDistinctHelper(vector<int>& nums, int k) {
    int n = nums.size();
    unordered_map<int,int> mp;
    int left = 0 , right = 0;
    int cnt = 0;
    while(right < n){
        mp[nums[right]]++;
        if(mp.size() > k){
            while(left < n && mp.size() > k){
                mp[nums[left]]--;
                if(mp[nums[left]] == 0) mp.erase(nums[left]);
                left++;
            }
        }
        if(mp.size() <= k) cnt += (right - left + 1);
        right++;
    }
    return cnt;
}

int main()
{
     int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<subarraysWithKDistinctHelper(arr,k) - subarraysWithKDistinctHelper(arr, k-1);

return 0;
}