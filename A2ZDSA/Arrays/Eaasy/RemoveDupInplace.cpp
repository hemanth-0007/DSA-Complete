#include <bits/stdc++.h>
using namespace std;

// remove duplicates inplace for a sorted array
int remDupInplace(vector<int> &arr)
{
    // elements are stored in sorted
    // tc to insert - O(logn)
    set<int> st;
    for (auto num : arr)
        st.insert(num);
    int k = st.size();
    int j = 0;
    for (auto n : st)
    {
        arr[j++] = n;
    }
    return k;
}

int remDupInplaceOp(vector<int> &arr)
{
    int ans = 0;
    int n = arr.size();
    int i = 0, j = 1;
    while (i < n && j < n)
    {
        while (j < n && arr[i] == arr[j]) j++;
        i += 1;
        arr[i] = arr[j];
    }
    return i;
}

int main()
{
    // vector<int> arr = {1, 1, 2, 2, 2, 3, 3, 3, 4};
    vector<int> arr = {1, 2,3,4,4};
    // cout<<remDupInplace(arr);
    int l = remDupInplaceOp(arr);
    for (int i = 0; i < l; i++)
        cout << arr[i] << " ";

    return 0;
}