// Give the height of the tree or max depth
// using level order traversal (using queues)

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

int height(Node* root)
{

// Initialising a variable to count the
// height of tree
    queue<Node*> q;
    q.push(root);
    int height = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
             Node* temp = q.front();
             q.pop();
             if(temp->left != NULL) q.push(temp->left);
             if(temp->right!= NULL) q.push(temp->right);
                
        }
        height++;
    }
    return height  ;
    
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
