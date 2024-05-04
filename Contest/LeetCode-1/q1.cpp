

#include<bits/stdc++.h>
using namespace std;

vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
    int missingNum = 0, repeatedNum = 0;
    int n = grid.size(), sum = 0;
    unordered_set<int> st;
    for(int i = 0 ; i < grid.size() ; i++){
        for(int j = 0; j < grid[0].size(); j++){
            sum += grid[i][j];
            if(st.find(grid[i][j]) != st.end()){
                repeatedNum = grid[i][j];
            }
            else{
                st.insert(grid[i][j]);
            }
        }
    }
    n = n*n;// squaring
    missingNum = (n*(n+1)/2) - sum + repeatedNum; 
    cout<< (n*(n+1)/2)<<" "<<sum<<" "<<missingNum<<" "<<repeatedNum<<endl;
    vector<int> result;
    result.push_back(repeatedNum);
    result.push_back(missingNum);
    return result;
}
int main()
{
    vector<vector<int>> grid = {{1, 2, 3}, {4, 5, 6}, {7, 8, 8}};
    vector<int> result = findMissingAndRepeatedValues(grid);
    for(auto num : result) cout<<num<<" ";

return 0;
}