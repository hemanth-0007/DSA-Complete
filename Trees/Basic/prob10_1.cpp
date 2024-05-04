// Level Order traversal 

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
 
 void print(queue<Node*> q){
    while (!q.empty())  
    {
        cout<<q.front()->data<< " ";
        q.pop();
    }
    cout<<endl;
 }


void levelOrder(Node* root){
    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        print(q);
        for (int i = 0; i < size; i++)
        {
            Node* temp = q.front();
            q.pop();
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
        
    }
    

}

int main()
{
    Node* root = new Node(3);
    insert(root , 7);
    insert(root , 1);
    insert(root , 5);
     levelOrder(root);
  
return 0;
}