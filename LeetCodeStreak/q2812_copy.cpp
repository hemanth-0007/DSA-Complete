#include <bits/stdc++.h>
using namespace std;



void printMat(vector<vector<int>> & grid){
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
    return;
}



vector<int> dx = {1, 0, 0 ,- 1};
vector<int> dy = {0, 1, -1, 0};


 
void bfs(vector<vector<int>>& grid, vector<vector<int>>& score, int n){
    queue<pair<int,int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(grid[i][j]){
                q.push({i,j});
                score[i][j] = 0;
            }
        }
    }

    while (!q.empty())
    {
        int x = q.front().first, y = q.front().second;
        // cout<<x<< " "<<y<<endl;
        q.pop();
        int s = score[x][y];
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i] , newY = y + dy[i];
            // cout<<"\t"<<newX<< " "<< newY<<endl;
            if(newX >= 0 && newX < n && newY >= 0 && newY < n && score[newX][newY] > 1 + s){
                score[newX][newY] = 1 + s;
                q.push({newX, newY});
            }
        }
        
    }
    return;
}
 
int maximumSafenessFactor(vector<vector<int>> &grid)
{
    int n = grid.size();
    vector<vector<int>> score(n , vector<int>(n , 1e9));

    bfs(grid, score, n);
    // printMat(grid);
    // cout<<endl;
    // printMat(score);
    // applying the dikstras
    priority_queue<pair<int,pair<int,int>>> q;
    q.push({score[0][0], {0,0}});
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    while (!q.empty())
    {
        auto temp = q.top().second;
        int s = q.top().first;
        q.pop();
        int x = temp.first, y = temp.second;
        if( x == n-1 && y == n-1 ) return s;

        visited[x][y] = true;
        for (int i = 0; i < 4; i++)
        {
            int newX = temp.first + dx[i], newY = temp.second + dy[i];
            if(newX >= 0 && newX < n && newY >= 0 && newY < n && !visited[newX][newY]){
                int p = min(s, score[newX][newY]);
                q.push({p, {newX, newY}});
                visited[newX][newY] = true;
            }
        }
    }

    return 0;
    
}



int main()
{
   vector<vector<int>>  grid = {{0,0,1},{0,0,0},{0,0,0}};
    cout<<maximumSafenessFactor(grid);
    return 0;
}