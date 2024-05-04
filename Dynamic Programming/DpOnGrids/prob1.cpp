#include<bits/stdc++.h>
using namespace std;

int maxPathSum(vector<vector<int>> &vec, int i , int j ,
 vector<vector<int>>& visited){
    int n = vec.size(), m = vec[0].size();
    if(i == n-1 && j == m-1 ) return vec[i][j];
    if( i >= n || j >= m || visited[i][j]) return -1e9;
 

    int up = vec[i][j] + maxPathSum(vec, i-1 , j , visited);
    int left = vec[i][j] + maxPathSum(vec, i , j-1 , visited);
    int down = vec[i][j] + maxPathSum(vec, i , j+1 , visited);
    int right = vec[i][j] + maxPathSum(vec, i+1 , j , visited);

    return max(max(down , right),max(up, left) );
}



int main()
{
int n = 3;
int m = 3;
vector<vector<int>> vec = {  {5,100,2},
                             {200,8,11},
                             {3,2,7} };
int n = vec.size();
vector<vector<int>> vis( n , vector<int>(n ,0));

cout<<maxPathSum(vec, 0, 0, vis);
return 0;
}
 