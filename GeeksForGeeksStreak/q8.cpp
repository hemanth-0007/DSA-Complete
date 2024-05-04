#include<bits/stdc++.h>
using namespace std;

bool canPair(vector<int> nums, int k) {
    // Code here.
    unordered_map<int, int> mp;
    for(auto num : nums) mp[(num%k + k)%k]++ ;
    // for(auto it : mp){
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    if (mp[0] % 2 != 0) {
        return false;
    }
    for (int i = 1; i <= k / 2; ++i) {
        if (mp[i] != mp[k - i]) {
            return false;
        }
    }

    return true;
}

int main()
{
    // vector<int> nums = {9, 7, 5, 3};
    vector<int> nums = {6 ,14 ,12 ,14};
    int k = 2;
    cout<<canPair(nums, k)<<endl;

return 0;
}