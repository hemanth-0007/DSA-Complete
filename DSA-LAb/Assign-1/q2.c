#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node structure for the linked list
struct Node {
    int keyValue;          // Key value of the node
    struct Node *next;     // Pointer to the next node
};



// Function to create a new node with the given key value
struct Node *createNode(int key) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        newNode->keyValue = key;
        newNode->next = NULL;
    }
    return newNode;
}

// Function to display the linked list
void listDisplay(struct Node *head) {
    if (head == NULL)
    {
        printf("-1\n");
        return;
    }
    while (head != NULL) {
        printf("%d ", head->keyValue);
        head = head->next;
    }
    printf("\n");
}



// Function to insert a node as the last node in the linked list
void listInsert(struct Node **head, struct Node *newNode) {
    if (*head == NULL) {
        *head = newNode;  // If the list is empty, newNode becomes the head
    } else {
        struct Node *current = *head;
        while (current->next != NULL) {
            current = current->next;  // Traverse to the last node
        }
        current->next = newNode;  // Insert newNode at the end
    }
}

// Function to delete a node at the specified index in the linked list
void listDelete(struct Node **head, int index) {
    if (*head == NULL) {
        printf("-1\n");  // Empty list
        return;
    }

    if (index == 1) {
        struct Node *temp = *head;
        *head = (*head)->next;
        printf("%d\n", temp->keyValue);  // Print the deleted key value
        free(temp);
    } else {
        struct Node *current = *head;
        struct Node *prev = NULL;

        int i = 1;
        while (i < index && current != NULL) {
            prev = current;
            current = current->next;
            i++;
        }

        if (current == NULL) {
            printf("-1\n");  // Index not found
            return;
        }

        prev->next = current->next;
        printf("%d\n", current->keyValue);  // Print the deleted key value
        free(current);
    }
}

// Function to remove duplicates from the linked list
struct Node* listRemoveDuplicates(struct Node* start)
{
    struct Node *ptr1, *ptr2, *dup;
    ptr1 = start;
 
    /* Pick elements one by one */
    while (ptr1 != NULL && ptr1->next != NULL) {
        ptr2 = ptr1;
        // cout<<"ptr1->keyValue: "<<ptr1->keyValue<<"\n";
        // printf("ptr1->keyValue: %d\n", ptr1->keyValue);
        // printf("ptr2->keyValue: %d\n", ptr2->keyValue);
        /* Compare the picked element with rest
           of the elements */
        while (ptr2->next != NULL) {
            /* If duplicate then delete it */
            if (ptr1->keyValue == ptr2->next->keyValue) {
                /* sequence of steps is important here */
                dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                free(dup);
            }
            else /* This is tricky */
                ptr2 = ptr2->next;
        }
        // listDisplay(start);
        ptr1 = ptr1->next;
    }
    return start;
}



// Function to check if the linked list is a palindrome
// char listIsPalindrome(struct Node *head) {
//     if (head == NULL) {
//         return 'N';  // Empty list is not a palindrome
//     }

//     struct Node *slow = head;
//     struct Node *fast = head;
//     struct Node *prev = NULL;
//     struct Node *mid = NULL;

//     while (fast != NULL && fast->next != NULL) {
//         fast = fast->next->next;

//         struct Node *temp = slow;
//         slow = slow->next;
//         temp->next = prev;
//         prev = temp;
//     }

//     if (fast != NULL) {
//         mid = slow;
//         slow = slow->next;  // If the length is odd, move the slow pointer to the next node
//     }

//     while (prev != NULL && slow != NULL) {
//         if (prev->keyValue != slow->keyValue) {
//             return 'N';  // Not a palindrome
//         }
//         prev = prev->next;
//         slow = slow->next;
//     }

//     if (mid != NULL) {
//         mid->next = prev;
//     }

//     return 'Y';  // Palindrome
// }


int isPalindromeUtil(struct Node** left,
                      struct Node* right)
{
    /* stop recursion when right becomes NULL */
    if (right == NULL)
        return 1;
 
    /* If sub-list is not palindrome then no need to
    check for current left and right, return false */
    int isp = isPalindromeUtil(left, right->next);
    if (isp == 0)
        return 0;
 
    /* Check values at current left and right */
    int isp1 = (right->keyValue == (*left)->keyValue);
 
    /* Move left to next node */
    *left = (*left)->next;
 
    return isp1;
}
 
// A wrapper over isPalindromeUtil()
int listIsPalindrome(struct Node* head)
{
    return isPalindromeUtil(&head, head) == 1 ? 'Y' : 'N';
}



int main() {
    struct Node *head = NULL;  // Head of the linked list

    char choice;
    int key, index;

    do {
        scanf(" %c", &choice);

        switch (choice) {
            case 'a':  // Insert node at the end
                scanf("%d", &key);
                listInsert(&head, createNode(key));
                break;

            case 'r':  // Delete node at the specified index
                scanf("%d", &index);
                listDelete(&head, index);
                break;

            case 'd':  // Remove duplicates
                head =  listRemoveDuplicates(head);
                listDisplay(head);
                break;

            case 'p':  // Check if the list is a palindrome
                printf("%c\n", listIsPalindrome(head));
                break;

            case 's':  // Display the linked list
                listDisplay(head);
                break;

            case 'e':  // Exit the program
                break;

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 'e');

    return 0;
}
