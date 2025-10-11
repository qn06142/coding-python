#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, p;
    if (!(cin >> n >> m >> p)) return 0;
    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        long long mask = 0;
        for (int j = 0; j < m; ++j) if (s[j] == '1') mask |= (1ULL << j);
        a[i] = mask;
    }

    int need = (n + 1) / 2;
    long long best_mask = 0;
    int best_cnt = 0;

    mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
    int ITER = 50; 

    uniform_int_distribution<int> dist(0, n - 1);
    for (int it = 0; it < ITER; ++it) {
        int idx = dist(rng);
        long long base = a[idx];
        if (base == 0) continue;

        vector<int> pos;
        for (int j = 0; j < m; ++j) if ( (base >> j) & 1ULL ) pos.push_back(j);
        int P = (int)pos.size();
        if (P == 0) continue;
        if (P > 20) continue; 

        int SZ = 1 << P;

        vector<int> cnt(SZ, 0);
        for (int i = 0; i < n; ++i) {
            int t = 0;
            long long x = a[i];

            for (int b = 0; b < P; ++b) if ( (x >> pos[b]) & 1ULL ) t |= (1 << b);
            cnt[t]++;
        }

        for (int b = 0; b < P; ++b) {
            for (int mask = 0; mask < SZ; ++mask) {
                if ((mask & (1 << b)) == 0) cnt[mask] += cnt[mask | (1 << b)];
            }
        }

        for (int mask = 0; mask < SZ; ++mask) {
            if (cnt[mask] >= need) {
                int pc = __builtin_popcount(mask);
                if (pc > best_cnt) {
                    best_cnt = pc;
                    long long ans = 0;
                    for (int b = 0; b < P; ++b) if (mask & (1 << b)) ans |= (1ULL << pos[b]);
                    best_mask = ans;
                }
            }
        }
    }

    string out(m, '0');
    for (int j = 0; j < m; ++j) if ((best_mask >> j) & 1ULL) out[j] = '1';
    cout << out << "\n";
}