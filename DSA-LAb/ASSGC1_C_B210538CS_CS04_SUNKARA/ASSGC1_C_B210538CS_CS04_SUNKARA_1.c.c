#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 200

// Function to initialize hash table with -1
void initializeHashTable(int hashTable[], int max_size) {
    for (int i = 0; i < max_size; ++i) {
        hashTable[i] = -1;
    }
}

// Function to insert element into hash table using open addressing
void insertIntoHashTable(int hashTable[], int max_size, int element) {
    int index = element % max_size;
    while (hashTable[index] != -1) {
        index = (index + 1) % max_size;
    }
    hashTable[index] = element;
}

// Function to print union of two arrays
void printUnion(int A[], int B[], int m, int n) {
    int max_size = m > n ? 2*m : 2*n;
    int hashTable[max_size];
    initializeHashTable(hashTable, max_size);
    if(m == 0 && n == 0) {
        printf("-1\n");
        return;
    }
    
    // Insert elements of first array into hash table
    // for (int i = 0; i < m; ++i) {
    //     insertIntoHashTable(hashTable,max_size, A[i]);
    // }

    // Print elements of first array
    for (int i = 0; i < m; ++i) {
        if (hashTable[A[i] % max_size] != A[i]) {
            insertIntoHashTable(hashTable,max_size, A[i]);
            printf("%d ", A[i]);
        }
    }

    // Print elements of second array which are not in hash table
    for (int i = 0; i < n; ++i) {
        if (hashTable[B[i] % max_size] != B[i]) {
            printf("%d ", B[i]);
        }
    }
    printf("\n");
}

// Function to print intersection of two arrays
void printIntersection(int A[], int B[], int m, int n) {
    int max_size = m > n ? 2*m : 2*n;
    int hashTable[max_size];
    initializeHashTable(hashTable, max_size);
    if(m == 0 || n == 0) {
        printf("-1\n");
        return;
    }
    // Insert elements of first array into hash table
    for (int i = 0; i < n; ++i) {
        insertIntoHashTable(hashTable,max_size, B[i]);
    }

    // Print elements of second array which are present in hash table
    int visited[max_size];
    for (int i = 0; i < max_size; ++i) visited[i] = 0;
    int isIntersection = 0;
    for (int i = 0; i < m; ++i) {
        if (hashTable[A[i] % max_size] == A[i] && visited[A[i]%max_size] == 0) {
            visited[A[i]%max_size] = 1;
            isIntersection = 1;
            printf("%d ", A[i]);
        }
    }
    if(isIntersection == 0) printf("-1");
    printf("\n");
}

// Function to print set difference of two arrays
void printSetDifference(int A[], int B[], int m, int n) {
    int max_size = m > n ? 2*m : 2*n;
    int hashTable[max_size];
    initializeHashTable(hashTable, max_size);
    if(m == 0){
        printf("-1\n");
        return;
    }
    // Insert elements of second array into hash table
    for (int i = 0; i < n; ++i) {
        insertIntoHashTable(hashTable,max_size, B[i]);
    }
    int isSetDiff = 0;
    // Print elements of first array which are not in hash table
    for (int i = 0; i < m; ++i) {
        if (hashTable[A[i] % max_size] != A[i]) {
            isSetDiff = 1;
            printf("%d ", A[i]);
        }
    }
    if(isSetDiff == 0) printf("-1");

    printf("\n");
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int A[m], B[n];
    for (int i = 0; i < m; ++i) {
        scanf("%d", &A[i]);
    }
    for (int i = 0; i < n; ++i) {
        scanf("%d", &B[i]);
    }
    
    char option;
    char firstCh;
    char secondCh;
    
    while (true) {
        scanf(" %c", &option);
        if(option == 'e') break;
        scanf(" %c %c", &firstCh, &secondCh);
        bool isReverse = (firstCh == 'B');
        
        switch(option) {
            case 'u':
                if(isReverse) printUnion(B, A, n, m);
                else printUnion(A, B, m, n);
                break;
            case 'i':
                if(isReverse) printIntersection(B, A, n, m);
                else printIntersection(A, B, m, n);
                break;
            case 's':
                if(isReverse) printSetDifference(B, A, n, m);
                else printSetDifference(A, B, m, n);
                break;
            case 'e':
                return 0;
                break;
        }
    }
    
    return 0;
}
