//subarray or subsequence of the array 
#include<bits/stdc++.h>
using namespace std;


 
 // To count the nuumber of the subsequences 
 // that sum upto k 
 

int printSub(int ind, vector<int> v, int s ,
int sum, int arr[], int n)
{
    if(ind >= n){ 
     if (sum == s) 
        return 1;
    
     else return 0;
    }
    v.push_back(arr[ind]);
    s+= arr[ind];
    int l = printSub(ind+1,v,s,sum, arr, n) ;
        
    s -= arr[ind];
    v.pop_back();
    
    int r = printSub(ind+1,v,s,sum, arr, n) ;
        
     
    return l + r;
}

int main()
{
    int arr[] = {2,8,6};
    int  n  = sizeof(arr)/sizeof(int);
    vector<int> vec;
 
    cout<<printSub(0,vec,0, 8, arr,n);

return 0;
}