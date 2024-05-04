//  In an N*N chess board return a possible way in which 
// 1. every row has a queen 
// 2. every column has a queen 
// 3. and the queens are not attacking

#include<bits/stdc++.h>
using namespace std;
 
void solve(int col, int n,vector<vector<string>> &ans, 
vector<string> &board ,vector<int> &rowArray,
vector<int> &upperDaigonal,vector<int> & lowerDaigonal){
    if(col == n ){
        ans.push_back(board);
         for (int i = 0; i < n; i++)
            cout<<board[i]<<endl;
    
  
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if(rowArray[row] == 0 && lowerDaigonal[row+col] ==0 &&
        upperDaigonal[n-1 + col-row] == 0){
            board[row][col] = 'Q';
            rowArray[row] = 1;
            lowerDaigonal[row+col]  = 1;
            upperDaigonal[n-1 + col-row] = 1;
            solve(col+1,n,ans, board , rowArray, upperDaigonal, lowerDaigonal);
            // backtraking that we need to be aware of 
            board[row][col] = '.';
            rowArray[row] = 0;
            lowerDaigonal[row+col]  = 0;
            upperDaigonal[n-1 + col-row] = 0;

        }
    }
    
}



vector<vector<string>> solveNQueens(int n){
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n,'.');
    for (int i = 0; i < n; i++)
        board[i] = s;
    
    vector<int> rowArray(n), upperDaigonal(2*n -1), lowerDaigonal(2*n -1);

    solve(0,n,ans, board , rowArray, upperDaigonal, lowerDaigonal);
  
    return ans;
    
}

 
  
int main()
{

    int n = 5;
    vector<vector<string>> ans = solveNQueens(n);

    return 0;
}