#include<bits/stdc++.h>
#include<sstream>
using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        string s;
        if(!root) return s;
        q.push(root);
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL) s.append("#,");
            else  s.append(to_string(node->val) + ',');
            if(node != NULL){
                q.push(node->left);
                q.push(node->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<TreeNode*> q;
        string s;
        if(data.size() == 0) return NULL;
        stringstream ss(data);
        getline(ss, s, ',');
        TreeNode* root = new TreeNode(stoi(s));
        q.push(root);
        while(ss && !q.empty()){
            TreeNode* node = q.front();
            q.pop();
            getline(ss, s, ',');
            if(s == "#") node->left = NULL;
            else{
                node->left = new TreeNode(stoi(s));
                q.push(node->left);
            }
            getline(ss, s, ',');
            if(s == "#") node->right = NULL;
            else{
                node->right = new TreeNode(stoi(s));
                q.push(node->right);
            }
        }
        return root;
    }
};






int main()
{
    string s = "143243 324 3412";
    stringstream ss(s);
    string str;
    getline(ss, str, ' ');
    cout<<str<<endl;
    getline(ss, str, ' ');
    cout<<str<<endl;
    getline(ss, str, ' ');
    cout<<str<<endl;


return 0;
}   