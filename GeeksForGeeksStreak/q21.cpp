#include<bits/stdc++.h>
using namespace std;

bool isMaxHeapify(int ind, int arr[], int n){
    // left child index 2*ind +1, 
    // right child index 2*ind + 2
    int leftInd = 2*ind + 1, rightInd = 2*ind + 2;
    if(rightInd < n && leftInd >= n){
        if(arr[rightInd] < arr[ind])
            return true;
        else return false;
    }
    else if(rightInd >= n && leftInd < n){
        if(arr[leftInd] < arr[ind])
            return true;
        else return false;
    }
    else if(rightInd < n && leftInd < n){
        if(arr[leftInd] < arr[ind] && arr[rightInd] < arr[ind])
            return true;
        else return false;
    }
    return false;
}

bool isMaxHeap(int arr[], int n)
{
    for (int i = (n/2)-1; i >= 0 ; i--)
    {
        if(!isMaxHeapify(i, arr, n)) return false;
        // cout<<i<<endl;
    }
    return true;
}
int main()
{
    int arr[] = {90 ,15, 10, 7, 12 ,2};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (isMaxHeap(arr, n))
        cout << "Given array is a max heap";
    else
        cout << "Given array is not a max heap";

    return 0;
}
   