#include<bits/stdc++.h>
using namespace std;

int helper(int ind, vector<vector<int>>& tasks, vector<int>& startTime, int n, vector<int>& dp){
    if(ind >= n) return 0;
    if(dp[ind] != -1) return dp[ind];
    int nxt_ind = lower_bound(startTime.begin(), startTime.end(), tasks[ind][1]) - startTime.begin();
    int pick = tasks[ind][2] + helper(nxt_ind, tasks, startTime, n, dp);
    int notPick = helper(ind+1, tasks, startTime, n, dp);
    return dp[ind] = max(pick, notPick);
}

 
int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
    int n = profit.size();
    vector<vector<int>> tasks;
    for(int i = 0; i < n; i++) tasks.push_back({startTime[i], endTime[i],profit[i]});
    sort(tasks.begin(), tasks.end());
    sort(startTime.begin(), startTime.end());
    // 1D dp
    vector<int> dp(n,-1);
    return helper(0 , tasks, startTime, n, dp);
}

int solveOp(int ind, vector<vector<int>> &tasks,vector<int>& startTime ){
    if(ind >= startTime.size()) return 0;
    int nxt_ind = lower_bound(startTime.begin(), startTime.end(), tasks[ind][1]) - startTime.begin();
    int inc = tasks[ind][2] + solveOp(nxt_ind, tasks , startTime);
    int not_inc = solveOp(ind + 1, tasks, startTime);
    return max(inc, not_inc);
}

int jobSchedulingOp(vector<int>& startTime, vector<int>& endTime, vector<int>& profit){
    int n = profit.size();
    vector<vector<int>> tasks;
    for (int i = 0; i < n; i++) tasks.push_back({startTime[i], endTime[i], profit[i]});
    sort(tasks.begin(), tasks.end());
    sort(startTime.begin(), startTime.end());
    return solveOp(0, tasks, startTime);
}


int main()
{
    vector<int> startTime = {1,2,3,3};
    vector<int> endTime = {3,4,5,6};
    vector<int> profit = {50,10,40,70};
    cout << jobScheduling(startTime, endTime, profit) << endl;
    cout << jobSchedulingOp(startTime, endTime, profit) << endl;

return 0;
}