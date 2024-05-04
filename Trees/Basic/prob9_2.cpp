// inOrder Successor of the element to the next pointer
 

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left , *right , *next;
        Node(){
            data = 0;
            left = NULL;
            right = NULL;
            next = NULL;
        }
        Node(int val){
            data = val;
            left = NULL;
            right = NULL;
            next = NULL;

        }
};

Node* insert(Node* root , int data){
    if(root ==NULL) return new Node(data);
    if(root->data < data) root->right = insert(root->right, data);
    else root->left = insert(root->left, data);
    return root;
}

 

void inOrder(Node* root){
    if(root != NULL){
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }
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

Node* inOrderSuccessor(Node* root, Node* p){
    Node* ans = NULL;
    while (root != NULL)
    {
       if(root->data <= p->data ) root = root->right;
       else {
        ans = root;
        root = root->left;
       }
    }
    return ans;
}


Node* inOrderPredecessor(Node* root, Node* p){
    Node* ans = NULL;
    while (root != NULL)
    {
       if(root->data >= p->data ) root = root->left;
       else {
        ans = root;
        root = root->right;
       }
    }
    return ans;
}
// Using the iterative inOrder Traversal
Node* fillNextPtr(Node* root){
    stack<Node*> st;
    Node* node = root;
    while (true)
    {
        if(node != NULL){
            st.push(node);
            node = node->left;
        }
        else{
            if(st.empty()) break;
            node = st.top();
            st.pop();
            node->next = inOrderSuccessor(root,node);
            node = node->right;
        }
    }
    
    return root;
}

 
int main()
{
    Node* root = new Node(3);
    insert(root , 7);
    insert(root , 1);
    insert(root , 5);
    inOrder(root);
    cout<<endl;
   
     fillNextPtr(root);
    cout<<root->data<<" "<<root->next->data<<endl;
    cout<<root->left->data<<" "<<root->left->next->data<<endl;
    
  
return 0;
}