#include <bits/stdc++.h>
using namespace std;

int specialArray(vector<int> &nums)
{
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i =0 ; i <= n ; i++){
        int ind = lower_bound(nums.begin(), nums.end(), i) - nums.begin();
        cout<<ind<<endl;
        if((n- ind) == i) return i;
    }
    return -1;
}

int main()
{
    vector<int> nums = {3,5};
    cout<<specialArray(nums)<<endl;

    return 0;
}