#include<bits/stdc++.h>
using namespace std;
 int minimumOperations(int n, vector<int> &arr, int p, int q) {
         priority_queue<int> pq;
         for(auto x : arr) pq.push(x);
         int op = 0;
         while(!pq.empty()){
             int t = pq.top();
             if(t - op*q <= 0) return op; 
             t = t - op*q;
             cout<<"t is "<<t<<endl;
             int y;
             if(t%p == 0) y = t/p;
             else y = floor(t/p) + 1;
             cout<<"y is "<<y<<endl;
             op += y;
             pq.pop();
         }
         return op;
    }
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int p , q;
    cin>>p>>q;
    cout<<minimumOperations(n, arr, p , q);
    

return 0;
}