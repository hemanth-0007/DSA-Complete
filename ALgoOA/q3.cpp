#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to compute LIS
int computeLIS(const vector<int>& seq) {
    vector<int> lis;
    for (int num : seq) {
        auto it = lower_bound(lis.begin(), lis.end(), num);
        if (it == lis.end()) {
            lis.push_back(num);
        } else {
            *it = num;
        }
    }
    return lis.size();
}

int findLongestIncreasingSubsequence(vector<int>& seq) {
    int n = seq.size();
    if (n == 0) return 0;

    // Compute LIS from left to right
    vector<int> leftLIS(n, 0);
    vector<int> lis;
    for (int i = 0; i < n; ++i) {
        auto it = lower_bound(lis.begin(), lis.end(), seq[i]);
        if (it == lis.end()) {
            lis.push_back(seq[i]);
        } else {
            *it = seq[i];
        }
        leftLIS[i] = lis.size();
    }

    // Compute LIS from right to left
    vector<int> rightLIS(n, 0);
    lis.clear();
    for (int i = n - 1; i >= 0; --i) {
        auto it = lower_bound(lis.begin(), lis.end(), seq[i]);
        if (it == lis.end()) {
            lis.push_back(seq[i]);
        } else {
            *it = seq[i];
        }
        rightLIS[i] = lis.size();
    }

    // Find the maximum LIS possible by reversing a subsequence
    int maxLIS = 0;
    for (int i = 0; i < n; ++i) {
        maxLIS = max(maxLIS, leftLIS[i] + rightLIS[i] - 1);
    }

    return maxLIS;
}

int main() {
    // vector<int> seq = {1, 9, 3, 10, 4, 20, 2};
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    // vector<int> arr = {7, 7, 6};
    cout << findLongestIncreasingSubsequence(arr) +1<< endl;
    return 0;
}