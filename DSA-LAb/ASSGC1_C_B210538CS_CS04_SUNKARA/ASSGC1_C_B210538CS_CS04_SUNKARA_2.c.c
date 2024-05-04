#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1000

// Structure to represent a node in the chain
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// Structure to represent a hash table with chaining
typedef struct HashTable {
    Node* table[MAX_SIZE];
    int size;
} HashTable;

// Function to initialize a hash table
void initializeHashTable(HashTable* hashTable, int size) {
    hashTable->size = size;
    for (int i = 0; i < size; ++i) {
        hashTable->table[i] = NULL;
    }
}

// Function to search for a key in the hash table
void search(HashTable* hashTable, int key) {
    int index = key % hashTable->size;
    Node* current = hashTable->table[index];
    // int position = 0;
    int position = 1; // maybe one depending upon the situation
    
    while (current != NULL && current->key != key) {
        current = current->next;
        position++;
    }
    
    if (current == NULL) {
        printf("-1\n");
    } else {
        printf("%d %d\n", index, position);
    }
}

Node* searchNode(HashTable* hashTable, int key) {
    int index = key % hashTable->size;
    Node* current = hashTable->table[index];
    int position = 1;
    
    while (current != NULL && current->key != key) {
        current = current->next;
        position++;
    }
    
    return current;
}

// Function to insert a key into the hash table
void insert(HashTable* hashTable, int key) {

    Node* tempSearchNode = searchNode(hashTable, key);
    if(tempSearchNode != NULL){
        printf("-1\n");
        return;
    }

    int index = key % hashTable->size;
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    
    if (hashTable->table[index] == NULL) {
        hashTable->table[index] = newNode;
    } else {
        Node* current = hashTable->table[index];
        Node* prev = NULL;
        while (current != NULL && current->key < key) {
            prev = current;
            current = current->next;
        }
        if (prev == NULL) {
            newNode->next = hashTable->table[index];
            hashTable->table[index] = newNode;
        } else {
            prev->next = newNode;
            newNode->next = current;
        }
    }
}


// Function to delete a key from the hash table
void deleteKey(HashTable* hashTable, int key) {

    Node* temp = searchNode(hashTable, key);
    if(temp == NULL){
        printf("-1\n");
        return;
    }
    search(hashTable, key);

    int index = key % hashTable->size;
    Node* current = hashTable->table[index];
    Node* prev = NULL;
    
    while (current != NULL && current->key != key) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("-1\n");
    } else {
        if (prev == NULL) {
            hashTable->table[index] = current->next;
        } else {
            prev->next = current->next;
        }
        free(current);
        // printf("%d %d\n", index, 1); // Position is always 1 after deletion
    }
}

// Function to update a key in the hash table
void update(HashTable* hashTable, int oldKey, int newKey) {
    if(searchNode(hashTable, oldKey) == NULL || searchNode(hashTable, newKey) != NULL){
        printf("-1\n");
        return;
    }
    deleteKey(hashTable, oldKey);
    insert(hashTable, newKey);
}

// Function to print elements in a chain of the hash table
void printElementsInChain(HashTable* hashTable, int index) {
    if(index >= hashTable->size){
        printf("-1\n");
        return;
    }
    if (hashTable->table[index] == NULL) {
        printf("-1\n");
    } else {
        Node* current = hashTable->table[index];
        while (current != NULL) {
            printf("%d ", current->key);
            current = current->next;
        }
        printf("\n");
    }
}

int main() {
    int TableSize;
    scanf("%d", &TableSize);
    HashTable hashTable;
    initializeHashTable(&hashTable, TableSize);
    
    char option;
    int key, oldKey, newKey, index;
    
    while (1) {
        scanf(" %c", &option);
        
        if (option == 'e') {
            break;
        }
        
        switch(option) {
            case 'i':
                scanf("%d", &key);
                insert(&hashTable, key);
                break;
            case 'd':
                scanf("%d", &key);
                deleteKey(&hashTable, key);
                break;
            case 'u':
                scanf("%d %d", &oldKey, &newKey);
                update(&hashTable, oldKey, newKey);
                break;
            case 's':
                scanf("%d", &key);
                search(&hashTable, key);
                break;
            case 'p':
                scanf("%d", &index);
                printElementsInChain(&hashTable, index);
                break;
            case 'e':
                return 0;
        }
    }
    
    return 0;
}
