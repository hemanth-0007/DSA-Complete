// Maximum Subarray
// (differs from subsequence as this subarray must
//  be contigous and in order) 
// sum in the array Brute force method

#include<bits/stdc++.h>
using namespace std;

int maxSubArraySum(vector<int> &vec){
    int maxi = -1e9;
    int n = vec.size();
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += vec[j];
            maxi = max(maxi, sum);
        }
        
    }
    return maxi;
    
}



int main()
{
    vector<int> vec = {1, 2, 3, -1, -3};
    cout<<maxSubArraySum(vec);


return 0;
}