#include<bits/stdc++.h>
using namespace std;

void solve( vector<vector<int>>& ans, int i , int j){

  int n = ans.size();// no of rows 
  int m = ans[i].size();// no of cols
  for (int x = 0; x < m; x++)
  {
    ans[i][x] = 0 ;
  }
  for (int y = 0; y < n; y++)
  {
    ans[y][j] = 0 ;
  }
  
}
// tc - O(n^3) 
// sc - O(n^2) 
vector<vector<int>> rowColZero(vector<vector<int>> &vec, vector<vector<int>> &ans){
    
    
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            if(vec[i][j] == 0){
                solve(ans, i, j);
            }
        }
        
    }
 return ans;
 
}


int main()
{
vector<vector<int>> vec = { {0,12,3},
                            {1,2,4},
                            {9,76,0}
                            };

vector<vector<int>> ans(vec);

 ans = rowColZero(vec , ans);
 for(auto itr : ans){
    for(auto it : itr){
        cout<<it<<" ";  
    }
    cout<<endl;
 }
 
return 0;
}