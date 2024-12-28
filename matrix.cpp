#include <iostream>
#include <vector>
#include <queue>
#include <climits> // For INT_MAX

using namespace std;

vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int rows = mat.size();
    if (rows == 0) return {}; // Handle empty matrix case
    int cols = mat[0].size();
    vector<vector<int>> dist(rows, vector<int>(cols, INT_MAX));
    queue<pair<int, int>> q;

    // Initialize the queue with all the zero positions
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (mat[i][j] == 0) {
                dist[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    // Directions for moving up, down, left, right
    vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    
    // BFS to update distances
    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (const auto& [dx, dy] : directions) {
            int newX = x + dx, newY = y + dy;
            // Check bounds and if we found a shorter path
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                if (dist[newX][newY] > dist[x][y] + 1) {
                    dist[newX][newY] = dist[x][y] + 1;
                    q.push({newX, newY});
                }
            }
        }
    }
    return dist;
}

int main() {
    vector<vector<int>> mat = {
        {0, 0, 0},
        {0, 1, 0},
        {1, 1, 1}
    };

    vector<vector<int>> result = updateMatrix(mat);

    // Print the result matrix
    for (const auto& row : result) {
        for (int cell : row) cout << cell << " ";
        cout << endl;
    }
    return 0;
}
