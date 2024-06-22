#include<bits/stdc++.h>
using namespace std;


int guessMax(vector<int>& arr, int n ){
    int maxi = -1;
    int mini = 1e9;
    for (int i = 1; i < n; i++)
    {
        int curMax = max(arr[i], arr[i-1]);
        mini = min(curMax, mini);
    }
    return mini-1;
}


int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }
        cout<<guessMax(arr, n)<<endl;
    }
    

return 0;
}

// 6
// 4
// 2 4 1 7
// 5
// 1 2 3 4 5
// 2
// 1 1
// 3
// 37 8 16
// 5
// 10 10 10 10 9
// 10
// 3 12 9 5 2 3 2 9 8 2
