// printing the subsets 

#include <bits/stdc++.h>
using namespace std;

// O(2^n * k) k == avg length
class ComboSum
{
public:
    vector<int> arr = {1, 2, 2};
    int n = arr.size();
  
    vector<vector<int>> ans;
   

    void findCombination(int ind, vector<int>& ds)
    {   
        ans.push_back(ds);
        for (int i = ind; i < n; i++)
        {
            if (i != ind && arr[i] == arr[i - 1])
                continue;
            ds.push_back(arr[i]);
            findCombination(ind + 1,ds);
            ds.pop_back();
        }
    }
     void combinationResult(vector<int>& ds)
    {
        sort(arr.begin(), arr.end());
        findCombination(0,ds);
      
    }
};

int main()
{
    ComboSum s;
     vector<int> ds;
    s.combinationResult(ds);

    for (auto vec : s.ans)
    {
       for(auto num : vec){
        cout<<num<<" ";
       }
       cout<<endl;
    }

    return 0;
}