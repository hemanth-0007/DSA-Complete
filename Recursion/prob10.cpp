// calculating the combinations that sum up to the required target using as many elements from the 
// array 

#include<bits/stdc++.h>
using namespace std;


class ComboSum{
    public:
        vector<int> arr = {2,3,4};// target =7 
        int n = arr.size();
        int target = 7;
        
        vector<vector<int>> ans;
        vector<int> ds;
        // O(2^t * k )
        void findCombination(int ind, int t){
            if(ind == n){
                if(t == 0){
                    ans.push_back(ds);
                }
                return;
            }
            if(arr[ind] <= t){
                ds.push_back(arr[ind]);
                findCombination(ind,t - arr[ind]);
                ds.pop_back();
            }
            findCombination(ind + 1 , t);
        }
        vector<vector<int>> combinationResult(){
                findCombination(0,target);
                return ans;
        }   
        
};




int main()
{
    ComboSum s;
    vector<vector<int>> ans = s.combinationResult();
    for(auto vec : ans){
        for(auto num : vec){
            cout<<num<<" ";
        }
        cout<<endl;
    }

return 0;
}