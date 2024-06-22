#include<bits/stdc++.h>
using namespace std;

bool canJump(vector<int>& nums) {
    int n = nums.size();
    int i = 0;
    int maxRange = nums[0] + 0;
    while (i < n && i < maxRange)
    {
        maxRange = max(maxRange, nums[i] + i);
        i++;
    }
    if(maxRange >= n-1) return true;
    return false;
}

int main()
{

return 0;
}