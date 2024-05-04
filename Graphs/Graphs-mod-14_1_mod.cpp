//Implementing dijkstras algo
// For the shortest path from the source vertex to every vertex
// This algorithm doesnot work for negative edges--> as the algorithm takes into a infinte loop
#include<bits/stdc++.h>
using namespace std;


class Graph {
public:
    int v;
	list<pair<int,int>> *adj;
    vector<int> dis;
    Graph(int n, vector<vector<int>>& edges) {
        this->v = n;
        this->dis.resize(n,1e9);
		adj = new list<pair<int,int>> [v];
		for(auto i : edges){
			adj[i[0]].push_back({i[1],i[2]});
		}
	
    }
    
    void addEdge(vector<int> edge) {
        adj[edge[0]].push_back({edge[1],edge[2]});
		// for(auto i : edges){
		// 	cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
		// }
        // structure is like {u, v , w}
    }
    
    int shortestPath(int node1, int node2) {
		for(int i = 0 ; i < v ; i++) dis[i] = 1e9;
        set<pair<int,int> , greater<pair<int,int>>> pq;
        pq.insert({0, node1});
        dis[node1] = 0;
        while(!pq.empty()){
			auto it  = *(pq.begin());
            int node = it.second;
            int node_distance = it.first;
            pq.erase(it);
            for(auto adjacent : adj[node]){
               
                    int adjNode = adjacent.second;
                    int adjNodeWeight = adjacent.first;
                    if(dis[adjNode] > node_distance + adjNodeWeight){
						if(dis[adjNode] != 1e9) pq.erase({dis[adjNode], adjNode});
                        dis[adjNode] =node_distance + adjNodeWeight;
                        pq.insert({dis[adjNode], adjNode});
                    } 
                
            }
        }
        return dis[node2]!= 1e9 ? dis[node2] : -1;
    }
};



int main()
{
	 int V = 4;
	 vector<vector<int>> edges = {{0,1,2},{0,2,5},{1,2,1},{3,0,3}};
    Graph g(V, edges);
  
    // making above shown graph
	// [[4,[[0,2,5],[0,1,2],[1,2,1],[3,0,3]]],[3,2],[0,3],[[1,3,4]],[0,3]]
	//[null,6,-1,null,6]
  
    
  
    // Function call
    cout<<g.shortestPath(3,2)<<endl;
    cout<<g.shortestPath(0,3)<<endl;
	g.addEdge({1, 3, 4});
    cout<<g.shortestPath(0,3)<<endl;
 
	

return 0;
}