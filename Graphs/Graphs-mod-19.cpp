// Finding the nearest distance using bfs in a binary maze

#include <bits/stdc++.h>
using namespace std;

class Graph
{

public:
	int V;

	vector<vector<int>> adjMatrix;

	vector<vector<bool>> visMatrix;

	Graph(int V);

	void addEdge(int v, int w);

	void BFS(vector<vector<int>> &vec, int i, int j);
};

Graph::Graph(int V)
{
	this->V = V;

	visMatrix.resize(V, vector<bool>(V, false));
}

// void Graph::BFS1(int s)
// {
// 	visited[s] = true;
// 	list<int> ls;
// 	ls.push_back(s);

// 	while (!ls.empty())
// 	{
// 		s = ls.front();
// 		cout << s << " ";
// 		ls.pop_front();
// 		for (auto adjNode : adj[s])
// 		{
// 			if (!visited[adjNode])
// 			{
// 				visited[adjNode] = true;
// 				ls.push_back(adjNode);
// 			}
// 		}
// 	}
// }
void Graph::BFS(vector<vector<int>> & resMatrix, int i, int j)
{
	visMatrix[i][j] = true;

	list<pair<int, int>> ls;
	ls.push_back({i, j});
	int dep = 0;
	while (!ls.empty())
	{
		int x = ls.front().first;
		int y = ls.front().second;

		ls.pop_front();
			dep++;
		for (int i = -1; i <= 1; i + 2)
		{
			for (int j = -1; j <= 1; j + 2)
			{
			   if( x+i < V && x+i >=0 && y+j <V && y+j >=0){


					if(!visMatrix[x+i][y+j] ){
						visMatrix[x+i][y+j] = true;
						if( adjMatrix[x+i][y+j] == 1){
							resMatrix[x][y] = dep;
							return;
						}
						ls.push_back({x+i,y+j});
						
					}


			   }
			}
		}
	}

	// for iterating the adjacent nodes
}



vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    int n=grid.size();
	    int m=grid[0].size();
	    vector<vector<int>> vis(n,vector<int>(m,0));
	    vector<vector<int>> ans(n,vector<int>(m,1e5));
	    queue<pair<int,int>> q;
	    for(int i=0;i<n;i++){
	        for(int j=0;j<m;j++){
	            if(grid[i][j]==1){
	                q.push({i,j});
	                vis[i][j]=1;
	                ans[i][j]=0;
	            }
	        }
	    }
	    int drow[]={-1,1,0,0};
	    int dcol[]={0,0,-1,1};
	    while(!q.empty()){
	        int row=q.front().first;
	        int col=q.front().second;
	        q.pop();
	        for(int i=0;i<4;i++){
	            int nrow=row+drow[i];
	            int ncol=col+dcol[i];
	            if(nrow>=0 and nrow<n and ncol>=0 and ncol<m and
	                vis[nrow][ncol]==0){
	                ans[nrow][ncol]=min(ans[nrow][ncol],ans[row][col]+1);
	                vis[nrow][ncol]=1;
	                q.push({nrow,ncol});
	            }
	        }
	    }
	    return ans;
	}

int main()
{
	int V = 3;
	Graph g(3);

	g.adjMatrix = {{1, 0, 1,0}, {1, 1, 0,0}, {1, 0, 0,0}};
	vector<vector<int>> resMatrix = nearest(g.adjMatrix);


	// vector<vector<int>> resMatrix(V, vector<int>(V, 0));
	// int depth = 0;
	// for (int i = 0; i < g.adjMatrix.size(); i++)
	// {
	// 	for (int j = 0; j < g.adjMatrix[i].size(); j++)
	// 	{
	// 		if (g.adjMatrix[i][j] == 0)
	// 		{
	// 			g.BFS(resMatrix, i, j);
	// 		}
	// 		else if (g.adjMatrix[i][j] == 1)
	// 		{
	// 			resMatrix[i][j] = 0;
	// 		}
	// 	}
	// }

	for (int i = 0; i < resMatrix.size(); i++)
	{
		for (int j = 0; j < resMatrix[i].size(); j++)
		{
			cout<<resMatrix[i][j]<<" ";
		}
		cout<<endl;
		
	}
	

	return 0;
}
