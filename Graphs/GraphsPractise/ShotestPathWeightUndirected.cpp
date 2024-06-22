#include<bits/stdc++.h>
using namespace std;
vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {

    vector<vector<pair<int,int>>> adjList(n+1);
    // creating an adjacency list
    for(auto v : edges){
        // v[0]- a v[1] - b v[2] - w
        // since its a weighted graph
        adjList[v[0]].push_back({v[1], v[2]});
        adjList[v[1]].push_back({v[0], v[2]});
        // cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<endl;
    }

    vector<int> parent(n+1, 0);
    vector<int> dis(n+1, 1e9);
    vector<int> res;
    priority_queue<pair<int,int>, vector<pair<int,int>> , greater<pair<int,int>> > pq;
    pq.push({0 , 1});
    dis[1] = 0;
    while(!pq.empty()){
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();
        // cout<<node<<" "<<distance<<endl;
        for(auto adjNode : adjList[node]){
            int adjacentNode = adjNode.first;
            int adjacentNodeWeight = adjNode.second;
            if(dis[adjacentNode] > distance + adjacentNodeWeight){
                dis[adjacentNode]  = distance + adjacentNodeWeight;
                parent[adjacentNode] = node;
                pq.push({dis[adjacentNode],adjacentNode});
            }
        }
    }
    if(dis[n] == 1e9){
        return {-1};
    }
    int i = n;
    while (parent[i] != i)
    {
        res.push_back(i);
        i = parent[i];
    }
   
    reverse(res.begin(), res.end());
    vector<int> finalRes;
    finalRes.push_back(dis[n]);
    for(auto num : res) finalRes.push_back(num);
    // for(auto num : res) cout<<num<<" ";    
    return finalRes;
}

int main()
{
    vector<vector<int>> edges = {{1,2,2}, {2,5,5}, {2,3,4}, {1,4,1},{4,3,3},{3,5,1}};
    int n = 5, m = edges.size();
    vector<int> finalRes = shortestPath(n,m , edges );
    for(auto num : finalRes) cout<<num<<" ";

return 0;
}