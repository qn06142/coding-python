#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct Edge {
    int node, cost;
};

int main() {
    int N;
    cin >> N;
    
    vector<int> fee(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> fee[i];
    }
    
    vector<vector<Edge>> graph(N + 1);
    
    for (int i = 1; i < N; ++i) {
        // Nhảy sang phải: i + k với k = 1, 2, 3, ...
        for (int k = 1; i + k <= N; ++k) {
            graph[i].push_back({i + k, fee[i + k]});
        }
        
        // Nhảy sang trái: i - k với k = 1, 2, 3, ...
        for (int k = 1; i - k > 0; ++k) {
            graph[i].push_back({i - k, fee[i - k]});
        }
    }
    
    vector<int> dist(N + 1, INT_MAX);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    dist[1] = 0;
    pq.push({0, 1});
    
    while (!pq.empty()) {
        auto [current_cost, current_node] = pq.top();
        pq.pop();
        
        if (current_cost > dist[current_node]) continue;
        
        for (auto& edge : graph[current_node]) {
            int next_node = edge.node;
            int next_cost = current_cost + edge.cost;
            
            if (next_cost < dist[next_node]) {
                dist[next_node] = next_cost;
                pq.push({next_cost, next_node});
            }
        }
    }
    
    cout << dist[N] << endl;
    
    return 0;
}
