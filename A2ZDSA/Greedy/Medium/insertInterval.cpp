#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> insert(vector<vector<int>>& arr, vector<int>& num) {
    int n = arr.size();
    vector<vector<int>> ans;
    int i = 0;
    int low  = num[0], high = num[1];
    while(i < n && low > arr[i][1]){
        ans.push_back(arr[i]);
        i++;
    }
    // case2
    while (i < n && high >= arr[i][0])
    {
        low = min(low , arr[i][0]);
        high = max(high , arr[i][1]);
        i++;
    }
    ans.push_back({low, high});

    while(i < n && high < arr[i][0]){
        ans.push_back(arr[i]);
        i++;
    }
    return ans;
}


int main()
{

return 0;
}