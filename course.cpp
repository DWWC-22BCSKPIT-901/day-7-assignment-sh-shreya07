#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
    vector<vector<int>> adj(numCourses);
    vector<int> inDegree(numCourses, 0);
    for (auto &prerequisite : prerequisites) {
        adj[prerequisite[1]].push_back(prerequisite[0]);
        ++inDegree[prerequisite[0]];
    }
    queue<int> q;
    for (int i = 0; i < numCourses; ++i) {
        if (inDegree[i] == 0) q.push(i);
    }
    vector<int> order;
    while (!q.empty()) {
        int course = q.front();
        q.pop();
        order.push_back(course);
        for (int neighbor : adj[course]) {
            if (--inDegree[neighbor] == 0) q.push(neighbor);
        }
    }
    return order.size() == numCourses ? order : vector<int>();
}

int main() {
    int numCourses = 4;
    vector<vector<int>> prerequisites = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    vector<int> order = findOrder(numCourses, prerequisites);
    for (int course : order) cout << course << " ";
    cout << endl;
    return 0;
}
