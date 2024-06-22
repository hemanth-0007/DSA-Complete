#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

bool helper(TreeNode* root){
    if(root->val == 1 || root->val == 0) return root->val;
    else if(root->val == 3) return helper(root->left) && helper(root->right);
    else if(root->val == 2) return helper(root->left) || helper(root->right);
}
 

bool evaluateTree(TreeNode *root)
{
    return helper(root);
}
int main()
{

    return 0;
}