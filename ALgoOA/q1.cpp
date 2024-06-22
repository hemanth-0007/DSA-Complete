// You are given a binary array a
//  of length n
//  (1≤n≤106)
//  consisting of either 0
//  or 1
// . You can carry out an operation (only once), where you convert any 1 to 0. You need to find the maximum count of subarrays having atleast one 0, after carrying out the operation.

// Input
// The first line of input consists of a single integer n
//  −
//  the total number of elements in the binary array. The second line of input consists of n
//  space separated integers - either 0 or 1 - where the ith
//  integer denotes the ith
//  element of the binary array.

// Output
// Output a single integer - the maximum total count of all subarrays which consist of atleast one 0, after carrying out the operation.

 
#include <bits/stdc++.h>
using namespace std;

int countSubbaryWithAtleastOneZero(int n , vector<int> & arr){
    int cnt = 0;
    
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == 0) cnt += (i + 1);
    }
    return cnt;
}


int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int maxi = -1e9;
    for (int i = 0; i < n; i++)
    {
        if(a[i] == 1) {
            a[i] = 0;
            maxi = max(maxi, countSubbaryWithAtleastOneZero(n, a));
            a[i] = 1;   
        }
    }
    maxi = max(maxi, countSubbaryWithAtleastOneZero(n, a));
    cout<<maxi<<endl;
    
    return 0;
}