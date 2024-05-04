// Recursive optimized C program to find the diameter of a
// Binary Tree Optimal solution
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


 
int diameter(Node* tree, int &maxi)
{
	 
	if (tree == NULL)
		return 0;
 
	int lheight = diameter(tree->left,maxi);
	int rheight = diameter(tree->right,maxi);

    maxi = max(maxi , lheight + rheight);

	 
	return  1 + max(lheight, rheight);
}



int main()
{

	//--> Not including the root element
	// Node* root = new Node(1);
    //     insert(root , 2);
    //     insert(root , 7);
    //     insert(root , 3);
    //     insert(root , 4);
    //     insert(root , 5);
    //     insert(root , 6);
    //     insert(root , 8);
    //     insert(root , 9);
    //     insert(root , 10);
    //     insert(root , 11);

    Node* root = new Node(2);
    insert(root,2);
    insert(root,3);
    insert(root,4);

        int maxi = 0;
        diameter(root, maxi);
	cout << "Diameter of the given binary tree is "
		<< maxi;

	return 0;
}

 
