#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    int P_input, Q_input;
    if (!(cin >> N >> P_input >> Q_input)) return 0;
    vector<ll> A(N);
    for (int i = 0; i < N; ++i) cin >> A[i];
    sort(A.begin(), A.end());

    int P = min(P_input, N);
    int Q = min(Q_input, N);

    auto check = [&](ll w)->bool {

        vector<int> nxt_small(N), nxt_large(N);
        int ptr_s = 0, ptr_l = 0;
        for (int i = 0; i < N; ++i) {
            ll limit_s = A[i] + (w - 1);
            ll limit_l = A[i] + (2*w - 1);
            while (ptr_s < N && A[ptr_s] <= limit_s) ++ptr_s;
            while (ptr_l < N && A[ptr_l] <= limit_l) ++ptr_l;
            nxt_small[i] = ptr_s;
            nxt_large[i] = ptr_l;
        }

        vector<vector<int>> dp(N+1, vector<int>(P+1, INF));
        dp[0][0] = 0;

        for (int pos = 0; pos < N; ++pos) {
            for (int s = 0; s <= P; ++s) {
                int used_large = dp[pos][s];
                if (used_large == INF || used_large > Q) continue;

                if (s < P) {
                    int nxt = nxt_small[pos];
                    if (dp[nxt][s+1] > used_large) dp[nxt][s+1] = used_large;
                }

                {
                    int nxt = nxt_large[pos];
                    if (dp[nxt][s] > used_large + 1) dp[nxt][s] = used_large + 1;
                }
            }
        }

        for (int s = 0; s <= P; ++s) {
            if (dp[N][s] <= Q) return true;
        }
        return false;
    };

    ll l = 1, r = 1000000000; 
    while (l < r) {
        ll mid = (l + r) >> 1;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << '\n';
}