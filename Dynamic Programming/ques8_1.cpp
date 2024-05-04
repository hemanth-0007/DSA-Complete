// if each cell of the grid has some positive integers then 
// we have to return the minimum path sum
// 1
// 2 3 
// 9 2 6
// 3 1 9 7
// possibel movements down and daigonally down-right 
#include<bits/stdc++.h>
using namespace std;

int minPathSum(vector<vector<int>> &vec, int i , int j ){
    if(i == vec.size() -1 ) return vec[i][j];
    
    int down = vec[i][j] + minPathSum(vec, i+1 , j );
    int daigonal = vec[i][j] + minPathSum(vec, i+1 , j+1 );

    return min(down , daigonal);
}



int main()
{
 

vector<vector<int>> vec = { {1},
                            {2, 3 },
                            {9, 2, 6},
                            {3, 1 ,9 ,7} };
 

 
cout<<minPathSum(vec,0 ,0);


return 0;
}
 