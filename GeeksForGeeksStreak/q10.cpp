#include<bits/stdc++.h>
using namespace std;

void solve(int index, int m, int prev, int n, int &count, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        count++;
        return;
    }

    if (index > m)
        return;

    // Check if the result for the current state is already memoized
    if (dp[index][prev + 1] != -1)
        return;

    // Memoize the result for the current state
    dp[index][prev + 1] = 0;

    if (prev == -1 || index >= 2 * prev)
    {
        solve(index + 1, m, index, n - 1, count, dp);
        dp[index][prev + 1] += count; // Update the memoization table
    }

    solve(index + 1, m, prev, n, count, dp);
    dp[index][prev + 1] += count; // Update the memoization table
}



int solve(int index, int m, int prev, int n, vector<vector<int>> &dp)
{
    // base condition
    if (n == 0) return 1;
    if (index > m) return 0;
    if(dp[index][prev+1] != -1) return dp[index][prev+1];
    int ans = 0;
    if (prev == -1 || index >= 2 * prev){
        ans += solve(index + 1, m, index, n - 1, dp);
        // dp[index][prev+1] = ans;
    } 
    ans += solve(index + 1, m, prev, n, dp);
    return dp[index][prev+1] = ans;
}



int solve(int index, int m, int prev, int n)
{
    // base condition
    if (n == 0) return 1;
    if (index > m) return 0;
    int ans = 0;
    if (prev == -1 || index >= 2 * prev){
        ans += solve(index + 1, m, index, n - 1);
    } 
    ans += solve(index + 1, m, prev, n);
    return  ans;
}



int numberSequence(int m, int n)
{
    // int count = 0;
    // solve(1, m, -1, n, count, dp);
    // return count;

    vector<vector<int>> dp(m + 1, vector<int>(m + 1, -1));
    return solve(1, m, -1, n, dp);
}

int main()
{
    int m = 10, n = 4;
    cout << numberSequence(m, n) << endl;

return 0;
}