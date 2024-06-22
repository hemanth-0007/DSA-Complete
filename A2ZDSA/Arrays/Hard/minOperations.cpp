#include <bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &nums)
{
    int n = nums.size();
    unordered_set<int> st;
    for(auto num : nums) st.insert(num);
    int mini = 1e9;
    // worst time complexity is O(n^2)
    for (int i = 0; i < n; i++)
    {
        if(st.find(nums[i]-1) == st.end()){
            int cnt = 0;
            for (int j = nums[i]; j < n  + nums[i]; j++)
            {
                if(st.find(j) == st.end()) cnt++;
            }
            mini = min(mini, cnt);
        }
    }
    return mini;
}


int minOperationOp(vector<int> &nums)
{
    int n = nums.size();
     
}

int main()
{

    return 0;
}