#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

const int MOD = 1000000007;

// Structure to represent a node in the graph
struct Node {
    int index;
    int weight;
};

// Function to perform topological sort using BFS
vector<int> topologicalSort(const vector<vector<Node>>& graph) {
    int n = graph.size();
    vector<int> inDegree(n, 0);
    vector<int> sorted;

    // Calculate in-degrees
    for (int i = 0; i < n; ++i) {
        for (const Node& neighbor : graph[i]) {
            inDegree[neighbor.index]++;
        }
    }

    // Create a queue to store nodes with in-degree 0
    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (inDegree[i] == 0) {
            q.push(i);
        }
    }

    // Perform BFS
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        sorted.push_back(node);

        for (const Node& neighbor : graph[node]) {
            if (--inDegree[neighbor.index] == 0) {
                q.push(neighbor.index);
            }
        }
    }

    return sorted;
}

// Function to calculate the shortest path using Dijkstra's algorithm
vector<int> dijkstra(const vector<vector<Node>>& graph, int start) {
    int n = graph.size();
    vector<int> dist(n, INT_MAX);
    dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (const Node& neighbor : graph[u]) {
            int v = neighbor.index;
            int weight = neighbor.weight;
            if (dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    return dist;
}

// Function to calculate the longest path, number of paths, and sum of products
void calculatePaths(const vector<vector<Node>>& graph, const vector<int>& sorted, const vector<int>& S, const vector<int>& T) {
    int n = graph.size();
    vector<vector<int>> longestPath(n, vector<int>(n, -1));
    vector<vector<int>> numPaths(n, vector<int>(n, 0));
    vector<vector<int>> sumProducts(n, vector<int>(n, 0));

    // Iterate over nodes in topological order
    for (int i = 0; i < n; ++i) {
        int u = sorted[i];

        for (const Node& neighbor : graph[u]) {
            int v = neighbor.index;
            int weight = neighbor.weight;

            // Update longest path
            if (longestPath[u][v] == -1 || longestPath[u][v] < longestPath[u][u] + weight) {
                longestPath[u][v] = longestPath[u][u] + weight;
                numPaths[u][v] = numPaths[u][u];
                sumProducts[u][v] = (sumProducts[u][u] * weight) % MOD;
            } else if (longestPath[u][v] == longestPath[u][u] + weight) {
                numPaths[u][v] = (numPaths[u][v] + numPaths[u][u]) % MOD;
                sumProducts[u][v] = (sumProducts[u][v] + (sumProducts[u][u] * weight) % MOD) % MOD;
            }
        }
    }

    // Calculate results for S and T
    int shortestPath = INT_MAX;
    int longestPathLength = -1;
    int totalNumPaths = 0;
    int totalSumProducts = 0;

    for (int u : S) {
        for (int v : T) {
            if (longestPath[u][v] != -1) {
                shortestPath = min(shortestPath, longestPath[u][v]);
                longestPathLength = max(longestPathLength, longestPath[u][v]);
                totalNumPaths = (totalNumPaths + numPaths[u][v]) % MOD;
                totalSumProducts = (totalSumProducts + sumProducts[u][v]) % MOD;
            }
        }
    }

    // Print results
    cout << "Shortest path: " << shortestPath << endl;
    cout << "Longest path: " << longestPathLength << endl;
    cout << "Number of paths: " << totalNumPaths << endl;
    cout << "Sum of products: " << totalSumProducts << endl;
}

int main() {
    // Read input data (replace with your input reading logic)
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    // Create the graph
    vector<vector<Node>> graph(n);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
    }

    // Get sets S and T
    vector<int> S(s);
    vector<int> T(t);
    for (int i = 0; i < s; ++i) {
        cin >> S[i];
    }
    for (int i = 0; i < t; ++i) {
        cin >> T[i];
    }

    // Perform topological sort
    vector<int> sorted = topologicalSort(graph);

    // Calculate paths
    calculatePaths(graph, sorted, S, T);

    return 0;
}