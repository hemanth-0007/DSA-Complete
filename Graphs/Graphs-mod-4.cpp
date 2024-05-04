#include<bits/stdc++.h>
using namespace std;

/*
    Simply printing the adjacent list of
    a graph using oops
*/
class Graph{

    public:
        int v;
        map <int, vector<int> > AdjList;
        map <int , bool> visited;

        void printAdjList( );
        void addEdge(int v, int u);
};
 

 void Graph :: addEdge(int v, int u){
      AdjList[v].push_back(u);
 }

 void Graph :: printAdjList(){
    for (auto itr = AdjList.begin(); itr != AdjList.end(); itr++)
    {
        cout<<itr->first<<" ->";
        auto v1 = itr->second;
        for (auto it = v1.begin(); it != v1.end() ; it++)
        {
            cout<<(*it)<<" ";
        }
         cout<<endl;

    }
    
 }

int main()
{
        Graph g;
    g.addEdge(0,1);
    g.addEdge(0,2);
    g.addEdge(1,0);
    g.addEdge(1,3);
    g.addEdge(2,3);
    g.addEdge(3,2);
    g.addEdge(4,3);

    g.printAdjList();

return 0;
}