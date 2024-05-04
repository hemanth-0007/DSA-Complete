// Recursive optimized C program to find the diameter of a
// Binary Tree
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
 
int height(Node* node)
{
	 
	if (node == NULL)
		return 0;
	return 1 + max(height(node->left), height(node->right));
}


 
int diameter(Node* tree)
{
	// base case where tree is empty
	if (tree == NULL)
		return 0;

	// get the height of left and right sub-trees
	int lheight = height(tree->left);
	int rheight = height(tree->right);

	// get the diameter of left and right sub-trees
	int ldiameter = diameter(tree->left);
	int rdiameter = diameter(tree->right);

	// Return max of following three
	// 1) Diameter of left subtree
	// 2) Diameter of right subtree
	// 3) Height of left subtree + height of right subtree +
	// 1
	return max(lheight + rheight + 1,
			max(ldiameter, rdiameter));
}



int main()
{

	
	Node* root = new Node(1);
        insert(root , 2);
        insert(root , 7);
        insert(root , 3);
        insert(root , 4);
        insert(root , 5);
        insert(root , 6);
        insert(root , 8);
        insert(root , 9);
        insert(root , 10);
        insert(root , 11);

 
	cout << "Diameter of the given binary tree is "
		<< diameter(root);

	return 0;
}

 
