#include <bits/stdc++.h>
using namespace std;

bool comp(vector<int> &v1, vector<int> &v2)
{
    if (v1[0] != v2[0])
        return v1[0] < v2[0];
    return v1[1] > v2[1];
}

class Solution
{
public:
    static bool comp(vector<int> &v1, vector<int> &v2)
    {
        if (v1[0] != v2[0])
            return v1[0] < v2[0];
        return v1[1] > v2[1];
    }

    int maxProfitAssignment(vector<int> &difficulty, vector<int> &profit, vector<int> &worker)
    {
        int n = profit.size();
        vector<vector<int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({difficulty[i], profit[i], -1});
        sort(arr.begin(), arr.end(),Solution:: comp);

        // for (int i = 0; i < n; i++)
        //     cout << arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << endl;
        // cout << endl;

        int maxi = -1;
        for (int i = 0; i < n; i++)
        {
            maxi = max(maxi, arr[i][1]);
            arr[i][2] = maxi;
        }

        int ans = 0;
        for (int i = 0; i < worker.size(); i++)
        {
            int val = worker[i];
            auto it = upper_bound(arr.begin(), arr.end(), vector<int>{val, 0, 0}, [](const vector<int> &vec, const vector<int> &valVec)
                                  { return vec[0] < valVec[0]; });
            int ind = it - arr.begin() - 1;
            if (ind > -1)
                ans += arr[ind][2];
        }
        return ans;
    }
};

int main()
{

    vector<int> difficulty = {2, 4, 6, 8, 10};
    vector<int> profit = {10, 20, 30, 40, 50};
    vector<int> worker = {4, 5, 6, 7};
    int n = profit.size();
    // 1 st dificulty and profit and max profit
    vector<vector<int>> arr;
    for (int i = 0; i < n; i++)
        arr.push_back({difficulty[i], profit[i], -1});
    sort(arr.begin(), arr.end(), comp);

    for (int i = 0; i < n; i++)
        cout << arr[i][0] << " " << arr[i][1] << " " << arr[i][2] << endl;
    cout << endl;

    int maxi = -1;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i][1]);
        arr[i][2] = maxi;
    }

    // Use upper_bound with corrected comparator
    // int val = 4;
    // auto it = upper_bound(arr.begin(), arr.end(), vector<int>{val, 0, 0}, [](const vector<int> &vec, const vector<int> &valVec)
    //                       { return vec[0] < valVec[0]; });

    // if(it == arr.end()){
    //     cout<<"no in the range"<<endl;
    // }
    // int ind = it - arr.begin();

    // cout << ind << endl;

    int ans = 0;
    for (int i = 0; i < worker.size(); i++)
    {
        int val = worker[i];
        auto it = upper_bound(arr.begin(), arr.end(), vector<int>{val, 0, 0}, [](const vector<int> &vec, const vector<int> &valVec)
                              { return vec[0] < valVec[0]; });
        int ind = it - arr.begin() - 1;
        if (ind > -1)
            ans += arr[ind][2];
    }
    cout << ans << endl;

    return 0;
}