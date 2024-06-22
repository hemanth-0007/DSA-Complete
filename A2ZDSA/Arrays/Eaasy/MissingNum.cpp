#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &nums)
{
    int res = nums.size();

    for (int i = 0; i < nums.size(); i++)
    {
        res += i - nums[i];
    }

    return res;
}

int main()
{

    vector<int> nums = {3, 0, 1};
    cout << missingNumber(nums);
    return 0;
}