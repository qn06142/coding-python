#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> A;

ll solve(int l, int r, ll h) {
    if (l > r) return 0;

    ll cost1 = r - l + 1;

    ll m = LLONG_MAX;
    for (int i = l; i <= r; ++i) m = min(m, A[i]);

    ll cost2 = m - h;
    int i = l;
    while (i <= r) {
        if (A[i] == m) { ++i; continue; }
        int j = i;
        while (j <= r && A[j] != m) ++j;
        cost2 += solve(i, j - 1, m);
        i = j;
    }
    return min(cost1, cost2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    if (!(cin >> N)) return 0;
    A.assign(N, 0);
    for (int i = 0; i < N; ++i) cin >> A[i];
    cout << solve(0, N-1, 0) << '\n';
    return 0;
}