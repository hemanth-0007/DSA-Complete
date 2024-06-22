#include <bits/stdc++.h>
using namespace std;

bool isConnected(const string &s1, const string &s2)
{
    int n = s1.size(), m = s2.size();
    if(abs(n-m) > 1) return false;
    int mask1 = 0, mask2 = 0;
    for (int i = 0; i < n; i++)
        mask1 |= (1 << (s1[i] - 'a'));
    for (int i = 0; i < m; i++)
        mask2 |= (1 << (s2[i] - 'a'));
    int mask = (mask1 & mask2);
    cout<<mask<<endl;
    int cnt = 0;
    for (int j = 0; j < 32; j++)
        if ((1 & (mask >> j)) != 0)
            cnt++;
    if(abs(n-m) == 0){
        if(cnt == n-1) return true;
        else false;
    }
    return cnt == min(m, n);
}


void dfs(int src, vector<vector<int>> &adjList,vector<bool>& vis,int& count){
    vis[src] = true;
    count++;
    for(auto adjNode : adjList[src]){
        if(!vis[adjNode]) dfs(adjNode, adjList, vis, count);
    }
}


vector<int> groupStrings(vector<string> &words)
{
    int n = words.size();
    vector<vector<int>> adjList(n);
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if(isConnected(words[i], words[j])){
                cout<<i<<" "<<j<<endl;
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    int numSets = 0, maxSet = 0;
    vector<bool> vis(n, false);
    for (int i = 0; i < n; i++)
    {
        if(!vis[i]){
            numSets++;
            int count = 0;
            dfs(i, adjList, vis, count);
            maxSet = max(maxSet , count);
        }
    }
    return {numSets, maxSet};
    
}

int main()
{
    // string s1 = "abc";
    // string s2 = "ab";
    string s1 = "yxsef"; 
    string s2 = "s";
    cout<<isConnected(s1, s2 );

    // vector<string> words = {"a","b","ab","cde"};
    // vector<string> words = {"a","ab","abc"};
    // vector<string> words = {"yxsef","s","mlx","ajft","lopj","ihn","vfzps"};
    // vector<int> ans = groupStrings(words);
    // cout<<ans[0]<<" "<<ans[1]<<endl;

    return 0;
}