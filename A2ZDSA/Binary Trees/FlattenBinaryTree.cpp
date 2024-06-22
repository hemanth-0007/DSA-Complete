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
 

class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == NULL) return;
        flatten(root->left);
        flatten(root->right);
        TreeNode* leftNode = root->left, *rightNode = root->right;
        if(!rightNode && !leftNode) return;
        else if(leftNode && !rightNode){
             root->left = NULL;
             root->right = leftNode;
        }
        else if(rightNode && leftNode){
                root->left = NULL;
                root->right = leftNode;
                while(leftNode->right) leftNode = leftNode->right;
                leftNode->right = rightNode;
        } 
        return;
    }
};

int main()
{

return 0;
}