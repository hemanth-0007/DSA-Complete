#include <bits/stdc++.h>
 

using namespace std;

// Define the grid size
const int N = 4;

// Structure to store the current grid state and the number of moves
struct State {
    int grid[N][N];
    int moves;
};

// Function to perform a clockwise rotation of the grid
State rotate(const State& current) {
    State next;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            next.grid[j][N - 1 - i] = current.grid[i][j];
        }
    }
    next.moves = current.moves + 1;
    return next;
}

// Function to flip a row of the grid
State flipRow(const State& current, int row) {
    State next = current;
    for (int i = 0; i < N; i++) {
        next.grid[row][i] = 1 - current.grid[row][i];
    }
    next.moves = current.moves + 1;
    return next;
}

// Function to flip a column of the grid
State flipColumn(const State& current, int col) {
    State next = current;
    for (int i = 0; i < N; i++) {
        next.grid[i][col] = 1 - current.grid[i][col];
    }
    next.moves = current.moves + 1;
    return next;
}

// Function to check if two grids are equal
bool isEqual(const State& a, const State& b) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (a.grid[i][j] != b.grid[i][j]) {
                return false;
            }
        }
    }
    return true;
}

// Function to perform BFS and find the minimum number of moves
int findMinMoves(State start, State target) {
    queue<State> q;
    unordered_set<string> visited;

    q.push(start);
    visited.insert(string(reinterpret_cast<const char*>(start.grid), sizeof(start.grid)));

    while (!q.empty()) {
        State current = q.front();
        q.pop();

        if (isEqual(current, target)) {
            return current.moves;
        }

        State next;
        // Rotate the grid and add to the queue if not visited
        next = rotate(current);
        if (visited.find(string(reinterpret_cast<const char*>(next.grid), sizeof(next.grid))) == visited.end()) {
            q.push(next);
            visited.insert(string(reinterpret_cast<const char*>(next.grid), sizeof(next.grid)));
        }

        // Flip rows and columns and add to the queue if not visited
        for (int i = 0; i < N; i++) {
            next = flipRow(current, i);
            if (visited.find(string(reinterpret_cast<const char*>(next.grid), sizeof(next.grid))) == visited.end()) {
                q.push(next);
                visited.insert(string(reinterpret_cast<const char*>(next.grid), sizeof(next.grid)));
            }

            next = flipColumn(current, i);
            if (visited.find(string(reinterpret_cast<const char*>(next.grid), sizeof(next.grid))) == visited.end()) {
                q.push(next);
                visited.insert(string(reinterpret_cast<const char*>(next.grid), sizeof(next.grid)));
            }
        }
    }

    return -1; // If no path is found
}

int main() {
    State gridA, gridB;
    cout << "Enter the elements of grid A (0 or 1):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> gridA.grid[i][j];
        }
    }

    cout << "Enter the elements of grid B (0 or 1):" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> gridB.grid[i][j];
        }
    }

    gridA.moves = 0;
    gridB.moves = 0;

    int minMoves = findMinMoves(gridA, gridB);
    cout << "Minimum number of moves: " << minMoves << endl;

    return 0;
}
