#include<bits/stdc++.h>
using namespace std;

int numSubarrayLessThanK(vector<int> & nums, int k){
    int n = nums.size();
    int ans = 0, mul = 1, lastInd = 0;
    queue<int> q;
    int i = 0;
    for (int i = 0; i < n; i++)
    {
        while(mul < k){
            mul = mul*nums[i];
            q.push(nums[i]);
            i++;
        }
        int var = (i - lastInd + 1);
        ans +=  var*(var + 1)/2;
        
    }
    
    return ans;
}


int main()
{

return 0;
}