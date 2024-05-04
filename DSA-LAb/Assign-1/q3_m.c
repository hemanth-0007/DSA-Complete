#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a patient
struct Person {
    char id[20];
    int priority;
    char time[10];
};

// Structure to represent a node in the priority queue
struct Node {
    struct Person person;
    struct Node *next;
};

// Priority Queue structure
struct Queue {
    struct Node *front;
};

 

// Function to initialize the priority queue
void initializeQueue(struct Queue *Q) {
    Q->front = NULL;
}

 

// Function to admit a new patient to the ER
void admitPerson(struct Queue *Q, char id[], int priority, char time[]) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        strcpy(newNode->person.id, id);
        newNode->person.priority = priority;
        strcpy(newNode->person.time, time);
        newNode->next = NULL;

        // Insert into priority queue based on priority and admit time
        struct Node *current = Q->front;
        struct Node *prev = NULL;

        while (current != NULL && (current->person.priority > priority || (current->person.priority == priority && strcmp(current->person.time, time) < 0))) {
            prev = current;
            current = current->next;
        }

        if (prev == NULL) {
            newNode->next = Q->front;
            Q->front = newNode;
        } else {
            prev->next = newNode;
            newNode->next = current;
        }
    }
}

 

// Function to treat the next patient in the ER
void treatNextPerson(struct Queue *Q) {
    if (Q->front != NULL) {
        struct Node *temp = Q->front;
        Q->front = Q->front->next;
        printf("%s %d %s\n", temp->person.id, temp->person.priority, temp->person.time);
        free(temp);
    }
}

 

// Function to check the next patient in the ER without removing them
void checkNextPerson(struct Queue *Q) {
    if (Q->front != NULL) {
        printf("%s %d %s\n", Q->front->person.id, Q->front->person.priority, Q->front->person.time);
    }
}

 

// Function to discharge a specific patient from the ER
void dischargePerson(struct Queue *Q, char id[], char time[]) {
    struct Node *current = Q->front;
    struct Node *prev = NULL;

    while (current != NULL && (strcmp(current->person.id, id) != 0 || strcmp(current->person.time, time) != 0)) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev == NULL) {
            Q->front = current->next;
        } else {
            prev->next = current->next;
        }

        free(current);
    }
}

 
// Function to update the condition severity of a specific patient
void updateCondition(struct Queue *Q, char id[], char time[], int newPriority) {
    struct Node *current = Q->front;

    while (current != NULL && (strcmp(current->person.id, id) != 0 || strcmp(current->person.time, time) != 0)) {
        current = current->next;
    }

    if (current != NULL) {
        current->person.priority = newPriority;

        // Reorder the priority queue after updating priority
        struct Node *temp = Q->front;
        Q->front = NULL;

        while (temp != NULL) {
            struct Node *nextNode = temp->next;
            admitPerson(Q, temp->person.id, temp->person.priority, temp->person.time);
            free(temp);
            temp = nextNode;
        }
    }
}

 

// Function to print details of all patients in the priority order
void printAllPersons(struct Queue *Q) {
    struct Node *current = Q->front;

    while (current != NULL) {
        printf("%s %d %s\n", current->person.id, current->person.priority, current->person.time);
        current = current->next;
    }
}

int main() {
    struct Queue Q;
    initializeQueue(&Q);

    char op;
    char id[20];
    int priority;
    char time[10];
    int newPriority;

 

    do {
       

        scanf(" %c", &op);

        switch (op) {
            case 'a':
                scanf("%s %d %s", id, &priority, time);
                admitPerson(&Q, id, priority, time);
                break;

            case 't':
                treatNextPerson(&Q);
                break;

            case 'c':
                checkNextPerson(&Q);
                break;

            case 'd':
                scanf("%s %s", id, time);
                dischargePerson(&Q, id, time);
                break;

            case 'u':
                scanf("%s %s %d", id, time, &newPriority);
                updateCondition(&Q, id, time, newPriority);
                break;

            case 'p':
                printAllPersons(&Q);
                break;

            case 'e':
                break;

            default:
                printf("Invalid option\n");
        }

        

    } while (op != 'e');

    

    return 0;
}
