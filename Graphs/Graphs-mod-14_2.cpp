//  Modifications for dikstras
#include<bits/stdc++.h>
using namespace std;

class Graph
{
private:
	int V;
	list<pair<int,int>> *adj;
	int threShold = 4;
public:
	vector<int> dis;
	vector<int> noOfCity;
	Graph(int V){
		this->V = V;
		adj = new list<pair<int,int>> [V];
		dis.resize(V, 1e9);
		noOfCity.resize(V,0);
	}
	int findMinThreshold();
	void addEdge(int u , int v, int w){
		// undirected weighted graph 
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}
	vector<int> dijkstra(int src){
		dis.resize(V, 1e9);
		priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
		pq.push({0, src});
		dis[src] = 0 ;

		while (!pq.empty())
		{
			int node = pq.top().second;
			int dist = pq.top().first;
			pq.pop();
			for(auto  itr : adj[node]){
				int adjNode = itr.first;
				int edgeWgt = itr.second;

					if((dis[adjNode] > dist + edgeWgt) && (dist + edgeWgt < threShold) ){
						dis[adjNode] = dist + edgeWgt;
						pq.push({dis[adjNode], adjNode});
					}
			}		
		}
		
		for(int i = 0 ; i < V; i++){
			
		}
	}
};

int Graph :: findMinThreshold(){
	
	for (int i = 0; i < V; i++)
	{
		
	}
	
}

int main()
{
	 int V = 4;
    Graph g(V);
	g.addEdge(0,1,3);
	g.addEdge(1,2,1);
	g.addEdge(1,3,4);
	g.addEdge(2,3,1);
    
    
	cout<<g.findMinThreshold()<<endl;

return 0;
}