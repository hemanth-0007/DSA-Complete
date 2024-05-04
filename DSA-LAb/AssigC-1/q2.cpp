#include <bits/stdc++.h>
using namespace std;

int leftRot = 0, rightRot = 0;

struct AVL
{
    struct AVL *left;
    struct AVL *right;
    int key;
    int value;
    struct AVL *par;
    int height;
    AVL()
    {
        left = NULL;
        right = NULL;
        par = NULL;
        height = 0;
    }
} typedef AVL;

void print_preorder(AVL *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        print_preorder(root->left);
        print_preorder(root->right);
    }
}

void Updateheight(AVL *root)
{
    if (root != NULL)
    {

        int val = 1;

        if (root->left != NULL)
            val = root->left->height + 1;

        if (root->right != NULL)
            val = max(
                val, root->right->height + 1);
        root->height = val;
    }
}

AVL *LLR(AVL *root)
{
    rightRot++;
    
    AVL *tmpnode = root->left;

    root->left = tmpnode->right;

    if (tmpnode->right != NULL)
        tmpnode->right->par = root;

    tmpnode->right = root;

    tmpnode->par = root->par;

    root->par = tmpnode;

    if (tmpnode->par != NULL && root->key < tmpnode->par->key)
    {
        tmpnode->par->left = tmpnode;
    }
    else
    {
        if (tmpnode->par != NULL)
            tmpnode->par->right = tmpnode;
    }

    root = tmpnode;

    Updateheight(root->left);
    Updateheight(root->right);
    Updateheight(root);
    Updateheight(root->par);

    return root;
}

AVL *RRR(AVL *root)
{
    leftRot++;
    AVL *tmpnode = root->right;

    root->right = tmpnode->left;


    if (tmpnode->left != NULL)
        tmpnode->left->par = root;

    tmpnode->left = root;

    tmpnode->par = root->par;

    root->par = tmpnode;

    if (tmpnode->par != NULL && root->key < tmpnode->par->key)
    {
        tmpnode->par->left = tmpnode;
    }
    else
    {
        if (tmpnode->par != NULL)
            tmpnode->par->right = tmpnode;
    }

    root = tmpnode;

    Updateheight(root->left);
    Updateheight(root->right);
    Updateheight(root);
    Updateheight(root->par);
 
    return root;
}

AVL *LRR(AVL *root)
{
    rightRot++;
    root->left = RRR(root->left);
    return LLR(root);
}

AVL *RLR(AVL *root)
{
    leftRot++;
    root->right = LLR(root->right);
    return RRR(root);
}

AVL *Balance(AVL *root)
{
     
    int firstheight = 0;
    int secondheight = 0;

    if (root->left != NULL)
        firstheight = root->left->height;

    if (root->right != NULL)
        secondheight = root->right->height;

     
    if (abs(firstheight - secondheight) == 2)
    {
        if (firstheight < secondheight)
        {

            int rightheight1 = 0;
            int rightheight2 = 0;
            if (root->right->right != NULL)
                rightheight2 = root->right->right->height;

            if (root->right->left != NULL)
                rightheight1 = root->right->left->height;

            if (rightheight1 > rightheight2)
            {
                root = RLR(root);
            }
            else
            {
                root = RRR(root);
            }
        }
        else
        {
            int leftheight1 = 0;
            int leftheight2 = 0;
            if (root->left->right != NULL)
                leftheight2 = root->left->right->height;

            if (root->left->left != NULL)
                leftheight1 = root->left->left->height;

            if (leftheight1 > leftheight2)
            {
                root = LLR(root);
            }
            else
            {
                root = LRR(root);
            }
        }
    }

    
    return root;
}

AVL* insert_node_util(AVL* root, AVL* parent, int key, int value)
{
 
    if (root == NULL) {
 
        // Create and assign values
        // to a new node
        root = new  AVL;
 
        // If the root is NULL
        if (root == NULL) {
            cout << "Error in memory"
                 << endl;
        }
        else {
            root->height = 1;
            root->left = NULL;
            root->right = NULL;
            root->par = parent;
            root->key = key;
            root->value = value;
        }
    }
 
    else if (root->key > key) {
 
        // Recur to the left subtree
        // to insert the node
        root->left = insert_node_util(root->left,root, key, value);
 
        // Store the heights of the
        // left and right subtree
        int firstheight = 0;
        int secondheight = 0;
 
        if (root->left != NULL)
            firstheight = root->left->height;
 
        if (root->right != NULL)
            secondheight = root->right->height;
 
        // Balance the tree if the
        // current node is not balanced
        if (abs(firstheight - secondheight) == 2) {
 
            if (root->left != NULL && key < root->left->key) {
                // Left Left Case
                root = LLR(root);
            }
            else {
 
                // Left Right Case
                root = LRR(root);
            }
        }
    }
 
    else if (root->key < key) {
 
        // Recur to the right subtree
        // to insert the node
        root->right = insert_node_util(root->right, root, key, value);
 
        // Store the heights of the
        // left and right subtree
        int firstheight = 0;
        int secondheight = 0;
 
        if (root->left != NULL)
            firstheight
                = root->left->height;
 
        if (root->right != NULL)
            secondheight = root->right->height;
 
        // Balance the tree if the
        // current node is not balanced
        if (abs(firstheight - secondheight) == 2) {
            if (root->right != NULL  && key < root->right->key) {
                // Right Left Case
                root = RLR(root);
            }
            else {
                // Right Right Case
                root = RRR(root);
            }
        }
    }
 

 
    // Update the height of the
    // root node
    Updateheight(root);
 
    // Return the root node
    return root;
}

