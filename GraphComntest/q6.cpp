// There are N
//  cities in the country. You want to travel from city 1
//  to city N
// . You wish to pick a flight path that lets you do so. However, there are a few conditions that need to be satisfied:

// Not all cities have a flight connecting them. That is, you can go directly from city u
//  to city v
//  if and only if there is a flight that explicitly connects cities u
//  and v
// . Note that a flight that goes from city u
//  to v
//  also goes from v
//  to u
// . That is, it is a two-way flight.
// Due to a new law in the country that monitors everyone's flight paths, there exist K
//  triplets of cities of the form {ai,bi,ci}
//  such that they cannot appear in the flight path in this exact order. Note that this means that for example they may appear as ai,ci,bi
// .
// For example, if N=5
// , and {1,3,4}
//  is a bad triplet, then, 1,2,1,3,4,5
//  would be an illegal flight path, but, 1,2,3,1,4,5
//  would be a legal one, assuming there are no other bad triplets and that all adjacent cities given in the path have a flight connecting them.

// You want to minimize the number of flights you take so that the cost is minimal. So, find a way to start from city 1
//  and end at city N
//  while making sure the entire flight path follows the above conditions and taking as less flights as possible. If there are no such paths, output −1
// . If there are multiple, output any of them.

// Input
// The first line of input contains three space-separated integers N,M,K
//  (2≤N≤3000,1≤M≤20000,0≤K≤105
// ) representing the number of cities, flights and triplets respectively.

// The next M
//  lines describe the flights. The ith
//  line consists of two integers u,v
//  (1≤u,v≤N,u≠v
// ). Note that this implies the flight can travel from city u
//  to v
//  and the other-way around too.

// The next K
//  lines describe the triplets. The ith
//  line consists of three integers ai,bi,ci
//  (1≤ai,bi,ci≤N
// ). No triplet appears more than once in the list.

// Output
// If it is impossible to obtain a valid flight path, output −1
// . Otherwise, output two lines. The first line containing a single integer x
//  (2≤x≤N
// ) denoting the number of cities in the flight path. On the second line, output x
//  integers describing the cities in the path denoting the shortest valid flight path from city 1
//  to city N
// . Note that both this trivially means that the path should start with 1
//  and end with N
// .

#include<bits/stdc++.h>
using namespace std;
int main()
{   
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<int>> adjList(n+1);
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    vector<pair<int,int>> triplets;
    for(int i=0;i<k;i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        triplets.push_back({a,b});
        triplets.push_back({b,c});
        triplets.push_back({a,c});
    }
    vector<bool> vis(n+1,false);
    queue<int> q;
    q.push(1);
    vis[1]=true;
    vector<int> parent(n+1,-1);
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        for(auto it:adjList[node])
        {
            if(!vis[it])
            {
                vis[it]=true;
                parent[it]=node;
                q.push(it);
            }
        }
    }
    if(!vis[n])
    {
        cout<<-1<<endl;
        return 0;
    }
    vector<int> path;
    int temp=n;
    while(temp!=-1)
    {
        path.push_back(temp);
        temp=parent[temp];
    }
    reverse(path.begin(),path.end());
    cout<<path.size()<<endl;
    for(auto it:path)
    {
        cout<<it<<" ";
    }
    cout<<endl;

return 0;
}