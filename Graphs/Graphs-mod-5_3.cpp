// C++ code to print BFS traversal from a given
// source vertex from a adjacency matrix

#include <bits/stdc++.h>
using namespace std;


struct Node {
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

void  BFS(int s,  vector<vector<int>> &grid , int V)
{
    vector<bool> visited(V,false);
   queue<int> q;
   visited[s] = true;
   q.push(s);

   while (!q.empty())
   {
     int node = q.front();
     cout<<node<<" ";
     q.pop();
        for(int adjNode = 0 ; adjNode < V; adjNode++){
            if(grid[node][adjNode] != 1) continue;
            if(!visited[adjNode]){
                visited[adjNode]= true;
                q.push(adjNode);
            }
        }
   }
    
}


Node*  cloneGraph(Node* node)
{
   vector<bool> visited(10000,false);
   queue<Node*> q;
   visited[node->val] = true;
   q.push(node);
   Node* result ;

   while (!q.empty())
   {
        Node* temp = q.front();
        result = new Node(temp->val);
        //  cout<<temp->val<<" ";
        q.pop();
        for(auto adjNode : temp->neighbors){
            if(!visited[adjNode->val]){
                visited[adjNode->val] = true;
                q.push(adjNode);
            }
            result->neighbors.push_back(new Node(adjNode->val));
        }
   }
    return result;
}



 
unordered_map<Node*, Node*> copies;
    // Function to clone a graph
Node* cloneGraph(Node* node) {
    // If the node is NULL, return NULL
    if (!node) {
        return NULL;
    }
    // If the node is not present in the map, create a copy of it
    if (copies.find(node) == copies.end()) {
        // Create a new node with the same value as the original node
        copies[node] = new Node(node -> val, {});
        // Copy the neighbors of the original node recursively
        for (Node* neighbor : node -> neighbors) {
            copies[node] -> neighbors.push_back(cloneGraph(neighbor));
        }
    }
    // Return the copy of the node
    return copies[node];
}
 
    
 
// Driver code
int main()
{
    int V = 4, src;
   vector<vector<int>> grid = {
      {0,1,9999,1},
      {1,0,1,9999},
      {9999,1,0,9999},
      {1,9999,9999,0}
    };
 
    cout<<"Enter the vertex you wanna start: ";
    cin>>src;

    cout << "Following is Breadth First Traversal "
         << "(starting from vertex "<<src<<") \n";
        BFS(src,grid,V);
 

    return 0;
}
