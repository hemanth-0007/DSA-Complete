#include<iostream>
#include<numeric> // For iota()
#include<algorithm>
using namespace std;


void show(int a[], int array_size)
{
    for (int i = 0; i < array_size; ++i)
        cout << a[i] << " ";
}

// Array Methods all_of, any_of , none_of
//copy_n(start address, n , destination start address or different array)
int main()
{
  int arr[] = {1,2,3,4,5,6};
  
  int n = sizeof(arr)/sizeof(int);
  int arr2[n];
          // all_of(arr, arr+n, [](int x) { return x>0; })?
          // cout << "All are positive elements" :
          // cout << "All are not positive elements";

          // any_of(arr, arr+n, [](int x) { return x<0; })?
          // cout << "There exist one negative number" :
          // cout << "There is no Negative number";

        //   none_of(arr, arr+n ,[](int x){return x<0;})?
        //   cout << "Array of positive Integers" :
        //   cout << "Not an Array of Poistive Integers";

          // This returns 1 if none of the aray elements pases the given test 

        copy_n(arr,n,arr2);
        // Or we Can use iota fucntion to have the continuos values
        // iota(arr,arr+n,20);
        show(arr,n);cout<<endl;
        show(arr2,n);

        

return 0;
}