#include<bits/stdc++.h>

using namespace std;

int second_largest(vector<int>& arr){
    int n = arr.size();
    int largest = arr[0], second_largest = arr[0];
    for (int i = 1; i < n; i++)
    {
        if(largest < arr[i]){
            second_largest = largest;
            largest = arr[i];
        }
        else if(second_largest < arr[i] && arr[i] != largest){
            second_largest = arr[i];
        }
    }
    return second_largest;
}




int main()
{
    vector<int> arr = {4, 2, 3, 9 , -1};
    cout<<second_largest(arr);

return 0;
}