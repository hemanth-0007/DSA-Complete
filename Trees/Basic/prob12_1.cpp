#include <bits/stdc++.h>

using namespace std;

struct node {
  int data;
  struct node * left, * right;
};

  vector<vector<int>> verticalT(node* root) {
        vector<vector<int>> res;
        // line , nodes in line
        map<int, vector<int>> mpp;
        // node , line
        queue<pair<node*, int>> q;
        q.push({root, 0}); 
        while(!q.empty()){
            node* node = q.front().first;
            int line = q.front().second;
            mpp[line].push_back(node->data);
            if(node->left != NULL) q.push({node->left,line-1});
            if(node->right != NULL) q.push({node->right,line+1});
        }
        for(auto it : mpp){
            res.push_back(it.second);
        }
        return res;
    }

struct node * newNode(int data) {
  struct node * node = (struct node * ) malloc(sizeof(struct node));
  node -> data = data;
  node -> left = NULL;
  node -> right = NULL;

  return (node);
}

int main() {

  struct node * root = newNode(1);
  root -> left = newNode(2);
  root -> left -> left = newNode(4);
  root -> left -> right = newNode(10);
  root -> left -> left -> right = newNode(5);
  root -> left -> left -> right -> right = newNode(6);
  root -> right = newNode(3);
  root -> right -> left = newNode(9);
  root -> right -> right = newNode(10);

  vector < vector < int > > verticalTraversal;
  verticalTraversal = verticalT(root);

  cout << "The Vertical Traversal is : " << endl;
  for (auto vertical: verticalTraversal) {
    for (auto nodeVal: vertical) {
      cout << nodeVal << " ";
    }
    cout << endl;
  }
  return 0;
}