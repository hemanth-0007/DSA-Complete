//Implementing Floy Warshall algorithm
 
#include<bits/stdc++.h>
using namespace std;
#define INF 99999
class Graph
{
private:
	int V;
public:
	vector<vector<int>> adjList;
	vector<int> dis;
	Graph(int V){
		this->V = V;
	}
	 
	vector<vector<int>> warshall(vector<vector<int>> & matrix ){
		 
		 for (int k = 0; k < V; k++)
		 {
			for (int i = 0; i < V; i++)
			{
				for (int j = 0; j < V; j++)
				{
					adjList[i][j] = min(adjList[i][j] , adjList[i][k] + adjList[k][j]);
				}
				
			}
			
		 }
		 
		 return matrix;
	}
		
		
};

void printVectors(vector<vector<int>>& v){
	
	for (int i = 0; i < v.size(); i++)
	{
		for (int j = 0; j < v[i].size(); j++)
		{
			if(v[i][j] == INF){
				cout<<-1<<" ";
			}
			else
				 cout<<v[i][j]<<" ";
		}
		cout<<endl;
		
	}
	
}

int main()
{ 
	int V = 4;
	Graph g(4);
    g.adjList =       { { 0, 5, INF, 10 },
                        { INF, 0, 3, INF },
                        { INF, INF, 0, 1 },
                        { INF, INF, INF, 0 } };

    vector<vector<int>> v = g.warshall(g.adjList);
	printVectors(v);
	cout<<g.adjList.size()<<endl;
	
/*
     0      5      8      9
    INF      0      3      4
    INF    INF      0      1
    INF    INF    INF      0
*/
  
    
	

return 0;
}