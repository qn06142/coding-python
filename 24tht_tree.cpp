#include <iostream>
#include <vector>
#include <set>
using namespace std;

vector<int> generate_primes(int n) {
    vector<bool> sieve(n + 1, true);
    sieve[0] = sieve[1] = false;
    for (int p = 2; p * p <= n; ++p) {
        if (sieve[p]) {
            for (int i = p * p; i <= n; i += p) {
                sieve[i] = false;
            }
        }
    }
    vector<int> primes;
    for (int i = 0; i <= n; ++i) {
        if (sieve[i]) {
            primes.push_back(i);
        }
    }
    return primes;
}

vector<pair<int, int>> spiral_order(int R, int C, const set<pair<int, int>>& cannot_plant) {
    vector<pair<int, int>> result;
    vector<vector<bool>> seen(R, vector<bool>(C, false));
    int dr[4] = {0, 1, 0, -1}; // Directions: right, down, left, up
    int dc[4] = {1, 0, -1, 0};
    int r = 0, c = 0, di = 0; // Starting point and direction index
    for (int i = 0; i < R * C; ++i) {
        if (cannot_plant.find({r, c}) == cannot_plant.end()) {
            result.push_back({r, c});
        }
        seen[r][c] = true;
        int cr = r + dr[di], cc = c + dc[di];
        if (0 <= cr && cr < R && 0 <= cc && cc < C && !seen[cr][cc]) {
            r = cr;
            c = cc;
        } else {
            di = (di + 1) % 4; // Change direction
            r += dr[di];
            c += dc[di];
        }
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int N, M, K, Q;
    cin >> N >> M >> K >> Q;
    set<pair<int, int>> cannot_plant;
    for (int i = 0; i < K; ++i) {
        int x, y;
        cin >> x >> y;
        cannot_plant.insert({x - 1, y - 1}); // Convert to 0-indexed
    }

    vector<int> primes = generate_primes(4000000); // Generate enough primes
    vector<vector<int>> grid(N, vector<int>(M, 0));
    vector<pair<int, int>> spiral = spiral_order(N, M, cannot_plant);
    int prime_index = 0;
    for (const auto& p : spiral) {
        int r = p.first, c = p.second;
        if (cannot_plant.find({r, c}) == cannot_plant.end()) {
            grid[r][c] = primes[prime_index++];
        }
    }

    vector<vector<long long>> pref(N + 5, vector<long long>(M + 5, 0)); // Prefix sum of grid values
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            pref[i][j] = pref[i - 1][j] + pref[i][j - 1] - pref[i - 1][j - 1] + grid[i - 1][j - 1];
        }
    }

    // Process each query
    vector<long long> results;
    for (int i = 0; i < Q; ++i) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        results.push_back(pref[x2][y2] - pref[x1 - 1][y2] - pref[x2][y1 - 1] + pref[x1 - 1][y1 - 1]);
    }

    // Output results
    for (const auto& result : results) {
        cout << result << endl;
    }

    return 0;
}