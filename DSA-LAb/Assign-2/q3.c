#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structure to represent a tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new tree node
struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to build a binary tree from a string representation
struct TreeNode* buildTree(char* str, int* start, int n) {
    if (n == 0 || *start >= n || str[*start] == ')') {
        (*start)++;
        return NULL;
    }

    int num = 0;

    while (*start < n && (str[*start] != '(' && str[*start] != ')')) {
        num = num * 10 + (str[*start] - '0'); // Subtract ASCII value of '0' to get the numeric value
        (*start)++;
    }

    struct TreeNode* root = NULL;
    if (num > 0) {
        root = newNode(num);
    }

    if (*start < n && str[*start] == '(') {
        (*start)++;
        root->left = buildTree(str, start, n);
    }

    if (*start < n && str[*start] == ')') {
        (*start)++;
        return root;
    }

    if (*start < n && str[*start] == '(') {
        (*start)++;
        root->right = buildTree(str, start, n);
    }

    if (*start < n && str[*start] == ')') {
        (*start)++;
    }

    return root;
}

// Function to build a binary tree from a string representation
struct TreeNode* treeFromString(char* str) {
    int start = 0;
    return buildTree(str, &start, strlen(str));
}

// Function to print values within the range [low, high] in the BST
void printRangeValues(struct TreeNode* root, int low, int high) {
    if (root == NULL) {
        return;
    }

    if (root->data > low) {
        printRangeValues(root->left, low, high);
    }

    if (root->data >= low && root->data <= high) {
        printf("%d ", root->data);
    }

    if (root->data < high) {
        printRangeValues(root->right, low, high);
    }
}

// Function to find ancestors of a node with value key in the BST
void ancestors_helper(struct TreeNode* root, int key, int* v, int* count) {
    if (root == NULL) {
        printf("-1\n");
        return;
    }

    if (root->data == key) {
        v[*count] = key;
        (*count)++;
        return;
    }

    if (root->data > key) {
        v[*count] = root->data;
        (*count)++;
        ancestors_helper(root->left, key, v, count);
    } else {
        v[*count] = root->data;
        (*count)++;
        ancestors_helper(root->right, key, v, count);
    }
}

// Function to print ancestors of a node with value key in the BST
void ancestors(struct TreeNode* root, int key) {
    int v[100];
    int count = 0;
    ancestors_helper(root, key, v, &count);
    for (int i = count - 1; i >= 0; i--) {
        printf("%d ", v[i]);
    }
}

int main() {
    char s[100];
    int x, y, key;
    scanf("%s", s);
    struct TreeNode* root = treeFromString(s);

    char ch; // Declare the variable 'ch'
    while (1) {
        scanf(" %c", &ch); // Added a space before %c to consume whitespace
        switch (ch) {
            case 'p':
                scanf("%d%d", &x, &y);
                printRangeValues(root, x, y);
                printf("\n");
                break;
            case 'a':
                scanf("%d", &key);
                ancestors(root, key);
                printf("\n");
                break;
            case 'e':
                return 0;
                break;
        }
    }

    return 0;
}
