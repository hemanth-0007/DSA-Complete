#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = NULL;
        right = NULL;
    }
};

class Solution
{
private:
    void helper(Node* root, Node*& head, Node*& cur){
        if(root == NULL) return;
        helper(root->left, head, cur);
        if(head == NULL){
            head = root;
            cur = root;
        }
        else{
            cur->right = root;
            root->left = cur;
            cur = root;
        }
        helper(root->right, head, cur);
    }    
public:
    Node *flattenBST(Node *root)
    {
        Node* head = NULL;
        Node* cur = NULL;
        helper(root, head, cur);
        return head;
       
    }
};



int main()
{

return 0;
}