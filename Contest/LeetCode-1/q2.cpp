#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> divideArray(vector<int>& nums, int k) {
    vector<vector<int>> result;        
    vector<vector<int>> emptyMatrix;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for(int i = 1 ; i < n ; i += 3){
        if(abs(nums[i-1] - nums[i]) <= k && 
            abs(nums[i] - nums[i+1]) <= k && 
            abs(nums[i-1] - nums[i+1]) <= k)
            result.push_back({nums[i-1], nums[i], nums[i+1]});    
       
    }
    
    return result.size() == (n/3) ? result : emptyMatrix;
}

int main()
{
    vector<int> nums = {1,3,4,8,7,9,3,5,1};
    int k = 2;
    vector<vector<int>> result = divideArray(nums, k);
    for(auto vec : result){
        for(auto num : vec){
            cout<<num<<" ";
        }
        cout<<endl;
    }

return 0;
}

