#include <bits/stdc++.h>
using namespace std;

const int dr[] = {-1, 1, 0, 0};
const int dc[] = {0, 0, -1, 1};

struct Action {
    int type; // 1: House, 2: Hotel, 3: Demolish
    int r, c;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    if (fopen("qhtd.inp", "r")) {
        freopen("qhtd.inp", "r", stdin);
        freopen("qhtd.out", "w", stdout);
    }

    int m, n;
    if (!(cin >> m >> n)) return 0;

    vector<string> grid(m);
    for (int i = 0; i < m; ++i) cin >> grid[i];

    auto get_id = [&](int r, int c) { return r * n + c; };
    auto get_rc = [&](int id) { return make_pair(id / n, id % n); };

    vector<long long> a(m * n), b(m * n), c(m * n);
    for (int i = 0; i < m * n; ++i) cin >> a[i];
    for (int i = 0; i < m * n; ++i) cin >> b[i];
    for (int i = 0; i < m * n; ++i) cin >> c[i];

    vector<bool> visited(m * n, false);
    vector<int> target_state(m * n, 0); // 0: Empty, 1: House, 2: Hotel
    vector<Action> actions;
    actions.reserve(3700000);

    long long total_beauty = 0;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            int start_id = get_id(i, j);
            if (grid[i][j] == '#' || visited[start_id]) continue;

            // 1. Collect connected component via BFS
            vector<int> comp;
            queue<int> q;
            q.push(start_id);
            visited[start_id] = true;

            while (!q.empty()) {
                int u = q.front();
                q.pop();
                comp.push_back(u);
                auto [ur, uc] = get_rc(u);

                for (int d = 0; d < 4; ++d) {
                    int nr = ur + dr[d], nc = uc + dc[d];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '.') {
                        int nid = get_id(nr, nc);
                        if (!visited[nid]) {
                            visited[nid] = true;
                            q.push(nid);
                        }
                    }
                }
            }

            // Case A: Isolated cell (|V| = 1)
            if (comp.size() == 1) {
                int u = comp[0];
                if (b[u] > a[u]) {
                    target_state[u] = 1;
                    total_beauty += b[u];
                    auto [r, col] = get_rc(u);
                    actions.push_back({1, r + 1, col + 1});
                } else {
                    target_state[u] = 0;
                    total_beauty += a[u];
                }
                continue;
            }

            // Case B: Component of size >= 2
            bool all_prefer_hotel = true;
            for (int u : comp) {
                if (c[u] <= max(a[u], b[u])) {
                    all_prefer_hotel = false;
                    break;
                }
            }

            int root = comp[0];
            if (all_prefer_hotel) {
                // Must sacrifice exactly one cell with minimal penalty
                long long min_loss = 4e18;
                for (int u : comp) {
                    long long loss = c[u] - max(a[u], b[u]);
                    if (loss < min_loss) {
                        min_loss = loss;
                        root = u;
                    }
                }
                for (int u : comp) {
                    if (u == root) {
                        target_state[u] = (b[u] > a[u]) ? 1 : 0;
                        total_beauty += (target_state[u] == 1) ? b[u] : a[u];
                    } else {
                        target_state[u] = 2;
                        total_beauty += c[u];
                    }
                }
            } else {
                for (int u : comp) {
                    long long best_non = max(a[u], b[u]);
                    if (c[u] > best_non) {
                        target_state[u] = 2;
                        total_beauty += c[u];
                    } else {
                        target_state[u] = (b[u] > a[u]) ? 1 : 0;
                        total_beauty += (target_state[u] == 1) ? b[u] : a[u];
                        root = u; // Pick any non-hotel cell as root
                    }
                }
            }

            // 2. Build Spanning Tree rooted at `root`
            vector<int> parent(m * n, -1);
            vector<int> depth(m * n, 0);
            vector<bool> tree_vis(m * n, false);

            queue<int> tq;
            tq.push(root);
            tree_vis[root] = true;

            while (!tq.empty()) {
                int u = tq.front();
                tq.pop();
                auto [ur, uc] = get_rc(u);

                for (int d = 0; d < 4; ++d) {
                    int nr = ur + dr[d], nc = uc + dc[d];
                    if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '.') {
                        int nid = get_id(nr, nc);
                        if (!tree_vis[nid]) {
                            tree_vis[nid] = true;
                            parent[nid] = u;
                            depth[nid] = depth[u] + 1;
                            tq.push(nid);
                        }
                    }
                }
            }

            // 3. Process hotel construction bottom-up by depth
            vector<int> hotel_cells;
            for (int u : comp) {
                if (target_state[u] == 2) hotel_cells.push_back(u);
            }

            sort(hotel_cells.begin(), hotel_cells.end(), [&](int u, int v) {
                return depth[u] > depth[v];
            });

            for (int u : hotel_cells) {
                int p = parent[u];
                auto [pr, pc] = get_rc(p);
                auto [ur, uc] = get_rc(u);

                actions.push_back({1, pr + 1, pc + 1}); // Temporary scaffolding house
                actions.push_back({2, ur + 1, uc + 1}); // Hotel constructed
                actions.push_back({3, pr + 1, pc + 1}); // Demolish scaffold
            }

            // 4. Construct permanent houses
            for (int u : comp) {
                if (target_state[u] == 1) {
                    auto [ur, uc] = get_rc(u);
                    actions.push_back({1, ur + 1, uc + 1});
                }
            }
        }
    }

    // Output answer
    cout << total_beauty << "\n";
    cout << actions.size() << "\n";
    for (const auto& act : actions) {
        cout << act.type << " " << act.r << " " << act.c << "\n";
    }

    return 0;
}