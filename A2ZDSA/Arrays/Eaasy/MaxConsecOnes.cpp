#include <bits/stdc++.h>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
    int n = nums.size();
    int i = 0;
    int maxi = 0;
    while (i < n)
    {
        int j = i;
        while (j < n && nums[j] == 1){
            j++;
        }
        maxi = max(maxi, j - i);
        i = j;
        i++;
    }
    return maxi;
}

int findMaxConsecutiveOnesOp(vector<int> &nums)
{
    int n = nums.size();
    int cnt = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        if(nums[i]==1){
            cnt++;
        }
        else cnt = 0;
        maxi = max(maxi, cnt);
    }
    
    return maxi;
}
int main()
{
    vector<int> nums = {1,1,0,1,1,1};
    cout<<findMaxConsecutiveOnesOp(nums);
    return 0;
}