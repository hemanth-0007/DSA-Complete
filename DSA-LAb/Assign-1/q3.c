#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a patient
struct Patient {
    char name[20];
    int priority;
    char admitTime[10];
};

// Structure to represent a node in the priority queue
struct Node {
    struct Patient patient;
    struct Node *next;
};

// Priority Queue structure
struct PriorityQueue {
    struct Node *front;
};

// Function to initialize the priority queue
void initializePriorityQueue(struct PriorityQueue *priorityQ) {
    priorityQ->front = NULL;
}

// Function to admit a new patient to the ER
void admitPatient(struct PriorityQueue *priorityQ, char name[], int priority, char admitTime[]) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode != NULL) {
        strcpy(newNode->patient.name, name);
        newNode->patient.priority = priority;
        strcpy(newNode->patient.admitTime, admitTime);
        newNode->next = NULL;

        // Insert into priority queue based on priority and admit time
        struct Node *current = priorityQ->front;
        struct Node *prev = NULL;

        while (current != NULL && (current->patient.priority > priority || (current->patient.priority == priority && strcmp(current->patient.admitTime, admitTime) < 0))) {
            prev = current;
            current = current->next;
        }

        if (prev == NULL) {
            newNode->next = priorityQ->front;
            priorityQ->front = newNode;
        } else {
            prev->next = newNode;
            newNode->next = current;
        }
    }
}

// Function to treat the next patient in the ER
void treatNextPatient(struct PriorityQueue *priorityQ) {
    if (priorityQ->front != NULL) {
        struct Node *temp = priorityQ->front;
        priorityQ->front = priorityQ->front->next;
        printf("%s %d %s\n", temp->patient.name, temp->patient.priority, temp->patient.admitTime);
        free(temp);
    }
}

// Function to check the next patient in the ER without removing them
void checkNextPatient(struct PriorityQueue *priorityQ) {
    if (priorityQ->front != NULL) {
        printf("%s %d %s\n", priorityQ->front->patient.name, priorityQ->front->patient.priority, priorityQ->front->patient.admitTime);
    }
}

// Function to discharge a specific patient from the ER
void dischargePatient(struct PriorityQueue *priorityQ, char name[], char admitTime[]) {
    struct Node *current = priorityQ->front;
    struct Node *prev = NULL;

    while (current != NULL && (strcmp(current->patient.name, name) != 0 || strcmp(current->patient.admitTime, admitTime) != 0)) {
        prev = current;
        current = current->next;
    }

    if (current != NULL) {
        if (prev == NULL) {
            priorityQ->front = current->next;
        } else {
            prev->next = current->next;
        }

        free(current);
    }
}

// Function to update the condition severity of a specific patient
void updateConditionSeverity(struct PriorityQueue *priorityQ, char name[], char admitTime[], int newPriority) {
    struct Node *current = priorityQ->front;

    while (current != NULL && (strcmp(current->patient.name, name) != 0 || strcmp(current->patient.admitTime, admitTime) != 0)) {
        current = current->next;
    }

    if (current != NULL) {
        current->patient.priority = newPriority;

        // Reorder the priority queue after updating priority
        struct Node *temp = priorityQ->front;
        priorityQ->front = NULL;

        while (temp != NULL) {
            struct Node *nextNode = temp->next;
            admitPatient(priorityQ, temp->patient.name, temp->patient.priority, temp->patient.admitTime);
            free(temp);
            temp = nextNode;
        }
    }
}

// Function to print details of all patients in the priority order
void printAllPatients(struct PriorityQueue *priorityQ) {
    struct Node *current = priorityQ->front;

    while (current != NULL) {
        printf("%s %d %s\n", current->patient.name, current->patient.priority, current->patient.admitTime);
        current = current->next;
    }
}

int main() {
    struct PriorityQueue priorityQ;
    initializePriorityQueue(&priorityQ);

    char option;
    char name[20];
    int priority;
    char admitTime[10];
    int newPriority;

    do {
        scanf(" %c", &option);

        switch (option) {
            case 'a':
                scanf("%s %d %s", name, &priority, admitTime);
                admitPatient(&priorityQ, name, priority, admitTime);
                break;

            case 't':
                treatNextPatient(&priorityQ);
                break;

            case 'c':
                checkNextPatient(&priorityQ);
                break;

            case 'd':
                scanf("%s %s", name, admitTime);
                dischargePatient(&priorityQ, name, admitTime);
                break;

            case 'u':
                scanf("%s %s %d", name, admitTime, &newPriority);
                updateConditionSeverity(&priorityQ, name, admitTime, newPriority);
                break;

            case 'p':
                printAllPatients(&priorityQ);
                break;

            case 'e':
                break;

            default:
                printf("Invalid option\n");
        }

    } while (option != 'e');

    return 0;
}
