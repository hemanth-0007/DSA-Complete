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


class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        TreeNode* root = NULL;
        unordered_map<int,int>inMap;
        for (int i = 0; i < n; i++)
            inMap[inorder[i]] = i;   
        root = build(preorder, 0, n-1, inorder, 0 , n-1, inMap);
        return root;
    }
    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
              vector<int>& inorder, int inStart, int inEnd, unordered_map<int,int>&inMap){
            if(inStart > inEnd || preStart > preEnd) return NULL;
            int ind = inMap[preorder[preStart]];
            int leftLen = ind - inStart;
            TreeNode* root = new TreeNode(preorder[preStart]);
            root->left = build(preorder, preStart + 1, preStart + leftLen, 
                            inorder, inStart, ind-1,inMap);
            root->right = build(preorder,  preStart + leftLen + 1, preEnd, 
                            inorder, ind +1, inEnd,inMap);
           return root;
    }

};

int main()
{

    return 0;
}