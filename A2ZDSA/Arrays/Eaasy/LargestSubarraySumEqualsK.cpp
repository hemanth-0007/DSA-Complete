#include <bits/stdc++.h>
using namespace std;

int lenOfLongSubarr(vector<int> &arr, int n, int k)
{
    // mp[prefix_sum] = index
    // unordered_map<int, int> mp;
    map<int, int> mp;
    int maxLength = 0, prefixSum = 0;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        if (prefixSum == k){
            // cout<<i<<" "<<maxLength<<" "<<i+1<<endl;
            maxLength = max(maxLength, i + 1);
        }

        int remSum = prefixSum - k;
        if (mp.find(remSum) != mp.end()){
            // cout<<i<<" "<<maxLength<<" "<<i - mp[remSum]<<endl;
            maxLength = max(maxLength, i - mp[remSum]);
        }

        if (mp.find(prefixSum) == mp.end())
            mp[prefixSum] = i;
    }
    // map
    cout<<"the map is : "<<endl;
    for(auto it : mp) cout<<"\t"<<it.first<<" "<<it.second<<endl;
    return maxLength;
}


// Two pointer method only for positive integers
int lenOfLongSubarrOp(vector<int> &arr, int n, int k)
{
     int i = 0 , j = 0;
     int sum = arr[0];
     int maxLength = 0;
     while (i < n && j < n)
     {
        while(i <= j && sum > k){
            sum -= arr[i];
            i++;
        }
        if(sum == k) maxLength = max(maxLength, j - i +1);
        j++;
        if(j < n ) sum += arr[j];
     }
     return maxLength;
}


int main()
{
    vector<int> arr = {10, 5, 2, 7, 1, 9};
    int K = 15;
    // vector<int> arr = {5, 0, 1,-1,0,3};
    // int K = 3;
    cout << lenOfLongSubarr(arr, arr.size(), K);
    return 0;
}