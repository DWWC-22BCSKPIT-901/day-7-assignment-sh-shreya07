#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> bfsOfGraph(int V, vector<vector<int>> &adj) {
    vector<int> bfs;
    vector<bool> visited(V, false);
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return bfs;
}

int main() {
    int V = 5;
    vector<vector<int>> adj = {
        {1, 2, 3},
        {0},
        {0, 4},
        {0},
        {2}
    };
    vector<int> bfs = bfsOfGraph(V, adj);
    for (int v : bfs) cout << v << " ";
    cout << endl;
    return 0;
}