AVL *search_util(AVL *root, int key)
{
    if (root == NULL || root->key == key)
        return root;

    if (root->key < key)
        return search_util(root->right, key);

    return search_util(root->left, key);
}

AVL *insert_node(AVL *root, AVL *parent, int key, int value)
{
    AVL* node = search_util(root, key);
    if (node != NULL)
    {
        node->value = value;
        return root;
    }
        return insert_node_util(root, parent, key, value);
     
}

AVL *Delete(AVL *root, int key)
{
    if (root != NULL)
    {

        // If the node is found
        if (root->key == key)
        {

            // Replace root with its
            // left child
            if (root->right == NULL && root->left != NULL)
            {
                if (root->par != NULL)
                {
                    if (root->par->key < root->key)
                        root->par->right = root->left;
                    else
                        root->par->left = root->left;

                    // Update the height
                    // of root's parent
                    Updateheight(root->par);
                }

                root->left->par = root->par;

                // Balance the node
                // after deletion
                root->left = Balance(
                    root->left);

                return root->left;
            }

            // Replace root with its
            // right child
            else if (root->left == NULL && root->right != NULL)
            {
                if (root->par != NULL)
                {
                    if (root->par->key < root->key)
                        root->par->right = root->right;
                    else
                        root->par->left = root->right;

                    // Update the height
                    // of the root's parent
                    Updateheight(root->par);
                }

                root->right->par = root->par;

                // Balance the node after
                // deletion
                root->right = Balance(root->right);
                return root->right;
            }

            // Remove the references of
            // the current node
            else if (root->left == NULL && root->right == NULL)
            {
                if (root->par->key < root->key)
                {
                    root->par->right = NULL;
                }
                else
                {
                    root->par->left = NULL;
                }

                if (root->par != NULL)
                    Updateheight(root->par);

                root = NULL;
                return NULL;
            }

            // Otherwise, replace the
            // current node with its
            // successor and then
            // recursively call Delete()
            else
            {
                AVL *tmpnode = root;
                tmpnode = tmpnode->right;
                while (tmpnode->left != NULL)
                {
                    tmpnode = tmpnode->left;
                }

                int val = tmpnode->key;

                root->right = Delete(root->right, tmpnode->key);

                root->key = val;

                // Balance the node
                // after deletion
                root = Balance(root);
            }
        }

        // Recur to the right subtree to
        // delete the current node
        else if (root->key < key)
        {
            root->right = Delete(root->right, key);

            root = Balance(root);
        }

        // Recur into the right subtree
        // to delete the current node
        else if (root->key > key)
        {
            root->left = Delete(root->left, key);

            root = Balance(root);
        }

        // Update height of the root
        if (root != NULL)
        {
            Updateheight(root);
        }
    }

    // Handle the case when the key to be
    // deleted could not be found
    else
    {
        cout << "Key to be deleted "
             << "could not be found\n";
    }

    // Return the root node
    return root;
}



void print_path(AVL *root, AVL *node)
{
    if (root->key == node->key)
    {
        cout << root->key << endl;
        return;
    }
    if (root->key < node->key)
    {
        cout << root->key << " ";
        print_path(root->right, node);
    }
    else
    {
        cout << root->key << " ";
        print_path(root->left, node);
    }
}

void search_node(AVL *root, int key)
{
    AVL *node = search_util(root, key);
    if (node != NULL) cout << node->key<<" " << node->value << endl;
    else
        cout << "-1" << endl;
}

int size_of_avl(AVL *root)
{
    if (root == NULL)
        return 0;
    else
        return size_of_avl(root->left) + size_of_avl(root->right) + 1;
}

void avl_is_empty(AVL *root)
{
    if (root == NULL)
        cout<<"1"<<endl;
    else
        cout<<"0"<<endl;
}

void print_inorder(AVL *root)
{
    if (root != NULL)
    {
        print_inorder(root->left);
        cout << root->key << " ";
        print_inorder(root->right);
    }
}

void lower_bound_avl(AVL *root, int key)
{
    AVL *node = search_util(root, key);
    if (node != NULL)
    {
        cout << node->key << " " << node->value << endl;
    }
    else
    {
        AVL *tmp = root;
        AVL *res = NULL;
        while (tmp != NULL)
        {
            if (tmp->key < key)
            {
                tmp = tmp->right;
            }
            else if (tmp->key > key)
            {
                res = tmp;
                tmp = tmp->left;
            }
            else
            {
                res = tmp;
                break;
            }
        }
        if (res != NULL)
        {
            cout << res->key << " " << res->value << endl;
        }
        else
        {
            cout << "-1" << endl;
        }
    }
}

int main()
{
    AVL *root;
    root = NULL;
    char ch;
    int key, value;
    do
    {
        cin >> ch;
        switch (ch)
        {
        case 'i':
            cin >> key>>value;
            root = insert_node(root, NULL, key, value);
            break;
        case 'l':
        // lower bound
            cin >> key;
            lower_bound_avl(root, key);
            break;
        case 'f':
            cin >> key;
            search_node(root, key);
            break;
        case 's':
            cout << size_of_avl(root) << endl;
            break;
        case 'e':
            avl_is_empty(root);
            break;
        case 'p':
            print_inorder(root);
            cout << endl;
            break;
        case 't':
            return 0;
            break;
        }
    } while (1);
}
