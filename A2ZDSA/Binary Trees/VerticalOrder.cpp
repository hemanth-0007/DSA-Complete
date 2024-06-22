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
    void helper(TreeNode *root, int row, int col,
                vector<pair<int, pair<int, int>>> &nodes)
    {
        if (root == NULL)
            return;
        nodes.push_back({root->val, {row, col}});
        helper(root->left, row + 1, col - 1, nodes);
        helper(root->right, row + 1, col + 1, nodes);
    }

    static bool comp(const pair<int, pair<int, int>> &p1, const pair<int, pair<int, int>> &p2)
    {
        if (p1.second.second != p2.second.second)
            return p1.second.second < p2.second.second;
        if (p1.second.first != p2.second.first)
            return p1.second.first < p2.second.first;
        return p1.first < p2.first;
    }

    vector<vector<int>> verticalTraversal(TreeNode *root)
    {
        vector<pair<int, pair<int, int>>> nodes;
        vector<vector<int>> ans;
        helper(root, 0, 0, nodes);
        sort(nodes.begin(), nodes.end(), Solution::comp);
        int n = nodes.size();
        int i = 0;
        while (i < n)
        {
            int col = nodes[i].second.second;
            vector<int> temp;
            while (i < n && col == nodes[i].second.second)
            {
                temp.push_back(nodes[i].first);
                i++;
            }
            // sort(temp.begin(),temp.end());
            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{

    return 0;
}
