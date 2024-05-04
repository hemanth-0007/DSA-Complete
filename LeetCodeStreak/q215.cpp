#include<bits/stdc++.h>
using namespace std;
// O(N*log(K))
int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++) pq.push(nums[i]);
    for (int j = k; j < n; j++)
    {
        if(pq.top() < nums[j]){
            pq.pop();
            pq.push(nums[j]);
        }
    }
    return pq.top();
}


int main()
{
    vector<int> nums = {3,2,1,5,6,4};
    int k = 2;
    cout<<findKthLargest(nums, k);
    return 0;
}