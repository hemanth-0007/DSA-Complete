#include <bits/stdc++.h>
using namespace std;

int subarraySum(vector<int> &arr, int k)
{
    int n = arr.size();
    map<int,int> mp;
    int cnt = 0, prefixSum = 0;
    mp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];
        int rem = prefixSum - k;
        cnt += mp[rem];
        mp[prefixSum] += 1;
    }
    return cnt;
}

int main()
{
    // vector<int> arr = {1, 2,3,-3, 1,1, 1,4, 2, -3 };
    vector<int> arr = {0, 0 , 1 };
    int k = 1;
    cout<<subarraySum(arr, k);
    return 0;
}