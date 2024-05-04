//Implementing the inDegree and OutDegree for a Directed Graph 

#include<bits/stdc++.h>
using namespace std;





int main(){
   vector<vector<int>> adjList;
   int v = 4;
   vector<int> indegree(v, 0);
   adjList.push_back({1, 2});
   adjList.push_back({2});
   adjList.push_back({3});
   adjList.push_back({0});

//     //outdegree
//    for(auto node : adjList){
//         cout<<node.size()<<" ";
//    }
//    cout<<endl;
//    //indegree
//     for(auto node : adjList){
//         for(auto adjNode : node){
//             indegree[adjNode]++;
//         }
//     }
//     for(auto num : indegree) cout<<num<<" ";




// graph reversal

   vector<vector<int>> revAdjList(v);
   for (int i = 0; i < v; i++)
   {
        for(auto adjNode : adjList[i]){
            revAdjList[adjNode].push_back(i);
        }
   }

    int i = 0;
   for(auto node : revAdjList)
   {
    cout<<(i++)<<" ";
    for(auto adjNode : node) {cout<<adjNode<<" ";}
    cout<<endl;
   }
   




    return 0;
}   