#include<bits/stdc++.h>
using namespace std;


int helper(int i, int j , int coins, int n , int k ,
 vector<vector<int>> & grid){
    
    // base
    if(i<0 || j<0 ) return 0;
    if(i == 0 && j == 0){
        cout<<coins<<" "<<k<<endl;
        if(coins == k) return 1;
        else return 0;
    }

    // main
    int top = helper(i-1, j, coins + grid[i][j], n , k , grid);
    int left = helper(i, j-1, coins + grid[i][j], n , k , grid);
    return left + top;
}


long long numberOfPath(int n, int k, vector<vector<int>> &arr){
        return helper(n-1,n-1,0, n , k , arr);
}
int main()
{
    int k = 12, n = 3;
    vector<vector<int>> arr = {{1, 2, 3}, 
                                {4, 6, 5}, 
                                {3, 2, 1}};
    cout<<numberOfPath(n , k , arr);

return 0;
}