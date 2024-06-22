#include <bits/stdc++.h>
using namespace std;

vector<int> leaders(vector<int> &arr, int n)
{
    int maxi = -1e9;
    vector<int> ans;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] >= maxi)
        {
            maxi = arr[i];
            ans.push_back(arr[i]);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> arr = {16, 17, 4, 3, 5, 2};
    vector<int> ans = leaders(arr, arr.size());
    for (auto num : ans)
        cout << num << " ";
    return 0;
}