#include <bits/stdc++.h>
using namespace std;

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    // stops , node , dis

    vector<pair<int, int>> adjList[n];
    // directed adjacency list
    for (auto v : flights)
        adjList[v[0]].push_back({v[1], v[2]});

    queue<pair<int, pair<int, int>>> q;
    vector<int> dis(n, 1e9);
    q.push({0, {src, 0}});
    dis[src] = 0;
    while (!q.empty())
    {
        int stops = q.front().first;
        int node = q.front().second.first;
        int distance = q.front().second.second;
        q.pop();
        // cout<<stops<<" "<<node<<" "<<distance<<endl;
        for (auto adj : adjList[node])
        {
            int adjNode = adj.first;
            int adjWt = adj.second;
            if (dis[adjNode] > adjWt + distance && stops <= k)
            {
                dis[adjNode] =  adjWt + distance;
                q.push({stops + 1, {adjNode, dis[adjNode]}});
            }
        }
    }

    return dis[dst] == 1e9 ? -1 : dis[dst];
}

int main()
{
    int n = 4;
    vector<vector<int>> flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
    int src = 0, dst = 3, k = 1;
    cout<<findCheapestPrice(n, flights, src, dst, k);

    return 0;
}