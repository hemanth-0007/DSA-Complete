#include <bits/stdc++.h>
using namespace std;

vector<int> UnionMod(vector<int> arr1, vector<int> &arr2)
{
    int n = arr1.size(), m = arr2.size();

    vector<int> res;
    int i = 0, j = 0;
    while (i < n && j < m)
    {

        if (arr1[i] < arr2[j])
        {

            if (res.empty() || res.back() != arr1[i])
            {
                res.push_back(arr1[i]);
            }
            i++;
        }
        else if (arr1[i] > arr2[j])
        {
            if (res.empty() || res.back() != arr2[j])
            {
                res.push_back(arr2[j]);
            }
            j++;
        }
        else
        {
            if (res.empty() || res.back() != arr1[i])
            {
                res.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    while (i < n)
    {
        if(res.empty() || res.back() != arr1[i])
            res.push_back(arr1[i]);
        i++;
    }
    while (j < m)
    {
        if(res.empty() || res.back() != arr2[j])
            res.push_back(arr2[j]);
        j++;
    }
    
    
    return res;
}

vector<int> UnionBrute(vector<int> arr1, vector<int> &arr2)
{
    int n = arr1.size(), m = arr2.size();
    set<int> st;
    vector<int> res;
    for (auto num : arr1)
        st.insert(num);
    for (auto num : arr2)
        st.insert(num);
    for (auto it : st)
        res.push_back(it);
    return res;
}

int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {2, 3, 4, 4, 5, 10 , 11 , 13};
    // vector<int> res = UnionBrute(arr1, arr2);
    vector<int> res = UnionMod(arr1, arr2);
    for (auto num : res)
        cout << num << " ";
    return 0;
}