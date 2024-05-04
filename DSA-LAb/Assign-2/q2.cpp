#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


TreeNode* buildTree(string str, int& start, int n) {
    if (n == 0 || start >= n) {
        return nullptr;
    }

    int num = 0;

    while (start < n && (str[start] != '(' && str[start] != ')')) {
        num = num * 10 + (str[start] - '0'); // Subtract ASCII value of '0' to get the numeric value
        start++;
    }

    TreeNode* root = nullptr;
    if (num > 0) root = new TreeNode(num);

    if (start < n && str[start] == '(') {
        start++;
        root->left = buildTree(str, start, n);
    }
    if (start < n && str[start] == ')') {
        start++;
        return root;
    }

    if (start < n && str[start] == '(') {
        start++;
        root->right = buildTree(str, start, n);
    }
    
    if (start < n && str[start] == ')') {
        start++;
    }
    return root;
}

TreeNode* treeFromString(string str) {
    int start = 0;
    return buildTree(str, start, str.size());
}

void levelOrderTraversal(TreeNode* root){
    if(root == NULL){
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curr = q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left != NULL){
            q.push(curr->left);
        }
        if(curr->right != NULL){
            q.push(curr->right);
        }
    }
}

bool isBST(TreeNode* root){
    if(root == NULL){
        return true;
    }
    if(root->left != NULL && root->left->data > root->data){
        return false;
    }
    if(root->right != NULL && root->right->data < root->data){
        return false;
    }
    return isBST(root->left) && isBST(root->right);

}

int sumBST(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return root->data + sumBST(root->left) + sumBST(root->right);
}

int maxSum = INT_MIN;
int maxSumBST(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    if(isBST(root)) return max(sumBST(root), maxSum);
    maxSumBST(root->left);
    maxSumBST(root->right);
}

void rightView(TreeNode* root){
    if(root == NULL){
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        for(int i=0;i<n;i++){
            TreeNode* curr = q.front();
            q.pop();
            if(i == n-1){
                cout<<curr->data<<" ";
            }
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
    }
}

int main()
{
    // string s = "1(4(2)(4))(3(2)(5(4)(6)))";
    string s;
    cin>>s;
    TreeNode* root = treeFromString(s);
    // levelOrderTraversal(root);
    // cout<<endl;
    // cout<<maxSumBST(root)<<endl;
    // rightView(root);
     char ch; // Declare the variable 'ch'
    while (1)
    {
        cin>>ch;
        switch (ch)
        {
        case 'l':  
            levelOrderTraversal(root);
            cout<<endl;
            break;
        case 'm':
            cout<<maxSumBST(root)<<endl;
            break;
        case 'r':
             rightView(root);
             cout<<endl;
            break;
        case 'e':
            return 0;
            break;
        }
    }

return 0;
}