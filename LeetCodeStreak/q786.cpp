#include<bits/stdc++.h>
using namespace std;

vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
    int n  = arr.size();
    double left = 0, right = 1, mid;
    vector<int> res;
    while(left < right){
        mid = left + (right - left)/2;
        int j = 1, startInd = 0, endInd = 0, total = 0;
        double maxFrac = 0;
        for (int i = 0; i < n; ++i)
        {
            cout<<i<<endl;
            while( j < n && arr[i] >= arr[j]*mid) ++j;
            total += (n - j);
            if(j < n && maxFrac < arr[i]*1.0/arr[j]){
                maxFrac = arr[i]*1.0/arr[j];
                startInd = i; endInd = j;
            }
        }
        if(total == k){
            res = {arr[startInd], arr[endInd]};
            break;
        }
        if(total > k) right = mid;
        else left = mid;
    }    
    return res;    
}


vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {

}




int main()
{
    vector<int> arr = {1,2,3,5};
    int k = 3;
    vector<int> res =  kthSmallestPrimeFraction(arr, k);
    cout<<res[0]<<" "<<res[1]<<endl;
return 0;
}