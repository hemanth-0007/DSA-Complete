#include <bits/stdc++.h>
using namespace std;

int longestOnes(vector<int> &nums, int k)
{
    int n = nums.size();
    int cnt = k, len = 0, maxLen = 0;
    int i = 0, j = 0;
    while (i < n && j < n && i <= j)
    {
        if (cnt == 0 && nums[j] == 0)
        {
            while (i < n && cnt == 0)
            {
                if (nums[i] == 0)
                    cnt++;
                i++;
            }
        }
        if (cnt > 0 && nums[j] == 0)
            cnt--;
        int len = j - i + 1;
        // cout << i << " " << j << " " << len << endl;
        maxLen = max(len, maxLen);
        j++;
    }
    return maxLen;
}

 
int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    int k;
    cin >> k;
    cout << longestOnes(nums, k);
    cout << "optimal" << endl;
    

    return 0;
}