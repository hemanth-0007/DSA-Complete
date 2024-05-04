//subarray or subsequence of the array 
// sum of them in the lexicographical order 
#include<bits/stdc++.h>
using namespace std;

void getArrayofSums(vector<int> arr , int n , 
int ind, int sum)
{
    if(ind >= n){ 
        // simply add this sums to a set and print them 
       cout<<sum<<endl;
        return;
    }
    sum += arr[ind];
    getArrayofSums(arr, n, ind +1, sum);
    sum -= arr[ind];
    getArrayofSums(arr,n , ind+1 , sum);
}
 
int main()
{
    vector<int> v = {7,8,9};
    int n = v.size();
    getArrayofSums(v,n, 0 , 0);
 

return 0;
}