#include<bits/stdc++.h>
using namespace std;

int findExtra(int n, int arr1[], int arr2[]) {
    int left = 0, right = n;
    while(left < right){
        int mid = left + (right - left)/2;
        if(arr1[mid] == arr2[mid]) left = mid + 1;
        else right = mid;
    }   
    return right;    
}

int main()
{
   int  n = 7;
   int arr1[] = {2,4,6,8,9,10,12};
   int arr2[] = {2,4,6,8,10,12};
   cout<<findExtra(n , arr1 ,arr2);
return 0;
}