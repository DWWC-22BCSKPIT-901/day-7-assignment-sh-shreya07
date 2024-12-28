#include <iostream>
#include <vector>
using namespace std;

void dfsUtil(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &result) {
    visited[node] = true;
    result.push_back(node);
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfsUtil(neighbor, adj, visited, result);
        }
    }
}

vector<int> dfsOfGraph(int V, vector<vector<int>> &adj) {
    vector<int> result;
    vector<bool> visited(V, false);
    dfsUtil(0, adj, visited, result);
    return result;
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
    vector<int> dfs = dfsOfGraph(V, adj);
    for (int v : dfs) cout << v << " ";
    cout << endl;
    return 0;
}
