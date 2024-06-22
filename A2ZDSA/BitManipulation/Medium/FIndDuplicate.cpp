#include<bits/stdc++.h>
using namespace std;


// pigeon hole principle O(nlogn) time complexity
int duplicate_bs(vector<int>& arr){
    int n = arr.size();
    int left = 0, right = n-1;
    while (left < right)
    {
        int mid = left + (right - left)/2;
        int cnt = 0;
        for (int i = 0; i < n; i++)
            if(arr[i] <= mid) cnt++;
        if(cnt <= mid) left = mid + 1;
        else right = mid; 
    }

    return left;
}


int main()
{
    vector<int> arr = {1,2 ,3, 3};
    cout<<duplicate_bs(arr);

return 0;
}