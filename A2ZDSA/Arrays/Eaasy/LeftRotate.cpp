#include<bits/stdc++.h>
using namespace std;


void leftRotate(vector<int>& arr, int k){
    int n = arr.size();
    k = k%n;
    for (int i = 0; i < k; i++)
    {
        int firstNum = arr[0];
        for (int i = 0; i < n; i++)
        {
            arr[i] = arr[i+1];
        } 
        arr[n-1] = firstNum;
    }
    return;
}


void leftRotateOp(vector<int>& arr, int k){
    int n = arr.size();
    k = k%n;
    reverse(arr.begin(), arr.begin() + (n-k));
    reverse(arr.begin() + n-k, arr.end());
    reverse(arr.begin(), arr.end());
}

int main()
{
    vector<int> arr = {1,2, 3, 4};
    leftRotateOp(arr, 1);
    for(auto num: arr)cout<<num<<" ";

return 0;
}