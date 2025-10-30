// live_triangle.cpp
#include <bits/stdc++.h>
using namespace std;

void combinations_rec(const vector<int>& vals, int start, int choose,
                      vector<int>& cur, vector<vector<int>>& out) {
    if (choose == 0) {
        out.push_back(cur);
        return;
    }
    int n = vals.size();
    for (int i = start; i <= n - choose; ++i) {
        cur.push_back(vals[i]);
        combinations_rec(vals, i + 1, choose - 1, cur, out);
        cur.pop_back();
    }
}

vector<vector<int>> combinations(const vector<int>& vals, int choose) {
    vector<vector<int>> out;
    vector<int> cur;
    if (choose <= 0) {
        out.push_back({});
        return out;
    }
    if ((int)vals.size() < choose) return out;
    combinations_rec(vals, 0, choose, cur, out);
    return out;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    long long T;
    if (!(cin >> n >> T)) return 0;

    if (n % 3 != 0) {
        cout << "-1\n";
        return 0;
    }

    int k = n / 3 + 1;
    int inner_count = k - 2;

    // Precompute numbers 1..n
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) nums[i] = i + 1;

    vector<int> side1_inner_idx, side2_inner_idx, side3_inner_idx;
    for (int idx = 1; idx <= k - 2; ++idx) side1_inner_idx.push_back(idx);
    for (int idx = k; idx <= 2*k - 3; ++idx) side2_inner_idx.push_back(idx);
    for (int idx = 2*k - 1; idx <= n - 1; ++idx) side3_inner_idx.push_back(idx);

    int vpos0 = 0;
    int vpos1 = k - 1;
    int vpos2 = 2*k - 2;

    vector<vector<int>> solutions;
    solutions.reserve(1024);

    // iterate triples of vertices (i<j<l)
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            for (int l = j + 1; l < n; ++l) {
                int vi = nums[i], vj = nums[j], vl = nums[l];
                // remaining values
                vector<int> remVals;
                remVals.reserve(n-3);
                for (int x = 0; x < n; ++x) {
                    if (x==i || x==j || x==l) continue;
                    remVals.push_back(nums[x]);
                }
                // try all 6 permutations assigning vertices to positions (0, k-1, 2k-2)
                array<int,3> vert = {vi, vj, vl};
                sort(vert.begin(), vert.end()); // we'll permute
                do {
                    int a = vert[0], b = vert[1], c = vert[2];
                    long long s1_target = T - (a + b); // side1 inner sum
                    long long s2_target = T - (b + c);
                    long long s3_target = T - (c + a);
                    if (s1_target < 0 || s2_target < 0 || s3_target < 0) continue;
                    long long total_rem = 0;
                    for (int v : remVals) total_rem += v;
                    if (s1_target + s2_target + s3_target != total_rem) continue;

                    // enumerate combinations for group1 (side1 inner)
                    auto group1_combs = combinations(remVals, inner_count);
                    for (auto &g1 : group1_combs) {
                        long long sumg1 = 0;
                        for (int v : g1) sumg1 += v;
                        if (sumg1 != s1_target) continue;

                        // build remAfterG1
                        vector<int> remAfterG1;
                        remAfterG1.reserve(remVals.size() - g1.size());
                        // mark used via unordered_set or boolean; here small n so simple check
                        for (int v : remVals) {
                            bool used = false;
                            for (int x : g1) if (x == v) { used = true; break; }
                            if (!used) remAfterG1.push_back(v);
                        }

                        // enumerate combinations for group2 from remAfterG1
                        auto group2_combs = combinations(remAfterG1, inner_count);
                        for (auto &g2 : group2_combs) {
                            long long sumg2 = 0;
                            for (int v : g2) sumg2 += v;
                            if (sumg2 != s2_target) continue;

                            // group3 is remaining of remAfterG1 after removing g2
                            vector<int> g3;
                            g3.reserve(inner_count);
                            for (int v : remAfterG1) {
                                bool in2 = false;
                                for (int x : g2) if (x == v) { in2 = true; break; }
                                if (!in2) g3.push_back(v);
                            }
                            if ((int)g3.size() != inner_count) continue;
                            long long sumg3 = 0;
                            for (int v : g3) sumg3 += v;
                            if (sumg3 != s3_target) continue;

                            // now we have partition g1,g2,g3 and vertices a,b,c -> permute within each group
                            sort(g1.begin(), g1.end());
                            sort(g2.begin(), g2.end());
                            sort(g3.begin(), g3.end());
                            do {
                                do {
                                    do {
                                        vector<int> pos(n, 0);
                                        pos[vpos0] = a;
                                        pos[vpos1] = b;
                                        pos[vpos2] = c;
                                        // fill side1 inner
                                        for (int t = 0; t < (int)side1_inner_idx.size(); ++t)
                                            pos[side1_inner_idx[t]] = g1[t];
                                        // fill side2 inner
                                        for (int t = 0; t < (int)side2_inner_idx.size(); ++t)
                                            pos[side2_inner_idx[t]] = g2[t];
                                        // fill side3 inner
                                        for (int t = 0; t < (int)side3_inner_idx.size(); ++t)
                                            pos[side3_inner_idx[t]] = g3[t];

                                        // final defensive check (optional)
                                        long long s1 = 0, s2 = 0, s3 = 0;
                                        for (int idx = 0; idx <= k-1; ++idx) s1 += pos[idx];
                                        for (int idx = k-1; idx <= 2*k-2; ++idx) s2 += pos[idx];
                                        for (int idx = 2*k-2; idx < n; ++idx) s3 += pos[idx];
                                        s3 += pos[0]; // close triangle as in definition
                                        if (s1 == T && s2 == T && s3 == T) {
                                            solutions.push_back(pos);
                                        }
                                    } while (next_permutation(g3.begin(), g3.end()));
                                } while (next_permutation(g2.begin(), g2.end()));
                            } while (next_permutation(g1.begin(), g1.end()));
                        }
                    }
                } while (next_permutation(vert.begin(), vert.end()));
            }
        }
    }

    if (solutions.empty()) {
        cout << "-1\n";
        return 0;
    }

    cout << solutions.size() << '\n';
    for (auto &pos : solutions) {
        for (int i = 0; i < (int)pos.size(); ++i) {
            if (i) cout << ' ';
            cout << pos[i];
        }
        cout << '\n';
    }

    return 0;
}
