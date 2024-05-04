// Boundary Traversal printing the left part from top to down
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
    else if(root->data < data) root->left = insert(root->left, data);
    else root->right = insert(root->right, data);
     
}
  
void printBoundaryLeft(Node* root)
{
	if (root == nullptr)
		return;

	if (root->left) {
		cout << root->data << " ";
		printBoundaryLeft(root->left);
	}
	else if (root->right) {
		cout << root->data << " ";
		printBoundaryLeft(root->right);
	}
 
}
 
int main()
{
    Node* root = new Node(4);
    insert(root,1);
    insert(root,6);
    insert(root,5);
    insert(root,7);
    insert(root,2);
   printBoundaryLeft(root);
    	 

	return 0;
}

 



 