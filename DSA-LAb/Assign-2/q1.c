#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // Include the missing header for INT_MIN

#define MAX_SIZE 100

struct Stack {
    struct TreeNode* array[MAX_SIZE];
    int top;
};

struct Queue {
    struct TreeNode* array[MAX_SIZE];
    int front, rear;
    int size;
};
 
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function prototypes
struct TreeNode* buildTree(int preOrder[], int preStart, int preEnd,
                           int inOrder[], int inStart, int inEnd, int inMap[]);
struct TreeNode* build(int preOrder[], int inOrder[], int size);
void postOrder(struct TreeNode* root);
int height(struct TreeNode* root);
int diameter(struct TreeNode* tree);
int leftLeafSum(struct TreeNode* root);
int isLeaf(struct TreeNode* node);
void levelMax(struct TreeNode* root);
void zigZag(struct TreeNode* root);
// Queue functions
struct Queue* createQueue();
int isEmptyQ(struct Queue* queue);
int isFullQ(struct Queue* queue);
void enqueue(struct Queue* queue, struct TreeNode* data);
struct TreeNode* dequeue(struct Queue* queue);
// Stack functions
struct Stack* createStack();
int isEmpty(struct Stack* stack);
int isFull(struct Stack* stack);
void push(struct Stack* stack, struct TreeNode* data);
struct TreeNode* pop(struct Stack* stack);


int main() {
    int n;
    scanf("%d", &n);
    
    int inOrder[n], preOrder[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &inOrder[i]);
    }
    for (int i = 0; i < n; i++) {
        scanf("%d", &preOrder[i]);
    }
    
    struct TreeNode* root = build(preOrder, inOrder, n);

    char ch;
    while (1) {
        scanf(" %c", &ch); // Added a space before %c to consume whitespace
        switch (ch) {
            case 'p':
                postOrder(root);
                printf("\n");
                break;
            case 'z':
                zigZag(root);
                printf("\n");
                break;
            case 'm':
                levelMax(root);
                printf("\n");
                break;
            case 'd':
                printf("%d\n", diameter(root));
                break;
            case 's':
                printf("%d\n", leftLeafSum(root));
                break;
            case 'e':
                return 0;
                break;
        }
    }
    
    return 0;
}


// stack functions
 
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->top = -1;
    return stack;
}

 
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

 
int isFull(struct Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

 
void push(struct Stack* stack, struct TreeNode* data) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->array[++stack->top] = data;
}

 
struct TreeNode* pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return NULL;
    }
    return stack->array[stack->top--];
}






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
 
 
 
// Function to build the tree
struct TreeNode* build(int preOrder[], int inOrder[], int size) {
    if (size == 0) {
        return NULL;
    }

    int inMap[size];
    for (int i = 0; i < size; i++)
        inMap[inOrder[i]] = i;

    return buildTree(preOrder, 0, size - 1, inOrder, 0, size - 1, inMap);
}

// Recursive function to construct binary tree from preOrder and inOrder traversals
struct TreeNode* buildTree(int preOrder[], int preStart, int preEnd,
                           int inOrder[], int inStart, int inEnd, int inMap[]) {
    if (preStart > preEnd || inStart > inEnd) {
        return NULL;
    }

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->data = preOrder[preStart];
    int inRoot = inMap[root->data];
    int numsLeft = inRoot - inStart;

    root->left = buildTree(preOrder, preStart + 1, preStart + numsLeft,
                           inOrder, inStart, inRoot - 1, inMap);
    root->right = buildTree(preOrder, preStart + numsLeft + 1,
                            preEnd, inOrder, inRoot + 1, inEnd, inMap);

    return root;
}

// Function to print postorder traversal of the tree
void postOrder(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
}

// Function to calculate the height of the tree
int height(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return 1 + (leftHeight > rightHeight ? leftHeight : rightHeight);
}

// Function to calculate the diameter of the tree
int diameter(struct TreeNode* tree) {
    if (tree == NULL) {
        return 0;
    }

    int lHeight = height(tree->left);
    int rHeight = height(tree->right);
    int lDiameter = diameter(tree->left);
    int rDiameter = diameter(tree->right);

    int maxDiameter = lHeight + rHeight + 1;
    if (lDiameter > maxDiameter)
        maxDiameter = lDiameter;
    if (rDiameter > maxDiameter)
        maxDiameter = rDiameter;

    return maxDiameter;
}

int isLeaf(struct TreeNode* node) {
    return (node->left == NULL && node->right == NULL);
}

// Function to find the sum of left leaf nodes
int leftLeafSum(struct TreeNode* root) {
    if (root != NULL) {
        if (root->left != NULL && isLeaf(root->left))
            return root->left->data + leftLeafSum(root->left) + leftLeafSum(root->right);
        else return leftLeafSum(root->left) + leftLeafSum(root->right);
    }
    else return 0;
}

// Function to print the maximum element at each level of the tree
void levelMax(struct TreeNode* root) {
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
            if (current->data > maxVal) {
                maxVal = current->data;
            }
            if (current->left != NULL) {
                enqueue(queue, current->left);
            }
            if (current->right != NULL) {
                enqueue(queue, current->right);
            }
        }
        printf("%d ", maxVal);
    }
}

// Function to print the zigzag order traversal of the tree
void zigZag(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    struct Stack* stack1 = createStack();
    struct Stack* stack2 = createStack();
    push(stack1, root);
    while (!isEmpty(stack1) || !isEmpty(stack2)) {
        while (!isEmpty(stack1)) {
            struct TreeNode* current = pop(stack1);
            printf("%d ", current->data);
            if (current->left != NULL) {
                push(stack2, current->left);
            }
            if (current->right != NULL) {
                push(stack2, current->right);
            }
        }
        while (!isEmpty(stack2)) {
            struct TreeNode* current = pop(stack2);
            printf("%d ", current->data);
            if (current->right != NULL) {
                push(stack1, current->right);
            }
            if (current->left != NULL) {
                push(stack1, current->left);
            }
        }
    }
}
