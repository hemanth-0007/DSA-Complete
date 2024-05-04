#include <bits/stdc++.h>

using namespace std;

int main()
{ 
    // for minimum in array 
    int arr[] = {1,2,3,-4,54,6,7};
    int n = sizeof(arr)/sizeof(int);
    int min = INT_MAX;
     
    for (int i = 0; i < n; i++)
    {
      if (min > arr[i])
      {
        min = arr[i];
      }
      
    }
    cout<<"The minimum in the array is : "<<min;
    return 0;
}