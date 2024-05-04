// Inorder Successor problem --> as the inorder is sorted store it and find the imediate next 
#include <bits/stdc++.h>
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
    
}
  

Node* search(Node* root, int key)
{
  if(root == NULL || root->data == key) return root;
  
  if(root->data < key) return search(root->right, key);
  if(root->data > key) return search(root->left, key);
  return NULL;
}

void inOrder(Node* root){
     if(root == NULL) return;
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
}

 


int main()
{
    Node* root = new Node(4);
    root = insert(root,1);
    insert(root,6);
    insert(root,5);
    insert(root,7);
    insert(root,2);
    inOrder(root);
    // Node* p = search(root,5);
    // if(p == NULL) cout<<"NULL";
    // else cout<<p->data;
 
    	 

	return 0;
}

 



 