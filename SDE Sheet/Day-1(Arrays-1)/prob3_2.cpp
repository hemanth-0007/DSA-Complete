// Finding the next permutation in for the given array
// Using the permutations concept
 
#include<bits/stdc++.h>
using namespace std;
// O(n! * N) --> Time Complexity 

void print(vector<int> nums){
    for(auto n : nums){
        cout<<n<<" ";
    }
    cout<<endl;
}
void getPermutations(vector<vector<int>> &ans,vector<int> &nums, int n ,int pt){
        if(pt == n){
            ans.push_back(nums);
            return;
        }
        for (int i = pt; i < n; i++)
        {
            swap(nums[pt], nums[i]);
            getPermutations(ans, nums, n , pt+1);
            swap(nums[pt], nums[i]);
        }
        
 }
  
int main()
{

    vector<int> nums = {2,1,4,3};
    int n = nums.size();
    vector<vector<int>> ans;
    getPermutations(ans,nums, n, 0);
    sort(ans.begin(), ans.end());
    for(auto vec : ans){
        if(vec <= nums)
            continue;
        print(vec);
        break;
    }
        

    return 0;
}