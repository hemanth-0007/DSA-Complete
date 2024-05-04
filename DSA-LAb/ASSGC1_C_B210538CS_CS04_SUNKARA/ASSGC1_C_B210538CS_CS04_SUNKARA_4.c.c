#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SIZE 1000

// Function to calculate next location using linear probing
int linearProbing1(int key, int i, int m) {
    return (key + i) % m;
}

// Function to calculate next location using quadratic probing
int quadraticProbing2(int key, int i, int m) {
    return (key + i*i) % m;
}

// Function to calculate next location using double hashing
int doubleHashing2(int key, int i, int h1, int R, int m) {
    return (h1 + i * (R - (key % R))) % m;
}

// Function to find maximum prime less than a number
int maxPrimeLessThan(int num) {
    int prime = num - 1;
    bool isPrime = false;
    while (!isPrime) {
        isPrime = true;
        for (int i = 2; i * i <= prime; i++) {
            if (prime % i == 0) {
                isPrime = false;
                break;
            }
        }
        if (!isPrime) {
            prime--;
        }
    }
    return prime;
}

int loadNumbersToArray(char *input, int *array) {
    int count = 0;
    char *token = strtok(input, " "); // Tokenize input string by space

    while (token != NULL && count < MAX_SIZE) {
        array[count] = atoi(token); // Convert token to integer and store in array
        count++;
        token = strtok(NULL, " "); // Move to the next token
    }

    return count; // Return the number of elements loaded into the array
}

bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }
    for (int i = 2; i * i <= number; i++) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

int largestPrimeLessThan(int tableSize) {
    for (int i = tableSize - 1; i > 1; i--) {
        if (isPrime(i)) {
            return i;
        }
    }
    return 2;
}

void linearProbing(int table[], int tsize, int arr[], int N)
{
    // Iterating through the array
    int collisions = 0;
    for (int i = 0; i < N; i++) {
        // Computing the hash value
        int hv = arr[i] % tsize;
 
        // Insert in the table if there
        // is no collision
        if (table[hv] == -1){
            printf("%d ", hv);
            table[hv] = arr[i];
        }
        else {
            // If there is a collision
            // iterating through all
            // possible quadratic values
            for (int j = 0; j < tsize; j++) {
                // Computing the new hash value
                int t = (hv + j) % tsize;
                if (table[t] == -1) {
                    // Break the loop after
                    // inserting the value
                    // in the table
                    table[t] = arr[i];
                    printf("%d ", t);
                    break;
                }
                else {
                    // Incrementing the number
                    // of collisions
                    collisions++;
                }
            }
        }
    }
    printf("\n%d\n", collisions);
}

void quadraticProbing(int table[], int tsize, int arr[], int N)
{
    // Iterating through the array
    int collisions = 0;
    for (int i = 0; i < N; i++) {
        // Computing the hash value
        int hv = arr[i] % tsize;
 
        // Insert in the table if there
        // is no collision
        if (table[hv] == -1){
            printf("%d ", hv);
            table[hv] = arr[i];
        }
        else {
            // If there is a collision
            // iterating through all
            // possible quadratic values
            for (int j = 0; j < tsize; j++) {
                // Computing the new hash value
                int t = (hv + j * j) % tsize;
                if (table[t] == -1) {
                    // Break the loop after
                    // inserting the value
                    // in the table
                    table[t] = arr[i];
                    printf("%d ", t);
                    break;
                }
                else {
                    // Incrementing the number
                    // of collisions
                    collisions++;
                }
            }
        }
    }
    printf("\n%d\n", collisions);
}


void doubleHashing(int table[], int tsize, int arr[], int N)
{
    int R = largestPrimeLessThan(tsize);
    // Iterating through the array
    int collisions = 0;
    for (int i = 0; i < N; i++) {
        // Computing the hash value
        int hv = arr[i] % tsize;
 
        // Insert in the table if there
        // is no collision
        if (table[hv] == -1){
            printf("%d ", hv);
            table[hv] = arr[i];
        }
        else {
            // If there is a collision
            // iterating through all
            // possible quadratic values
            for (int j = 0; j < tsize; j++) {
                // Computing the new hash value
                // h2(k) = R − (key mod R)
                //  (h1(key) + i ∗ h2(key))
                int h2 = (R - (arr[i]%R));
                int t = (hv + j * h2) % tsize;
                if (table[t] == -1) {
                    // Break the loop after
                    // inserting the value
                    // in the table
                    table[t] = arr[i];
                    printf("%d ", t);
                    break;
                }
                else {
                    // Incrementing the number
                    // of collisions
                    collisions++;
                }
            }
        }
    }
    printf("\n%d\n", collisions);
}

int main() {
    int m;// table size
    scanf("%d", &m);
    // read the input string
    char input[MAX_SIZE];
    scanf(" %[^\n]s", input);
    
    
    int keys[MAX_SIZE];
    int n = loadNumbersToArray(input, keys);
    int table[m];
    int tableSize = m;
    for (int i = 0; i < m; i++) {
        table[i] = -1;
    }
    // for (int i = 0; i < m; i++) {
    //     scanf("%d", &keys[i]);
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ", keys[i]);
    // }
    // printf("\n");
    // if(1) return 0;
    linearProbing(table, tableSize, keys, n);
    for(int i = 0; i < m; i++) {
        table[i] = -1;
    }
    quadraticProbing(table, tableSize, keys, n);
    for(int i = 0; i < m; i++) {
        table[i] = -1;
    }
    doubleHashing(table, tableSize, keys, n);
 

    return 0;
}
