// Merging the intervals and returning out the minimum possible 
// vector of arrays 
// Optimal approach

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &grid){

    vector<vector<int>> ans;
    int n = grid.size();
    // O(n)
    for (int i = 0; i < n; i++)
    {
       if(ans.empty() || ans.back()[1] < grid[i][0]){
        ans.push_back(grid[i]);
       }
       else{
        ans.back()[1] = max(ans.back()[1], grid[i][1]);
       }
    }
    
    return ans;
}


void printVecOfVec(vector<vector<int>> &grid){
     for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[i].size(); j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
vector<vector<int>> grid = { {1, 3}, {2, 4}, {3, 5}, {6, 7}};
vector<vector<int>> ans =mergeOverlappingIntervals(grid);
printVecOfVec(ans);
return 0;
}