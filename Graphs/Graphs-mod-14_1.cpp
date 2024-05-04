//Implementing dijkstras algo
// For the shortest path from the source vertex to every vertex
// This algorithm doesnot work for negative edges--> as the algorithm takes into a infinte loop
#include<bits/stdc++.h>
using namespace std;

class Graph
{
private:
	int V;
	list<pair<int,int>> *adj;
public:
	vector<int> dis;
	Graph(int V){
		this->V = V;
		adj = new list<pair<int,int>> [V];
		dis.resize(V, 1e9);
	}
	void addEdge(int u , int v, int w){
		// undirected weighted graph 
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	vector<int> dijkstra(int src){
		
		queue<pair<int,int>> pq;
		// priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
		pq.push({0, src});
		dis[src] = 0 ;

		while (!pq.empty())
		{
			
			int node = pq.front().second;
			int nodeDis = pq.front().first;
			pq.pop();
			for(auto  itr : adj[node]){
				int adjNode = itr.first;
				int edgeWgt = itr.second;

				if(dis[adjNode] > nodeDis + edgeWgt){
					dis[adjNode] = nodeDis + edgeWgt;
					pq.push({dis[adjNode], adjNode});
				}
			}		
		}
		
		return dis;
	}
};



int main()
{
	 int V = 9;
    Graph g(V);
  
    // making above shown graph
    g.addEdge(0, 1, 4);
    g.addEdge(0, 7, 8);
    g.addEdge(1, 2, 8);
    g.addEdge(1, 7, 11);
    g.addEdge(2, 3, 7);
    g.addEdge(2, 8, 2);
    g.addEdge(2, 5, 4);
    g.addEdge(3, 4, 9);
    g.addEdge(3, 5, 14);
    g.addEdge(4, 5, 10);
    g.addEdge(5, 6, 2);
    g.addEdge(6, 7, 1);
    g.addEdge(6, 8, 6);
    g.addEdge(7, 8, 7);
  
    // Function call
    vector<int> d = g.dijkstra(0);

	for (int i = 0; i < V; i++)
	{
		cout<<i<<" -- "<<d[i]<<endl;
	}
	

return 0;
}