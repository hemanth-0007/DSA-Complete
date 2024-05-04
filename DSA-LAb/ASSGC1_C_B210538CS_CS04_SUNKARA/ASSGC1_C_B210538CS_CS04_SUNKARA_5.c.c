#include <stdio.h>

#define MAX_SIZE 100005

// Function to calculate count of distinct integers in all windows of size K
void countDistinctInWindows(int A[], int N, int K) {
    // Initialize variables
    int count[MAX_SIZE] = {0};
    int distinctCount = 0;

    // Count distinct integers in first window of size K
    for (int i = 0; i < K; ++i) {
        if (count[A[i]] == 0) {
            distinctCount++;
        }
        count[A[i]]++;
    }

    // Print count of distinct integers in first window
    printf("%d ", distinctCount);

    // Slide the window and calculate count of distinct integers for each window
    for (int i = K; i < N; ++i) {
        // Remove the leftmost element from the window
        count[A[i - K]]--;
        if (count[A[i - K]] == 0) {
            distinctCount--;
        }

        // Add the new element to the window
        if (count[A[i]] == 0) {
            distinctCount++;
        }
        count[A[i]]++;

        // Print count of distinct integers in current window
        printf("%d ", distinctCount);
    }
}

int main() {
    int N, K;
    scanf("%d %d", &N, &K);

    int A[MAX_SIZE];
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
    }

    countDistinctInWindows(A, N, K);

    return 0;
}
