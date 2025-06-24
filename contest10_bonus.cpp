#include <bits/stdc++.h>
using namespace std;

// We will keep F[i] as a vector<pair<long long,long long>> 
// of (score, energy), sorted by descending score.  No pair is dominated.
//
// At each i: generate a temporary vector `candidates` for all three cases
// then prune `candidates` into F[i].

static const long long NEG_INF = -1e18;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<long long> a(n), c(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> c[i];

    // Build prefix sums pa[0..n]
    vector<long long> pa(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        pa[i] = pa[i - 1] + a[i - 1];
    }

    // F[i] will be the Pareto frontier (score, energy) after processing gift i.
    // We'll store it in a 0-based array of vectors, size n+1.  F[0] = { (0,0) }.
    vector<vector<pair<long long,long long>>> F(n + 1);
    F[0].push_back({0LL, 0LL});

    for (int i = 1; i <= n; i++) {
        vector<pair<long long,long long>> candidates;

        // 1) GAIN: from F[i-1], add (score_prev, energy_prev + 1)
        for (auto &st: F[i - 1]) {
            long long sc = st.first, en = st.second;
            candidates.push_back({sc, en + 1});
        }

        // 2) BUY SINGLE: from F[i-1] if en >= c[i-1], add (sc + a[i-1], en - c[i-1])
        long long cost_i = c[i - 1];
        long long val_i  = a[i - 1];
        for (auto &st: F[i - 1]) {
            long long sc = st.first, en = st.second;
            if (en >= cost_i) {
                candidates.push_back({ sc + val_i, en - cost_i });
            }
        }

        // 3) MERGE & BUY: for each l=1..i, for each (sc_prev,en_prev) in F[l-1] with en_prev>=cost_i,
        //    add (sc_prev + sum(a[l..i]), en_prev - cost_i).  sum(a[l..i]) = pa[i] - pa[l-1].
        for (int l = 1; l <= i; l++) {
            long long sum_seg = pa[i] - pa[l - 1];
            for (auto &st: F[l - 1]) {
                long long sc_prev = st.first, en_prev = st.second;
                if (en_prev >= cost_i) {
                    candidates.push_back({ sc_prev + sum_seg, en_prev - cost_i });
                }
            }
        }

        // Now `candidates` contains all merged states for F[i], possibly with duplicates
        // or dominated pairs.  We must prune to keep only the Pareto‐front:
        //
        // (A) Sort by descending score; if tied, by descending energy.
        sort(candidates.begin(), candidates.end(),
            [](const pair<long long,long long> &A, const pair<long long,long long> &B) {
                if (A.first != B.first) return A.first > B.first;
                return A.second > B.second;
            });

        // (B) Walk through `candidates` in that order, and keep only those whose energy
        //     is strictly greater than any we've kept so far.  That ensures non‐domination.
        F[i].clear();
        long long best_en_so_far = -1;
        for (auto &pr: candidates) {
            long long sc = pr.first, en = pr.second;
            if (en > best_en_so_far) {
                F[i].push_back({sc, en});
                best_en_so_far = en;
            }
        }
        // Now F[i] is a pruned Pareto front, kept in descending order of score.
    }

    // Finally, the answer is max score among all (score,en) in F[0..n].
    long long answer = 0;
    for (int i = 0; i <= n; i++) {
        for (auto &pr: F[i]) {
            answer = max(answer, pr.first);
        }
    }
    cout << answer << "\n";
    return 0;
}
