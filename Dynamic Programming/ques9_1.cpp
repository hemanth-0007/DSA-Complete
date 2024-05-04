// if each cell of the grid has some positive integers then 
// we have to return the MAXIMUM path sum
// 1 2 10 9
// 100 3 2 1 
// 1 1 20 2
// 1 2 2 1
// possible movements down and daigonally down-right and down-left 
#include<bits/stdc++.h>
using namespace std;
// since all three recursive funtions are called for each and every functuiuon
//O(3^(n)) is the time complexity
int f(int i , int j, vector<vector<int>> vec){
    if(i == 0 ) return vec[0][j];
    if(j < 0 || j >= vec[0].size() ) return -1e9;
    
    int down = vec[i][j] + f(i-1, j ,vec);
    int dgRight = vec[i][j] + f(i-1, j+1 ,vec);
    int dgLeft = vec[i][j] + f(i-1, j-1 ,vec);

    return max(down , max(dgRight, dgLeft));
}



int maxPathSum(vector<vector<int>> &vec, int i , int j ){
    int n = vec.size();
    int m = vec[0].size();
    int maxi = -1e9;
    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi , f(n-1,i,vec));
    
    }
    return maxi;
    
}



int main()
{
 

vector<vector<int>> vec = { {1, 2, 10, 9},
                            {100, 3, 2, 1},
                            {1, 1, 20, 2},
                            {1, 2, 2, 1} };
 

cout<<maxPathSum(vec,0 ,0);


return 0;
}
 