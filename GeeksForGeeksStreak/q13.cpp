#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

void helper(Node *root, int sum, vector<int> &ds, vector<vector<int>> &result){
    if(root == NULL) return;
    if(sum == root->data){
        result.push_back(ds);
    }
    ds.push_back(root->data);
    if(!root->left)  helper(root->left, sum - root->data, ds, result);
    if(!root->right) helper(root->right, sum - root->data, ds, result);
    ds.pop_back();
}



vector<vector<int>> printPaths(Node *root, int sum)
{
        //code here
        vector<vector<int>> result;
        vector<int> ds;
        helper(root, sum, ds, result);
        return result;
}



int main()
{
    int sum = 8;
    Node *root = new Node(1);
    root->left = new Node(20);
    root->right = new Node(3);
    root->right->left = new Node(4);
    root->right->left->left = new Node(6);
    root->right->left->right = new Node(7);
    root->right->right = new Node(15);
    root->right->right->left = new Node(8);
    root->right->right->right = new Node(9);
    vector<vector<int>>  result = printPaths(root, sum);
    for(auto v : result){
        for(auto num : v) cout<<num<<" ";
        cout<<endl;
    }

return 0;
}