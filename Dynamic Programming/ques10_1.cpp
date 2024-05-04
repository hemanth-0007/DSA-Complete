//Maximum no of chocolates question 

#include<bits/stdc++.h>
using namespace std;

int f(int i , int j1, int j2, int r ,int c, vector<vector<int>> &grid  ){
    if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c)  return -1e8;
    if(i == r-1){
        if(j1==j2)  return grid[i][j1];
        else return grid[i][j1] + grid[i][j2];
    }


    int maxi = -1e8;
    for (int dj1 = -1; dj1 <=  1; dj1++)
    {
        for (int dj2 = -1; dj2 <=  1; dj2++)
        {
            int value = 0;
            if(j1 == j2) value = grid[i][j1];
            else value = grid[i][j1] + grid[i][j2];
            value += f(i+1, j1 + dj1, j2 + dj2 , r,c,grid);
            maxi = max(maxi , value);
        }
        
    }
    return maxi;
    

}

int maximumChocolates(int r, int c, vector<vector<int>> &grid ){
    return f(0,0,c-1, r,c, grid);
}











int main()
{
vector<vector<int>> grid = {
    {1,2,3,4},
    {3,4,7,9},
    {9,43,2,1}
};
int r = grid.size();
int c = grid[0].size();

cout<<maximumChocolates(r, c, grid);
return 0;
}