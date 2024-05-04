#include<bits/stdc++.h>
using namespace std;
// kth smallest element using a queue
int main()
{
    int arr[] = {10, 50, 40, 75, 60, 65, 45};
    int n = sizeof(arr)/sizeof(int);
    int k = 4;
    priority_queue<int , vector<int> , greater<int>> pq;
     
    for (int i = 0; i < n; i++)
    {
        pq.push(arr[i]);
    }
    for (int j = 1; j < k; j++)
    {
        pq.pop();
    }

    cout<<pq.top();
    

    return 0;
}