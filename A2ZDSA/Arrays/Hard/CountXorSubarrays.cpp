#include<bits/stdc++.h>
using namespace std;


int xorSubarrays(vector<int>& arr, int k){
    unordered_map<int , int> mp;
    int xored = 0, cnt = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        xored ^= arr[i];
        if(xored == k) cnt++;
        cnt += mp[(xored^k)];
        mp[xored]++;
    }
    for(auto it : mp) cout<<it.first<<" "<<it.second<<endl;
    return cnt;
}




int main()
{

    vector<int> arr = {4, 2,2, 6, 4};
    int k = 6;
    cout<<xorSubarrays(arr, k);

return 0;
}