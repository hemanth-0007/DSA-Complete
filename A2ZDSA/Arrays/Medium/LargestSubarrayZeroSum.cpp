#include <bits/stdc++.h>
using namespace std;

int maxLen(vector<int> &arr, int n)
{
    // sum , ind
    unordered_map<int, int> mp;
    int maxi = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (sum == 0){
            maxi = max(maxi, i + 1);
        }
        if (mp.find(sum) == mp.end())
            mp[sum] = i;
        else maxi = max(maxi, abs(mp[sum] - i));
    }
    return maxi;
}

int main()
{
    vector<int> arr =  {15,-2,2,-8,1,7,10,23};
    cout<<maxLen(arr, arr.size());
     return 0;
}