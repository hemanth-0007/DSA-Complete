 // Min colors to color the graph with no two adjacent verteces being of the same color
#include<bits/stdc++.h>
using namespace std;
 
class Graph
{
private:
	int V;
	vector<list<int>> adj;
public:
	 
	Graph(int V){
		this->V = V;
	}
	void addEdge(int u , int v ){
	 
		adj[u].push_back(v);
		adj[v].push_back(u);
		 
	}
	vector<int> greedyColor(int s);
};

vector<int> Graph :: greedyColor(int src){
	vector<int> result;// this resembles the number of the color that is stored 
	vector<bool> avail;
	avail.resize(V, true);	
	result.resize(V, -1);

	result[src] = 0;
	
	 for (int node = 1; node < V; node++)
	 {
		for(auto adjNode : adj[node]){
			if(result[adjNode] != -1){
				avail[result[adjNode]] = false;
			}
		}
		// first color that is available
		
		for ( int cr = 0; cr < V; cr++)
		{
			if(avail[cr] == true){
				result[node] = cr;
				break;
			}
		}
 
		

		for(auto adjNode : adj[node]){
			if(result[adjNode] != -1){
				avail[result[adjNode]] = true;
			}
		}
		

	 }
	 
	 return result;
	


}


int main()
{
    int V = 4;
	 Graph g(V);
   
  g.addEdge(0,1);
  g.addEdge(1,2);
  g.addEdge(0,2);
  g.addEdge(0,3);
  g.addEdge(2,3);

  vector<int> d = g.greedyColor(0);

  cout<<"node"<<"--- color"<<endl;
  for (int i = 0; i < V; i++)
  {
	cout<<i<<"---"<<d[i]<<endl;
  }
  
    
	

return 0;
}