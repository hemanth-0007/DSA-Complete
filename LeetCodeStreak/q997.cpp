#include<bits/stdc++.h>
using namespace std;

 int findJudge(int n, vector<vector<int>>& trust) {
    int ans = -1;
    vector<int> trustCount(n+1,0);
    for(int i=0;i<trust.size();i++)
    {
        trustCount[trust[i][0]]--;
        trustCount[trust[i][1]]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(trustCount[i]==n-1)
        {
            ans = i;
            break;
        }
    }
    return ans;
}

int main()
{
    // vector<vector<int>> trust = {{1,2},{2,3}};
    // vector<vector<int>> trust = {{1,3},{2,3}};
    vector<vector<int>> trust = {{1,3},{1,4},{2,3},{2,4},{4,3}};

    // std::cout<<findJudge(3,trust);
    std::cout<<findJudge(4,trust);

    return 0;
}