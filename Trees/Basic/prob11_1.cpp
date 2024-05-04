// Connect all nodes at same level
// This is done using Iterative inOrder Traversal

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left , *right ,*nextRight;
        Node(){
            data = 0;
            left = NULL;
            right = NULL;
            nextRight = NULL;
        }
        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
            nextRight = NULL;
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

Node* search(Node* root , int key){
    while (root!=NULL)
    {
        if(root->data == key ) return root;
        else if(root->data > key) root = root->left;
        else root = root->right;
    }
    return root;
}

void connectNodes(Node* root){
    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        
        for (int i = 0; i < size; i++)
        {
            Node* temp = q.front();
            q.pop();
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
        queue<Node*> q2(q);
        while (!q2.empty())
        {
            Node* firstNode,*secNode;
            firstNode = q2.front();
            q2.pop();
            if(!q2.empty())  secNode = q2.front();
            else  secNode = NULL;
            firstNode->nextRight = secNode;
        }
        
        
    }
    

}

int main()
{
    Node* root = new Node(4);
    insert(root , 1);
    insert(root , 8);
    insert(root , 0);
    insert(root , 2);
    insert(root , 6);
    insert(root , 10);
     connectNodes(root);
     // For Testing if Connected or not
    Node* p = search(root,1);
    while (p!= NULL)
    {
        cout<<p->data<<" ";
        p = p->nextRight;
    }
    
  
return 0;
}