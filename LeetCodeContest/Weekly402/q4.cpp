#include<bits/stdc++.h>
using namespace std;


void updateInd(int i, vector<int> & nums, vector<int>& ones,
vector<int>& prefix, int n){
    if(nums[i-1] < nums[i] && nums[i] > nums[i+1]){
         ones[i] = 1;
         for (int ind = i; ind < n; ind++)
            prefix[ind]++;
    }
}
void updateOnes(int ind, vector<int> & nums, vector<int>& ones,
 vector<int>& prefix, int n){
    if(ind == 0) 
        updateInd(1, nums, ones, prefix, n);
    else if(ind == n-1) 
        updateInd(n-2, nums, ones, prefix, n);    
    else {
        updateInd(ind-1, nums, ones, prefix, n);
        updateInd(ind, nums, ones, prefix, n);
        updateInd(ind+1, nums, ones, prefix, n);
    }
}



vector<int> countOfPeaks(vector<int>& nums, 
vector<vector<int>>& queries) {
    int n = nums.size();
    vector<int> ones(n, 0), prefix(n , 0);
    for (int i = 1; i < n-1; i++)
        if(nums[i-1] < nums[i] && nums[i] > nums[i+1]) ones[i] = 1;
    for (int i = 0; i < n; i++) prefix[i] += (ones[i] + prefix[i]);
    // for (int i = 0; i < n; i++) cout<<ones[i]<<" "<<prefix[i]<<endl;
    for(auto it : queries){
        if(it[0] == 1){ 
            

        }
        else{

        }
    }
    
    return {};
}


int main()
{
    vector<int> nums = {3,1,4,2,5};
    vector<vector<int>> queries = {{2,3,4},{1,0,4}};
    vector<int> ans = countOfPeaks(nums, queries);
return 0;
}