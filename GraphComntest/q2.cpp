// In a region consisting of N
//  towns, there are M
//  bidirectional roads connecting these towns. Each road is of equal length. In this region, there are two types of armies stationed: the Red Army and the Blue Army. The Red Army is stationed in R
//  distinct towns, and the Blue Army is stationed in B
//  distinct towns, with no town hosting both a Red and a Blue army unit simultaneously.

// Find the minimum amount of time required for any two armies of different colors to clash. It is known that an army can travel from one town to another across any road in exactly one day. Consider all possible paths and scenarios in which the two armies might travel and clash. Armies can move independently and simultaneously.

// If two armies can never clash, then print "-1".

// Input
// The first line contains two integers N
//  and M
// , the number of towns and the number of bidirectional roads respectively.
// The second line contains N
//  integers, where each integer is either 0 (no army), 1 (Blue army), or 2 (Red army), representing the presence of an army in each town.
// The next M
//  lines each contain two integers u
//  and v
// , representing a bidirectional road between towns u
//  and v
// .
// Output
// The minimum number of days required for any two armies of different colors (one Red and one Blue) to meet, assuming they start traveling towards each other at the same time.

// If red and blue armies can never clash, then print "-1".

// test case 1
// input
// 2 1
// 1 2
// 1 2
// output
// 0.5

// test case 1 explanation
// Blue army is at town-1
//  and Red army is at town-2
// . They will clash in between road connecting town 1
//  and 2
// . Since both armies can move simultaneously, they will meet in between and require only 1/2 day.


#include<bits/stdc++.h>
using namespace std;

float min_days(vector<vector<int>>& adjList, vector<int>& army, int n){
    vector<int> red, blue;
    for(int i = 1; i <= n; i++){
        if(army[i] == 1) blue.push_back(i);
        else if(army[i] == 2) red.push_back(i);
    }
    if(red.size() == 0 || blue.size() == 0) return -1;
    float min_days = INT_MAX;
    for(auto r : red){
        for(auto b : blue){
            vector<bool> vis(n, false);
            queue<int> q;
            q.push(r);
            vis[r] = true;
            int count = 0;
            while(!q.empty()){
                int size = q.size();
                for(int i = 0; i < size; i++){
                    int node = q.front();
                    q.pop();
                    if(node == b){
                        min_days = min(min_days, (float)count/2);
                        break;
                    }
                    for(auto adjNode : adjList[node]){
                        if(!vis[adjNode]){
                            vis[adjNode] = true;
                            q.push(adjNode);
                        }
                    }
                }
                count++;
            }
        }
    }
    return min_days;
}


int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> army(n+1);
    for (int i = 1; i <= n; i++)
        cin >> army[i];
    vector<vector<int>> adjList(n+1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }  
     
    cout<<float(min_days(adjList, army, n))<<endl;
     
return 0;
}