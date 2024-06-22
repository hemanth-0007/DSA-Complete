#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;
};

bool isLeaf(Node* root){
    if(root && (!root->left && !root->right)) return false;
    return true;
}


void leftBoundary(Node *root, vector<int> &ans)
{
    Node* cur = root->left;
    while (cur)
    {
        if(!isLeaf(cur)) ans.push_back(cur->data);
        if(cur->left) cur = cur->left;
        else cur = cur->right;
    }
    return;
}

void leafNodes(Node *root, vector<int> &ans)
{
    if(isLeaf(root)){
        ans.push_back(root->data);
        return;
    }
    if(root->left) leafNodes(root->left, ans);
    if(root->right) leafNodes(root->right, ans);
}

void rightRevereseBoundary(Node *root, vector<int> &ans)
{
    stack<int> st;
    Node* cur = root->right;
    while (cur)
    {
        if(!isLeaf(cur)) st.push(cur->data);
        if(cur->right) cur = cur->right;
        else cur = cur->left;
    }
     
    while (!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    return;
}

vector<int> boundary(Node *root)
{

    if (!root)
        return {};
    vector<int> ans;
    if(root) ans.push_back(root->data);
    leftBoundary(root, ans);
    leafNodes(root, ans);
    rightRevereseBoundary(root->right, ans);
    return ans;
}

int main()
{

    return 0;
}