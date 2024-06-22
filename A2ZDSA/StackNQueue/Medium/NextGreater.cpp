#include <bits/stdc++.h>
using namespace std;
vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
{
    vector<int> ans(queries, -1);
    for (int i = 0; i < queries; i++)
    {
        int ind = indices[i];
        int cnt = 0;
        for (int j = ind + 1; j < n; j++)
            if (arr[j] > arr[ind])
                cnt++;
        ans[i] = cnt;
    }
    return ans;
}

int main()
{

    return 0;
}