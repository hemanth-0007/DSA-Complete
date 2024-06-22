#include <bits/stdc++.h>
using namespace std;

vector<int> insert(vector<int> &obst, int x)
{
    obst.push_back(x);
    sort(obst.begin(), obst.end());
    vector<int> maxSpace;
    int maxi = -1;
    maxSpace.push_back(obst[0]);
    for (int i = 1; i < obst.size(); i++)
    {
        maxi = max(maxi, obst[i] - obst[i-1]);
        maxSpace.push_back(maxi);
    }
    return maxSpace;
}

vector<bool> getResults(vector<vector<int>> &queries)
{
    int n = queries.size();
    vector<int> obst;
    vector<int> maxSpace;
    vector<bool> res;
    for (int i = 0; i < n; i++)
    {
        if (queries[i][0] == 1)
        {
            maxSpace = insert(obst, queries[i][1]);
            for(auto n : obst) cout<<n<<" ";
            cout<<endl;
            for(auto n : maxSpace) cout<<n<<" ";
            cout<<endl;
            cout<<endl;
        }
        else if (queries[i][0] == 2)
        {
            int m = obst.size();
            int x = queries[i][1];
            int sz = queries[i][2];
            int ind = upper_bound(obst.begin(), obst.end(), x) - obst.begin();
            // cout<<"x is "<<x<<"ind is"<<ind<<"obst size is "<<obst.size()<<endl;
            if(ind == m) ind = m-1;
            if(sz <= x - obst[ind])
                res.push_back(true);
            else if (sz <= maxSpace[ind])
                res.push_back(true);
            else
                res.push_back(false);
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> queries = {{1, 2}, {2, 3, 3}, {2, 3, 1}, {2, 2, 2}};
    vector<bool> res = getResults(queries);
    for (auto num : res)
        cout << num << " ";

    // vector<int> arr = {2};
    // int ind = upper_bound(arr.begin(), arr.end(), 1) - arr.begin();
    // cout<<ind<<endl;
    return 0;
}