#include<bits/stdc++.h>
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


TreeNode* buildTree(string str, int& start, int n) {
    if (n == 0 || start >= n) {
        return nullptr;
    }

    int num = 0;

    while (start < n && (str[start] != '(' && str[start] != ')')) {
        num = num * 10 + (str[start] - '0'); // Subtract ASCII value of '0' to get the numeric value
        start++;
    }

    TreeNode* root = nullptr;
    if (num > 0) root = new TreeNode(num);

    if (start < n && str[start] == '(') {
        start++;
        root->left = buildTree(str, start, n);
    }
    if (start < n && str[start] == ')') {
        start++;
        return root;
    }

    if (start < n && str[start] == '(') {
        start++;
        root->right = buildTree(str, start, n);
    }
    
    if (start < n && str[start] == ')') {
        start++;
    }
    return root;
}

TreeNode* treeFromString(string str) {
    int start = 0;
    return buildTree(str, start, str.size());
}

void printRangeValues(TreeNode* root, int low, int high){
    if(root == NULL){
        return;
    }
    if(root->data > low){
        printRangeValues(root->left, low, high);
    }
    if(root->data >= low && root->data <= high){
        cout<<root->data<<" ";
    }
    if(root->data < high){
        printRangeValues(root->right, low, high);
    }
}

void ancestors_helper(TreeNode* root, int key, vector<int> &v){
     if(root == NULL){
        cout<<"-1"<<endl;
        return;
    }
    if(root->data == key){
        // cout<<key<<" ";
        v.push_back(key);
        return;
    }
    if(root->data > key){
        // cout<<root->data<<" ";
        v.push_back(root->data);
        ancestors_helper(root->left, key,v);
    }
    else{
        // cout<<root->data<<" ";
        v.push_back(root->data);
        ancestors_helper(root->right, key, v);
    }
}

void ancestors(TreeNode* root, int key){
    vector<int> v;
    ancestors_helper(root, key, v);
    for(int i= v.size() - 1 ; i>= 0; i--) cout<<v[i]<<" ";
    return;
}

void inOrder(TreeNode* root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);
}

int main()
{
    string s;
    cin>>s;
    // string s = "(1(4(2)(4))(3(2)(5(4)(6)))";

    TreeNode* root = treeFromString(s);
    // inOrder(root);
    // vector<int> v;
    // search(root, 8, v);
    // for(int i= v.size() - 1 ; i>= 0; i--){
    //     cout<<v[i]<<" ";
    // }
        char ch; // Declare the variable 'ch'
    while (0)
    {
        cin>>ch;
        switch (ch)
        {
        case 'p':  
            int x, y;
            cin>>x>>y;
            printRangeValues(root, x, y);
            cout<<endl;
            break;
        case 'a':
            int key;
            cin>>key;
            ancestors(root, key);
            cout<<endl;
            break;
        case 'e':
            return 0;
            break;
        }
    }
return 0;
}