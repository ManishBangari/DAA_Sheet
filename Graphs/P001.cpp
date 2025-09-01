
/*
Breadth First Search (BFS): Level Order Traversal

Problem Statement: Given an undirected graph, return a vector of all nodes by traversing the graph using breadth-first search (BFS).

Pre-req: Graph Representation, Queue STL
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to perform BFS
void bfs(int start, const vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;                // Queue for BFS
    q.push(start);               // Start from the given node
    visited[start] = true;       // Mark the start node as visited

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        cout << node << " ";     // Process the current node

        // Visit all unvisited neighbors
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }
}

int main() {
    int n, m;
    cout << "Enter number of nodes and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n + 1); // Adjacency list (1-based indexing)

    cout << "Enter " << m << " edges (u v):" << endl;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        // Add edge to the undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<bool> visited(n + 1, false); // Track visited nodes

    cout << "Enter start node for BFS: ";
    int start;
    cin >> start;

    cout << "BFS traversal is : ";
    bfs(start, adj, visited);
    cout << endl;

    return 0;
}