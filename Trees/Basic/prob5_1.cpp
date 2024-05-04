// FInding the width of a binary tree
// equals number of leave nodes
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
 
int width(Node* root)
{
    queue<Node*> q;
    q.push(root);
    int wd = 0;
    while (!q.empty())
    {   
        int size = q.size();
        
        wd = max(wd, size);
        for (int i = 0; i < size; i++)
        {
            Node* temp = q.front();
            q.pop();
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
        
    }
    
    return wd;
	 
	 
}


 
 


int main()
{

	 

    Node* root = new Node(4);
    insert(root,1);
    insert(root,6);
    insert(root,5);
    insert(root,7);
    insert(root,2);

   
	cout << "Width of the given binary tree is ";
    cout<<width(root);
		 

	return 0;
}

 
