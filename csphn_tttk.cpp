#include <bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN = 7e5;
int n, d, k, A, B;
void solve() {
    cin >> n >> d >> k >> A >> B;
    if (n == 1) {
        cout << A << '\n';
        return;
    }
    if (n <= MAXN) {
        vector<int> v;
        v.push_back(A);
        v.push_back(B);
        for (int i = 1; i <= n - 2; ++i) {
            tie(A, B) = make_tuple(B, (A + B) % d);
            v.push_back(B);
        }
        sort(v.begin(), v.end());
        cout << v[k - 1] << '\n';
        return;
    }
    map<pair<int, int>, int> mp;
    map<int, int> cnt;
    ++cnt[A];
    ++cnt[B];
    mp[{A, B}] = 1;
    n -= 2;
    pair<int, int> start = {-1, -1};
    while (1) {
        tie(A, B) = make_tuple(B, (A + B) % d);
        if (mp.count({A, B})) {
            start = {A, B};
            break;
        }
        mp[{A, B}] = 1;
        ++cnt[B];
        --n;
    }
    int cycle_size = 0;
    while (1) {
        ++cnt[B];
        tie(A, B) = make_tuple(B, (A + B) % d);
        ++cycle_size;
        --n;
        if (pair<int, int>(A, B) == start) break;
    }
    int whole = n / cycle_size;
    int remain = n % cycle_size;
    cycle_size = 0;
    while (1) {
        ++cycle_size;
        cnt[B] += whole + (cycle_size <= remain);
        tie(A, B) = make_tuple(B, (A + B) % d);
        if (pair<int, int>(A, B) == start) break;
    }
    for (auto &i : cnt) {
        k -= i.second;
        if (k <= 0) {
            cout << i.first << '\n';
            return;
        }
    }
}
signed main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    #ifdef LOCAL
        // freopen("TEST.inp", "r", stdin);
        // freopen("TEST.out", "w", stdout);
    #else
        // freopen("TEST.inp", "r", stdin);
        // freopen("TEST.out", "w", stdout);
    #endif
    int t;
    cin >> t;
    while (t--) {
        solve();
    }       
    return 0;
}
