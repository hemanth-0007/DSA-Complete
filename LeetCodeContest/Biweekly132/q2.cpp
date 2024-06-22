#include <bits/stdc++.h>
using namespace std;

int findWinningPlayer(vector<int> &arr, int k)
{
    int n = arr.size();
    deque<int> dq;
    for (int i = 1; i < n; i++)
        dq.push_back(i);
    int ele = 0, cnt = 0;
    while (true)
    {
        int ind = dq.front();
        dq.pop_back();
        if (arr[ind] < arr[ele])
        {
            cnt++;
            dq.push_back(ind);
        }
        else
        {
            cnt = 1;
            dq.push_back(ele);
            ele = ind;
        }
        if (cnt == k || cnt >= n - 1)
            return ele;
    }
    return 1;
}

int findWinningPlayer(vector<int> &arr, int k)
{
    int n = arr.size();
    int maxi_i = 0, cnt = 0;
    for (int i = 1; i < n && cnt < k; i++)
    {
        if(arr[maxi_i] > arr[i]){
            ++cnt;
        }
        else{
            cnt = 1;
            maxi_i = i;
        }
    }
    
    return maxi_i;
}

int main()
{
    // vector<int> skills = {4,2,6,3,9};
    // int k = 2;
    vector<int> skills = {2, 5, 4};
    int k = 3;
    cout << findWinningPlayer(skills, k) << endl;
    return 0;
}