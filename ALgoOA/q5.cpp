#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;

int M, N, K;
vector<vector<int>> altitude;

vector<int> dx = {0, 0, 1, -1};
vector<int> dy = {1, -1, 0, 0};

bool canVisitKCells(int startX, int startY, int c) {
    vector<vector<bool>> visited(M, vector<bool>(N, false));
    queue<pair<int, int>> q;
    q.push({startX, startY});
    visited[startX][startY] = true;
    int visitedCells = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        visitedCells++;

        if (visitedCells > K) return true;

        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d];
            int ny = y + dy[d];
            if (nx >= 0 && nx < M && ny >= 0 && ny < N && !visited[nx][ny]) {
                if (abs(altitude[x][y] - altitude[nx][ny]) <= c) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
    return visitedCells > K;
}

int findMinimumCapability(int startX, int startY) {
    int left = 0, right = INT_MAX;
    int result = INT_MAX;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (canVisitKCells(startX, startY, mid)) {
            result = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    cin >> M >> N >> K;
    altitude.resize(M, vector<int>(N));

    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> altitude[i][j];
        }
    }

    vector<vector<int>> result(M, vector<int>(N));
    for (int i = 0; i < M; ++i) {
        for (int j = 0; j < N; ++j) {
            result[i][j] = findMinimumCapability(i, j);
        }
    }

    for (const auto& row : result) {
        for (int value : row) {
            cout << value << " ";
        }
        cout << endl;
    }

    return 0;
}
