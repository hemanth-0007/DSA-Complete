#include<bits/stdc++.h>
using namespace std;




int nene_card_game(vector<int>& nums){
    int n = nums.size();
    unordered_map<int,int> mp;
    for(auto num : nums) mp[num]++;
    int ans = 0;
    for(auto it : mp){
        if(it.second == 2) ans++;
    }
    return ans;
}



int main()
{
    int testCases;
    cin>>testCases;
    while (testCases--)
    {
        int n;
        cin>>n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin>>nums[i];
        cout<<nene_card_game(nums)<<endl;
    }
    

return 0;
}