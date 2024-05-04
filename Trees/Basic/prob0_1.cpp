//  FInd the maximum absolute difference between any two level sum

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
 
int Qsum(queue<Node*> q){
    int sm = 0;
    while (!q.empty())  
    {
        sm += q.front()->data;
        q.pop();
    }
    return sm;
 }




int maxLvlSum(Node* root){
    queue<Node*> q;
    q.push(root);
    int maxi = -1e9 , mini = 1e9;

    while (!q.empty())
    {
        int size = q.size();
        int sumOfQueue = Qsum(q);
        mini = min(mini, sumOfQueue);
        maxi = max(maxi,sumOfQueue);
        for (int i = 0; i < size; i++)
        {
            Node* temp = q.front();
            q.pop();
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
        
    }
    
    return (maxi - mini);
}

int main()
{
    Node* root = new Node(4);
    insert(root , 8);
    insert(root , 1);
    insert(root , 0);
    insert(root , 2);
    insert(root , 6);
    insert(root , 10);
     cout<<maxLvlSum(root);
  
return 0;
}