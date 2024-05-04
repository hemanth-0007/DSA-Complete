#include <stdio.h>
#include <stdlib.h>
// Stack structure
#define MAX_SIZE 100000

struct Stack {
    char items[MAX_SIZE];
    int top;
};

// Function to initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack *stack) {
    return (stack->top == -1);
}

// Function to push an element onto the stack
void push(struct Stack *stack, char value) {
    if (stack->top < MAX_SIZE - 1) {
        stack->items[++stack->top] = value;
    } else {
        printf("Stack overflow\n");
    }
}

// Function to pop an element from the stack
void pop(struct Stack *stack) {
    if (!isEmpty(stack)) {
        stack->top--;
    } else {
        printf("Stack underflow\n");
    }
}

char top(struct Stack *stack) {
    if (!isEmpty(stack)) {
        return stack->items[stack->top];
    } else {
        printf("Stack underflow\n");
        return '\0';
    }
}

// Function to check if there are duplicate parentheses
int isDuplicateParenthesis(const char *s, int n) {
    struct Stack st;
    initialize(&st);

    int duplicate = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == ')') {
            char stackTop = top(&st);
            pop(&st);
            int elementsCount = 0;
            // printf("Entering into while loop with stackTop : %c\n", stackTop);
            while (stackTop != '(') {
                elementsCount++;
                stackTop = top(&st);
                pop(&st);
                // printf("elementsCount = %d\n", elementsCount);
                // printf("Popping %c\n", stackTop);
            }
            if (elementsCount <= 1){
                // printf("Duplicate parentheses found\n");
                return 1;
            }
        } else {
            // printf("Pushing %c\n", s[i]);
            push(&st, s[i]);
        }
    }

    return 0; // No duplicate parentheses
}

int main() {
    
    int n;
    scanf("%d", &n);
    // read a string from the user until the newline character
    char* s = (char*)malloc((n + 1) * sizeof(char)); // Allocate memory for n+1 characters
    scanf(" %[^\n]%*c", s); // Add a space before %[^\n] to skip leading whitespace
    // const char *s = "((a+b)+((c+d)))";
    // const char *s = "((a))";
    printf("%d\n", isDuplicateParenthesis(s, n));
    
    // free(s); // Free the allocated memory
    
    return 0;
}
