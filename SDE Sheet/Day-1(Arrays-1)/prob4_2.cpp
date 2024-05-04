// Maximum Subarray
// (differs from subsequence as this subarray must
//  be contigous and in order) 
// sum in the array
// Optimal Approach(Kadane's ALgorithm)

#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int> &vec){
    int maxi = -1e9;
    int n = vec.size();
    int sum = 0;
    //O(n) tc
    for (int i = 0; i < n; i++)
    {
        sum += vec[i];
        if(sum > maxi)  maxi = sum;
        if(sum < 0) sum = 0;
        // To consider the sum of the empty subarray
        // uncomment the following check:
        //if (maxi < 0) maxi = 0;
    }
    return maxi;
    
}



int main()
{
    vector<int> vec = {-8, -2, -1, -3};
    cout<<maxSubArraySum(vec);


return 0;
}