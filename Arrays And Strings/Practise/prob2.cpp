#include <bits/stdc++.h>
using namespace std;
// getting the wave of a sorted array
void convertToWave(int n, vector<int> &arr)
{

    for (int i = 0; i < n - 1; i++)
    {
        if (i % 2 == 0)
        {

            int temp2 = arr[i];
            int temp1 = arr[i + 1];

            arr[i + 1] = temp2;
            arr[i] = temp1;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];
    convertToWave(n, vec);
    for (int i = 0; i < n; i++)
        cout << vec[i];
    return 0;
}