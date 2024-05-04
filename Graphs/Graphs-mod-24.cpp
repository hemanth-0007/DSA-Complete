 // using dijstras for longest paths (DAG)
#include<bits/stdc++.h>
using namespace std;
#define NINF INT_MIN
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
		dis.resize(V, NINF);
	}
	void addEdge(int u , int v, int w){
	 
		adj[u].push_back({v,w});
		 
	}
	vector<int> dijkstra(int src){
		
		queue<pair<int,int>> pq;
		 
		pq.push({0, src});
		dis[src] = 0 ;

		while (!pq.empty())
		{
			int node = pq.front().second;
			int dist = pq.front().first;
			pq.pop();
			for(auto  itr : adj[node]){
				int adjNode = itr.first;
				int edgeWgt = itr.second;

					if(dis[adjNode] < dist + edgeWgt){
						dis[adjNode] = dist + edgeWgt;
						pq.push({dis[adjNode], adjNode});
					}
			}		
		}
		
		return dis;
	}
};



int main()
{
    int V = 6;
	 Graph g(V);
    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 6);
    g.addEdge(1, 2, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 3, 7);
    g.addEdge(3, 5, 1);
    g.addEdge(3, 4, -1);
    g.addEdge(4, 5, -2);
  
  
    vector<int> d = g.dijkstra(1);

	for (int i = 0; i < V; i++)
	{
        if(d[i] == NINF){
            cout<<i<<" -- "<<"no path"<<endl;
        }
        else{
		cout<<i<<" -- "<<d[i]<<endl;
        }
            
	}
	

return 0;
}