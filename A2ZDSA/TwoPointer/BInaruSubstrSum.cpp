#include<bits/stdc++.h>
using namespace std;

int numSubarraysWithSum(vector<int>& arr, int goal) {
    int n = arr.size();
    unordered_map<int,int> mp;
    int sum = 0, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum == goal) cnt++;
        // this will check the prev stored computations
        int rem = sum - goal;
        if(mp.find(rem) != mp.end()) cnt += (mp[rem]);
        // this will update the current map
        mp[sum]++;
    }
    return cnt;
}

// this func calculates atmost goal subarrays
int numSubarraysWithSumOp(vector<int>& arr, int goal) {
    int n = arr.size();
    int sum = 0, cnt = 0;
    int left =0, right = 0;
    while(right < n){
        sum += arr[right];
        while(left < n && sum > goal){
            sum -= arr[left];
            left++;
        }
        if(sum <= goal) cnt += (right - left + 1);
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
    int goal;
    cin>>goal;
    cout<<numSubarraysWithSum(arr, goal)<<endl;
    cout<<numSubarraysWithSumOp(arr, goal) - numSubarraysWithSumOp(arr, goal-1)<<endl;

return 0;
}