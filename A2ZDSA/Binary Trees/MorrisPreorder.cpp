#include<bits/stdc++.h>
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

vector<int> MorrisPreorder(TreeNode* root){
    TreeNode* cur = root;
    vector<int> preorder;
     
    while(cur != NULL){
        if(cur->left == NULL){
            preorder.push_back(cur->val);
            cur = cur->right;
        }
        else{
            TreeNode* prev = cur->left;
            while(prev->right && prev->right != cur) prev = prev->right;
            if(prev->right == NULL){
                prev->right = cur;
                cur = cur->left;
                preorder.push_back(cur->val);
            }
            else{
                prev->right = NULL;
                // preorder.push_back(cur->val);
                cur = cur->right;
            }
        }
    }
    return preorder;
}


int main()
{

return 0;
}