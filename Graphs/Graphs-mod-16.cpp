//Implementing Bellman Ford algorithm
 
#include<bits/stdc++.h>
using namespace std;

class Graph
{
private:
	int V;
	vector<vector<int>> edges;
public:
	vector<int> dis;
	Graph(int V){
		this->V = V;
		dis.resize(V, INT16_MAX);
	}
	void addEdge(int u , int v, int w){
		// undirected weighted graph 
		edges.push_back({w, u, v});
	}
	vector<int> bellman(int src){
		 dis[src] = 0;
		 for (int i = 0; i < V-1; i++)
		 {
			for(auto edge : edges){
				int w = edge[0];
				int u = edge[1];
				int v = edge[2];
				if(dis[u] != INT16_MAX && dis[u] + w < dis[v]){
						dis[v] = dis[u] + w ;
				}

			}
		 }
		 return dis;
		 
	}
		
		
};



int main()
{ 
	 int V = 5;
    Graph g(V);
  
    // making above shown graph
    g.addEdge(0, 1, -1);
    g.addEdge(0, 2, 4);
    g.addEdge( 1, 4, 2);
    g.addEdge( 3, 2, 5);
    g.addEdge(3, 1, 1);
    g.addEdge( 4, 3, -3);
    
  
    // Function call
    vector<int> d = g.bellman(0);

	for (int i = 0; i < V; i++)
	{
		cout<<i<<" -- "<<d[i]<<endl;
	}
	

return 0;
}