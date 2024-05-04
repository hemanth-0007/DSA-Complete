#include<bits/stdc++.h>
using namespace std;

int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    int n = arr.size();
    map<int,int> mp;
    multimap<int,int> mmp;
    int count = 0;
    for (int i = 0; i < n; i++) mp[arr[i]]++;
    for(auto it : mp){
        mmp.insert({it.second, it.first});
        // cout<<it.first<<" "<<it.second<<endl;
    }
    // cout<<endl;
    for(auto it : mmp){
        //  cout<<it.first<<" "<<it.second<<endl;
         if(k > 0 && it.first <= k) {
            count++;
            mp[it.second] -= (it.first);
            k = k - it.first;
         }
         else break;
    }
    // cout<<endl;
    //  for(auto it : mp){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    return mp.size() - count;
}


int findLeastNumOfUniqueIntsOp(vector<int>& arr, int k) {
    int n = arr.size(), count = 0;
    map<int,int> mp;
    multimap<int,int> mmp;
    // O(N)
    for (int i = 0; i < n; i++) mp[arr[i]]++;
    // O(N)
    for(auto it : mp) mmp.insert({it.second, it.first});

    // O(N)
    for(auto it : mmp){
         if(k > 0 && it.first <= k) {
            count++;
            mp[it.second] -= (it.first);
            k -= it.first;
         }
         else break;
    }

    return mp.size() - count;
}


int main()
{
    vector<int> arr = {4,3,1,1,3,3,2};
    int k = 3;
    cout<<findLeastNumOfUniqueInts(arr, k);
return 0;
}