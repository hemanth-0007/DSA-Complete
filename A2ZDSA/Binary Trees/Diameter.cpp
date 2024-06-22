#include<bits/stdc++.h>
using namespace std;


struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 

int height(TreeNode* root){
    if(!root) return 0;
    return max(1 + height(root->left) , 1 + height(root->right));
}


int helper(TreeNode* root){

    if(root == NULL) return 0;

    int leftD =  helper(root->left);
    int rightD  =  helper(root->right);
    // cur daimeter
    int dia = height(root->left) + height(root->right) - 2;

    return max(max(leftD, rightD), dia);
}

int maxi = -1;
int helperOp(TreeNode* root){

    if(root == NULL) return 0;

    int leftD = 1 + helper(root->left);
    int rightD  = 1 + helper(root->right);
    maxi = max(maxi, leftD + rightD);
    return maxi;
}


int diameterOfBinaryTree(TreeNode* root) {
    return helper(root);
}

int main()
{

return 0;
}