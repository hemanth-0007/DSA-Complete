#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h> // Include the missing header for INT_MIN
#include <string.h> // Include the missing header for string functions
#define MAX_SIZE 100

struct Queue {
    struct TreeNode* array[MAX_SIZE];
    int front, rear;
    int size;
};
 
// Structure to represent a tree node
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};
// Queue functions



//  Function for queue
struct Queue* createQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = queue->rear = -1;
    queue->size = 0;
    return queue;
}


int isEmptyQ(struct Queue* queue) {
    return queue->size == 0;
}

 
int isFullQ(struct Queue* queue) {
    return queue->size == MAX_SIZE;
}

void enqueue(struct Queue* queue, struct TreeNode* data) {
    if (isFullQ(queue)) {
        printf("Queue is full\n");
        return;
    }
    if (isEmptyQ(queue)) {
        queue->front = queue->rear = 0;
    } else {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    queue->array[queue->rear] = data;
    queue->size++;
}

 
struct TreeNode* dequeue(struct Queue* queue) {
    if (isEmptyQ(queue)) {
        printf("Queue is empty\n");
        return NULL;
    }
    struct TreeNode* data = queue->array[queue->front];
    if (queue->front == queue->rear) {
        queue->front = queue->rear = -1;
    } else {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    queue->size--;
    return data;
}
 
 



// Function to create a new tree node
struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Function to build a binary tree from a string representation
struct TreeNode* buildTree(char* str, int* start) {
    int n = strlen(str);
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
        root->left = buildTree(str, start);
    }

    if (*start < n && str[*start] == ')') {
        (*start)++;
        return root;
    }

    if (*start < n && str[*start] == '(') {
        (*start)++;
        root->right = buildTree(str, start);
    }

    if (*start < n && str[*start] == ')') {
        (*start)++;
    }

    return root;
}

// Function to build a binary tree from a string representation
struct TreeNode* treeFromString(char* str) {
    int start = 0;
    return buildTree(str, &start);
}


void levelOrderTraversal(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    struct TreeNode* current;
    int maxVal;
    int n;
    struct Queue* queue = createQueue();
    enqueue(queue, root);
    while (!isEmptyQ(queue)) {
        n = queue->size;
        maxVal = INT_MIN;
        for (int i = 0; i < n; i++) {
            current = dequeue(queue);
            printf("%d ", current->data);
            if (current->left != NULL) {
                enqueue(queue, current->left);
            }
            if (current->right != NULL) {
                enqueue(queue, current->right);
            }
        }
        
    }
}

// Function to check if a binary tree is a binary search tree (BST)
bool isBST(struct TreeNode* root) {
     if(root == NULL){
        return true;
    }
    if(root->left != NULL && root->left->data > root->data){
        return false;
    }
    if(root->right != NULL && root->right->data < root->data){
        return false;
    }
    return isBST(root->left) && isBST(root->right);
}

// Function to calculate the sum of all nodes in a BST
int sumBST(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return root->data + sumBST(root->left) + sumBST(root->right);
}

// Function to find the maximum sum BST in a binary tree
int maxSum = INT_MIN;
int maxSumBST(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }

    if (isBST(root)) {
        int sum = sumBST(root);
        if (sum > maxSum) {
            maxSum = sum;
        }
        return maxSum;
    }

    maxSumBST(root->left);
    maxSumBST(root->right);
 
}

 void rightView(struct TreeNode* root){
    if(root == NULL){
        return;
    }
    struct Queue* queue = createQueue();
    enqueue(queue, root);
    while(!isEmptyQ(queue)){
        int n = queue->size;
        for(int i=0;i<n;i++){
            struct TreeNode* curr = dequeue(queue);
            if(i == n-1){
                printf("%d ", curr->data);
            }
            if(curr->left != NULL){
                enqueue(queue, curr->left);
            }
            if(curr->right != NULL){
                enqueue(queue, curr->right);
            }
        }
    }
}

int main() {
    char s[100];
    scanf("%s", s);
    struct TreeNode* root = treeFromString(s);

    char ch; // Declare the variable 'ch'
    while (1) {
        scanf(" %c", &ch); // Added a space before %c to consume whitespace
        switch (ch) {
            case 'l':
                levelOrderTraversal(root);
                printf("\n");
                break;
            case 'm':
                printf("%d\n", maxSumBST(root));
                break;
            case 'r':
                rightView(root);

                
                printf("\n");
                break;
            case 'e':
                return 0;
                break;
        }
    }

    return 0;
}
