#include <bits/stdc++.h>
using namespace std;

// maximum subarray sum
int kadanes(vector<int> &arr)
{
    int n = arr.size();
    int maxi = -1e9;
    int sum = 0;
    int start = -1, startInd = -1, endInd = -1;
    for (int i = 0; i < n; i++)
    {
        if(sum == 0) start = i;
        sum += arr[i];
        if (sum > maxi){
            maxi = max(maxi, sum);

            startInd = start;
            endInd = i;
        }
        if (sum < 0)
            sum = 0;
    }
    cout<<startInd<<" "<<endInd<<endl;
    return maxi;
}

int main()
{
    vector<int> arr = {-1, 0, 3, -2, 3};
    cout << kadanes(arr);

    return 0;
}