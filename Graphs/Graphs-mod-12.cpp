#include <bits/stdc++.h>
using namespace std;
// solution for finding the total weight of minimum spanning tree using the prims algo
class Solution
{
public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int spanningTree(int V, vector<vector<int>> adj[])
	{
		priority_queue<pair<int, int>,
		               vector<pair<int, int> >, greater<pair<int, int>>> pq;

		vector<int> vis(V, 0);
		// {wt, node}
		pq.push({0, 0});
		int sum = 0;
		while (!pq.empty()) {
			auto it = pq.top();
			pq.pop();
			int node = it.second;
			int wt = it.first;

			 
			if(!vis[node]){
				// if not visited adding the node to the mst
				vis[node] = 1;
				sum += wt;
				for (auto it : adj[node]) {
					int adjNode = it[0];
					int edW = it[1];
					if (!vis[adjNode]) {
						pq.push({edW, adjNode});
					}
				}
			}
		}
		return sum;
	}
};

void printVectorOfVectors(vector<vector<int>> &vec){
    for (int i = 0; i < vec.size(); i++)
    {
       for (int j = 0; j < vec[i].size(); j++)
       {
            cout<<vec[i][j]<<" ";
       }
       cout<<"\n";
    }
    
}

int main() {

	int V = 5;
	vector<vector<int>> edges = {{0, 1, 2},
                                 {0, 2, 1}, 
                                 {1, 2, 1},
                                 {2, 3, 2},
                                 {3, 4, 1},
                                 {4, 2, 2}};
	vector<vector<int>> adj[V];
	for (auto it : edges) {
		// Since it is an undirected graph we do it for both the edges
		vector<int> tmp(2);
		tmp[0] = it[1];
		tmp[1] = it[2];
		adj[it[0]].push_back(tmp);

		tmp[0] = it[0];
		tmp[1] = it[2];
		adj[it[1]].push_back(tmp);
	}
// for(int i = 0 ; i<V ; i++)
    printVectorOfVectors(adj[2]);



	// Solution obj;
	// int sum = obj.spanningTree(V, adj);
	// cout << "The sum of all the edge weights: " << sum << endl;

	return 0;
}