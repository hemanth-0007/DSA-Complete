#include<bits/stdc++.h>
#include<queue> // Add the missing include statement for the <queue> library

using namespace std;

struct TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

TreeNode* buildTree(vector<int> &preOrder, int preStart, int preEnd,
                    vector<int>& inOrder, int inStart, int inEnd, map<int, int> &inMap);

TreeNode* build(vector<int> &preOrder, vector<int>& inOrder){
    if(preOrder.size() == 0){
        return NULL;
    }
    map<int, int> inMap;
    for(int i=0;i<inOrder.size();i++)inMap[inOrder[i]] = i;

    TreeNode* root = buildTree(preOrder, 0, preOrder.size()-1, 
                            inOrder, 0, inOrder.size()-1, inMap);
    return root;
}

TreeNode* buildTree(vector<int> &preOrder, int preStart, int preEnd,
                    vector<int>& inOrder, int inStart, int inEnd, map<int, int> &inMap){
    if(preStart > preEnd || inStart > inEnd){
        return NULL;
    }
    TreeNode* root = new TreeNode(preOrder[preStart]);
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTree(preOrder, preStart+1, preStart+numsLeft,
                             inOrder, inStart, inRoot-1, inMap);
    root->right = buildTree(preOrder, preStart+numsLeft+1, 
                             preEnd, inOrder, inRoot+1, inEnd, inMap);
    return root;
}

void postOrder(TreeNode* root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
}

int height(TreeNode* root){
    if(root == NULL){
        return 0;
    }
    return 1 + max(height(root->left), height(root->right));
}

int diameter(TreeNode* tree)
{
    if (tree == NULL)
        return 0;
 
    int lheight = height(tree->left);
    int rheight = height(tree->right); 
    int ldiameter = diameter(tree->left);
    int rdiameter = diameter(tree->right);
    return max(lheight + rheight + 1,
               max(ldiameter, rdiameter));
}
int leftLeafSum(TreeNode* root){

    if(root != NULL){
        if(root->left->left == NULL && root->left->right == NULL)
            return root->left->data;
        return leftLeafSum(root->left) + leftLeafSum(root->right);
    }
       
}


void levelMax(TreeNode* root){
    if(root == NULL){
        return;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        int maxVal = INT_MIN;
        for(int i=0;i<n;i++){
            TreeNode* curr = q.front();
            q.pop();
            maxVal = max(maxVal, curr->data);
            if(curr->left != NULL){
                q.push(curr->left);
            }
            if(curr->right != NULL){
                q.push(curr->right);
            }
        }
        cout<<maxVal<<" ";
    }
}


void zigZag(TreeNode* root){
    if(root == NULL){
        return;
    }
    stack<TreeNode*> s1;
    stack<TreeNode*> s2;
    s1.push(root);
    while(!s1.empty() || !s2.empty()){
        while(!s1.empty()){
            TreeNode* curr = s1.top();
            s1.pop();
            cout<<curr->data<<" ";
            if(curr->left != NULL){
                s2.push(curr->left);
            }
            if(curr->right != NULL){
                s2.push(curr->right);
            }
        }
        while(!s2.empty()){
            TreeNode* curr = s2.top();
            s2.pop();
            cout<<curr->data<<" ";
            if(curr->right != NULL){
                s1.push(curr->right);
            }
            if(curr->left != NULL){
                s1.push(curr->left);
            }
        }
    }
}



int main()
{
    
    int n;
    cin>>n;
    vector<int> inOrder, preOrder;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        inOrder.push_back(x);
    }
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        preOrder.push_back(x);
    }
    // vector<int> inOrder = {4 ,2 ,5 ,1 ,6 ,3 ,7};
    // vector<int> preOrder = {1 ,2 ,4 ,5 ,3 ,6 ,7};
    TreeNode* root = build(preOrder, inOrder);
    // cout<<root->data<<endl;
    // cout<<diameter(root)<<endl;
    // levelMax(root);
    // cout<<endl;
    // cout<<leftLeafSum(root)<<endl;
    // postOrder(root);
    // cout<<endl;
    // zigZag(root);
    char ch; // Declare the variable 'ch'
    while (1)
    {
        cin>>ch;
        switch (ch)
        {
        case 'p':  
            postOrder(root);
            cout<<endl;
            break;
        case 'z':
            zigZag(root);
            cout<<endl;
            break;
        case 'm':
             levelMax(root);
             cout<<endl;
            break;
        case 'd':
            cout<<diameter(root)<<endl;
            break;
        case 's':
            cout<<leftLeafSum(root)<<endl;
            break;
        case 'e':
            return 0;
            break;
        }
    }
    
    



    return 0;
}

