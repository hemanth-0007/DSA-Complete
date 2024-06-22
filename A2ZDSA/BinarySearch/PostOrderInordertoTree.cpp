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


class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        TreeNode* root = NULL;
        unordered_map<int,int>inMap;
        for (int i = 0; i < n; i++)
            inMap[inorder[i]] = i;   
        root = build(postorder, 0, n-1, inorder, 0 , n-1, inMap);
        return root;
    }
    TreeNode* build(vector<int>& postorder, int postStart, int postEnd,
              vector<int>& inorder, int inStart, int inEnd, unordered_map<int,int>&inMap){
            if(inStart > inEnd || postStart > postEnd) return NULL;
            TreeNode* root = new TreeNode(postorder[postEnd]);
            int ind = inMap[root->val];
            int rightLen = inEnd - ind;
            root->left = build(postorder, postStart, postEnd - rightLen-1, 
                            inorder, inStart, ind-1,inMap);
            root->right = build(postorder,  postEnd - rightLen, postEnd-1, 
                            inorder, ind +1, inEnd,inMap);
           return root;
    }

};

int main()
{

return 0;
}