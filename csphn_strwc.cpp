#include <bits/stdc++.h>
using namespace std;
using u32 = uint32_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N, L;
    if (!(cin >> N >> L)) return 0;
    string S; cin >> S;

    // For each residue a (0..L-1) we will prepare:
    // - num_blocks = floor((N-a)/L)
    // - masks[a][m] = vector<u32> of length num_blocks for offset m in 0..L-1
    // - sparse_tables likewise to answer OR queries quickly
    struct Residue {
        int a;
        int num_blocks;
        // masks[m][t] => bitmask for offset m at block t
        vector<vector<u32>> masks; // size L x num_blocks (some offsets beyond tail may not exist when num_blocks=0)
        // sparse_tables[m] : vector<vector<u32>> (k levels) for RMQ-or
        vector<vector<vector<u32>>> st;
        vector<int> log2;
    };
    vector<Residue> residues;
    residues.reserve(L);

    for (int a = 0; a < L; ++a) {
        int num_blocks = (N - a) / L;
        if (num_blocks <= 0) {
            residues.push_back({a, 0, {}, {}, {}});
            continue;
        }
        Residue R;
        R.a = a;
        R.num_blocks = num_blocks;
        R.masks.assign(L, vector<u32>(num_blocks, 0u));
        // fill masks
        for (int t = 0; t < num_blocks; ++t) {
            int base = a + t * L;
            for (int m = 0; m < L; ++m) {
                char ch = S[base + m];
                if (ch != '*') R.masks[m][t] = (1u << (ch - 'a'));
                else R.masks[m][t] = 0u;
            }
        }
        // precompute log2
        R.log2.assign(num_blocks + 1, 0);
        for (int i = 2; i <= num_blocks; ++i) R.log2[i] = R.log2[i>>1] + 1;
        // build sparse table per offset m
        int K = R.log2[num_blocks] + 1;
        R.st.assign(L, vector<vector<u32>>(K, vector<u32>(num_blocks, 0u)));
        for (int m = 0; m < L; ++m) {
            for (int i = 0; i < num_blocks; ++i) R.st[m][0][i] = R.masks[m][i];
            for (int k = 1; k < K; ++k) {
                int len = 1 << k;
                int half = 1 << (k-1);
                for (int i = 0; i + (1<<k) - 1 < num_blocks; ++i) {
                    R.st[m][k][i] = R.st[m][k-1][i] | R.st[m][k-1][i + half];
                }
            }
        }
        residues.push_back(move(R));
    }

    // helper to query OR on R.st for offset m range [l..r], inclusive
    auto query_or = [&](const Residue &R, int m, int l, int r) -> u32 {
        int len = r - l + 1;
        int k = R.log2[len];
        return R.st[m][k][l] | R.st[m][k][r - (1<<k) + 1];
    };

    // check if there exists any window of t blocks (for any residue) that is valid
    auto check_t = [&](int t) -> bool {
        if (t <= 0) return true;
        // For every residue, we will have window_starts = num_blocks - t + 1 (must be >=1)
        for (const Residue &R : residues) {
            int B = R.num_blocks;
            if (B < t) continue;
            int W = B - t + 1; // number of window starts in this residue
            // counter per window start: how many offsets m are valid at this window
            // we will increment counters and check if any reaches L
            vector<int> cnt(W, 0);
            // for each offset m (0..L-1), compute OR for every window start b
            for (int m = 0; m < L; ++m) {
                // if all masks for this offset are zero, then all windows are trivially ok for this offset
                // But we'll still check generically.
                for (int b = 0; b < W; ++b) {
                    u32 mask = query_or(R, m, b, b + t - 1);
                    // valid offset if at most one bit set:
                    // popcount(mask) <= 1
                    if (__builtin_popcount(mask) <= 1) ++cnt[b];
                }
            }
            // check counters
            for (int b = 0; b < W; ++b) if (cnt[b] == L) return true;
        }
        return false;
    };

    // binary search on number of blocks t
    int lo = 0, hi = 0;
    for (const Residue &R : residues) hi = max(hi, R.num_blocks);
    while (lo < hi) {
        int mid = (lo + hi + 1) >> 1;
        if (check_t(mid)) lo = mid;
        else hi = mid - 1;
    }
    // lo is max number of blocks; answer length = lo * L
    cout << (lo * L) << "\n";
    return 0;
}
