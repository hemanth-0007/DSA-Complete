#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};


class Solution {
public:
    unordered_map<int, vector<int>> graph;

    int amountOfTime(TreeNode* root, int start) {
        constructGraph(root);
        // Implement the BFS algorithm
        queue<int> q;
        q.push(start);

        unordered_set<int> visited;

        int minutesPassed = -1;

        while (!q.empty()) {
            ++minutesPassed;
            for (int levelSize = q.size(); levelSize > 0; --levelSize) {
                int currentNode = q.front();
                q.pop();
                visited.insert(currentNode);
                for (int adjacentNode : graph[currentNode]) {
                    if (!visited.count(adjacentNode)) {
                        q.push(adjacentNode);
                    }
                }
            }
        }

        return minutesPassed;
    }

    void constructGraph(TreeNode* root) {
        if (!root) return;

        if (root->left) {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
        }

        if (root->right) {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
        }

        constructGraph(root->left);
        constructGraph(root->right);
    }
};



int main()
{
    Solution s;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(5);
    root->left->right = new TreeNode(4);
    root->left->right->left = new TreeNode(9);
    root->left->right->right = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(10);
    root->right->right = new TreeNode(6);

    // s.constructGraph(root);
    // for(auto it : s.graph){
    //     cout << it.first << " : ";
    //     for(auto it2 : it.second){
    //         cout << it2 << " ";
    //     }
    //     cout << endl;
    // }
    cout << s.amountOfTime(root, 3) << endl;

return 0;
}