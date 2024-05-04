// calculating the combinations that sum up to the required target using only one element at a time from the 
// array 

#include<bits/stdc++.h>
using namespace std;


class ComboSum{
    public:
        vector<int> arr = {10,1,2,7,6,1,5};
        int n = arr.size();
        int target = 8;
        
        set<vector<int>> ans;
        vector<int> ds;
         
        void findCombination(int ind, int t){
            if(ind >= n){
                if(t == target){
                     sort(ds.begin(), ds.end());
                    ans.insert(ds);
                }
                return;
            }
             
                t += arr[ind];
                ds.push_back(arr[ind]);
                findCombination(ind+1,t);
                t -= arr[ind];
                ds.pop_back();
                findCombination(ind + 1 , t);
           
        }
        set<vector<int>> combinationResult(){
                findCombination(0,0);
                return ans;
        }   
        
};




int main()
{
    ComboSum s;
    set<vector<int>> ans = s.combinationResult();
    
    for(auto vec : ans){
        for(auto num : vec){
            cout<<num<<" ";
        }
        cout<<endl;
    }

return 0;
}