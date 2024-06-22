#include<bits/stdc++.h>
using namespace std;

int numberOfSubarraysOp(vector<int>& nums, int k) {
    int n = nums.size();
    int left = 0, right = 0;
    int cnt = 0, ans = 0;
    while(right <  n){
        if(nums[right]%2 != 0) cnt++;
        while(left < n && cnt > k){
            if(nums[left]%2 != 0) cnt--;
            left++;
        }
        if(cnt <= k) ans += (right - left + 1);
        right++;
    }
    return ans;
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
    cout<<numberOfSubarraysOp(arr, k) - numberOfSubarraysOp(arr, k-1)<<endl;

return 0;
}