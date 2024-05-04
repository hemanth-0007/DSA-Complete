// Deleting tree using postOrder Traversal
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
  
 
void deleteTree(Node* root){
    if(root == NULL) return;
    deleteTree(root->left);
    deleteTree(root->right);
    cout<<"deleting node : "<<root->data<<endl;
    delete root;
}

void deleteUtil(Node** ref_node)
{
    deleteTree(*ref_node);
    *ref_node = NULL;
}

 
int main()
{

	 

    Node* root = new Node(4);
    insert(root,1);
    insert(root,6);
    insert(root,5);
    insert(root,7);
    insert(root,2);

   
	deleteUtil(&root);// pass the address of root not the root itself
    if(root ==NULL) cout<<"NULL";
      
    
		 

	return 0;
}

 
