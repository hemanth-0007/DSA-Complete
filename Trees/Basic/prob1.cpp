// Give the size of a tree

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
    if(root->data < data) root->right = insert(root->right, data);
    else root->left = insert(root->left, data);
    return root;
}

void preOrder(Node* root){
    if(root != NULL){
        cout<<root->data<<" ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(Node* root){
    if(root != NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
}

int size(Node* root){

    if(root == NULL) return 0;

    int left = size(root->left);
    int right = size(root->right);
    return (1 + left + right);
}

int main()
{
    Node* root = new Node(3);
    insert(root , 7);
    insert(root , 1);
    insert(root , 5);
    inOrder(root);
    preOrder(root);
  
return 0;
}