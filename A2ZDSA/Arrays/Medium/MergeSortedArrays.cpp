#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int left = m-1, right = 0;
    while (left >=0 && right < n && nums1[left] > nums2[right] ){
        swap(nums1[left], nums2[right]);
        left--;
        right++;
    }
    sort(nums1.begin(), nums1.begin() + m);
    sort(nums2.begin(), nums2.end());
    for (int i = m; i < m+n; i++)
        nums1[i] = nums2[i-m];
}

int main()
{

    return 0;
}