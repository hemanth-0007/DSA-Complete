#include<bits/stdc++.h>
using namespace std;

  int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int op = 0, prev = nums[0];
        for(int i = 1; i < n ; i++){
            int num = nums[i];
            if(prev >= nums[i]){
                num = (prev + 1);
                op += (prev - nums[i] + 1);
            }
            prev = num;
        }
        return op;
    }

int main()
{
    vector<int> nums = {3,2,1,2,1,7};
    cout << minIncrementForUnique(nums) << endl;
return 0;
}