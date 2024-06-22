#include <bits/stdc++.h>
using namespace std;

int findMaxLength(vector<int> &arr)
{
    int n = arr.size();
    int sum = 0;
    vector<int> prefix(n);
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == 0) sum -= 1;
        else sum += 1;
        prefix[i] = sum;
    }
    // prefix[i] and i
    unordered_map<int,int> mp;
    int maxLength = 0;
    for (int i = 0; i < n; i++)
    {
        if(prefix[i] == 0) maxLength = max(maxLength, i+1);
        if(mp.find(prefix[i]) != mp.end()){
            maxLength= max(maxLength, i - mp[prefix[i]] );
        }
        else mp[prefix[i]] = i;
    }
    return maxLength;
}

int main()
{
    vector<int> arr = {1,1,0,0,1,1,0,1,1};
    cout<<findMaxLength(arr);

    return 0;
}