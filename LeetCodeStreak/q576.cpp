#include <bits/stdc++.h>
using namespace std;

int findPaths(int m, int n, int N, int x, int y)
{
        const int M = 1000000000 + 7;
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[x][y] = 1;
        int count = 0;

        for (int moves = 1; moves <= N; moves++)
        {
                vector<vector<int>> temp(m, vector<int>(n, 0));

                for (int i = 0; i < m; i++)
                {
                        for (int j = 0; j < n; j++)
                        {
                                if (i == m - 1)
                                        count = (count + dp[i][j]) % M;
                                if (j == n - 1)
                                        count = (count + dp[i][j]) % M;
                                if (i == 0)
                                        count = (count + dp[i][j]) % M;
                                if (j == 0)
                                        count = (count + dp[i][j]) % M;
                                temp[i][j] = (((i > 0 ? dp[i - 1][j] : 0) + (i < m - 1 ? dp[i + 1][j] : 0)) % M +
                                              ((j > 0 ? dp[i][j - 1] : 0) + (j < n - 1 ? dp[i][j + 1] : 0)) % M) %
                                             M;
                        }
                }
                dp = temp;
        }

        return count;
}



int findPaths_dp(int i , int j , int maxMove, int m ,int n){
        if( i < 0 || j < 0 || i >= m || j >= n)
                return 1;
        if(maxMove == 0) return 0;
        int left = 0 , right = 0 , up = 0 , down = 0;
         if(maxMove>0)left = findPaths_dp(i , j-1 , maxMove-1 , m , n);
         if(maxMove>0)right = findPaths_dp(i , j+1 , maxMove-1 , m , n);
         if(maxMove>0)up = findPaths_dp(i-1 , j , maxMove-1 , m , n);
         if(maxMove>0)down = findPaths_dp(i+1 , j , maxMove-1 , m , n);
        return left + right + up + down;
}


 int M=1e9+7;
    int solve(int n, int m, int maxMove, int startRow, int startColumn){

        if(startColumn<0 || startColumn>=n || startRow<0 || startRow>=m)return 1;


        int up=0,down=0,left=0,right=0;
        if(maxMove>0)up=solve(n, m, maxMove-1, startRow-1, startColumn);
        if(maxMove>0)down=solve(n, m, maxMove-1, startRow+1, startColumn);
        if(maxMove>0)left=solve(n, m, maxMove-1, startRow, startColumn-1);
        if(maxMove>0)right=solve(n, m, maxMove-1, startRow, startColumn+1);

        return (up+down+left+right)%M;
    }





int main()
{
        int m = 1, n = 3, maxMove = 3, startRow = 0, startColumn = 1;
        cout << findPaths(m, n, maxMove, startRow, startColumn)<<endl;
        cout << solve(m, n, maxMove, startRow, startColumn);
        return 0;
}