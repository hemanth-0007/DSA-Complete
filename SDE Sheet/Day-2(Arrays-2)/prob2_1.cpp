// Merging the intervals and returning out the minimum possible 
// vector of arrays 
// Brute force approach

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &grid){

    vector<vector<int>> ans;
    int n = grid.size();
    for (int i = 0; i < n; i++)
    {
        int first = grid[i][0];
        int second = grid[i][1];
        if(!ans.empty() && second <= ans.back()[1])
        continue;
        for(int j = i+1; j < n ; j++){
            if(grid[j][0] <= second)
                second = max(second,grid[j][1] );
            else 
                break;
        }
        ans.push_back({first, second});
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