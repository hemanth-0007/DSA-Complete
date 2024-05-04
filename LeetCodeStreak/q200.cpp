#include<bits/stdc++.h>
using namespace std;

void bfs(vector<vector<char>>& grid, int i, int j){
    cout<<"bfs"<<endl;
    int n = grid.size(), m = grid[0].size();
    queue<pair<int, int>> q;
    vector<pair<int,int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    q.push({i ,j});
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        grid[x][y] = '0';
        for(auto & dir : directions){
            int newX = x + dir.first;
            int newY = y + dir.second;
            if(newX >= 0 && newY >= 0 && newX < n && newY < m && grid[newX][newY] == '1'){
                q.push({newX, newY});
            }
        } 
    }
    
}

void dfs(vector<vector<char>>& grid, int x , int y ){
    int n = grid.size(), m = grid[0].size();
    grid[x][y] = '0';
    vector<pair<int,int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for(auto& dir : directions){
        int newX = x + dir.first;
        int newY = y + dir.second;
        if(newX >=0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == '1'){
            dfs(grid, newX, newY);
        }
    }
}

int numIslands(vector<vector<char>>& grid) {
    int n = grid.size(), m = grid[0].size();
    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m ; j++){
            if(grid[i][j] == '1'){
                dfs(grid, i, j);
                ans++;
            }
        }
    }
    return ans;
}


int main()
{
    vector<vector<char>> grid =  {{'1','1','0','1','0'},
                                   {'1','1','0','1','0'},
                                   {'1','1','0','0','0'},
                                   {'0','0','1','0','0'}};
    cout<<numIslands(grid);

return 0;
}