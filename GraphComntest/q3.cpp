
// It's a dark valley, and you must reach the other side. There are N
//  street lamps that light a circular area. The ith
//  lamp has a radius 'Ri
// '. The valley is filled with criminals, so you only want to travel in light to remain safe.

//  Given M
//  and N
//  as the valley's length and number of lamps, respectively.

// As you only have to travel from (0,a)→(M,b)
//  for any random numbers a and b, you can consider the width of the valley to be infinite. You can only travel in the light of the lamps.
// . You can choose any a and b of your choice.

// For each lamp, you will be given X, Y, denoting the coordinate of the lamp, and R, denoting the radius of the lamp.

// Find if it's possible to reach the other side safely.

// Constraints

// 1≤T≤10
// 1≤N≤105
// 1≤M≤105
// 1≤X,Y,R≤108
// Input
// The first line contains the T, denoting the number of test cases.

// The first line contains 2
//  integers, M and N, denoting the valley's length and the number of lamps.

// The next N lines consider three integers denoting the Xi, Yi, and Ri for the ith lamp.

// Output
// Output YES if you can reach the other side safely. Output NO otherwise.

#include<bits/stdc++.h>
using namespace std;

// modify this function as the test case is getting failed

// input
// 2
// 10 2
// 2 5 2
// 7 5 3
// 10 2
// 2 5 2
// 7 6 3

// output
// YES
// NO
// use graph to solve this problem
bool canTravel(vector<pair<pair<int, int>, int>> &lamps, int m){
    // create a graph
    vector<vector<int>> adjList(lamps.size());
    for(int i = 0; i < lamps.size(); i++){
        for(int j = i+1; j < lamps.size(); j++){
            int x1 = lamps[i].first.first, y1 = lamps[i].first.second, r1 = lamps[i].second;
            int x2 = lamps[j].first.first, y2 = lamps[j].first.second, r2 = lamps[j].second;
            int dist = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
            int r = (r1+r2)*(r1+r2);
            if(dist <= r){
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }
    }
    vector<bool> vis(lamps.size(), false);
    queue<int> q;
    q.push(0);
    vis[0] = true;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(lamps[node].first.first + lamps[node].second >= m) return true;
        for(auto adjNode : adjList[node]){
            if(!vis[adjNode]){
                vis[adjNode] = true;
                q.push(adjNode);
            }
        }
    }
    return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        // valley length and number of lamps
        int m, n;
        cin>>m>>n;
        // x , y and r for each lamp
        vector<pair<pair<int, int>, int>> lamps;
        for(int i = 0; i < n; i++){
            int x, y, r;
            cin>>x>>y>>r;
            lamps.push_back({{x, y}, r});
        }
        if(canTravel(lamps, m)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }

return 0;
}