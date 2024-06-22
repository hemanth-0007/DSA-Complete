#include <bits/stdc++.h>
using namespace std;

int calculateRangedAnd(vector<int> &bit)
{
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        ans += (1 << i) * (bit[i] == 0);
    }
    return ans;
}

void addElement(vector<int> &bit, int el)
{
    for (int i = 0; i < 32; i++)
    {
        if (!((el >> i) & 1))
            bit[i]++;
    }
}

void subtractElement(vector<int> &bit, int el)
{
    for (int i = 0; i < 32; i++)
    {
        if (!((el >> i) & 1))
            bit[i]--;
    }
}

int minimumDifference(vector<int> &arr, int k)
{
    int n = arr.size();
    int left = 0, right = 0;
    int minDiff = 1e9, rangeAnd = 0;
    vector<int> bit(32, 0);
    while (right < n)
    {
        addElement(bit, arr[right]);
        rangeAnd = calculateRangedAnd(bit);
        minDiff = min(minDiff, abs(k - rangeAnd));
        while (rangeAnd < k && left < right)
        {
            subtractElement(bit, arr[left]);
            rangeAnd = calculateRangedAnd(bit);
            minDiff = min(minDiff, abs(k - rangeAnd));
            left++;
        }
        right++;
        if (minDiff == 0)
            return 0;
    }
    return minDiff;
}

int main()
{
    vector<int> arr = {1, 2, 4, 5};
    int k = 3;
    cout << minimumDifference(arr, k);

    return 0;
}