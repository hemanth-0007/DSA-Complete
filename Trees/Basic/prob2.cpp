// Give the height of the tree or max depth

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left , *right;
        Node(){
            data = 0;
            left = NULL;
            right = NULL;
        }
        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
        }
};

Node* insert(Node* root , int data){
    if(root ==NULL) return new Node(data);
    else if(root->data < data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
    // return root;
}

void preOrder(Node* root){
    if(root != NULL){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int height(Node* root){

    if(root == NULL || (root->left == NULL && root->right == NULL)) return 0;
    int left =  height(root->left);
    int right = height(root->right);
    return 1 + max(left , right);
}

int main()
{
    Node* root = new Node(3);
    insert(root , 7);
    insert(root , 1);
    insert(root , 5);
    insert(root , 10);
    insert(root , 19);
    cout<<height(root);

return 0;
}