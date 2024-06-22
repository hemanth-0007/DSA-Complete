// There are N
//  cities with M
//  bi-directional roads between them. You want to travel from a given source city to target city. But there are some cities that have landmines in them and you will die if you visit these cities.

// Find the smallest number of roads that you can take to complete your travel without dying. If it is not possible to do so output −1
// .

// Input
// The first line contains two integers N
//  and M
//  denoting the number of cities and the number of roads respectively.

// The second line contains two integers: source and target.

// The third line contains N
//  integers which are either 0
//  or 1
//  denoting whether each city has landmines or not. (1
//  means that the city has landmines.)

// Finally, there are M
//  lines containing 2
//  integers each u
//  and v
//  denoting that there is a road between city u
//  and city v
// .

// Output
// Output the smallest number of roads that you should take to complete your travel without dying. If it is not possible to do so output −1
// .


#include<bits/stdc++.h>
using namespace std;


int shoretest_dis(vector<vector<int>>& adjList, int src, int target, vector<bool>& vis, vector<int>& landmines){
    queue<int> q;
    q.push(src);
    vis[src] = true;
    int count = 0;
    while(!q.empty()){
        int size = q.size();
        for(int i = 0; i < size; i++){
            int node = q.front();
            q.pop();
            if(node == target) return count;
            for(auto adjNode : adjList[node]){
                if(!vis[adjNode] && landmines[adjNode] == 0){
                    vis[adjNode] = true;
                    q.push(adjNode);
                }
            }
        }
        count++;
    }
    return -1;
}



int main()
{
    int N , M;
    cin>>N>>M;
    int src, target;
    cin>>src>>target;
    vector<int> landmines(N);
    for(int i = 0; i < N; i++) cin>>landmines[i];
    vector<vector<int>> adjList(N);
    for(int i = 0; i < M; i++){
        int u, v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<bool> vis(N, false);
    cout<<shoretest_dis(adjList, src, target, vis, landmines)<<endl;

return 0;
}