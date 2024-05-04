// Boundary Traversal from left nodes to root anticlock wise direc
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
  
 void printLeaves(Node* root)
{
	if (root == nullptr)
		return;

	printLeaves(root->left);

	// Print it if it is a leaf node
	if (!(root->left) && !(root->right))
		cout << root->data << " ";

	printLeaves(root->right);
}

// A function to print all left boundary nodes, except a
// leaf node. Print the nodes in TOP DOWN manner
void printBoundaryLeft(Node* root)
{
	if (root == nullptr)
		return;

	if (root->left) {

		// to ensure top down order, print the node
		// before calling itself for left subtree
		cout << root->data << " ";
		printBoundaryLeft(root->left);
	}
	else if (root->right) {
		cout << root->data << " ";
		printBoundaryLeft(root->right);
	}
	// do nothing if it is a leaf node, this way we avoid
	// duplicates in output
}

// A function to print all right boundary nodes, except a
// leaf node Print the nodes in BOTTOM UP manner
void printBoundaryRight(Node* root)
{
	if (root == nullptr)
		return;

	if (root->right) {
		// to ensure bottom up order, first call for right
		// subtree, then print this node
		printBoundaryRight(root->right);
		cout << root->data << " ";
	}
	else if (root->left) {
		printBoundaryRight(root->left);
		cout << root->data << " ";
	}
	// do nothing if it is a leaf node, this way we avoid
	// duplicates in output
}

// A function to do boundary traversal of a given binary
// tree
void printBoundary(Node* root)
{
	if (root == NULL)
		return;

	cout << root->data << " ";

	// Print the left boundary in top-down manner.
	printBoundaryLeft(root->left);

	// Print all leaf nodes
	printLeaves(root->left);
	printLeaves(root->right);

	// Print the right boundary in bottom-up manner
	printBoundaryRight(root->right);
}
 
 
int main()
{

	 

    Node* root = new Node(4);
    insert(root,1);
    insert(root,6);
    insert(root,5);
    insert(root,7);
    insert(root,2);

   
	 
      
    
		 

	return 0;
}

 



 