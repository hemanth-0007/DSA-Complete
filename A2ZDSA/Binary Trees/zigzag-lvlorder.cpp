#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    stack<TreeNode*> st1, st2;
    st1.push(root);
    vector<vector<int>> ans;
    vector<int> temp;
    if(!root) return ans;
    while(!st1.empty() || !st2.empty()){
        while(!st1.empty()){
            TreeNode* node = st1.top();
            temp.push_back(node->val);
            st1.pop();
            if(node->left) st2.push(node->left);
            if(node->right) st2.push(node->right);
        }
         if(temp.size() > 0)  ans.push_back(temp);
        temp.clear();
        while(!st2.empty()){
            TreeNode* node = st2.top();
            temp.push_back(node->val);
            st2.pop();
            if(node->right) st1.push(node->right);
            if(node->left) st1.push(node->left);
        }
        if(temp.size() > 0)  ans.push_back(temp);
        temp.clear();
    }
    return ans;
}
// using a dequeue





int main()
{

    return 0;
}