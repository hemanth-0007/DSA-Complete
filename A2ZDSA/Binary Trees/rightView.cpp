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

class Solution
{
public:
    
    vector<int> rightSideView(TreeNode *root)
    {
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;
        map<int, TreeNode*> mp;
        q.push({root, 0});
        mp[0] = root;
        while(!q.empty()){
            TreeNode* node = q.front().first;
            int lvl = q.front().second;
            q.pop();
            if(mp.find(lvl) == mp.end()) mp[lvl] = node;
            if(node->right) q.push({node->right, lvl +1});
            if(node->left) q.push({node->left, lvl +1});
        }
        for(auto it : mp) ans.push_back(it.second->val);
    }
};

int main()
{

    return 0;
}