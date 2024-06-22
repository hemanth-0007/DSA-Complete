#include<bits/stdc++.h>
using namespace std;
vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
    int n = nums.size();
    vector<int> ind;
    for (int i = 0; i < n; i++) if(nums[i] == x) ind.push_back(i);
    vector<int> ans;
    for(auto q : queries){
        if(q > ind.size()) ans.push_back(-1);
        ans.push_back(ind[q-1]);
    }
    return ans;
}
int main()
{
    vector<int> nums = {1,3,1,7};
    vector<int> queries = {1,3,2,4};
    int x = 1;
    
return 0;
}