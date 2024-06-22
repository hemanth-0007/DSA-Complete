#include <bits/stdc++.h>
using namespace std;

int xorSubaarrays(vector<int> &nums, int x)
{
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        int xored = 0;
        for (int j = i; j < nums.size(); j++)
        {
            xored ^= nums[i];
            mp[xored]++;
        }
    }
    int no_of_subarrays =0;
    multimap<int,int> mlp;
    for(auto it : mp){
        // cout<<it.first<<" "<<it.second<<endl;
        // no_of_subarrays  += it.second;
        // if(no_of_subarrays > 0) return it.first;
        mlp.insert({it.second, it.first});
    }

    for(auto it : mlp){
        no_of_subarrays++;
        if(no_of_subarrays >= x) return it.second;
        cout<<no_of_subarrays<<endl;
        cout<<it.first<<" "<<it.second<<endl;
    }

    return -1;
}

int main()
{
    // int t;
    // cin>>t;
     
    // while (t--)
    // {
    //     int n , x;
    //     cin>>n>>x;
    //     vector<int> nums(n);
    //     for (int i = 0; i < n; i++) cin>>nums[i];
    //     cout<<xorSubaarrays(nums, x);
    // }
    
         int n = 4 , x = 7;
        vector<int> nums = {1,2, 3,4};
        // for (int i = 0; i < n; i++) cin>>nums[i];
        cout<<xorSubaarrays(nums, x);

    return 0;
}