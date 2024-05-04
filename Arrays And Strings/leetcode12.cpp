#include<bits/stdc++.h>
using namespace std;

int onesRowF(vector<vector<int>>& grid, int x ){
        int count = 0;
        for(int j = 0; j < grid[0].size(); j++){
                if(grid[x][j] == 1){
                count++;
                }
        }
        return count;
        
}


int onesColF(vector<vector<int>>& grid, int y ){
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
                if(grid[i][y] == 1){
                count++;
                }
        }
        return count;
        
}
vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> diff(n , vector<int>(m ,0));
        vector<int> onesRow(n, 0), onesCol(m, 0);
        for(int i = 0 ; i < n ;i++) onesRow[i] = onesRowF(grid, i);
        for(int i = 0 ; i < m ;i++) onesCol[i] = onesColF(grid, i);
        for(int i = 0; i < n; i++){
                for(int j = 0; j < m; j++){
                  diff[i][j] = 2*(onesRow[i] + onesCol[j]) - (n + m);
                }
        }
        return diff;
}


int main()
{
        vector<vector<int>> grid = {{0,1,1},{1,0,1},{0,0,1}};
        vector<vector<int>> diff = onesMinusZeros(grid);
        for(int i = 0; i < diff.size(); i++){
                for(int j = 0; j < diff[0].size(); j++){
                        cout << diff[i][j] << " ";
                }
                cout << endl;
        }

return 0;
}