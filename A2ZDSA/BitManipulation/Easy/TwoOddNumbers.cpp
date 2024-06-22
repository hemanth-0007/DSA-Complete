#include <bits/stdc++.h>
using namespace std;

vector<long long int> twoOddNum(long long int Arr[], long long int N)
{
    long long int xored = 0;
    for (int i = 0; i < N; i++)
    {
        xored ^= Arr[i];
    }
    long long int set_bit = (xored & (xored - 1)) ^ xored;
    long long int bucket_1 = 0, bucket_2 = 0;
    for (int i = 0; i < N; i++)
    {
        if ((set_bit & Arr[i]) > 0)
        {
            bucket_1 ^= Arr[i];
        }
        else
        {
            bucket_2 ^= Arr[i];
        }
    }
    if (bucket_1 > bucket_2)
        return {bucket_1, bucket_2};
    return {bucket_2, bucket_1};
}

int main()
{
    long long int arr[] = {1, 2, 2, 3, 3, 4};
    long long int n = sizeof(arr) / sizeof(long long int);
    vector<long long int> nums = twoOddNum(arr, n);
    cout << nums[0] << " " << nums[1] << endl;

    return 0;
}