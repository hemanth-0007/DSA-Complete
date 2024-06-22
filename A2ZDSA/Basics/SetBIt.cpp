#include <bits/stdc++.h>
using namespace std;

long long sumDigitDifferences(vector<int> &arr)
{
    int n = arr.size();
    long long ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            string s1 = to_string(arr[i]);
            string s2 = to_string(arr[j]);
            long long sum = 0;
            cout << s1 << " " << s2 << endl;
            for (int k = 0; k < s1.size(); k++){
                sum += abs(s1[k] - s2[k]);
                cout << sum << endl;
            }
            ans += sum;
        }
    }
    return ans;
}

int main()
{
  vector<int> nums = {13,23,12};
    cout << sumDigitDifferences(nums) << endl;
}