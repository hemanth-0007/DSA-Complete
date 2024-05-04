#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> uniqueP;
    set<vector<int>> st;
    void solve(int ind, vector<int> &arr, int n)
    {
        // base condition
        if (ind == n)
        {
            st.insert(arr);
            return;
        }
        // main code
        for (int i = ind; i < n; i++)
        {
            swap(arr[ind], arr[i]);
            solve(ind + 1, arr, n);
            swap(arr[ind], arr[i]);
        }
    }

    vector<vector<int>> uniquePerms(vector<int> &arr, int n)
    {
        // code here
        solve(0, arr, n);
        cout << st.size() << endl;
        for (auto v : st)
        {
            for (auto i : v)
            {
                cout << i << " ";
            }
            cout << endl;
            uniqueP.push_back(v);
        }
    }
};
 

int main()
{
    vector<int> nums = {1, 2, 3};
    int n = nums.size();
    Solution obj;
    obj.uniquePerms(nums, n);
    for(auto v : obj.uniqueP)
    {
        for(auto i : v)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}