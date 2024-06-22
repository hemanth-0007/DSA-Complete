#include<bits/stdc++.h>
using namespace std;

long long subArrayRanges(vector<int>& arr) {
    int n = arr.size();
    long long ans = 0;
    int maxi = -1e9, mini = 1e9;
    for (int i = 0; i < n; i++)
    {
        maxi = arr[i];
        mini = arr[i];
        for (int j = i; j < n; j++)
        {
            maxi = max(maxi , arr[j]);
            mini = min(mini , arr[j]);
            ans += static_cast<long long>(abs(maxi - mini));
        }
        
    }
    return ans;     
}


int main()
{
    vector<int> arr= {1,2, 3};
    cout<<subArrayRanges(arr)<<endl;

return 0;
}