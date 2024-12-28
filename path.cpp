#include <iostream>
#include <vector>
#include <queue>
using namespace std;

bool validPath(int n, vector<vector<int>> &edges, int source, int destination) {
    vector<vector<int>> adj(n);
    for (auto &edge : edges) {
        adj[edge[0]].push_back(edge[1]);
        adj[edge[1]].push_back(edge[0]);
    }
    vector<bool> visited(n, false);
    queue<int> q;
    q.push(source);
    visited[source] = true;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        if (node == destination) return true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return false;
}

int main() {
    vector<vector<int>> edges = {{0, 1}, {1, 2}, {2, 0}};
    int n = 3, source = 0, destination = 2;
    cout << (validPath(n, edges, source, destination) ? "True" : "False") << endl;
    return 0;
}
