#include <stdio.h>
#include <stdlib.h>

int leftRot = 0, rightRot = 0;

typedef struct AVL
{
    struct AVL *left;
    struct AVL *right;
    int key;
    struct AVL *par;
    int height;
} AVL;

void print_preorder(AVL *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        print_preorder(root->left);
        print_preorder(root->right);
    }
}

void print_inorder(AVL *root)
{
    if (root != NULL)
    {
        print_inorder(root->left);
        printf("%d ", root->key);
        print_inorder(root->right);
    }
}

int max(int a, int b)
{
    return a > b ? a : b;
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
    root->left = RRR(root->left);
    return LLR(root);
}

AVL *RLR(AVL *root)
{
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

AVL* insert_node(AVL* root, AVL* parent, int key)
{
 
    if (root == NULL) {
 
        // Create and assign values
        // to a new node
       root = (AVL *)malloc(sizeof(AVL));
        // If the root is NULL
        if (root == NULL) {
             printf("Error in memory\n");
        }
 
        // Otherwise
        else {
            root->height = 1;
            root->left = NULL;
            root->right = NULL;
            root->par = parent;
            root->key = key;
        }
    }
 
    else if (root->key > key) {
 
        // Recur to the left subtree
        // to insert the node
        root->left = insert_node(root->left,
                            root, key);
 
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
        if (abs(firstheight
                - secondheight)
            == 2) {
 
            if (root->left != NULL
                && key < root->left->key) {
 
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
        root->right = insert_node(root->right,
                             root, key);
 
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
            if (root->right != NULL
                && key < root->right->key) {
 
                // Right Left Case
                root = RLR(root);
            }
            else {
 
                // Right Right Case
                root = RRR(root);
            }
        }
    }
 
    // Case when given key is already
    // in the tree
    else {
    }
 
    // Update the height of the
    // root node
    Updateheight(root);
 
    // Return the root node
    return root;
}

AVL *Delete(AVL *root, int key)
{
    if (root != NULL)
    {
        if (root->key == key)
        {
            if (root->right == NULL && root->left != NULL)
            {
                if (root->par != NULL)
                {
                    if (root->par->key < root->key)
                        root->par->right = root->left;
                    else
                        root->par->left = root->left;
                    Updateheight(root->par);
                }
                root->left->par = root->par;
                root->left = Balance(root->left);
                return root->left;
            }
            else if (root->left == NULL && root->right != NULL)
            {
                if (root->par != NULL)
                {
                    if (root->par->key < root->key)
                        root->par->right = root->right;
                    else
                        root->par->left = root->right;
                    Updateheight(root->par);
                }
                root->right->par = root->par;
                root->right = Balance(root->right);
                return root->right;
            }
            else if (root->left == NULL && root->right == NULL)
            {
                if (root->par->key < root->key)
                    root->par->right = NULL;
                else
                    root->par->left = NULL;
                if (root->par != NULL)
                    Updateheight(root->par);
                root = NULL;
                return NULL;
            }
            else
            {
                AVL *tmpnode = root;
                tmpnode = tmpnode->right;
                while (tmpnode->left != NULL)
                    tmpnode = tmpnode->left;
                int val = tmpnode->key;
                root->right = Delete(root->right, tmpnode->key);
                root->key = val;
                root = Balance(root);
            }
        }
        else if (root->key < key)
        {
            root->right = Delete(root->right, key);
            root = Balance(root);
        }
        else if (root->key > key)
        {
            root->left = Delete(root->left, key);
            root = Balance(root);
        }
        if (root != NULL)
            Updateheight(root);
    }
    else
        printf("Key to be deleted could not be found\n");
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

void print_path(AVL *root, AVL *node)
{
    if (root->key == node->key)
    {
        printf("%d\n", root->key);
        return;
    }
    if (root->key < node->key)
    {
        printf("%d ", root->key);
        print_path(root->right, node);
    }
    else
    {
        printf("%d ", root->key);
        print_path(root->left, node);
    }
}

void search_node(AVL *root, int key)
{
    AVL *node = search_util(root, key);
    if (node != NULL)
        print_path(root, node);
    else
        printf("-1\n");
}

int main()
{
    AVL *root;
    root = NULL;
    char ch;
    int key;
    do
    {
        scanf(" %c", &ch);
        switch (ch)
        {
        case 'i':
            scanf("%d", &key);
            root = insert_node(root, NULL, key);
            break;
        case 'x':
            scanf("%d", &key);
            search_node(root, key);
            break;
        case 'p':
            print_preorder(root);
            printf("\n");
            break;
        case 'o':
            print_inorder(root);
            printf("\n");
            break;
        case 's':
            printf("%d %d\n", leftRot, rightRot);
            break;
        case 'e':
            return 0;
            break;
        }
    } while (1);
}
