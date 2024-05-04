// Counting the number of ways to reach a bottom right point from top left 
// suppose we have an n * m array
// if each cell of the grid has some positive integers then 
// we have to return the minimum path sum
// space optimization method
#include<bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>> &vec, int i , int j ){
    if(i ==0 && j ==0 ) return vec[i][j];
    if( i < 0 || j < 0) return 1e9;
 

    int upStep = vec[i][j] + minPathSum(vec, i , j-1 );
    int leftStep = vec[i][j] + minPathSum(vec, i-1 , j );

    return min(upStep , leftStep);
}



int main()
{
int n = 3;
int m = 3;
vector<vector<int>> vec = {  {5,1,2},
                             {1,8,100},
                             {3,2,7} };
  // O(n) is the space complexity now 
  vector<int> dp(n , 0);
  vector<int> temp(n , 0);

for (int i = 0; i < m; i++)
{
    for (int j = 0; j < n; j++)
    {
        int leftStep = 1e9 , upStep = 1e9;
        if(i ==0 && j ==0 )
            temp[j] = vec[i][j];
        else{
            if(i > 0)
                leftStep = vec[i][j] + dp[j];
            if(j > 0)
                upStep = vec[i][j] + temp[j-1];
            temp[j] = min(leftStep, upStep);
        }
    }
    dp = temp;
    
}
cout<<dp[n-1];


return 0;
}
 