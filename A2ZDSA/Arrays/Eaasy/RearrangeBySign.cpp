#include <bits/stdc++.h>

using namespace std;

// consider zero as a positive
vector<int> rearrangeBySign(vector<int> &arr)
{
    int n = arr.size();
    int posInd = 0, negInd = 1;
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= 0)
        {
            ans[posInd] = arr[i];
            posInd += 2;
        }
        else
        {
            ans[negInd] = arr[i];
            negInd += 2;
        }
    }
    return ans;
}

int main()
{
    // vector<int> arr = {1, 2, 3, -1, -2, -3};
    vector<int> arr = {1, 2, -4, -8};
    vector<int> ans = rearrangeBySign(arr);
    for (auto num : ans)
        cout << num << " ";
    return 0;
}