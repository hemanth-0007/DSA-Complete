#include<bits/stdc++.h>
using namespace std;


// Removing the duplicates from a vector
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int> mp;
        int count = 0;
        for(auto it : nums){
            mp[it]++;
        }

        for (auto itr = mp.begin(); itr != mp.end(); itr++)
        {
                 cout<<itr->first<<" ";
                 count++;
        }
        cout<<endl;
        
        return count;
    }
};

int main()
{
    vector<int> nums = {1,1,2,2,2,3,4};
    // for (auto itr : nums)
    // {
    //    cout<<itr<<" ";
    // }
    
    Solution s1;
    cout<<s1.removeDuplicates(nums);

return 0;
}