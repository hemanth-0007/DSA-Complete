#include<bits/stdc++.h>
using namespace std;

bool isPerfectSquare(long long N){
    if(N < 0) return false;
    long long sqRoot = sqrt(N);
    return sqRoot*sqRoot == N ? true : false;
}

int minOperationsToPerfectSquare(int n) {
    if (n <= 0) {
        return -1; // Invalid input, return -1
    }

    int nextSquare = ceil(sqrt(n)); // Nearest perfect square greater than n
    int prevSquare = floor(sqrt(n)); // Nearest perfect square less than n

    int diffNext = nextSquare * nextSquare - n; // Difference between next square and n
    int diffPrev = n - prevSquare * prevSquare; // Difference between n and previous square

    return std::min(diffNext, diffPrev); // Return the minimum difference
}

long long equalize(vector<int> & nums){
    int n = nums.size(), count = 0;
    long long ans = 0;
    priority_queue<int , vector<int> , greater<int>> pq;
    for(auto num : nums){
        int minOp = minOperationsToPerfectSquare(num);
        cout<<num<<" "<<minOp<<endl;
        pq.push(minOp);
    }
    for (int i = 0; i < n/2; i++)
    {
        ans += pq.top();
        pq.pop();
    }
    return ans;
}




int main()
{
    vector<int> nums = {2, 2, 3, 4, 5};
    // ans is 2
    cout << equalize(nums) << endl;

return 0;
}