//subarray or subsequence of the array 
#include<bits/stdc++.h>
using namespace std;


 
 // technique to check it the subsequence with req sum exits or not
 // *** must remember technique

bool printSub(int ind, vector<int> ds , int s , 
int sum, int arr[], int n)
{
    if(ind >= n){ 
     if (sum == s){
        // This for loop is optional just for knowing which subarray are we considering
        for(auto n : ds){
            cout<<n<<" ";
        }
        return true;
     }
     else 
        return false;
    }
   
    ds.push_back(arr[ind]);
    s+= arr[ind];
    if(printSub(ind+1,ds, s, sum, arr, n) == true) return true;
       
    s -= arr[ind];
    ds.pop_back();
    
    if(printSub(ind+1,ds, s, sum, arr, n) == true) return true;
     
    
    return false;
}

int main()
{
    int arr[] = {2,8,6};
    int  n  = sizeof(arr)/sizeof(int);
    vector<int> vec;
 
    printSub(0,vec,0, 8, arr,n);

return 0;
}