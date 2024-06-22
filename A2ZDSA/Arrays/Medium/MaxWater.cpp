#include <bits/stdc++.h>
using namespace std;


int getLeftMax(int ind , vector<int>& nums){
    int leftMax = 0;
    for (int i = ind+1; i < nums.size(); i++)
    {
        leftMax = max(leftMax, nums[i]);
    }
    return leftMax;
}

int maxArea(vector<int> &height)
{
    int n = height.size();
    int ans = 0;
    int rightMax = 0, leftMax = 0;
    for (int i = 0; i < n; i++)
    {
        leftMax = getLeftMax(i, height);
        int water = min(rightMax, leftMax) - height[i];
        cout<<water<<endl;
        if(water > 0) ans+= water;
        rightMax = max(rightMax, height[i]);
    }
    return ans;
}
int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    cout<<maxArea(height);

    return 0;
}