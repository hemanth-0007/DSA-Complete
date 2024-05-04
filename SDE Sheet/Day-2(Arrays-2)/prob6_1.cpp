// Getting the Number of inversions in an array 
#include<bits/stdc++.h>
using namespace std;
//O(n^2)
int noOfInversions(vector<int> &nums){

    int n = nums.size();
    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(nums[j] < nums[i]){
                cnt++;
            }
        }
        
    }
    return cnt;
}


int main()
{
    vector<int> nums= {1,2,3,4,5};
    cout<<noOfInversions(nums);

return 0;
}