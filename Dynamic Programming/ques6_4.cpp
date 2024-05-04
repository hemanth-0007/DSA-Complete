// Counting the number of ways to reach a bottom right point from top left 
// suppose we have an n * m array
// using basic recursion but in the grid if the value is -1 it is dead cell so
//one cannot go through it 0 means one can go through it
#include<bits/stdc++.h>
using namespace std;

int noOfWays(vector<vector<int>> &vec, int i , int j ){
    if( i < 0 || j < 0) return 0;
    if(i >= 0 && j >= 0 && vec[i][j] == -1) return 0;
    if(i ==0 && j ==0 ) return 1;

    int upStep = noOfWays(vec, i  , j-1 );
    int leftStep = noOfWays(vec, i-1 , j );

    return upStep + leftStep;
}



int main()
{
int n = 3;
int m = 3;
vector<vector<int>> vec = {  {0,0,0},
                             {0,-1,0},
                             {0,0,0} };
cout<<noOfWays(vec, n-1, m-1);
return 0;
}
 