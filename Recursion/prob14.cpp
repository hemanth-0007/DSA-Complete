// Printing all the permutations of a string or a array 
#include<bits/stdc++.h>
using namespace std;
// O(n! * N) --> Time Complexity 
void recurrenceCall(vector<int> nums ,int n ,vector<int> &ds ,
 vector<vector<int>> &ans,int freq[]){

    if(ds.size() == n){
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if(freq[i] == 0){
            ds.push_back(nums[i]);
            freq[i] = 1;
            recurrenceCall(nums , n , ds , ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
        
    }
    
 }



vector<vector<int>> getPermutations(vector<int> nums, int n){
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[n];
    for(int i = 0; i< n ; i++)freq[i] = 0;
    recurrenceCall(nums , n , ds , ans, freq);
    return ans;
}

int main()
{

    vector<int> nums = {1,2,3};
    int n = nums.size();
    vector<vector<int>> v = getPermutations(nums, n);

    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
        
    }
    
return 0;
}