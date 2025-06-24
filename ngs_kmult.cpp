#include <bits/stdc++.h>
using namespace std;

// Backtracking (correctness reference) for small n
bool backtrack(const vector<int>& a, int k, int idx, int current_mod) {
    int n = a.size() - 1;
    if (idx > n) {
        return current_mod % k == 0;
    }
    // '+'
    if (backtrack(a, k, idx + 1, (current_mod + a[idx]) % k))
        return true;
    // '-'
    if (backtrack(a, k, idx + 1, (current_mod - a[idx] % k + k) % k))
        return true;
    return false;
}

// DP solution
bool dp_solve(const vector<int>& a, int k) {
    int n = a.size() - 1;
    vector<vector<char>> dp(n+1, vector<char>(k));
    dp[1][a[1]] = 1;
    for (int i = 2; i <= n; ++i) {
        for (int r = 0; r < k; ++r) {
            if (!dp[i-1][r]) continue;
            int add = (r + a[i]) % k;
            int sub = (r - a[i] + k) % k;
            dp[i][add] = 1;
            dp[i][sub] = 1;
        }
    }
    return dp[n][0];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
    uniform_int_distribution<int> dist_n(1, 20);
    uniform_int_distribution<int> dist_k(1, 10);
    uniform_int_distribution<int> dist_val(-50, 50);

    int test_count;
    cout << "Enter number of random tests: ";
    cin >> test_count;
    for (int t = 1; t <= test_count; ++t) {
        int n = dist_n(rng);
        int k = dist_k(rng);
        vector<int> a(n+1);
        for (int i = 1; i <= n; ++i) a[i] = dist_val(rng);

        // normalize a mod k
        vector<int> a_mod(n+1);
        for (int i = 1; i <= n; ++i) {
            a_mod[i] = ((a[i] % k) + k) % k;
        }

        bool res_bt = backtrack(a_mod, k, 2, a_mod[1]);
        bool res_dp = dp_solve(a_mod, k);
        if (res_bt != res_dp) {
            cerr << "Mismatch on test " << t << "\n";
            cerr << "n=" << n << ", k=" << k << "\n";
            cerr << "a = [";
            for (int i = 1; i <= n; ++i) cerr << a[i] << (i<n?",":"");
            cerr << "]\n";
            cerr << "backtrack=" << res_bt << ", dp=" << res_dp << "\n";
            return 1;
        }
    }
    cout << "All " << test_count << " tests passed!" << endl;
    return 0;
}
 