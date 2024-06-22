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



int helper(TreeNode* root, int &maxi){
    if(root == NULL) return 0;
    int leftMax = helper(root->left,maxi);
    int rightMax = helper(root->right, maxi);
    maxi = max(maxi, root->val + leftMax + rightMax);
    maxi = max(maxi , max( root->val, max(leftMax, rightMax)));
    return root->val + (max(leftMax, rightMax) < 0 ? 0 : max(leftMax, rightMax));
}
 
int maxPathSum(TreeNode* root) {
    int maxi = -1e9;
    // int x = helper(root, maxi);
    // cout<<x <<endl;
    int x = maxPathDown(root, maxi);
    return maxi;
}

int maxPathDown(TreeNode* root ,int & maxi){
    if(!root) return 0;
    int leftSum = max(0, maxPathDown(root->left, maxi));
    int rightSum = max(0 , maxPathDown(root->right, maxi));
    maxi = max(maxi , root->val + leftSum + rightSum);
    return root->val + max(leftSum, rightSum);
}





int main()
{

return 0;
}