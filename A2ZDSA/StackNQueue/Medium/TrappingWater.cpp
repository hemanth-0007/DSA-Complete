#include <bits/stdc++.h>
using namespace std;

int trap(vector<int> &arr)
{
    int n = arr.size();
    vector<int> rightMax(n, 0);
    vector<int> leftMax(n, 0);
    int maxi = 0;
    for (int i = 0; i < n; i++)
    {
        leftMax[i] = maxi;
        maxi = max(maxi, arr[i]);
    }
    maxi = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        rightMax[i] = maxi;
        maxi = max(maxi, arr[i]);
    }
    // for(auto num : arr) cout<<num<<" ";
    // cout<<endl;
    // for(auto num : rightMax) cout<<num<<" ";
    // cout<<endl;
    // for(auto num : leftMax) cout<<num<<" ";
    // cout<<endl;

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int water = (min(rightMax[i], leftMax[i]) - arr[i]);
        if (water > 0)
            ans += water;
    }
    return ans;
}

int trapOp(vector<int> &arr)
{
    int n = arr.size();
    int leftMax = 0, rightMax = 0;
    int left = 0, right = n - 1;
    int ans = 0;
    while (left < right)
    {
        if (arr[left] <= arr[right])
        {
            if (arr[left] > leftMax)
                leftMax = arr[left];
            else
                ans += (leftMax - arr[left]);
            left++;
        }
        else if (arr[left] > arr[right])
        {
            if (arr[right] > rightMax)
                rightMax = arr[right];
            else
                ans += (rightMax - arr[right]);
            right--;
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << trap(arr)<<endl;
    cout << trapOp(arr);
    return 0;
}