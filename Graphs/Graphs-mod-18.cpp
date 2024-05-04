//Printing the shortest path through the dijkstras algo 
 
#include<bits/stdc++.h>
using namespace std;
#define INF 99999
class Graph
{
private:
	int V;
public:
	vector<vector<int>> adjMatrix;
	vector<vector<int>> *adj;
	vector<int> dis;
	Graph(int V){
		this->V = V;
		adj = new vector<vector<int>> [V];
	}
	 
	int dijkstra(int src, int dest){
			
	        vector<int> parent(V,-1);
			priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
			pq.push({0, src});
			dis[src] = 0 ;

			while (!pq.empty())
			{
				int node = pq.top().second;
				int dist = pq.top().first;
				pq.pop();
				for(auto  itr : adj[node]){
					int adjNode = itr[0];
					int edgeWgt = itr[1];

						if(dis[adjNode] > dist + edgeWgt){
							dis[adjNode] = dist + edgeWgt;
							pq.push({dis[adjNode], adjNode});
							parent[adjNode] = node;
						}
				}		
			}

			// while (parent[dest] != src)
			// {
			// 	 cout<<dest<<" ";
			// 	 dest = parent[dest];
			// }
			// cout<<src<<" ";
			for(auto num : parent){ cout<<num<<" ";}
			return dis[dest];
		}
		
		
};

 

int main()
{ 
	int V = 9;
	Graph g(V);
	g.adjMatrix =      { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
 

 for (int i = 0; i < 9; i++)
 {
	for (int j = 0; j < 9; j++)
	{
		if(g.adjMatrix[i][j] != 0){
			// as this is undirected graph
			g.adj[i].push_back({j,g.adjMatrix[i][j]});
			g.adj[j].push_back({i,g.adjMatrix[i][j]});
		}
	}
	
 }
 
 cout<<g.dijkstra(0,8);
 

 
return 0;
}