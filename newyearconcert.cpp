#include <bits/stdc++.h>
using namespace std;

const long long maxN = 4e5 + 5;
const long long mod = 1e9 + 7;
const long long oo = 1e18;
long long n, q;
long long a[maxN], lg[maxN], f[20][maxN];

#define endl "\n"

void log() {
    for (long long i = 2; i < maxN; i++)
        lg[i] = lg[i / 2] + 1;
}

void sparse_table() {
    for (long long i = 1; i <= n; i++)
        f[0][i] = a[i];
    for (long long k = 1; k <= lg[n]; k++)
        for (long long i = 1; i + (1 << k) - 1 <= n; i++) {
            long long j = i + (1 << (k - 1));
            f[k][i] = gcd(f[k - 1][i], f[k - 1][j]);
        }
}

long long get(long long l, long long r) {
    long long k = lg[r - l + 1];
    return gcd(f[k][l], f[k][r - (1 << k) + 1]);
}

void solve() {
    cin >> n;
    for (long long i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sparse_table();
    vector<vector<int>> bads(n);
    for (long long i = 1; i <= n; i++) {
        long long bot = i, top = n, ans = i;
        while (bot <= top) {
            long long mid = (bot + top) / 2;
            if (get(i, mid) >= mid - i + 1) {
                ans = mid;
                bot = mid + 1;
            } else {
                top = mid - 1;
            }
        }
        if (get(i, ans) == ans - i + 1) {
            bads[ans - 1].push_back(i - 1);
        }
    }
    int answer = 0, pi = -1;
    for (int i = 0; i < n; i++) {
        for (auto x : bads[i]) {
            if (x > pi) {
                answer++;
                pi = i;
            }
        }
        cout << answer << ' ';
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    log();
    solve();
    return 0;
}