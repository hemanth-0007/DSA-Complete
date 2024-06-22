#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
};

class Solution
{
public:
    
    vector<int> topView(Node *root)
    {
        queue<pair<Node*,int>> q;
        map<int, Node*> mp;
        vector<int> ans;
        q.push({root, 0});
        mp[0] = root;
        while(!q.empty()){
            Node* node = q.front().first;
            int vrt_lvl = q.front().second;
            q.pop();
            if(mp.find(vrt_lvl) == mp.end()) mp[vrt_lvl] = node;
            if(node->left) q.push({node->left, vrt_lvl-1});
            if(node->right) q.push({node->right, vrt_lvl+1});
        }
        for(auto it : mp) ans.push_back(it.second->data);
        return ans;
    }
};

int main()
{

    return 0;
}