#include <iostream>
#include <vector>
#include <algorithm>
#include <set> 
// yes its ai, i give up
struct Edge {
    int u, v;

    bool operator<(const Edge& other) const {
        if (u != other.u) return u < other.u;
        return v < other.v;
    }

    bool operator==(const Edge& other) const {
        return u == other.u && v == other.v;
    }
};

std::vector<int> tin; 
std::vector<int> low; 
std::vector<bool> visited; 
int timer; 
bool has_bridge; 

void dfs_bridge_finder(int v, int p, const std::vector<std::vector<int>>& adj_current) {
    visited[v] = true;
    tin[v] = low[v] = timer++;
    for (int to : adj_current[v]) {
        if (to == p) continue; 
        if (visited[to]) {

            low[v] = std::min(low[v], tin[to]);
        } else {

            dfs_bridge_finder(to, v, adj_current);
            low[v] = std::min(low[v], low[to]); 

            if (low[to] > tin[v]) {
                has_bridge = true; 
            }
        }
    }
}

bool is_2_edge_connected(int n_nodes, const std::vector<std::vector<int>>& adj_current) {
    tin.assign(n_nodes + 1, 0);
    low.assign(n_nodes + 1, 0);
    visited.assign(n_nodes + 1, false);
    timer = 0;
    has_bridge = false;

    dfs_bridge_finder(1, -1, adj_current);

    for (int i = 1; i <= n_nodes; ++i) {
        if (!visited[i]) {

            return false;
        }
    }

    return !has_bridge;
}

void generate_combinations(const std::vector<Edge>& possible_edges, int k, int start_idx,
                           std::vector<Edge>& current_combination,
                           std::vector<std::vector<Edge>>& all_combinations) {
    if (current_combination.size() == k) {
        all_combinations.push_back(current_combination);
        return;
    }
    if (start_idx == possible_edges.size()) {
        return;
    }

    current_combination.push_back(possible_edges[start_idx]);
    generate_combinations(possible_edges, k, start_idx + 1, current_combination, all_combinations);
    current_combination.pop_back(); 

    generate_combinations(possible_edges, k, start_idx + 1, current_combination, all_combinations);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<std::vector<int>> original_adj(n + 1);
    std::set<std::pair<int, int>> existing_edges; 
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        original_adj[u].push_back(v);
        original_adj[v].push_back(u);

        existing_edges.insert({std::min(u, v), std::max(u, v)});
    }

    if (n <= 2) {
        if (n == 1) std::cout << 0 << "\n";
        else { 
            std::cout << 1 << "\n"; 
            std::cout << "1 2\n";
        }
        return 0;
    }

    std::vector<Edge> possible_edges;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) {
            if (existing_edges.find({i, j}) == existing_edges.end()) {
                possible_edges.push_back({i, j});
            }
        }
    }

    for (int k = 1; k <= possible_edges.size(); ++k) {
        std::vector<std::vector<Edge>> combinations;
        std::vector<Edge> current_combination;

        generate_combinations(possible_edges, k, 0, current_combination, combinations);

        for (const auto& combo : combinations) {

            std::vector<std::vector<int>> current_adj = original_adj;
            for (const auto& new_edge : combo) {
                current_adj[new_edge.u].push_back(new_edge.v);
                current_adj[new_edge.v].push_back(new_edge.u);
            }

            if (is_2_edge_connected(n, current_adj)) {

                std::cout << k << "\n";
                for (const auto& new_edge : combo) {
                    std::cout << new_edge.u << " " << new_edge.v << "\n";
                }
                return 0; 
            }
        }
    }

    return 0; 
}