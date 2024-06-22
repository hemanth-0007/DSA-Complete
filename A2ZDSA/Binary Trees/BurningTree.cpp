#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
    private:
    void markParent(Node* root, unordered_map<Node*, Node*> &parent){
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
           Node* node = q.front(); q.pop();
           if(node->left){
                parent[node->left] = node;
                q.push(node->left);
           } 
           if(node->right){
                parent[node->right] = node;
                q.push(node->right);
           } 
        }
        return;
    }
    Node* getNode(Node* root, int target){
        if(!root) return NULL;
        Node* l = getNode(root->left, target);
        Node* r = getNode(root->right, target);
        if(l) return l;
        if(r) return r;
        if(target == root->data) return root;
        return NULL;
    }
public:
    int minTime(Node *root, int target)
    {
        unordered_map<Node* , Node*> parent;
        markParent(root, parent);
        Node* tar = getNode(root, target);
        queue<Node*> q;
        unordered_map<Node* , bool> visited;
        int time = 0;
        q.push(tar);
        visited[tar] = true;
        while(!q.empty()){
            int size = q.size();
            time++;
            for (int i = 0; i < size; i++)
            {
                Node* node = q.front(); q.pop();
                if(node->left && !visited[node->left]){
                    q.push(node->left);
                    visited[node->left] = true;
                }
                if(node->right && !visited[node->right]){
                    q.push(node->right);
                    visited[node->right] = true;
                }
                if(parent[node] && !visited[parent[node]]){
                    q.push(parent[node]);
                    visited[parent[node]] = true;
                }
            } 
        }
        return time-1;
    }
};

int main()
{

    return 0;
}