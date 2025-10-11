/*
    CUT PAPER PUZZLE - FULL SOLUTION
    --------------------------------
    Given an initial paper of size 2^n x 2^n, folded alternately vertically
    and horizontally down to size 2^k x 2^k, then m holes are cut at positions
    (i, j) on the folded paper. Once unfolded, each hole replicates by symmetry,
    producing holes on the full 2^n grid. We need to count the number of
    connected components of the remaining (unpunched) cells.

    Approach:
    1. Build a 2^k x 2^k boolean array `cut[i][j]` marking the m punched cells.
    2. We observe that two adjacent cells on the unfolded grid remain adjacent
       if and only if their folded-image positions (on the 2^k grid) are both
       unpunched and are adjacent there.
    3. Thus connectivity on the unfolded grid reduces to connectivity on the
       folded grid: count connected components of uncut cells in the 2^k x 2^k grid.
    4. Use Union-Find to merge each pair of adjacent uncut cells.
    5. Answer is number of distinct sets among uncut cells.

    Time complexity: O(2^k * 2^k * α(2^k * 2^k)) <= about 10^6 operations.
*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct UnionFind {
    int n;
    vector<int> parent, rankv;
    UnionFind(int _n) : n(_n), parent(n), rankv(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find_set(int x) {
        return parent[x] == x ? x : parent[x] = find_set(parent[x]);
    }
    void union_set(int a, int b) {
        a = find_set(a);
        b = find_set(b);
        if (a != b) {
            if (rankv[a] < rankv[b]) swap(a, b);
            parent[b] = a;
            if (rankv[a] == rankv[b]) rankv[a]++;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, m;
    if (!(cin >> n >> k >> m)) return 0;
    int size = 1 << k;
    vector<vector<bool>> cut(size, vector<bool>(size, false));

    for (int t = 0; t < m; t++) {
        int i, j;
        cin >> i >> j;
        // assume input uses 1-based indexing; convert to 0-based
        cut[i-1][j-1] = true;
    }

    int total = size * size;
    UnionFind uf(total);

    auto id = [&](int r, int c) {
        return r * size + c;
    };

    // directions: right, down
    int dr[2] = {0, 1};
    int dc[2] = {1, 0};

    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            if (cut[r][c]) continue;
            for (int d = 0; d < 2; d++) {
                int nr = r + dr[d];
                int nc = c + dc[d];
                if (nr < size && nc < size && !cut[nr][nc]) {
                    uf.union_set(id(r, c), id(nr, nc));
                }
            }
        }
    }

    // count unique roots among uncut cells
    unordered_set<int> comps;
    comps.reserve(total);
    for (int r = 0; r < size; r++) {
        for (int c = 0; c < size; c++) {
            if (!cut[r][c]) {
                comps.insert(uf.find_set(id(r,c)));
            }
        }
    }

    cout << comps.size();
    return 0;
}
