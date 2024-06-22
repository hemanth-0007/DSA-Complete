// You have a grid with n
//  rows and 3
//  columns. Each cell has a value written on it. You also have k
//  tiles of dimensions 2×1
// . You need to place all the tiles on the grid vertically or horizontally such that no tiles overlap and the sum of values covered by the tiles is maximum. Find this maximum value. It is guaranteed that atleast one valid arrangement of tiles always exists under given constrains.

// Input
// The first line contains 2
//  integers n,k(1≤n,k≤1000)
// . The next n
//  lines contains 3
//  integers each, the grid (−106≤ai,j≤106)
// .

// Output
// Output a single integer - the maximum sum.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    vector<vector<int>> grid(n,vector<int>(3));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<3;j++)
        {
            cin>>grid[i][j];
        }
    }
    vector<int> dp(1<<n,INT_MIN);
    dp[0]=0;
    for(int mask=0;mask<(1<<n);mask++)
    {
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(mask&(1<<i))
            {
                cnt++;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(!(mask&(1<<i)))
            {
                for(int j=i+1;j<n;j++)
                {
                    if(!(mask&(1<<j)))
                    {
                        dp[mask|(1<<i)|(1<<j)]=max(dp[mask|(1<<i)|(1<<j)],dp[mask]+grid[i][0]+grid[j][0]);
                        dp[mask|(1<<i)|(1<<j)]=max(dp[mask|(1<<i)|(1<<j)],dp[mask]+grid[i][1]+grid[j][1]);
                        dp[mask|(1<<i)|(1<<j)]=max(dp[mask|(1<<i)|(1<<j)],dp[mask]+grid[i][2]+grid[j][2]);
                    }
                }
            }
        }
    }
    cout<<dp[(1<<n)-1]<<endl;
    return 0;
}
