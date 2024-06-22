#include<bits/stdc++.h>
using namespace std;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int,int> mp;
    for (int i = 0; i < arr2.size(); i++)
        mp[arr2[i]] = i;
    
    vector<pair<int,int>> ans;
    for (int i = 0; i < arr1.size(); i++)
    {
        if(mp.find(arr1[i]) != mp.end()) ans.push_back({mp[arr1[i]], arr1[i]});
        else ans.push_back({2000, arr1[i]}); 
    }
    sort(ans.begin(), ans.end());
    for (int i = 0; i < arr1.size(); i++) arr1[i] = ans[i].second;
    return arr1;
}


int main()
{
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};
    vector<int> ans = relativeSortArray(arr1, arr2);
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    

return 0;
}